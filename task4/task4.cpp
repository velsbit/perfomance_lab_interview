// Задание 4
// Программа читает массив чисел из файла, переданного через аргумент командной строки,
// и вычисляет минимальное количество ходов, чтобы привести все элементы к одному числу.
// За один ход можно увеличить или уменьшить число на 1.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input.txt\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Failed to open " << argv[1] << "\n";
        return 1;
    }

    std::vector<int> nums;
    int num;
    while (in >> num) {
        nums.push_back(num);
    }
    in.close();

    if (nums.empty()) {
        std::cout << "0\n";
        return 0;
    }

    // Сортируем массив, чтобы найти медиану
    std::sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];

    // Считаем минимальное количество ходов
    int moves = 0;
    for (const auto& n : nums) {
        moves += std::abs(n - median);
    }

    std::cout << moves << "\n";
    return 0;
}