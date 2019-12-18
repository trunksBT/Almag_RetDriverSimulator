message("AlmagRetDriver TestCMakeLists")
set(PROJECT_TESTS_NAME Almag_RetDriver_Test)

include_directories(${PROJECT_SOURCE_DIR}/test)

set(EXTERNAL_LIBRARIES_TESTUTILS_FIXTURES
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDB.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDB.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDBAndHDLC.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDBAndHDLC.cpp
)

set(EXTERNAL_LIBRARIES_TESTUTILS_HDLC_FRAMESFACTORIES
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/HDLC/FramesFactories/SRetHDLCRespFrameBodyStrFactory.cpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/HDLC/FramesFactories/SRetHDLCRespFrameBodyStrFactory.hpp
)

add_subdirectory(MT)
add_subdirectory(UT)
