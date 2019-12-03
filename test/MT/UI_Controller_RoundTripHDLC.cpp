#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <CommandPattern/AlmagController.hpp>

#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>
#include <Utils/Utils.hpp>

#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/MatcherUtils.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>

using namespace hardcodes::IOPaths;
using namespace constraints::almag;

namespace
{
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
constexpr int NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS = 6;
FrameStrFactoryPtr retDeviceStrFactory = std::make_shared<SRetHDLCFrameStrFactory>();
}

namespace mt
{
class UI_Controller_RoundTripHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<CommandsToExpectedFrame>
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
   ASSERT_THAT(toString(sentFrames), StrEq(GetParam().expectedHdlcFrame));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_RoundTripHDLC,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ L1::DUMMY_SCAN, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameXID_DummyScan().data()
      },
      CommandsToExpectedFrame{
         {{ L1::SET_LINK_SPEED, BUFFER_TO_SEND_VAL_1 }},
         multiplyString(
                 NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS, retDeviceStrFactory->get_FrameXID_DummyScan().data())
      },
      CommandsToExpectedFrame{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameXID_AddressAssignment().data()
      },
      CommandsToExpectedFrame{
         {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameSNRM_LinkEstablishment().data()
      },
      CommandsToExpectedFrame{
         {{ L2::THREEGPP_RELEASE_ID, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameXID_3GPPReleaseId().data()
      },
      CommandsToExpectedFrame{
         {{ L2::AISG_PROTOCOL_VERSION, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameXID_AISGProtocolVersion().data()
      },
      CommandsToExpectedFrame{
         {{ L7::CALIBRATE, BUFFER_TO_SEND_VAL_1 }},
         retDeviceStrFactory->get_FrameI_Calibrate().data()
      }
   )
);
}
