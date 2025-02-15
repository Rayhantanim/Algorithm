#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int st, int end)
{
    int i = st - 1;
    int pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
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
    if (st < end)
    {
        int pi = partition(arr, st, end);
        quicksort(arr, st, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

int main()
{
    int arr[] = {4, 3, 7, 1, 2, 8, 5, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array:" << endl;
    for (int a : arr)
    {
        cout << a << "  ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted Array:" << endl;
    for (int a : arr)
    {
        cout << a << "  ";
    }
    getchar();
    return 0;
}
