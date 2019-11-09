#include "CommandPattern/Commands/StartPooling.hpp"

#include <chrono>
#include <thread>

#include <HDLC/IHDLCCommunicator.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;

StartPooling::StartPooling(IHDLCCommunicator& hdlcCommunicator)
    : ICommand(hdlcCommunicator)
{
    LOG(debug);
}

StartPooling::~StartPooling()
{
    LOG(debug);
}

/*
void StartPooling::maintainConnection()
{
    while(true)
    {
        LOG(debug) << "************ " << std::this_thread::get_id();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
*/

void StartPooling::execute()
{
    LOG(info);
/*
    std::thread th(&StartPooling::maintainConnection, this); 
    th.join();
*/
    informControllerAboutResult_();
}

std::string StartPooling::handleResponse()
{
    return START_POOLING_NULL + DELIMITER;
}

