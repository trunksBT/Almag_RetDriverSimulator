#pragma once

#include <CommandPattern/ICommand.hpp>
#include <Utils/TypeAliases.hpp>

class IHDLCCommunicator;

class LinkEstablishment : public ICommand 
{
public:
   LinkEstablishment(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput);
   virtual ~LinkEstablishment() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

