#include <iostream>
using namespace std;

string dopa = "umzunsik";

int main()
{
	cout << dopa << "\n";

	// Q1.�տ������� 3���� ���ڿ��� ����϶�
	cout << dopa.substr(0, 3) << "\n";

	// Q2.�ش� ���ڿ��� �Ųٷ� �ؼ� ����϶�.
	reverse(dopa.begin(), dopa.end());
	cout << dopa << "\n";

	// �Ųٷε� �ش� ���ڿ� ���� "umzunsik"�̶� ���ڿ��� �߰��϶�.
	dopa += "umzunsik";
	cout << dopa << '\n';
	return 0;
}

