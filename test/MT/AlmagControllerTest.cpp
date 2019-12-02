#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>

#include <CommandPattern/AlmagController.hpp>
#include <CommandPattern/AlmagControllerNull.hpp>
#include <CommandPattern/IController.hpp>

#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>

#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;
using namespace constraints::almag;
using namespace hardcodes::IOPaths;

namespace mt
{

class AlmagControllerShouldPar:
   public BaseFixtureWithDBAndHDLC,
   public ::testing::WithParamInterface<CommandsToExpectedFrame>
{
protected:
    AlmagControllerShouldPar()
      : BaseFixtureWithDBAndHDLC({}, {std::make_shared<test::RoundTripHDLCCommunicatorStub>()})
      , ctrl_(std::make_shared<AlmagController>(db_, std::make_shared<RetDriverCommandFactory>(hdlcCommunicators_)))
    {};

    IAlmagControllerPtr ctrl_;
};

TEST_F(AlmagControllerShouldPar, ForNullPattern_Execute_StartPooling_WithoutResult)
{
   ctrl_ = std::make_shared<AlmagControllerNull>();

	ctrl_->addCommands({{ START_POOLING }});
   ctrl_->executeCommand();

   ASSERT_THAT(ctrl_->getFinalResultCode(), StrEq(defaultVals::FOR_STRING));
}

TEST_P(AlmagControllerShouldPar, Execute_Command_Expect_ResultCode)
{
	ctrl_->addCommands(GetParam().inCommands);
   ctrl_->executeCommand();

   ASSERT_THAT(ctrl_->getFinalResultCode(), StrEq(GetParam().expectedHdlcFrame));
}

INSTANTIATE_TEST_CASE_P(BaseFixtureWithDBAndHDLC,
   AlmagControllerShouldPar,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ START_POOLING }},
         START_POOLING_NULL + DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L1::DUMMY_SCAN, BUFFER_TO_SEND_VAL_1 }},
         L1::DUMMY_SCAN + DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L1::SET_LINK_SPEED, BUFFER_TO_SEND_VAL_1 }},
         multiplyString(NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS, L1::DUMMY_SCAN + DELIMITER)
      },
      CommandsToExpectedFrame{
	      {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         L2::ADDRESS_ASSIGNMENT + DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         L2::LINK_ESTABLISHMENT + DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L2::THREEGPP_RELEASE_ID, BUFFER_TO_SEND_VAL_1 }},
         L2::THREEGPP_RELEASE_ID+ DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L2::AISG_PROTOCOL_VERSION, BUFFER_TO_SEND_VAL_1 }},
         L2::AISG_PROTOCOL_VERSION + DELIMITER
      },
      CommandsToExpectedFrame{
	      {{ L7::CALIBRATE, BUFFER_TO_SEND_VAL_1 }},
         L7::CALIBRATE + DELIMITER
      }
   )
);

}  // namespace mt

