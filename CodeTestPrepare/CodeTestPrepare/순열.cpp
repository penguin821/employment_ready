#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	int a[] = { 2, 1, 3 };
	sort(a, a + 3);
	do {
		for (int i : a) 
			cout << i << " ";
		cout << '\n';
	} while (next_permutation(a, a + 3));
}
