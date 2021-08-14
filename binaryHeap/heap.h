#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class heap {
private:
	vector<int> list;
	int listSize;
public:
	int changeSize() { listSize = list.size();}
	void add(int priority) {
		list.push_back(priority);
		int i = listSize - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && list[parent] < list[i]) {
			swap(list[i], list[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
		changeSize();
	}
	void restor(int i) {
		int leftChild, rightChild;
		
		leftChild = 2 * i + 1;
		rightChild = 2 * i + 2;
		if (leftChild < listSize && list[leftChild] > list[i]) {
			swap(list[leftChild], list[i]);
			restor(leftChild);
		}
		if (rightChild < listSize && list[rightChild] > list[i]) {
			swap(list[rightChild], list[i]);
			restor(rightChild);
		}
	}
	void buildHeap(int *arr, int arrSize){
		for (int i = 0; i < arrSize; i++)
			list.push_back(arr[i]);
		//list.assign(begin(arrcp), end(arrcp));
		for (int i = listSize / 2; i >= 0; i--)
			restor(i);
	}
	int max() {
		if (listSize != 0) {
			int result = list[0];
			list[0] = list[listSize - 1];
			auto iter = list.cbegin();
			list.erase(iter + listSize - 1);/// - 1
			changeSize();
			restor(0);
			return result;
		}
		return -1;
	}
	void print() {
		for (int i = 0; i < listSize; i++)
			cout << list[i] << '\t';
		cout << '\n';
	}
};