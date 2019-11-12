#pragma once

#include <CommandPattern/Commands/ICommand.hpp>

class IHDLCCommunicator;

class ThreeGPPReleaseID : public ICommand 
{
public:
   ThreeGPPReleaseID(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput);
   virtual ~ThreeGPPReleaseID() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

