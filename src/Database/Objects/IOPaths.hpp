#pragma once

#include <ostream>
#include <string>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

struct IOPaths
{
   boost::optional<std::string> bufferToSend;
};

std::ostream& operator << (std::ostream& os, const IOPaths& rhs);

