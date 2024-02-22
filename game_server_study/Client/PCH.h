#pragma once

#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifdef _DEBUG // 만약 디버그 모드라면
#pragma comment(lib,"Debug\\ServerCore.lib")
#else // 릴리스
#pragma comment(lib,"Release\\ServerCore.lib")
#endif

#include "CorePCH.h"