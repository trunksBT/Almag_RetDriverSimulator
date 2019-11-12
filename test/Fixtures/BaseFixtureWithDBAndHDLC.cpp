#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <TestUtils/HDLCCommunicators/ZeroMqHDLCCommunicator.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(
        const Database::ValueType inDB, std::shared_ptr<IHDLCCommunicator> hdlcComm)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicator_(hdlcComm)
{}

