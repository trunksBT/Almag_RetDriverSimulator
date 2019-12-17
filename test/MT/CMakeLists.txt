set(PROJECT_TESTS_NAME Almag_RetDriver_MT)
message(${CMAKE_CURRENT_SOURCE_DIR})

set(TESTUTILS_COMMUNICATORS
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqPubSubCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqPubSubCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZeroMqUtils.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/DataLinkLayerCommunicators/ZeroMqUtils.hpp
)

set(MT
    ${PROJECT_SOURCE_DIR}/test/MT/AlmagControllerTest.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndDBIntegration/UIAndDBIntegrationTests.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_RoundTripHDLC.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_ZeroMqHDLC.cpp
)

add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${PLUGIN_SPECIFICS}

    ${MT}
    ${FIXTURES}
    ${TESTUTILS}
    ${TESTUTILS_COMMUNICATORS}
    ${TESTUTILS_HDLC_FRAMESFACTORIES}

    ${EXTERNAL_LIBRARIES_COMMAND_PATTERN}
    ${EXTERNAL_LIBRARIES_DATABASE}
    ${EXTERNAL_LIBRARIES_HDLC}
    ${EXTERNAL_LIBRARIES_USER_INTERFACE}
    ${EXTERNAL_LIBRARIES_UTILS}
)

add_dependencies(${PROJECT_TESTS_NAME} gmock_main)

target_link_libraries(${PROJECT_TESTS_NAME}
    gmock_main
    gmock
    ${Boost_LIBRARIES}
    # /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a # uncomment on UBUNTU, I know it sucks
    /usr/lib64/libstdc++fs.a # uncomment on Manjaro, I know it sucks
    ${cppzmq_LIBRARY}
)
