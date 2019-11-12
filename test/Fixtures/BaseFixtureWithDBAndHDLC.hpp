#pragma once

#include <memory>
#include <Fixtures/BaseFixtureWithDB.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class BaseFixtureWithDBAndHDLC : public BaseFixtureWithDB
{
protected:
    BaseFixtureWithDBAndHDLC(const Database::ValueType inDB, std::shared_ptr<IHDLCCommunicator> hdlcComm);
    std::shared_ptr<IHDLCCommunicator> hdlcCommunicator_;
};

