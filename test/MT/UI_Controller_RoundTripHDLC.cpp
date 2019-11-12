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
#include <TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp>

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

class UI_Controller_RoundTripHDLC:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<CommandsToExpectedFrame>
{
protected:
   UI_Controller_RoundTripHDLC()
      : BaseFixtureWithDBAndHDLC({}, std::make_shared<test::RoundTripHDLCCommunicatorStub>())
      , ctrl_(std::make_shared<AlmagController>(db_, hdlcCommunicator_))
      , ui_("AlmagRetDriverUI", "_", db_, ctrl_)
   {};

   AlmagControllerPtr ctrl_;
   CMenu ui_;
};

TEST_P(UI_Controller_RoundTripHDLC, ExecuteCommandAndExpectSentFrame)
{
	const auto& returnCode = ui_.runPredefinedCommands(
      GetParam().inCommands
   );

   const auto& sentFrames = hdlcCommunicator_->receive(BUFFER_TO_SEND_VAL_1);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(sentFrames);
   ASSERT_THAT(toString(sentFrames->build()), StrEq(GetParam().expectedHdlcFrame));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_RoundTripHDLC,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ L1::DUMMY_SCAN, BUFFER_TO_SEND_VAL_1 }},
         DUMMY_SCAN_FRAME
      },
      CommandsToExpectedFrame{
         {{ L1::SET_LINK_SPEED, BUFFER_TO_SEND_VAL_1 }},
         DUMMY_SCAN_FRAME
      },
      CommandsToExpectedFrame{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         ADDRESS_ASSIGNMENT_FRAME
      },
      CommandsToExpectedFrame{
         {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         LINK_ESTABLISHMENT 
      },
      CommandsToExpectedFrame{
         {{ L2::THREEGPP_RELEASE_ID, BUFFER_TO_SEND_VAL_1 }},
         THREEGPP_RELEASE_ID 
      },
      CommandsToExpectedFrame{
         {{ L2::AISG_PROTOCOL_VERSION, BUFFER_TO_SEND_VAL_1 }},
         AISG_PROTOCOL_VERSION 
      },
      CommandsToExpectedFrame{
         {{ L7::CALIBRATE, BUFFER_TO_SEND_VAL_1 }},
         CALIBRATE_STR
      }
   )
);

}  // namespace mt

