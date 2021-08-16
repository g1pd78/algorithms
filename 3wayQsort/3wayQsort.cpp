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

void partition(int *arr, int leftPointer, int rightPointer, int &i, int &j) {
	if (rightPointer - leftPointer == 1) {
		if(arr[leftPointer] > arr[rightPointer])
			swap(arr[leftPointer], arr[rightPointer]);
		i = leftPointer;
		j = rightPointer;
		return;
	}

	int pivot = arr[rightPointer];
	int middlePointer = leftPointer;

	while (middlePointer <= rightPointer) {
		if (arr[middlePointer] < pivot)
			swap(arr[leftPointer++], arr[middlePointer++]);
		else if (arr[middlePointer] == pivot)
			middlePointer++;
		else if (arr[middlePointer] > pivot)
			swap(arr[middlePointer], arr[rightPointer--]);
	}

	i = leftPointer - 1;
	j = middlePointer;
}

void qsort(int* arr, int leftSide, int rightSide) {
	if (leftSide <= rightSide) {
		int i, j;
		partition(arr, leftSide, rightSide, i, j);
		qsort(arr, leftSide, i);
		qsort(arr, j, rightSide);
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