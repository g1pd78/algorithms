#include <iostream>
#include <array>

using namespace std;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
    cout << '\n';
}

void mergeFunc(int leftPointer, int middlePointer, int rightPointer, int arr[]) {
    int leftPartSize = middlePointer - leftPointer + 1,
        rightPartSize = rightPointer - middlePointer;
    int* mergedLeftSubArray = new int[leftPartSize];
    int* mergedRightSubArray = new int[rightPartSize];
    int leftPartPointer = 0, rightPartPointer = 0, mergerdArrayPointer = leftPointer;

    for (int i = 0; i < leftPartSize; i++)
        mergedLeftSubArray[i] = arr[i + leftPointer];
    for (int i = 0; i < rightPartSize; i++)
        mergedRightSubArray[i] = arr[i + middlePointer + 1];

    while (leftPartSize > leftPartPointer && rightPartSize > rightPartPointer) {
        if (mergedLeftSubArray[leftPartPointer] < mergedRightSubArray[rightPartPointer]) {
            arr[mergerdArrayPointer] = mergedLeftSubArray[leftPartPointer];
            leftPartPointer++;
        }
        else {
            arr[mergerdArrayPointer] = mergedRightSubArray[rightPartPointer];
            rightPartPointer++;
        }
        mergerdArrayPointer++;
    }
    while (leftPartPointer < leftPartSize) {
        arr[mergerdArrayPointer] = mergedLeftSubArray[leftPartPointer];
        mergerdArrayPointer++;
        leftPartPointer++;
    }
    while (rightPartPointer < rightPartSize) {
        arr[mergerdArrayPointer] = mergedRightSubArray[rightPartPointer];
        mergerdArrayPointer++;
        rightPartPointer++;
    }
    delete[] mergedLeftSubArray;
    delete[] mergedRightSubArray;
}

void mergeSort(int leftPointer, int rightPointer, int arr[]){
    if (rightPointer <= leftPointer)return;
    int middlePointer = leftPointer + (rightPointer - leftPointer) / 2;
    mergeSort(leftPointer, middlePointer, arr);
    mergeSort(middlePointer + 1, rightPointer, arr);
    mergeFunc(leftPointer, middlePointer, rightPointer, arr);
}



int main()
{
    int inputArray[100000], n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inputArray[i];

    printArray(inputArray, n);
    mergeSort(0, n - 1, inputArray);
    printArray(inputArray, n);
}