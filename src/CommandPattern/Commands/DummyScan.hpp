#pragma once

#include <CommandPattern/Commands/ICommand.hpp>
#include <Utils/TypeAliases.hpp>

class IHDLCCommunicator;

class DummyScan : public ICommand 
{
public:
   DummyScan(
      IHDLCCommunicator& hdlcCommunicator, 
      Strings userInput, uint8_t numberOfExecutions);

   virtual ~DummyScan() = default;

   void execute() override;
   std::string handleResponse() override;

protected:
   void executeImpl();

private:
   std::string responseMessage_;
   uint8_t numberOfExecutions_;
};

