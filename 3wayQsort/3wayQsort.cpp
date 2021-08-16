#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}

void qsort(int* arr, int leftSide, int rightSide) {
}

int main()
{
	int n, inputArray[100000];
	size_t size = sizeof(inputArray) / sizeof(int);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputArray[i];
	qsort(inputArray, 0, n - 1);
	printArray(inputArray, n);
}