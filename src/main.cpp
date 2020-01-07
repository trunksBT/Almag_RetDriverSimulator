#include <Controller/AlmagController.hpp>
#include <Database/Database.hpp>
#include <Database/DatabaseConstraints.hpp>
#include <HDLC/HDLCCommunicator.hpp>

#include <UserInterface/CMenu.hpp>

#include <Utils/Logger.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <Controller/CmdValidationRules/AlmagCommandValidationManager.hpp>
#include <Controller/CmdValidationRules/DatabaseCommandValidationManager.hpp>
#include <MessagingPattern/ZMqReqRepSecondaryStrategy.hpp>

#include <Utils/UserCommandParser.hpp>

int main()
{
   init_logger(IS_LOG_TO_FILE, IS_LOG_ON_STD_OUT,
               boost::log::trivial::trace);

   LOG(trace) << "BEGIN";
   Database db({});
   std::vector<IHDLCCommunicatorPtr> hdlcCommunicators {{
      std::make_shared<ZMqReqRepPrimaryStrategy>(zmq::socket_type::req),  // release mode
//       std::make_shared<HDLCCommunicator>(),  // debug mode
   }};
   ICommandFactoryPtr commandFactory = std::make_shared<RetDriverCommandFactory>(hdlcCommunicators);
   AlmagControllerPtr ctrl = std::make_shared<AlmagController>(db, commandFactory);

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
