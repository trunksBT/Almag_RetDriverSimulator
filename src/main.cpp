#include <CommandPattern/AlmagController.hpp>
#include <Database/Database.hpp>
#include <HDLC/HDLCCommunicator.hpp>
#include <UserInterface/CMenu.hpp>

#include <Utils/Logger.hpp>
#include <PluginCommandConstraints/AlmagConstraints.hpp>
#include <PluginCommandConstraints/DatabaseConstraints.hpp>
#include <Utils/UserCommandParser.hpp>

using namespace std;

int main()
{
   init_logger(!IS_LOG_TO_FILE, IS_LOG_ON_STD_OUT,
               boost::log::trivial::trace);

   LOG(trace) << "BEGIN";
   Database db({});
   std::shared_ptr<IHDLCCommunicator> hdlcCommunicator = std::make_shared<HDLCCommunicator>();
   AlmagControllerPtr ctrl = std::make_shared<AlmagController>(db, hdlcCommunicator);

   CMenu ui_("AlmagRetDriverUI", "_", db, ctrl);

   ui_.setAlmagCommandsConstraints({
      constraints::almag::values.begin(), constraints::almag::values.end()});
   ui_.setDatabaseCommandsConstraints({
      constraints::database::values.begin(), constraints::database::values.end()});

   ui_.run({});

   LOG(trace) << "END";
   return 0;
}
