#include "Utils/UserCommandParser.hpp"

#include <iostream>
#include <unordered_map>
#include <boost/algorithm/string/join.hpp>
#include <boost/tokenizer.hpp>
#include <boost/optional.hpp>

#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>

using tokenizer = boost::tokenizer<boost::char_separator<char>>;
using namespace defaultVals;

namespace
{
    static std::unordered_map<std::string, std::string> commandsToRuleMap({
        { "StartPooling", "ValidationRule" },
        { "Shutdown", "ValidationRule" }
    });
}

Strings UserCommandParser::performLexer(std::string inCommand)
{
   return funs::lex(inCommand, defaultVals::SEPARATOR);
}

Strings UserCommandParser::receiveAndLex()
{
    std::string inChain;
    do
    {
        LOG(info) << "Please pass your command ( Pascal Case )";
        getline(std::cin, inChain);
    } while(inChain.size() == ZERO);

    return performLexer(std::move(inChain));
}

std::string UserCommandParser::validate(const Strings& inCommandWithArgs)
{
    boost::optional<std::string> retVal;
    LOG(info) << boost::algorithm::join(inCommandWithArgs, " ");

    const std::string& command = inCommandWithArgs.at(idxOf::COMMAND);
    if (commandsToRuleMap.count(command))
    {
        retVal = "Shutdown" == command ? validation::SHUTDOWN : validation::ACCEPTED;
    }
    else
    {
        retVal = validation::REJECTED_UNKNOWN_COMMAND;
    }
    LOG(info) << "End " << retVal;
    return *retVal;
}

