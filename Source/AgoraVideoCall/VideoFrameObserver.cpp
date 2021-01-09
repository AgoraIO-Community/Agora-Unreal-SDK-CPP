//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoFrameObserver.h"


bool VideoFrameObserver::onCaptureVideoFrame(VideoFrame& Frame)
{
   const auto BufferSize = Frame.yStride*Frame.height;

	if (OnCaptureVideoFrame)
	{
		OnCaptureVideoFrame( static_cast< uint8_t* >( Frame.yBuffer ), Frame.width, Frame.height, BufferSize );
	}
   
	return true;
}

bool VideoFrameObserver::onRenderVideoFrame(unsigned int uid, VideoFrame& Frame)
{
	const auto BufferSize = Frame.yStride*Frame.height;

	if (OnRenderVideoFrame)
	{
		OnRenderVideoFrame(uid, static_cast<uint8_t*>(Frame.yBuffer), Frame.width, Frame.height, BufferSize );
	}

	return true;
}

void VideoFrameObserver::setOnCaptureVideoFrameCallback(
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback)
{
	OnCaptureVideoFrame = Callback;
}

void VideoFrameObserver::setOnRenderVideoFrameCallback(
	std::function<void(std::uint32_t, std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback)
{
	OnRenderVideoFrame = Callback;
}

