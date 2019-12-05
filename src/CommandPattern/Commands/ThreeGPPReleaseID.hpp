#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class ThreeGPPReleaseID : public HDLCCommand
{
public:
   ThreeGPPReleaseID(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~ThreeGPPReleaseID() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};

