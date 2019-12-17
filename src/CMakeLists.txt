message("AlmagRetDriver ReleaseCMakeLists")

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${EXTERNAL_LIBRARIES_COMMAND_PATTERN}
    ${DATABASE}
    ${UTILS}
    ${EXTERNAL_LIBRARIES_UTILS}
    ${LOGGER}
    ${USER_INTERFACE}
    ${HDLC}
    ${PLUGIN_SPECIFICS}
)

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    # /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a # uncomment on UBUNTU, I know it sucks
    /usr/lib64/libstdc++fs.a # uncomment on Manjaro, I know it sucks
)

