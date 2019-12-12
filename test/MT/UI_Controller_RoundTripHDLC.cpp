#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <CommandPattern/AlmagController.hpp>

#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>
#include <Utils/Utils.hpp>

#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <HDLC/HDLCReqFrameBodyFactory.hpp>

using testing::Eq;
using namespace hardcodes::IOPaths;
using namespace constraints::almag;

namespace
{
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
constexpr int NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS = 6;
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
      : BaseFixtureWithDBAndHDLC({}, {std::make_shared<test::RoundTripHDLCCommunicatorStub>()})
      , ctrl_(std::make_shared<AlmagController>(db_, std::make_shared<RetDriverCommandFactory>(hdlcCommunicators_)))
      , ui_("AlmagRetDriverUI", "_", db_, ctrl_,
            std::make_shared<AlmagCommandValidationManager>(db_),
            std::make_unique<DatabaseCommandValidationManager>(db_)
      )
   {
      ui_.setAlmagCommandsConstraints({
         constraints::almag::values.begin(), constraints::almag::values.end()});
   };

   AlmagControllerPtr ctrl_;
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
   ASSERT_THAT(sentFrames->build(), Eq(GetParam().expectedFrameHexes));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_RoundTripHDLC,
   ::testing::Values(
      ReceivedCommand_ExpectedFrameHexes{
         {{ L1::DUMMY_SCAN, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_DummyScan()).build()
      },
//      ReceivedCommand_ExpectedFrameHexes{
//         {{ L1::SET_LINK_SPEED, BUFFER_TO_SEND_VAL_1 }},
//         multiplyString(
//                 NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS,
//                 HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_DummyScan()).build())
//      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameU_SNRM_LinkEstablishment()).build()
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
