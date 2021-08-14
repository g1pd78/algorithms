#include <iostream>
#include <math.h>

using namespace std;

const int arr_size = 100000;
int initialData[arr_size];
int binSearch(int num, int leftSide, int rightSide) {
	if (rightSide >= leftSide) {
		int middleNum = leftSide + (rightSide - leftSide) / 2;
		if (initialData[middleNum] == num)return middleNum + 1;
		if (initialData[middleNum] > num)return binSearch(num, leftSide, middleNum - 1);
		if (initialData[middleNum] < num)return binSearch(num, middleNum + 1, rightSide);
	}
	return -1;
}

int main()
{
	int n, k, numsForSearch[arr_size];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> initialData[i];
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> numsForSearch[i];
	for (int i = 0; i < k; i++)
		cout << binSearch(numsForSearch[i], 0, n - 1) << ' ';
}
