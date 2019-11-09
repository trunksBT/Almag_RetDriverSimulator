#include <Database/Objects/IOPaths.hpp>

std::ostream& operator << (std::ostream& os, const IOPaths& rhs)
{
    os << "bufferToSend " << rhs.bufferToSend;
    return os;
 
}

