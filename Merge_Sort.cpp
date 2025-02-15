#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int st, int end, int mid)
{
    vector<int> temp;
    int i = st, j = mid + 1;
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
    for(int k = 0; k < temp.size(); k++)
    {
        arr[k+st] = temp[k];
    }
    
}
void mergesort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, end, mid);
    }
}
int main()
{
    vector<int> arr = {2, 5, 6, 34, 8, 10, 13, 23, 1, 9, -4};

    cout << "Unsorted Array: " << endl;
    for(int i : arr)
    {
        cout << i << "\t";
    }
    mergesort(arr, 0, arr.size()-1);
    cout << "\nSorted Array: " << endl;
    for(int i : arr)
    {
        cout << i << "\t";
    }
    getchar();
    return 0;
}