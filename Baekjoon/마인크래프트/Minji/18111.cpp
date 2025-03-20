#include <iostream>
using namespace std;

int n, m, b, sec, min_sec = 99999999, min_height;
int ground[501][501];

int main() {
	cin >> n >> m >> b;
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> ground[i][j];
		}
	}

	for (int h = 0; h <= 256; h++) {
		int destory = 0, build = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (ground[i][j] < h) { //�׾ƾ��ϴ� ����
					build += h - ground[i][j]; 
				}
				else if (ground[i][j] == h) continue; // ������ �н�
				else if (ground[i][j] > h) { //�μž��� ����
					destory += ground[i][j] - h; 
				}
			}
		}
		if (destory + b >= build) {
			sec = destory * 2 + build; //�ױ� 1��, ���� 2��
			if (sec < min_sec) {
				
				min_sec = sec;
				min_height = h;
			}
			else if (sec == min_sec && h > min_height) {
				min_height = h;
			}

		}
		
	}
	cout << min_sec << ' ' << min_height;

	return 0;
}