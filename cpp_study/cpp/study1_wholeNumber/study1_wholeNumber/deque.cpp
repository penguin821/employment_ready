#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// ������ �����̳� : �����Ͱ� ���� ������� �����Ǵ� ����
	// ���� : vector list deque

	// deque : double ended queue ��ũ
	// ���� ���� ���� ������ٶ� ����ϴ� ����� �ֱ��� (�� �̿� ����)
	
	// ����ó�� �迭(�������� ����)ó�� ���ǳ� ������ �߰���
	// �޸� �Ҵ� ��å�� �ٸ�
	 
	deque<int> dq;

	dq.push_back(1);
	// capacity ����, ������ ��°� �ƴ϶� ����Ʈó�� �� ������ ���°Ŷ�
	dq.push_front(2);

	return 0;
}