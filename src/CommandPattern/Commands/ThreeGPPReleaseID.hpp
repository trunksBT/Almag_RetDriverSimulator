#pragma once

#include <CommandPattern/Commands/ICommand.hpp>

class IHDLCCommunicator;

class ThreeGPPReleaseID : public ICommand 
{
public:
   ThreeGPPReleaseID(IHDLCCommunicator& hdlcCommunicator, Strings userInput);
   virtual ~ThreeGPPReleaseID() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

