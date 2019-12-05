#pragma once

#include <CommandPattern/ICommand.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommand : public ICommand
{
public:
   virtual ~HDLCCommand();

   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;
   virtual HDLCFrameBodyPtr getFrameBody() const = 0;

protected:
   explicit HDLCCommand(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);

   IHDLCCommunicatorPtr hdlcCommunicator_;
   Strings validatedUserInput_;
   IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory_;
};

using HDLCCommandPtr = std::shared_ptr<HDLCCommand>;
