#include <iostream>
#include <thread>
using namespace std;

template <typename T>
void printArray(T arr[], int size)
{
    for_each(arr, arr + size, [](const T &element)
             { cout << element << " "; });
    cout << endl;
}

template <typename T>
void merge(T arr[], int l, int m, int r)
{
    const int size_left = m - l + 1;
    const int size_right = r - m;

    T left_tab[size_left];
    T right_tab[size_right];

    for (int i = 0; i < size_left; ++i)
        left_tab[i] = arr[l + i];
    for (int j = 0; j < size_right; ++j)
        right_tab[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < size_left && j < size_right)
    {
        if (left_tab[i] <= right_tab[j])
        {
            arr[k] = left_tab[i];
            ++i;
        }
        else
        {
            arr[k] = right_tab[j];
            ++j;
        }
        ++k;
    }

    while (i < size_left)
    {
        arr[k] = left_tab[i];
        ++i;
        ++k;
    }

    while (j < size_right)
    {
        arr[k] = right_tab[j];
        ++j;
        ++k;
    }
}

template <typename T>
void merge_sort(T arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        std::thread thread1(merge_sort<T>, arr, l, m);
        std::thread thread2(merge_sort<T>, arr, m + 1, r);

        thread1.join();
        thread2.join();

        merge<T>(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 1, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printArray(arr, arr_size);

    return 0;
}