#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
    int i = st-1;
    int pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[end], arr[i]);
    return i;
}
void quicksort(int arr[], int st, int end)
{
    if(st < end){
        int pidx = partition(arr, st, end);
        quicksort(arr, st, pidx-1);
        quicksort(arr, pidx+1, end);
    }
}
int main()
{
    int arr[] = {5,4,8,10,2,45,7,14,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0 , n-1);
    for( int i : arr){
        cout << i << " ";
    }

    return 0;
}