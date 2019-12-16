#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class HDLCParameters : public HDLCCommand
{
public:
   HDLCParameters(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~HDLCParameters() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};
