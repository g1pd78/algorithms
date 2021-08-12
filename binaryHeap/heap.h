#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class heap {
private:
	vector<int> list;
public:
	int size() {return list.size();}
	void add(int priority) {
		list.push_back(priority);
		int i = size() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && list[parent] < list[i]) {
			swap(list[i], list[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}
	void restor(int i) {
		int leftChild, rightChild, largestChild;
		for (;;){
			leftChild = 2 * i + 1;
			rightChild = 2 * i + 2;
			largestChild = i;
			if (leftChild < size() && list[leftChild] > list[largestChild])
				largestChild = leftChild;
			if (rightChild < size() && list[rightChild] > list[largestChild])
				largestChild = rightChild;
			if (largestChild == i)break;
			swap(list[largestChild], list[i]);
			largestChild = i;
		}
	}
	void buildHeap(int *arr, int arrSize){
		for (int i = 0; i < arrSize; i++)
			list.push_back(arr[i]);
		//list.assign(begin(arrcp), end(arrcp));
		for (int i = size() / 2; i >= 0; i--)
			restor(i);
	}
	int max() {
		int result = list[0];
		list[0] = list[size() - 1];
		auto iter = list.cbegin();
		list.erase(iter + size() - 1);/// - 1
		return result;
	}
};