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

int partition(int *arr, int leftPointer, int rightPointer) {
	int iter = leftPointer - 1;
	int pivot = arr[rightPointer];
	for (int i = leftPointer; i < rightPointer;i++) {
		if (arr[i] < pivot) {
			swap(arr[++iter], arr[i]);
		}
	}
	swap(arr[++iter], arr[rightPointer]);
	return iter;
}

void qsort(int *arr, int leftSide, int rightSide) {
	if (leftSide <= rightSide) {
		int pivot = partition(arr, leftSide, rightSide);
		qsort(arr, leftSide, pivot - 1);
		qsort(arr, pivot + 1, rightSide);
	}
}

int main()
{
	int n, inputArray[100000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputArray[i];
	qsort(inputArray, 0, n - 1);
	printArray(inputArray, n);
}