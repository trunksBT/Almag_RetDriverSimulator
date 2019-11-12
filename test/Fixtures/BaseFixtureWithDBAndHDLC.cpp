#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/RoundTripHDLCCommunicatorStub.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(const Database::ValueType inDB)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicator_(std::make_shared<test::RoundTripHDLCCommunicatorStub>())
{}

