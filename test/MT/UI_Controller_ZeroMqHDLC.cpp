#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>

#include <UserInterface/CMenu.hpp>
#include <CommandPattern/Commands/DummyScan.hpp>

#include <HDLC/HDLCCommunicator.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/MessagesHelpers.hpp>

#include <CommandPattern/AlmagController.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>
#include <Utils/TypeAliases.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/ObjectTypes.hpp>
#include <TestUtils/UniqueKeys.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLCCommunicators/ZeroMqHDLCCommunicator.hpp>

using namespace command;
using namespace funs;
using namespace hardcodes::IOPaths;
using namespace ui::databaseCommands;

namespace
{

const std::string DUMMY_SCAN_FRAME = "7e ff bf 81 f0 8 1 2 33 33 3 2 ff ff 13 37 7e ";
const std::string ADDRESS_ASSIGNMENT_FRAME = 
"7e ff bf 81 f0 1b 1 13 41 4e "
"30 30 30 30 43 4e 31 30 31 32 "
"33 33 32 32 34 36 31 2 1 3 4 1 1 13 37 7e ";
const std::string LINK_ESTABLISHMENT = "7e 3 93 13 37 7e ";
const std::string THREEGPP_RELEASE_ID = "7e 3 bf 81 f0 3 5 1 a 13 37 7e ";
const std::string AISG_PROTOCOL_VERSION = "7e 3 bf 81 f0 3 14 1 2 13 37 7e ";
const std::string CALIBRATE_STR = "7e 3 fe 31 13 37 7e ";

}  // namespace

namespace mt
{

class UI_Controller_ZeroMqHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<CommandsToExpectedFrame>
{
protected:
   UI_Controller_ZeroMqHDLC()
      : BaseFixtureWithDBAndHDLC({}, std::make_shared<ZeroMqHDLCCommunicator>())
      , ctrl_(std::make_shared<AlmagController>(db_, hdlcCommunicator_))
      , ui_("AlmagRetDriverUI", "_", db_, ctrl_)
   {};

   AlmagControllerPtr ctrl_;
   CMenu ui_;
};

TEST_P(UI_Controller_ZeroMqHDLC, ExecuteCommandAndExpectSentFrame)
{
	const auto& returnCode = ui_.runPredefinedCommands(
      GetParam().inCommands
   );

   const auto& receivedFromSecondaryHdlcFrame = hdlcCommunicator_->receiveStr(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(receivedFromSecondaryHdlcFrame);
   ASSERT_THAT(receivedFromSecondaryHdlcFrame.get(), StrEq(GetParam().expectedHdlcFrame));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_ZeroMqHDLC,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ L1::DUMMY_SCAN, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
         DUMMY_SCAN_FRAME
      }
//      CommandsToExpectedFrame{
//         {{ L1::SET_LINK_SPEED, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         DUMMY_SCAN_FRAME
//      },
//      CommandsToExpectedFrame{
//         {{ L2::ADDRESS_ASSIGNMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         ADDRESS_ASSIGNMENT_FRAME
//      },
//      CommandsToExpectedFrame{
//         {{ L2::LINK_ESTABLISHMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         LINK_ESTABLISHMENT
//      },
//      CommandsToExpectedFrame{
//         {{ L2::THREEGPP_RELEASE_ID, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         THREEGPP_RELEASE_ID
//      },
//      CommandsToExpectedFrame{
//         {{ L2::AISG_PROTOCOL_VERSION, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         AISG_PROTOCOL_VERSION
//      },
//      CommandsToExpectedFrame{
//         {{ L7::CALIBRATE, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
//         CALIBRATE_STR
//      }
   )
);

}  // namespace mt

