#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>
#include <CommandPattern/AlmagController.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespCommunicator.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqPubSubCommunicator.hpp>

using namespace constraints::almag;
using namespace hardcodes::IOPaths;

namespace
{
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
FrameStrFactoryPtr retDeviceStrFactory = std::make_shared<SRetHDLCFrameStrFactory>();
}

namespace mt
{

class UI_Controller_ZeroMqHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<CommandsToExpectedFrame>
{
protected:
   UI_Controller_ZeroMqHDLC()
      : BaseFixtureWithDBAndHDLC({}, {
         std::make_shared<ZMqReqRespCommunicator>(),
         std::make_shared<ZMqPubSubCommunicator>()})
      , ctrl_{std::make_shared<AlmagController>(
              db_, std::make_shared<RetDriverCommandFactory>(hdlcCommunicators_))}
      , ui_{"AlmagRetDriverUI", "_", db_, ctrl_,
            std::make_shared<AlmagCommandValidationManager>(db_),
            std::make_unique<DatabaseCommandValidationManager>(db_)}
   {
      ui_.setAlmagCommandsConstraints({
         constraints::almag::values.begin(), constraints::almag::values.end()});
   };

   AlmagControllerPtr ctrl_;
   CMenu ui_;
};

TEST_P(UI_Controller_ZeroMqHDLC, ExecuteCommandAndExpectSentFrame)
{
	const auto& returnCode = ui_.runPredefinedCommands(
      GetParam().inCommands
   );
   const auto& receivedFromSecondaryHdlcFrame = hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR)
           ->receiveStr(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(receivedFromSecondaryHdlcFrame);
   ASSERT_THAT(receivedFromSecondaryHdlcFrame.get(), StrEq(GetParam().expectedHdlcFrame));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_ZeroMqHDLC,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ L1::DUMMY_SCAN, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameXID_DummyScan().data()
      },
//      CommandsToExpectedFrame{
//         {{ L1::SET_LINK_SPEED, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//          multiplyString(
//              NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS, retDeviceStrFactory->get_FrameXID_DummyScan().data())
//      },
      CommandsToExpectedFrame{
         {{ L2::ADDRESS_ASSIGNMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameXID_AddressAssignment().data()
      },
      CommandsToExpectedFrame{
         {{ L2::LINK_ESTABLISHMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameSNRM_LinkEstablishment().data()
      },
      CommandsToExpectedFrame{
         {{ L2::THREEGPP_RELEASE_ID, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameXID_3GPPReleaseId().data()
      },
      CommandsToExpectedFrame{
         {{ L2::AISG_PROTOCOL_VERSION, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameXID_AISGProtocolVersion().data()
      },
      CommandsToExpectedFrame{
         {{ L7::CALIBRATE, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         retDeviceStrFactory->get_FrameI_Calibrate().data()
      }
   )
);
}
