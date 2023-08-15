
#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, int left, int mid, int right);

void Sort(std::vector<int>& arr, int first_num, size_t lenght)
{
    int q = 0;
    if (first_num < lenght)
    {
        q = (first_num + lenght) / 2;
        Sort(arr, first_num, q);
        Sort(arr, q + 1, lenght);
        Merge(arr, first_num, q, lenght);
    }
}
void Merge(std::vector<int>& arr, int left, int mid, int right)
{
    int ArrayOne = mid - left + 1;
    int ArrayTwo = right - mid;

    std::vector<int> leftArray;
    std::vector<int> rightArray;

    leftArray.resize(ArrayOne);
    rightArray.resize(ArrayTwo);

    for (int i = 0; i < ArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < ArrayTwo; i++)
        rightArray[i] = arr[mid + 1 + i];
    
    int ArrayOneIndex = 0, ArrayTwoIndex = 0;
    int MergeArrayIndex = left;

    while (ArrayOneIndex < ArrayOne && ArrayTwoIndex < ArrayTwo)
    {
        if (leftArray[ArrayOneIndex] <= rightArray[ArrayTwoIndex])
        {
            arr[MergeArrayIndex] = leftArray[ArrayOneIndex];
            ArrayOneIndex++;
        }
        else
        {
            arr[MergeArrayIndex] = rightArray[ArrayTwoIndex];
            ArrayTwoIndex++;
        }
        MergeArrayIndex++;
    }

    while (ArrayOneIndex < ArrayOne)
    {
        arr[MergeArrayIndex] = leftArray[ArrayOneIndex];
        ArrayOneIndex++;
        MergeArrayIndex++;
    }

    while (ArrayTwoIndex < ArrayTwo)
    {
        arr[MergeArrayIndex] = rightArray[ArrayTwoIndex];
        ArrayTwoIndex++;
        MergeArrayIndex++;
    }
    
}


int main()
{
    std::vector<int> arr = { 5,2,4,6,1,3,2,6 };
    Sort(arr, 0, arr.size()-1);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

