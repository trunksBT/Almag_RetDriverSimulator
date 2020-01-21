#include <TestUtils/Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <Controller/KorytkoMagController.hpp>

#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Controller/CmdValidationRules/KorytkoMagCommandValidationManager.hpp>
#include <Controller/CmdValidationRules/DatabaseCommandValidationManager.hpp>

#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCTestCommunicatorStub.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <Controller/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>

using namespace hardcodes::IOPaths;
using namespace constraints::korytkomag;

namespace
{
constexpr unsigned IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
}

namespace mt
{
class UI_Controller_RoundTripHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<ReceivedCommand_ExpectedFrameHexes>
{
protected:
   UI_Controller_RoundTripHDLC()
      : BaseFixtureWithDBAndHDLC({}, {
         std::make_shared<test::RoundTripHDLCTestCommunicatorStub>(),
         std::make_shared<test::RoundTripHDLCTestCommunicatorStub>()
      })
      , ctrl_(std::make_shared<KorytkoMagController>(db_, std::make_shared<RetDriverCommandFactory>(hdlcCommunicators_)))
      , ui_("KorytkoMagRetDriverUI", "_", db_, ctrl_,
            std::make_shared<KorytkoMagCommandValidationManager>(db_),
            std::make_unique<DatabaseCommandValidationManager>(db_)
      )
   {
      ui_.setKorytkoMagCommandsConstraints({
         constraints::korytkomag::values.begin(), constraints::korytkomag::values.end()});
   };

   KorytkoMagControllerPtr ctrl_;
   CMenu ui_;
};

TEST_P(UI_Controller_RoundTripHDLC, ExecuteCommandAndExpectSentFrame)
{
	const auto& returnCode = ui_.runPredefinedCommands(
       GetParam().inCommands
   );
   auto sentFrames = hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR)
       ->receive(BUFFER_TO_SEND_VAL_1);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(sentFrames);
   ASSERT_EQ(sentFrames->build(), GetParam().expectedFrameHexes);
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_RoundTripHDLC,
   ::testing::Values(
      ReceivedCommand_ExpectedFrameHexes{
         {{ L1::DUMMY_SCAN, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_DummyScan()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::THREEGPP_RELEASE_ID, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::AISG_PROTOCOL_VERSION, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L7::CALIBRATE, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameI_Calibrate()).build()
      }
   )
);
}
