#pragma once

#include <CommandPattern/ICommand.hpp>

class IHDLCCommunicator;

class StartPooling : public ICommand 
{
public:
    explicit StartPooling(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator);
    virtual ~StartPooling();

    void execute() final override;
    std::string handleResponse() final override;

private:
//    void maintainConnection();
};

