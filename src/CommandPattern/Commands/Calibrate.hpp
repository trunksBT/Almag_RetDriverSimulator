#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class Calibrate : public HDLCCommand
{
public:
   Calibrate(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~Calibrate() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody();

protected:
   void executeImpl();
};

