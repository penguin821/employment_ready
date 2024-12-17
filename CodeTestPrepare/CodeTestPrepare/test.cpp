#include <iostream>
#include <vector>
using namespace std;

int split(const string& input, string delimiter)
{
	int result = 0;

	auto start = 0;
	auto end = input.find(delimiter);

	while (end != string::npos)
	{
		if (start != end && start != 0) // 시작부터 매듭 + 매듭없이 시작한 구슬
		{
			string temp = input.substr(start, end - start);
			for (char a : temp)
				result += (a - '0');
		}		

		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	return result;
}

int main()
{
	string str = "*213*22";
	//cout << str.size() << endl;
	cout << split(str, "*") << endl;

	return 0;
}

// 111*213*22*3*132**12