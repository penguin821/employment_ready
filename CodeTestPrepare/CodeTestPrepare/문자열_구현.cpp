#include <iostream>
using namespace std;

string dopa = "111*213*22*3*132**12";

int main()
{
	cout << dopa << "\n";

	// Q1.앞에서부터 3개의 문자열을 출력하라
	cout << dopa.substr(3, 5) << "\n";

	// Q2.해당 문자열을 거꾸로 해서 출력하라.
	reverse(dopa.begin(), dopa.end());
	cout << dopa << "\n";

	// 거꾸로된 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
	dopa += "umzunsik";
	cout << dopa << '\n';
	return 0;
}

