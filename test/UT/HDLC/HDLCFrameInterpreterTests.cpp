#include <gmock/gmock.h>

#include <HDLC/HDLCFrameInterpreter.hpp>

using testing::Eq;

class HDLCFrameInterpreterTests : public testing::Test
{
protected:
   HDLCFrameInterpreter frameInterpreter;
};

TEST_F(HDLCFrameInterpreterTests, InterpretFrameXID)
{

   ASSERT_THAT(false, An<>());
}