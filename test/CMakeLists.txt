message("AlmagRetDriver TestCMakeLists")
set(PROJECT_TESTS_NAME Almag_RetDriver_Test)

include_directories(${PROJECT_SOURCE_DIR}/test)

set(FIXTURES
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDB.hpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDB.cpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDBAndHDLC.hpp
    ${PROJECT_SOURCE_DIR}/test/Fixtures/BaseFixtureWithDBAndHDLC.cpp
)

set(TEST_UTILS
    ${PROJECT_SOURCE_DIR}/test/TestUtils/Hardcodes.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/ObjectTypes.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/StructsForParametrizedTests.hpp
    ${PROJECT_SOURCE_DIR}/test/TestUtils/UniqueKeys.hpp
)

add_subdirectory(MT)
add_subdirectory(UT)

