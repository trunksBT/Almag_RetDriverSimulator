#pragma once

#include <Utils/TypeAliases.hpp>

struct CommandsToExpectedFrame
{
   const StringsMatrix inCommands;
   const std::string expectedHdlcFrame;
};

struct ReceivedCommand_ExpectedFrameBodyHexes
{
   const StringsMatrix inCommands;
   const Hexes expectedFrameBodyHexes;
};

struct ExpectedFrameType_ExpectedValue_ReceivedString
{
   const FRAME_TYPE expectedFrameType;
   const Hexes expectedHexes;
   const std::string receivedString;
};
