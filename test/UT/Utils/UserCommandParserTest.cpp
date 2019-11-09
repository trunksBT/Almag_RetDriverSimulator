#include <gmock/gmock.h>

#include <Utils/UserCommandParser.hpp>
#include <Utils/Utils.hpp>

using testing::StrEq;
using namespace std::string_literals;

class UserCommandParserShould : public testing::Test
{
protected:
    UserCommandParser userCommandParser_;
};

TEST_F(UserCommandParserShould, Accept_OnInput_StartPooling)
{
   ASSERT_THAT(
      userCommandParser_.validate({"StartPooling"s, "3"s}),
      StrEq(validation::ACCEPTED));
}

TEST_F(UserCommandParserShould, RejectUnknownCommand_OnInput_startPooling)
{
   ASSERT_THAT(
      userCommandParser_.validate({"startPooling"s, "3"s}),
      StrEq(validation::REJECTED_UNKNOWN_COMMAND));
}

TEST_F(UserCommandParserShould, Shutdown_OnInput_Shutdown)
{
   ASSERT_THAT(
      userCommandParser_.validate({"Shutdown"s, "3"s}),
      StrEq(validation::SHUTDOWN));
}

