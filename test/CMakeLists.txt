message("KorytkoMRetDriver TestCMakeLists")
set(PROJECT_TESTS_NAME Korytko_RetDriver_Test)

include_directories(${PROJECT_SOURCE_DIR}/test)

set(EXTERNAL_LIBRARIES_TESTUTILS_FIXTURES
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDB.hpp
    ${PROJECT_SOURCE_DIR}/externalLibraries/TestUtils/Fixtures/BaseFixtureWithDBAndHDLC.hpp
    )

add_subdirectory(MT)
add_subdirectory(UT)
