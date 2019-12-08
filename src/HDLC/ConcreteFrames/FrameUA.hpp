#pragma once

#include <HDLC/FrameTypes/FrameU.hpp>

class FrameUA : public FrameU
{
public:
   FrameUA();
   explicit FrameUA(const std::string& value);

   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;
};

using FrameUA = std::unique_ptr<FrameUA>;
