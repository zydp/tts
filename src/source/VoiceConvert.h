#pragma once
#include <stdio.h>
extern "C" {
	#include "libavformat/avformat.h"
	#include "libavformat/avio.h"
	#include "libavcodec/avcodec.h"
	#include "libavutil/audio_fifo.h"
	#include "libavutil/avassert.h"
	#include "libavutil/avstring.h"
	#include "libavutil/frame.h"
	#include "libavutil/opt.h"
	#include "libswresample/swresample.h"
}
#include "PapereaderGlobalDef.h"


int audio2aac(const char* input, const char* output);