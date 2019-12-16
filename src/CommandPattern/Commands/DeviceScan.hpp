#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class DeviceScan : public HDLCCommand
{
public:
   DeviceScan(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~DeviceScan() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};
