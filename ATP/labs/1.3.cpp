#include <iostream>
#include <vector>

int binary_search(std::vector<int> &cursor, int key)
{
    int left = 0;
    int right = cursor.size() - 1;
    int result_left = -1, result_right;

    while (left <= right) {

        int middle = (left + right) / 2;

        if (cursor[middle] == key) {

            result_left = middle;
            right = middle - 1;
        }
        else if (cursor[middle] < key) {

            left = middle + 1;
        }
        else {

            right = middle - 1;
        }
    }

    if (result_left == -1) {
        std::cout<<"0"<<std::endl;
        return 0;
    }

    left = 0;
    right = cursor.size() - 1;

    while (left <= right) {

        int middle = (left + right) / 2;

        if (cursor[middle] == key) {

            result_right = middle;
            left = middle + 1;
        }
        else if (cursor[middle] < key) {

            left = middle + 1;
        }
        else {

            right = middle - 1;
        }
    }

    std::cout<< ++result_left<< std::endl;
    std::cout<< ++result_right<< std::endl;
    return 0;
}

int main(void)
{
    int arr_size, search_size;

    std::cin>>arr_size;
    std::cin>>search_size;

    std::vector<int> arr(arr_size);
    std::vector<int> search(search_size);

    for (int i = 0; i < arr.size(); i++){

        std::cin>>arr[i];
    }

    for (int i = 0; i < search.size(); i++) {

      std::cin>>search[i];
    }

    for (int i = 0; i < search.size(); i++){

        binary_search(arr, search[i]);
    }

    return 0;
}

