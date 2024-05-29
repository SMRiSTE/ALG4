#include <iostream>


void print_pyramid(int* arr, int size) {
    int level = 0;
    int index = 0;
std::cout << "\n" << level << " root " << arr[0] << std::endl;
    while (index < size) {
        if (index == 0) {
            if(2 * index + 1 < size) {
                std::cout << (level + 1) << " left (" << arr[index] << ") " << arr[2 * index + 1] << std::endl;
            }

            if (2 * index + 2 < size) {
                std::cout << (level + 1) << " right (" << arr[index] << ") " << arr[2 * index + 2] << std::endl;
            }
            index++;
            level++;
        }
        else {
            if (2 * index + 1 < size) {
                std::cout << (level + 1) << " left (" << arr[index] << ") " << arr[2 * index + 1] << std::endl;
            }

            if (2 * index + 2 < size) {
                std::cout << (level + 1) << " right (" << arr[index] << ") " << arr[2 * index + 2] << std::endl;
            }

            index++;

            if (2 * index + 1 < size) {
                std::cout << (level + 1) << " left (" << arr[index] << ") " << arr[2 * index + 1] << std::endl;
            }

            if (2 * index + 2 < size) {
                std::cout << (level + 1) << " right (" << arr[index] << ") " << arr[2 * index + 2] << std::endl;
            }
            index++;
            level++;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    std::cout << "Исходный массив: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++) {
        std::cout << arr[i] << " ";
    }
    print_pyramid(arr, sizeof(arr) / sizeof(arr[1]));

}