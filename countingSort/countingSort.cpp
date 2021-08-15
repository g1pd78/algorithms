#include <iostream>

using namespace std;

const int arrSize = 15;//depends on task

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}

int* countingSort(int *arr, int arraySize) {
	int *counterArr = new int[arrSize];
	int *sortedArray = new int[arraySize + 1];

	for (int i = 0; i < arrSize; i++)
		counterArr[i] = 0;
	for (int i = 0; i < arraySize; i++)
		counterArr[arr[i]]++;
	for (int i = 1; i < arrSize; i++)
		counterArr[i] += counterArr[i - 1];
	for (int i = arraySize - 1; i >= 0; i--) {
		sortedArray[counterArr[arr[i]] - 1] = arr[i];
		counterArr[arr[i]]--;
	}
	delete[] counterArr;
	return sortedArray;
}

int main()
{
	int n, inputArray[10000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputArray[i];
	cout << countingSort(inputArray, n);
}
