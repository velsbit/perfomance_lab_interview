// Задание 1
// Круговой массив - массив из элементов, в котором по достижению конца массива
// следующим элементом будет снова первый.Массив задается числом n, то есть
// представляет собой числа от 1 до n.
// Пример кругового массива для n = 3:

#include <iostream>

int main() {
    int n, m;
    int* arr;

    // Ввод данных
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "arr = ";

    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        std::cout << arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}