#pragma once

#include <Utils/TypeAliases.hpp>

struct CommandsToExpectedFrame
{
   const StringsMatrix inCommands;
   const std::string expectedHdlcFrame;
};

struct ReceivedCommand_ExpectedFrameHexes
{
   const StringsMatrix inCommands;
   const Hexes expectedFrameHexes;
};

struct ExpectedFrameType_ExpectedValue_ReceivedString
{
   const frameType::BYTE_CTRL expectedFrameType;
   const Hexes expectedHexes;
   const std::string receivedString;
};
