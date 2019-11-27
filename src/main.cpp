#include <CommandPattern/AlmagController.hpp>
#include <Database/Database.hpp>
#include <HDLC/HDLCCommunicator.hpp>
#include <UserInterface/CMenu.hpp>

#include <Utils/Logger.hpp>
#include <PluginCommandConstraints/AlmagConstraints.hpp>
#include <Utils/UserCommandParser.hpp>

using namespace std;
using namespace constraints::almag;

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
                                    L1::DUMMY_SCAN,
                                    L1::SET_LINK_SPEED,
                                    L2::ADDRESS_ASSIGNMENT,
                                    L2::LINK_ESTABLISHMENT,
                                    L2::THREEGPP_RELEASE_ID,
                                    L2::AISG_PROTOCOL_VERSION,
                                    L7::CALIBRATE});
   ui_.run({});

   LOG(trace) << "END";
   return 0;
}
