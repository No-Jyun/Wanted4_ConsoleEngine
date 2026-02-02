#include "TestLevel.h"
#include "Actor/Player.h"

#include <iostream>

/*
# : 벽(Wall) 
. : 바닥(Ground) 
p : 플레이어(Player) 
b : 박스(Box) 
t : 타겟(Target)
*/

TestLevel::TestLevel()
{
	// TestActor 액터를 레벨에 추가
	//AddNewActor(new Player());
	LoadMap("Map.txt");
}

void TestLevel::LoadMap(const char* filename)
{
	// 파일 로드
	// 최종 파일 경로 만들기 ("../Assets/filename")
	char path[2048] = { };
	sprintf_s(path, 2048, "../Assets/%s", filename);

	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	// 예외 처리
	if (!file)
	{
		// 표준 오류 콘솔 활용
		std::cerr << "Failed to open map file\n";

		// 디버그 모드에서 중단점으로 중단해주는 기능
		__debugbreak();
	}

	// 맵 읽기
	// 맵 크기 파악: File Position 포인터를 파일의 끝으로 이동
	fseek(file, 0, SEEK_END);

	// 이 위치 읽기
	size_t fileSize = ftell(file);

	// File Position 처음으로 되돌리기
	rewind(file);

	// 파일에서 데이터를 읽어올 버퍼 생성
	char* data = new char[fileSize + 1];

	// 데이터 읽기
	size_t readSize = fread(data, sizeof(char), fileSize, file);

	// Test: 읽어온 데이터 임시로 출력
	std::cout << data;

	// 읽어온 문자열을 분석 (파싱-Parcing) 해서 출력

	// 사용한 버퍼 해제
	delete[] data;

	// 파일이 정상적으로 열렸으면 닫기
	fclose(file);
}
