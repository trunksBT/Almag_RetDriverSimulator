#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class IHDLCCommunicator;

class AISGProtocolVersion : public HDLCCommand
{
public:
   AISGProtocolVersion(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~AISGProtocolVersion() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};

