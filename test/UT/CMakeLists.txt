set(PROJECT_TESTS_NAME KorytkoMag_RetDriver_UT)
message(${CMAKE_CURRENT_SOURCE_DIR})

set(UT
    ${PROJECT_SOURCE_DIR}/test/UT/Communication/ZmqReqRespCommunicatorTests.cpp
    ${PROJECT_SOURCE_DIR}/test/UT/DB/DBTests.cpp
    ${PROJECT_SOURCE_DIR}/test/UT/HDLC/HDLCReqFrameBodyTests.cpp
    ${PROJECT_SOURCE_DIR}/test/UT/HDLC/HDLCFrameTests.cpp
    ${PROJECT_SOURCE_DIR}/test/UT/HDLC/HDLCReqFrameBodyInterpreterTests.cpp
    ${PROJECT_SOURCE_DIR}/test/UT/Utils/UserCommandParserTest.cpp
)

add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${UT}
    ${EXTERNAL_LIBRARIES_TESTUTILS}
    ${EXTERNAL_LIBRARIES_TESTUTILS_COMMUNICATORS}
    ${EXTERNAL_LIBRARIES_TESTUTILS_FIXTURES}
    ${EXTERNAL_LIBRARIES_TESTUTILS_HDLC_FRAMESFACTORIES}

    ${PLUGIN_SPECIFICS}
    ${EXTERNAL_LIBRARIES_DATABASE}
    ${EXTERNAL_LIBRARIES_HDLC}
    ${EXTERNAL_LIBRARIES_MESSAGING_PATTERN}
    ${EXTERNAL_LIBRARIES_UTILS}
)

add_dependencies(${PROJECT_TESTS_NAME} gmock_main)

target_link_libraries(${PROJECT_TESTS_NAME}
    gmock_main
    gmock
    ${Boost_LIBRARIES}
    # /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a # uncomment on UBUNTU, I know it sucks
    /usr/lib64/libstdc++fs.a # uncomment on Manjaro, I know it sucks
)

