#include <Controller/KorytkoMagController.hpp>
#include <Controller/CmdValidationRules/KorytkoMagCommandValidationManager.hpp>
#include <Controller/CmdValidationRules/DatabaseCommandValidationManager.hpp>
#include <Database/Database.hpp>
#include <Database/DatabaseConstraints.hpp>
#include <HDLC/HDLCCommunicator.hpp>
#include <MessagingPattern/ZMqPubSubPrimaryStrategy.hpp>
#include <MessagingPattern/ZMqReqRepPrimaryStrategy.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <PluginSpecifics/RetDriverCommandFactory.hpp>
#include <UserInterface/CMenu.hpp>
#include <Utils/Logger.hpp>
#include <Utils/UserCommandParser.hpp>
#include <Utils/Utils.hpp>

using namespace defaultVals;

int main()
{
   init_logger(IS_LOG_TO_FILE, IS_LOG_ON_STD_OUT,
               boost::log::trivial::debug);

   LOG(trace) << BEGIN;
   Database db({});
   std::vector<IHDLCCommunicatorPtr> hdlcCommunicators {{
      std::make_shared<ZMqReqRepPrimaryStrategy>(zmq::socket_type::req),
      std::make_shared<ZMqPubSubPrimaryStrategy>(zmq::socket_type::pub),
   }};
   ICommandFactoryPtr commandFactory = std::make_shared<RetDriverCommandFactory>(hdlcCommunicators);
   KorytkoMagControllerPtr ctrl = std::make_shared<KorytkoMagController>(db, commandFactory);

   CMenu ui{"KorytkoMagRetDriverUI", "_", db, ctrl,
      std::make_shared<KorytkoMagCommandValidationManager>(db),
      std::make_unique<DatabaseCommandValidationManager>(db)
   };

   ui.setKorytkoMagCommandsConstraints({
      constraints::korytkomag::values.begin(), constraints::korytkomag::values.end()});
   ui.setDatabaseCommandsConstraints({
      constraints::database::values.begin(), constraints::database::values.end()});

   const std::string hardcodedPort = "5555";
   hdlcCommunicators.at(0)->setupSend(hardcodedPort);

   ui.run({});

   LOG(trace) << END;
   return 0;
}
