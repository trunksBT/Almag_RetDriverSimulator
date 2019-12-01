set(PROJECT_TESTS_NAME Almag_RetDriver_MT)
message(${CMAKE_CURRENT_SOURCE_DIR})

set(TESTUTILS_COMMUNICATORS
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqPubSubCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqPubSubCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqReqRespCommunicator.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZMqReqRespCommunicator.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqUtils.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqUtils.hpp
)

set(MT_HappyPath
    ${PROJECT_SOURCE_DIR}/test/MT/AlmagControllerTest.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndDBIntegration/UIAndDBIntegrationTests.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_RoundTripHDLC.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_ZeroMqHDLC.cpp
)

add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${FIXTURES}
    ${MT_HappyPath}
    ${TESTUTILS}
    ${TESTUTILS_COMMUNICATORS}

    ${COMMAND_PATTERN}
    ${DATABASE}
    ${HDLC}
    ${UTILS}
    ${EXTERNAL_LIBRARIES_UTILS}
    ${LOGGER}
    ${USER_INTERFACE}
    ${PLUGIN_SPECIFICS}
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
