#include <iostream>
#include <functional>

enum type {less, greater};

template <typename T, type e>
void SortInsert(T arr[], int n){
    int passages = 0;
    std::function<bool(T, T)> predicate;

    switch (e) {    //SwitchGreateLess
        case greater:
            predicate = [](T x, T y) {return x > y ? true:false; };
        break;
        case less: 
            predicate = [](T x, T y) {return x < y ? true : false; };
        break;
    }

    for (int j = 1; j < n; j++) {   //SortingAlgorithm
        T key = arr[j];
        int i = j - 1;
        while (i >= 0 && predicate(arr[i], key)) {
            passages++;
            arr[i + 1] = arr[i];
            i--;
        }
        arr[++i] = key;
        passages++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "(" << passages << ")" << std::endl;
}

int main()
{
    {
        int arr[] = { 41,58,32,64,85,73,20 };
        SortInsert<int, greater>(arr, 7);
    }
    {
        int arr[] = { 35,58,32,45,85,73,827 };
        SortInsert<int, greater>(arr, 7);
    }
    {
        int arr[] = { 41,58,32,64,85,73,20 };
        SortInsert<int, less>(arr, 7);
    }
    {
        int arr[] = { 35,58,32,45,85,73,827 };
        SortInsert<int, less>(arr, 7);
    }
}

