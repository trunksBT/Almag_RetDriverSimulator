#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class LinkEstablishment : public HDLCCommand
{
public:
   LinkEstablishment(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~LinkEstablishment() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

