#pragma once
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

class MaxHeap {
private:
	int* arr;
	int size;
	int capacity;
public:
	MaxHeap(int _capacity);
	~MaxHeap() {
		delete[] arr;
	}

	void MaxHeapify(int);

	int parent(int i) { return (i - 1) / 2; }

	int leftChild(int i) { return (2 * i + 1); }

	int rightChild(int i) { return (2 * i + 2); }

	int getMax();

	void addPoint(int x);

	void print() {
		for (int i = 0; i < size; i++)
			cout << arr[i] << '\t';
		cout << '\n';;
	}

};

MaxHeap::MaxHeap(int _capacity) {
	capacity = _capacity;
	size = 0;
	arr = new int[_capacity];
}

void MaxHeap::addPoint(int x) {
	arr[size] = x;
	int i = size;
	while (arr[parent(i)] < arr[i] && i > 0) {
		swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
	size++;
}

int MaxHeap::getMax() {
	if (size == 0) {
		return -1;
	}//////1 
	int heapRoot = arr[0];
	arr[0] = arr[size - 1];
	size--;
	MaxHeapify(0);
	return heapRoot;
}

void MaxHeap::MaxHeapify(int i) {
	int left = leftChild(i);
	int right = rightChild(i);
	int largestChild = i;

	if (left < size && arr[left] > arr[largestChild])
		largestChild = left;
	if (right < size && arr[right] > arr[largestChild])
		largestChild = right;
	if (largestChild != i) {
		swap(arr[largestChild], arr[i]);
		MaxHeapify(largestChild);
	}
}