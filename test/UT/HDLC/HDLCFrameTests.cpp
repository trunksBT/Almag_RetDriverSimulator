#include <gmock/gmock.h>

#include <HDLC/HDLCFrame.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <HDLC/HDLCReqFrameBodyFactory.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <Utils/Functions.hpp>

using testing::Eq;
using namespace funs;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
}

class HDLCFrameTests : public testing::Test
{};

TEST_F(HDLCFrameTests, Transceive_XID_DummyScan)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_DummyScan();
   const auto hdlcFrame = HDLCFrame(hdlcFrameBody);
   ASSERT_THAT(hdlcFrame.build(), Eq(
         merge(START_STOP_FLAG, hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build(),
               {CRC.at(0), CRC.at(1)}, START_STOP_FLAG)));
}
