#pragma once

#include <CommandPattern/ICommandFacade.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class RetDriverCommandFacade final : public ICommandFacade
{
public:
   explicit RetDriverCommandFacade(std::vector<IHDLCCommunicatorPtr>& hdlcCommunicators);
   ICommandPtr interpretAndCreateCommand(std::vector<std::string> validatedInput) override;
   virtual ~RetDriverCommandFacade();
private:
   std::vector<IHDLCCommunicatorPtr> hdlcCommunicators_;
};
