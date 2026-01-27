#pragma once

// 아래 설정을 껏다 키며 조절해도 됨
//#define ENGINE_BUILD_DLL 0

#define DLLEXPORT   __declspec( dllexport )
#define DLLIMPORT   __declspec( dllimport )

// ENGINE_BUILD_DLL 이 선언되어 있는지에 따라 분기
#if ENGINE_BUILD_DLL
#define WANTED_API DLLEXPORT
#else
#define WANTED_API DLLIMPORT
#endif