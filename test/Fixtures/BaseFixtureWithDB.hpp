#pragma once

#include <gmock/gmock.h>

#include <Database/Database.hpp>
#include <Utils/Logger.hpp>

using testing::StrEq;
using namespace std::string_literals;

class BaseFixtureWithDB : public testing::Test
{
protected:
    explicit BaseFixtureWithDB(const Database::ValueType inDB);

    Database db_;
};

