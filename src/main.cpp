#include <CommandPattern/AlmagController.hpp>
#include <Database/Database.hpp>
#include <HDLC/HDLCCommunicator.hpp>
#include <UserInterface/CMenu.hpp>

#include <Utils/Logger.hpp>

#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/CmdConstraints/DatabaseConstraints.hpp>
#include <PluginSpecifics/RetDriverCommandFacade.hpp>
#include <PluginSpecifics/UICmdValidators/AlmagCommandValidationManager.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>

#include <Utils/UserCommandParser.hpp>

using namespace std;

int main()
{
   init_logger(!IS_LOG_TO_FILE, IS_LOG_ON_STD_OUT,
               boost::log::trivial::trace);

   LOG(trace) << "BEGIN";
   Database db({});
   std::vector<IHDLCCommunicatorPtr> hdlcCommunicators {{
      std::make_shared<HDLCCommunicator>(),
   }};
   std::shared_ptr<ICommandFacade> commandFacade = std::make_shared<RetDriverCommandFacade>(hdlcCommunicators);
   AlmagControllerPtr ctrl = std::make_shared<AlmagController>(db, commandFacade);

   CMenu ui{"AlmagRetDriverUI", "_", db, ctrl,
      std::make_shared<AlmagCommandValidationManager>(db),
      std::make_unique<DatabaseCommandValidationManager>(db)
   };

   ui.setAlmagCommandsConstraints({
      constraints::almag::values.begin(), constraints::almag::values.end()});
   ui.setDatabaseCommandsConstraints({
      constraints::database::values.begin(), constraints::database::values.end()});

   ui.run({});

   LOG(trace) << "END";
   return 0;
}
