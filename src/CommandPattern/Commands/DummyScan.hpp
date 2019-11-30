#pragma once

#include <CommandPattern/ICommand.hpp>
#include <Utils/TypeAliases.hpp>

class IHDLCCommunicator;

class DummyScan : public ICommand 
{
public:
   DummyScan(
      std::shared_ptr<IHDLCCommunicator> hdlcCommunicator,
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

