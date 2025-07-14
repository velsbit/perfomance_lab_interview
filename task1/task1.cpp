// Задание 1
// Круговой массив - массив из элементов, в котором по достижению конца массива
// следующим элементом будет снова первый.Массив задается числом n, то есть
// представляет собой числа от 1 до n.
// Пример кругового массива для n = 3:

#include <iostream>

int main() {
    int n, m;
    int* arr;
    int* circ_arr;

    // Ввод данных
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter m: ";
    std::cin >> m;
    if (n <= 0 || m <= 0) {
        std::cerr << "[ERROR] n and m must be positive." << std::endl;
        return 1;
    }

    // Заполнение массивов
    std::cout << "arr = ";
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    // foo
    // {
    int i = 0;
    do {
        for (int j = 0; j < m; j++) {
            std::cout << arr[(i + j) % n] << ' ';
        }
        std::cout << std::endl;
        i = (i + m - 1) % n;
    } while (i != 0);
    // }

    // Освобождение памяти
    delete[] arr;

    return 0;
}