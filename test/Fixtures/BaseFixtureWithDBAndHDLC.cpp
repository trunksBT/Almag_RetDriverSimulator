#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespCommunicator.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(
        const Database::ValueType inDB, std::vector<IHDLCCommunicatorPtr> hdlcComm)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicators_{hdlcComm}
{}
