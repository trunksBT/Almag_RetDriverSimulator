#pragma once

#include <Fixtures/BaseFixtureWithDB.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class BaseFixtureWithDBAndHDLC : public BaseFixtureWithDB
{
protected:
    explicit BaseFixtureWithDBAndHDLC(const Database::ValueType inDB);

    std::shared_ptr<IHDLCCommunicator> hdlcCommunicator_;
};

