#pragma once

#include <any>
#include <functional>
#include <string>
#include <boost/signals2.hpp>
#include <Utils/TypeAliases.hpp>

class ICommand
{
public:
   virtual ~ICommand() = default;

   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;
   void registerResponseHandler(std::function<void(void)> responseHandler);

protected:
   ICommand() = default;

   using AlmagControllerInformer = boost::signals2::signal<void(void)>;
   AlmagControllerInformer informControllerAboutResult_;
};

using ICommandPtr = std::shared_ptr<ICommand>;
