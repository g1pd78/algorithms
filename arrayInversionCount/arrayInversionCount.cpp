#include <iostream>
#include <array>

using namespace std;
typedef long long int lli;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
    cout << '\n';
}

lli  mergeFunc(int leftPointer, int middlePointer, int rightPointer, int arr[]) {
    int leftPartSize = middlePointer - leftPointer + 1,
        rightPartSize = rightPointer - middlePointer;
    int* mergedLeftSubArray = new int[leftPartSize];
    int* mergedRightSubArray = new int[rightPartSize];
    int leftPartPointer = 0, rightPartPointer = 0, mergerdArrayPointer = leftPointer;
    lli arrayInversionCount = 0;

    for (int i = 0; i < leftPartSize; i++)
        mergedLeftSubArray[i] = arr[i + leftPointer];
    for (int i = 0; i < rightPartSize; i++)
        mergedRightSubArray[i] = arr[i + middlePointer + 1];

    while (leftPartSize > leftPartPointer && rightPartSize > rightPartPointer) {
        if (mergedLeftSubArray[leftPartPointer] <= mergedRightSubArray[rightPartPointer]) {
            arr[mergerdArrayPointer] = mergedLeftSubArray[leftPartPointer];
            leftPartPointer++;
        }
        else {
            arr[mergerdArrayPointer] = mergedRightSubArray[rightPartPointer];
            rightPartPointer++;
            arrayInversionCount += middlePointer - (leftPartPointer + leftPointer) + 1;
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
    return arrayInversionCount;
}

lli mergeSort(int leftPointer, int rightPointer, int arr[]) {
    lli arrayInversionCount = 0;
    if (rightPointer > leftPointer) {
        int middlePointer = leftPointer + (rightPointer - leftPointer) / 2;
        arrayInversionCount += mergeSort(leftPointer, middlePointer, arr);
        arrayInversionCount += mergeSort(middlePointer + 1, rightPointer, arr);
        arrayInversionCount += mergeFunc(leftPointer, middlePointer, rightPointer, arr);
    }
    return arrayInversionCount;
}



int main()
{
    int inputArray[100000], n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inputArray[i];

    ///// printArray(inputArray, n);
    cout << mergeSort(0, n - 1, inputArray);
    ////printArray(inputArray, n);
}