set(PROJECT_TESTS_NAME Almag_RetDriver_MT)
message(${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_UTILS
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HexesUtils.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HexesUtils.hpp)

set(MT_HappyPath
    ${PROJECT_SOURCE_DIR}/test/MT/AlmagControllerTest.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndDBIntegration/UIAndDBIntegrationTests.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_RoundTripHDLC.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_ZeroMqHDLC.cpp
)

set(MT_SadPath
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndControllerIntegrationTestsSadPath.cpp 
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqHDLCCommunicator.cpp 
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqHDLCCommunicator.hpp 
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqUtils.cpp 
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLCCommunicators/ZeroMqUtils.hpp)


add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${FIXTURES}
    ${MT_HappyPath}
    ${MT_SadPath}
    ${TEST_UTILS}

    ${COMMAND_PATTERN}
    ${DATABASE}
    ${HDLC}
    ${UTILS}
    ${USER_INTERFACE}
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
