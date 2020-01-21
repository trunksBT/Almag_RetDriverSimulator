set(PROJECT_TESTS_NAME KorytkoMag_RetDriver_MT)
message(${CMAKE_CURRENT_SOURCE_DIR})


set(MT
    ${PROJECT_SOURCE_DIR}/test/MT/KorytkoMagControllerTest.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UIAndDBIntegration/UIAndDBIntegrationTests.cpp
    ${PROJECT_SOURCE_DIR}/test/MT/UI_Controller_RoundTripHDLC.cpp
)

add_executable(${PROJECT_TESTS_NAME}
    ${PROJECT_SOURCE_DIR}/test/main.cpp

    ${MT}
    ${EXTERNAL_LIBRARIES_TESTUTILS}
    ${EXTERNAL_LIBRARIES_TESTUTILS_COMMUNICATORS}
    ${EXTERNAL_LIBRARIES_TESTUTILS_FIXTURES}
    ${EXTERNAL_LIBRARIES_TESTUTILS_HDLC_FRAMESFACTORIES}

    ${PLUGIN_SPECIFICS}
    ${EXTERNAL_LIBRARIES_COMMAND_PATTERN}
    ${EXTERNAL_LIBRARIES_DATABASE}
    ${EXTERNAL_LIBRARIES_HDLC}
    ${EXTERNAL_LIBRARIES_MESSAGING_PATTERN}
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
