#pragma once

#include <memory>
#include <TestUtils/Fixtures/BaseFixtureWithDB.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class BaseFixtureWithDBAndHDLC : public BaseFixtureWithDB
{
protected:
    BaseFixtureWithDBAndHDLC(const Database::ValueType inDB, std::vector<IHDLCCommunicatorPtr> hdlcComm);
    std::vector<IHDLCCommunicatorPtr> hdlcCommunicators_;
};

