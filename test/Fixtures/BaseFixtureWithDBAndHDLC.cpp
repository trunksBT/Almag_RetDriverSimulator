#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/HDLCCommunicator.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(const Database::ValueType inDB)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicator_(std::make_shared<test::HDLCCommunicator>())
{}

