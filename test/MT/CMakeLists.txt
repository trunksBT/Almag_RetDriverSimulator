set(PROJECT_TESTS_NAME Almag_RetDriver_MT)
message(${CMAKE_CURRENT_SOURCE_DIR})

set(MT_HappyPath
    ${PROJECT_SOURCE_DIR}/test/MT/AlmagControllerTest.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndDBIntegration/UIAndDBIntegrationTests.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndControllerIntegrationTestsHappyPath.cpp
)

set(MT_SadPath
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndControllerIntegrationTestsSadPath.cpp
        ../TestUtils/HDLCCommunicator.cpp ../TestUtils/HDLCCommunicator.hpp ../TestUtils/HexesUtils.cpp ../TestUtils/HexesUtils.hpp)

add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${FIXTURES}
    ${MT_HappyPath}
    ${MT_SadPath}
    ${TEST_UTILS}

    ${COMMAND_PATTERN}
    ${DATABASE}
    ${HDLC}
    ${USER_INTERFACE_ALMAG_COMMAND_VALIDATION}
    ${USER_INTERFACE_DATABASE}
    ${USER_INTERFACE}
    ${UTILS}
)

add_dependencies(${PROJECT_TESTS_NAME} gmock_main)

target_link_libraries(${PROJECT_TESTS_NAME}
    gmock_main
    gmock
    ${Boost_LIBRARIES}
    # /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a # uncomment on UBUNTU, I know it sucks
    /usr/lib64/libstdc++fs.a # uncomment on Manjaro, I know it sucks
)

