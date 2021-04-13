#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int numArray[9] = {};
	int randNum[3] = {};
	int answer[3] = {};
	int st = 0;
	int ball = 0;

	srand((unsigned int)time(0));

	for (int i = 0; i < 9; ++i) {
		numArray[i] = i + 1;
	}
	//shuffle, swap algo
	int iTemp, idx1, idx2;
	for (int i = 0; i < 20; ++i)
	{	// index를 가져오기 때문에 0~44까지 이다. 
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		iTemp = numArray[idx1];
		numArray[idx1] = numArray[idx2];
		numArray[idx2] = iTemp;
	}

	for (int i = 0; i < 3; i++) {
		randNum[i] = numArray[i];
	}

	while(1){
		st = 0;
		ball = 0;
		cout << "0~9숫자 3개를 입력하세요 : " << endl;
		for (int i = 0; i < 3; i++) {
			cin >> answer[i];
			if(answer[i]==0){
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (randNum[i] == answer[j] && i == j) {
					st++;
				}
				else if (randNum[i] == answer[j])
				{
					ball++;
				}
			}
		}

		cout << st << " 스트라이크" << "  " << ball << " 볼입니다" << endl;

		/*
		for (int i = 0; i < 3; i++) {
			cout << randNum[i] << "\t";
		}
		*/

		cout << endl;
		for (int i = 0; i < 3; i++) {
			cout << answer[i] << "\t";
		}
		cout << endl;

		if (st == 3) {
			break;
		}
	}
	
	return 0;
}
