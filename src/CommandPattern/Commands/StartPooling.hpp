#pragma once

#include "CommandPattern/Commands/ICommand.hpp"

class IHDLCCommunicator;

class StartPooling : public ICommand 
{
public:
    explicit StartPooling(IHDLCCommunicator& hdlcCommunicator);
    virtual ~StartPooling();

    void execute() final override;
    std::string handleResponse() final override;

private:
//    void maintainConnection();
};

