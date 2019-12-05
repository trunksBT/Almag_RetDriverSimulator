#pragma once

#include <CommandPattern/Commands/HDLCCommand.hpp>

class DummyScan : public HDLCCommand
{
public:
   DummyScan(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput, uint8_t numberOfExecutions);
   virtual ~DummyScan() = default;

   void execute() override;
   std::string handleResponse() override;

protected:
   void executeImpl();

private:
   std::string responseMessage_;
   uint8_t numberOfExecutions_;
};

