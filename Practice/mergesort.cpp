#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int merge(int arr[], int st, int mid, int end)
{
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
    {
        arr[k + st] = temp[k];
    }
}

int mergesort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {4, 10, 2, 45, 13, 5, 7, 14, 36, 56, 25, 20, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n-1);
    for(int i : arr)
    {
        cout << i << "  ";
    }
    return 0;
}