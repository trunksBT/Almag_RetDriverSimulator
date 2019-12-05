#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class AddressAssignment : public HDLCCommand
{
public:
   AddressAssignment(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~AddressAssignment() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

