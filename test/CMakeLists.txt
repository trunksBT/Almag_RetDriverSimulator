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
)

set(TESTUTILS_HDLC_FRAMESFACTORIES
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/FrameHexFactory.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetFrameBodyStrFactory.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetFrameBodyStrFactory.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetFrameBodyHexFactory.cpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/HDLC/FramesFactories/SRetFrameBodyHexFactory.hpp
)

add_subdirectory(MT)
add_subdirectory(UT)
