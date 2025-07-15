// Задание 3
// На вход в качестве аргументов программы поступают три пути к файлу:
// - values.json содержит результаты прохождения тестов с уникальными id
// - tests.json содержит структуру для построения отчета (вложенность может быть любой)
// - report.json - сюда записывается результат.
// Программа формирует report.json с заполненными полями value из values.json.

// Файл json.hpp скачан с https://github.com/nlohmann/json/releases/tag/v3.12.0

#include <fstream>
#include <iostream>
#include "json.hpp"
#include <unordered_map>

using json = nlohmann::json;

// Рекурсивно заполняем "value" из мапы
void fill_values(json& item, const std::unordered_map<int, std::string>& values_map) {
    if (item.contains("id")) {
        int id = item["id"];
        auto it = values_map.find(id);
        if (it != values_map.end()) {
            item["value"] = it->second;
        }
    }

    if (item.contains("values")) {
        for (auto& sub : item["values"]) {
            fill_values(sub, values_map);
        }
    }
}

int main(int argc, char* argv[]) {
    // Проверяем, что переданы пути к файлам
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " values.json tests.json report.json\n";
        return 1;
    }

    // Чтение values.json
    std::ifstream values_file(argv[1]);
    if (!values_file) {
        std::cerr << "Failed to open " << argv[1] << "\n";
        return 1;
    }
    json values_json;
    values_file >> values_json;
    values_file.close();

    // Чтение tests.json
    std::ifstream tests_file(argv[2]);
    if (!tests_file) {
        std::cerr << "Failed to open " << argv[2] << "\n";
        return 1;
    }
    json tests_json;
    tests_file >> tests_json;
    tests_file.close();

    // Построение map { id : value }
    std::unordered_map<int, std::string> values_map;
    for (const auto& entry : values_json["values"]) {
        values_map[entry["id"]] = entry["value"];
    }

    // Заполняем значения в массиве тестов
    if (tests_json.contains("tests")) {
        for (auto& test : tests_json["tests"]) {
            fill_values(test, values_map);
        }
    }

    // Сохранение результата в report.json
    std::ofstream out(argv[3]);
    if (!out) {
        std::cerr << "Failed to write " << argv[3] << "\n";
        return 1;
    }
    out << tests_json.dump(2) << std::endl;
    out.close();

    std::cout << "report.json creation success.\n";
    return 0;
}