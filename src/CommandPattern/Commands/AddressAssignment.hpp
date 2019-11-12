#pragma once

#include <CommandPattern/Commands/ICommand.hpp>
#include <Utils/TypeAliases.hpp>

class IHDLCCommunicator;

class AddressAssignment : public ICommand 
{
public:
   AddressAssignment(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput);
   virtual ~AddressAssignment() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

