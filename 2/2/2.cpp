#include <iostream>

void print_pyramid(int* arr, int size) {
    int level = 0;
    int index = 0;
    std::cout << "\n" << level << " root " << arr[0] << std::endl;
    while (index < size) {
        if (index == 0) {
            if (2 * index + 1 < size) {
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

void yourloc(int* arr, int size) {
    int level = 0;
    int index = 0;
    std::string befans;

    std::cout << "Вы находитесь здесь: " << level << " root " << arr[index] << std::endl;
    std::string ans;
    std::cout << "Введите команду: ";
    std::cin >> ans;
    befans = ans;

    while (true) {
        if (ans == "up") {
            if (level == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                std::cout << "Вы находитесь здесь: " << level << " root " << arr[index] << std::endl;
            }

            else {
                level--;

                index = (index - 1) / 2;
                if (index != 0) {
                    if (index % 2 == 0) {
                        std::cout << "Вы находитесь здесь: " << level << " " << " right" << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
                    }
                    else {
                        std::cout << "Вы находитесь здесь: " << level << " " << " left" << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
                    }
                }
                else {
                    std::cout << "Вы находитесь здесь: " << level << " root " << arr[index] << std::endl;
                }
            }
            
        }
        else if (ans == "left") {
            if (2 * index + 1 < size) {
                index = index * 2 + 1;
                level++;
                std::cout << "Вы находитесь здесь: " << level << " " << ans << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
                befans = ans;
            }

            else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
                std::cout << "Вы находитесь здесь: " << level << " " << befans << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
            }
        }
        else if (ans == "right") {
            if (2 * index + 2 < size) {
                index = index * 2 + 2;
                level++;
                std::cout << "Вы находитесь здесь: " << level << " " << ans << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
                befans = ans;
            }

            else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
                std::cout << "Вы находитесь здесь: " << level << " " << befans << "(" << arr[(index - 1) / 2] << ") " << " " << arr[index] << std::endl;
            }
        }
        else if (ans == "exit") {
            std::exit(0);
        }

        std::cout << "Введите команду: ";
        std::cin >> ans;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 1, 3, 6, 5, 9, 8 };
    std::cout << "Исходный массив: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++) {
        std::cout << arr[i] << " ";
    }
    print_pyramid(arr, sizeof(arr) / sizeof(arr[1]));
    yourloc(arr, sizeof(arr) / sizeof(arr[1]));
}