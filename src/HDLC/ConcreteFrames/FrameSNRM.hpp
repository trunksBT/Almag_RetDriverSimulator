#pragma once

#include <HDLC/FrameTypes/FrameU.hpp>

class FrameSNRM : public FrameU
{
public:
   FrameSNRM();
   explicit FrameSNRM(const std::string& value);

   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;
};

using FrameSNRMPtr = std::unique_ptr<FrameSNRM>;
