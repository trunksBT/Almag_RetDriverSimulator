#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>
#include <Controller/AlmagController.hpp>
#include <Controller/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespCommunicator.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqPubSubCommunicator.hpp>

using testing::Eq;
using namespace constraints::almag;
using namespace hardcodes::IOPaths;

namespace
{
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
}

namespace mt
{

class UI_Controller_ZeroMqHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<ReceivedCommand_ExpectedFrameHexes>
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
   auto receivedFrame = hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR)
           ->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(GetParam().expectedFrameHexes));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_ZeroMqHDLC,
   ::testing::Values(
      ReceivedCommand_ExpectedFrameHexes{
         {{ L1::DUMMY_SCAN, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build()
      },
//    {{ L1::SET_LINK_SPEED, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//       CANNOT IMPLEMENT THAT TEST AS APPLICATION IS ONE_THREADED
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::ADDRESS_ASSIGNMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::LINK_ESTABLISHMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::THREEGPP_RELEASE_ID, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::AISG_PROTOCOL_VERSION, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L7::CALIBRATE, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         hdlcFrameBodyFactory->get_FrameI_Calibrate()->build()
      }
   )
);
}
