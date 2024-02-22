#pragma once
// 그냥 PCH는 말 그대로 패키지용 라이브러리를 모아둘거라 ServerCore 외 다른 프로젝트 파일에 영향을 못줌
// 실질적으로 클라랑 서버에 영향 줄 전처리기 파일들은 여기에

#include "TypeDef.h"

#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

void HelloWorld();

