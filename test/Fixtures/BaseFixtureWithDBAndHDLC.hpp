#pragma once

#include <Fixtures/BaseFixtureWithDB.hpp>
#include <HDLC/HDLCCommunicator.hpp>

class BaseFixtureWithDBAndHDLC : public BaseFixtureWithDB
{
protected:
    explicit BaseFixtureWithDBAndHDLC(const Database::ValueType inDB);

    HDLCCommunicator hdlcCommunicator_;
};

