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
protected:
   IHDLCCommunicatorPtr hdlcCommunicator{
      std::make_shared<ZMqReqRespTestCommunicator>() };
};

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_DummyScan)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_DummyScan());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build()));
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_AddressAssignment)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_AddressAssignment());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build()));
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameU_LinkEstablishment)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameU_LinkEstablishment());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build()));
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_3GPPReleaseId)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build()));
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameXID_AISGProtocolVersion)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build()));
}

TEST_F(ZmqReqRespCommunicatorTests, Should_get_FrameI_Calibrate)
{
   hdlcCommunicator->send(ADDRESS_OF_PORT_FOR_ZERO_MQ, hdlcFrameBodyFactory->get_FrameI_Calibrate());
   auto receivedFrame = hdlcCommunicator->receive(ADDRESS_OF_PORT_FOR_ZERO_MQ);

   ASSERT_TRUE(receivedFrame);
   ASSERT_THAT(receivedFrame->getFrameBody()->build(), Eq(
           hdlcFrameBodyFactory->get_FrameI_Calibrate()->build()));
}
////INSTANTIATE_TEST_CASE_P(ZmqReqRespCommunicatorTests,
////    ZmqReqRespCommunicatorTests,
////    ::testing::Values(
////         SentFrame_ExpectedFrameHexes{
////             hdlcFrameBodyFactory->get_FrameXID_DummyScan(),
////             hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build()
////      }
////    {{ L1::SET_LINK_SPEED, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////       CANNOT IMPLEMENT THAT TEST AS APPLICATION IS ONE_THREADED
////      ReceivedCommand_ExpectedFrameHexes{
////         {{ L2::ADDRESS_ASSIGNMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////         hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build()
////      },
////      ReceivedCommand_ExpectedFrameHexes{
////         {{ L2::LINK_ESTABLISHMENT, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////         hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build()
////      },
////      ReceivedCommand_ExpectedFrameHexes{
////         {{ L2::THREEGPP_RELEASE_ID, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////         hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build()
////      },
////      ReceivedCommand_ExpectedFrameHexes{
////         {{ L2::AISG_PROTOCOL_VERSION, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////         hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build()
////      },
////      ReceivedCommand_ExpectedFrameHexes{
////         {{ L7::CALIBRATE, ADDRESS_OF_PORT_FOR_ZERO_MQ }},
////         hdlcFrameBodyFactory->get_FrameI_Calibrate()->build()
////      }
//   )
//);
}
