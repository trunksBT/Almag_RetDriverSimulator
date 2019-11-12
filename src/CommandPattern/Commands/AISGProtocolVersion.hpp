#pragma once

#include <CommandPattern/Commands/ICommand.hpp>

class IHDLCCommunicator;

class AISGProtocolVersion : public ICommand 
{
public:
   AISGProtocolVersion(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput);
   virtual ~AISGProtocolVersion() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;

protected:
   void executeImpl();
};

