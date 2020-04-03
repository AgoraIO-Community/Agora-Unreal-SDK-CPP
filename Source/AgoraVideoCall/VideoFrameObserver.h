//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <functional>

#include "AgoraMediaEngine.h"

/**
 * 
 */
class AGORAVIDEOCALL_API VideoFrameObserver : public agora::media::IVideoFrameObserver
{
public:
	virtual ~VideoFrameObserver() = default;
public:
	bool onCaptureVideoFrame(VideoFrame& videoFrame) override;

	bool onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame) override;

	void setOnCaptureVideoFrameCallback(
		std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> callback);

	void setOnRenderVideoFrameCallback(
		std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> callback);

   virtual VIDEO_FRAME_TYPE getVideoFormatPreference() override { return FRAME_TYPE_RGBA; }

private:

	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnCaptureVideoFrame;
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnRenderVideoFrame;
};
