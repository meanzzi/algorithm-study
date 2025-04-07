#include <iostream>
using namespace std;

int pw = 0; //���� ���� �� ī��Ʈ ����
int checkarr[4]; //�����ؾ��ϴ� ����
int arr[4]; //���� ���� ����

void Add(char c) {
	if (c == 'A') {
		arr[0]++;
		if (checkarr[0] == arr[0]) pw++; // �ּ����� ���� -> ��� �������� �����ؾ���, ó�� �������� ���� ++ (<= ��� X)
	}
	else if (c == 'C') {
		arr[1]++;
		if (checkarr[1] == arr[1]) pw++;
	}
	else if (c == 'G') {
		arr[2]++;
		if (checkarr[2] == arr[2]) pw++;
	}
	else if (c == 'T') {
		arr[3]++;
		if (checkarr[3] == arr[3]) pw++;
	}
}

void Remove(char c) {
	if (c == 'A') {
		if (checkarr[0] == arr[0]) pw--;
		arr[0]--;
	}
	else if (c == 'C') {
		if (checkarr[1] == arr[1]) pw--;
		arr[1]--;
	}
	else if (c == 'G') {
		if (checkarr[2] == arr[2]) pw--;
		arr[2]--;
	}
	else if (c == 'T') {
		if (checkarr[3] == arr[3]) pw--;
		arr[3]--;
	}
}

int main() {
	int s, p, result = 0;
	string dna;

	cin >> s >> p >> dna;
	for (int i = 0;i < 4;i++) {
		cin >> checkarr[i];
		if (checkarr[i] == 0) pw++;
	}

	for (int i = 0;i < p;i++) {
		Add(dna[i]);
	}
	if (pw == 4) result++;

	for (int i = p;i < s;i++) {
		int j = i - p;
		Add(dna[i]); //��ĭ �̵��ϹǷ� ���� ���� ���� �߰�
		Remove(dna[j]); //��ĭ �̵��ϹǷ� ���� �տ� ���� ���� ����
		if (pw == 4) result++;
	}
	cout << result;

	return 0;
}