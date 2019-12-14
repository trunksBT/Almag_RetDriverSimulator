//#include <gmock/gmock.h>
//
//#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
//#include <HDLC/HDLCRespFrameBodyFactory.hpp>
//#include <TestUtils/HDLC/FramesFactories/SRetHDLCRespFrameBodyStrFactory.hpp>
//#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
//#include <TestUtils/StructsForParametrizedTests.hpp>
//#include <Utils/Functions.hpp>
//
//using testing::StrEq;
//using namespace convert;
//
//namespace
//{
//IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCRespFrameBodyFactory>();
//FrameStrFactoryPtr retDeviceStrFactory = std::make_shared<SRetHDLCRespFrameBodyStrFactory>();
//}
//
//class HDLCRespFrameBodyTests :
//    public ::testing::TestWithParam<BuiltFrame_ExpectedFrameStr>
//{};
//
//TEST_P(HDLCRespFrameBodyTests, BuiltFrame)
//{
//   const auto hdlcFrameBody = GetParam().builtFrame;
//   ASSERT_THAT(toString(hdlcFrameBody->build()),StrEq(GetParam().expectedFrameStr));
//}
//
//INSTANTIATE_TEST_CASE_P(HDLCRespFrameBodyTests,
//    HDLCRespFrameBodyTests,
//    ::testing::Values(
////        BuiltFrame_ExpectedFrameStr{
////            hdlcFrameBodyFactory->get_FrameXID_AddressAssignment(),
////            retDeviceStrFactory->get_FrameXID_AddressAssignment()
////        },
//        BuiltFrame_ExpectedFrameStr{
//            hdlcFrameBodyFactory->get_FrameU_LinkEstablishment(),
//            retDeviceStrFactory->get_FrameU_LinkEstablishment()
//        }
////        BuiltFrame_ExpectedFrameStr{
////            hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId(),
////            retDeviceStrFactory->get_FrameXID_3GPPReleaseId()
////        },
////        BuiltFrame_ExpectedFrameStr{
////            hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion(),
////            retDeviceStrFactory->get_FrameXID_AISGProtocolVersion()
////        },
////        BuiltFrame_ExpectedFrameStr{
////            hdlcFrameBodyFactory->get_FrameI_Calibrate(),
////            retDeviceStrFactory->get_FrameI_Calibrate()
////        }
//    )
//);
