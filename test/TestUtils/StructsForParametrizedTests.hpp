#pragma once

#include <Utils/TypeAliases.hpp>

struct CommandsToExpectedFrame
{
   const StringsMatrix inCommands;
   const std::string expectedHdlcFrame;
};

struct StringToRecognizedFrameType
{
   const FRAME_TYPE expectedFrameType;
   const Hexes expectedHexes;
   const std::string receivedString;
};
