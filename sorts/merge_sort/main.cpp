#include <iostream>

using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];

    for (int i = 0; i < rightArraySize; i++)
        rightArray[i] = array[midIndex + 1 + i];

    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main()
{
    int array[] = {6, 4, 2, 5, 1, 3};
    int array2[] = {7, 9, 8, 10, 11, 13, 12};
    int array3[] = {14, 18, 22, 15, 17, 16};
    int size = sizeof(array) / sizeof(array[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);

    int leftIdx = 0;
    int rightIdx = size - 1;
    mergeSort(array, leftIdx, rightIdx);
    for (auto value : array)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto value : array2)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto value : array3)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}