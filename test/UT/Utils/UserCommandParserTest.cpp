#include <gmock/gmock.h>

#include <Utils/UserCommandParser.hpp>
#include <Utils/Utils.hpp>

using namespace std::string_literals;

class UserCommandParserShould : public testing::Test
{
protected:
    UserCommandParser userCommandParser_;
};

TEST_F(UserCommandParserShould, Accept_OnInput_StartPooling)
{
   ASSERT_EQ(
      userCommandParser_.validate({"StartPooling"s, "3"s}),
      validation::ACCEPTED);
}

TEST_F(UserCommandParserShould, RejectUnknownCommand_OnInput_startPooling)
{
   ASSERT_EQ(
      userCommandParser_.validate({"startPooling"s, "3"s}),
      validation::REJECTED_UNKNOWN_COMMAND);
}

TEST_F(UserCommandParserShould, Shutdown_OnInput_Shutdown)
{
   ASSERT_EQ(
      userCommandParser_.validate({"Shutdown"s, "3"s}),
      validation::SHUTDOWN);
}

