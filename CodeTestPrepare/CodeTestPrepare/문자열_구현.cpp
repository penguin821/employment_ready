#include <iostream>
using namespace std;

string dopa = "111*213*22*3*132**12";

int main()
{
	cout << dopa << "\n";

	// Q1.�տ������� 3���� ���ڿ��� ����϶�
	cout << dopa.substr(3, 5) << "\n";

	// Q2.�ش� ���ڿ��� �Ųٷ� �ؼ� ����϶�.
	reverse(dopa.begin(), dopa.end());
	cout << dopa << "\n";

	// �Ųٷε� �ش� ���ڿ� ���� "umzunsik"�̶� ���ڿ��� �߰��϶�.
	dopa += "umzunsik";
	cout << dopa << '\n';
	return 0;
}

