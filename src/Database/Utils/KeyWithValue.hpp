#pragma once

#include <any>
#include <string>

struct KeyWithValue
{
    std::string key;
    std::any value;
};

struct TypeWithValue
{
    std::string type;
    std::any value;
};

struct TypeWithInstanceId
{
    std::string type;
    uint32_t id;
};

