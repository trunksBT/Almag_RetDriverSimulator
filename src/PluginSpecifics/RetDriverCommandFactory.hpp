#pragma once

#include <Controller/ICommandFactory.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class RetDriverCommandFactory final : public ICommandFactory
{
public:
   explicit RetDriverCommandFactory(std::vector<IHDLCCommunicatorPtr>& hdlcCommunicators);
   ICommandPtr interpretAndCreateCommand(std::vector<std::string> validatedInput) override;
   virtual ~RetDriverCommandFactory();
private:
   std::vector<IHDLCCommunicatorPtr> hdlcCommunicators_;
};
