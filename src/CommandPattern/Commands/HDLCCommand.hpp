#pragma once

#include <CommandPattern/ICommand.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommand : public ICommand
{
public:
   virtual ~HDLCCommand();

   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;

protected:
   explicit HDLCCommand(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);

   IHDLCCommunicatorPtr hdlcCommunicator_;
   Strings validatedUserInput_;
};

using HDLCCommandPtr = std::shared_ptr<HDLCCommand>;
