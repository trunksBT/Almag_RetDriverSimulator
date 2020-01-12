#include <gmock/gmock.h>

#include <Controller/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespTestCommunicator.hpp>

using testing::Eq;
using namespace hardcodes::IOPaths;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
}

namespace mt
{
class ZmqReqRespCommunicatorTests : public testing::Test
{
public:
   ZmqReqRespCommunicatorTests()
   : hdlcCommunicator{ std::make_shared<ZMqReqRespTestCommunicator>() }
   {
      hdlcCommunicator->setupSend(ADDRESS_OF_PORT_FOR_ZERO_MQ);
      hdlcCommunicator->setupReceive(ADDRESS_OF_PORT_FOR_ZERO_MQ);
   }
protected:
   IHDLCCommunicatorPtr hdlcCommunicator;
};

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_DummyScan)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_DummyScan());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build());
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_AddressAssignment)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_AddressAssignment());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build());
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameU_LinkEstablishment)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameU_LinkEstablishment());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build());
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_3GPPReleaseId)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build());
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_AISGProtocolVersion)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build());
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameI_Calibrate)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameI_Calibrate());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_EQ(receivedFrame->getFrameBody()->build(), 
           hdlcFrameBodyFactory->get_FrameI_Calibrate()->build());
}

}
/// TODO I wanted to parametrize that test but it looks like there cannot be pased pointer as a test parameter
//terminate called after throwing an instance of 'boost::wrapexcept<boost::log::v2_mt_posix::system_error>'
//what():  Failed to set TLS value: Invalid argument
