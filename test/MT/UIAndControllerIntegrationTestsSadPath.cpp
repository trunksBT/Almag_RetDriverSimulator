#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <UserInterface/CMenu.hpp>
#include <CommandPattern/AlmagController.hpp>
#include <Utils/Utils.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp>

using namespace command;
using namespace hardcodes::IOPaths;
using namespace std::string_literals;
using namespace ui::databaseCommands;

namespace mt
{

class UIAndControllerIntegrationShouldForSadPath : public BaseFixtureWithDBAndHDLC
{
protected:
   UIAndControllerIntegrationShouldForSadPath()
      : BaseFixtureWithDBAndHDLC({}, std::make_shared<test::RoundTripHDLCCommunicatorStub>())
      , ctrl_(std::make_shared<AlmagController>(db_, hdlcCommunicator_))
      , ui_("AlmagRetDriverUI", "_", db_, ctrl_)
   {};

   AlmagControllerPtr ctrl_;
   CMenu ui_;
};

TEST_F(UIAndControllerIntegrationShouldForSadPath, Execute_Unknown)
{
	const auto& returnCode = ui_.runPredefinedCommands({
        { UNKNOWN },
   });

   ASSERT_TRUE(returnCode);
}
//
//TEST_F(UIAndControllerIntegrationShouldForSadPath, Execute_DummyScan)
//{
//	const auto& returnCode = ui_.runPredefinedCommands({
//        { L1::DUMMY_SCAN },
//   });
//
//   ASSERT_FALSE(returnCode);
//} // TODO TO UNCOMMENT

}  // namespace mt

