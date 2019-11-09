#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(const Database::ValueType inDB)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicator_(HDLCCommunicator())
{}

