message("AlmagRetDriver TestCMakeLists")
set(PROJECT_TESTS_NAME Almag_RetDriver_Test)

include_directories(${PROJECT_SOURCE_DIR}/test)

set(FIXTURES
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDB.hpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDB.cpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDBAndHDLC.hpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDBAndHDLC.cpp
)

set(TESTUTILS
    ${PROJECT_SOURCE_DIR}/test/TestUtils/Hardcodes.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/ObjectTypes.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/StructsForParametrizedTests.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/UniqueKeys.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HexesUtils.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HexesUtils.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/MatcherUtils.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/MatcherUtils.hpp
)

set(TESTUTILS_HDLC_FRAMESFACTORIES
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetHDLCRespFrameBodyStrFactory.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetHDLCRespFrameBodyStrFactory.hpp
)

add_subdirectory(MT)
add_subdirectory(UT)
