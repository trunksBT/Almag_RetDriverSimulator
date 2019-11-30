#pragma once

#include <CommandPattern/ICommand.hpp>

class IHDLCCommunicator;

class Calibrate : public ICommand 
{
public:
   Calibrate(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput);
   virtual ~Calibrate() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

