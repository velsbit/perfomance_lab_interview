// Задание 2
// Напишите программу, которая рассчитывает положение точки относительно окружности.
// Координаты центра окружности и его радиус считываются из файла 1
// Координаты точек считываются из файла 2

// Здесь я решил задачу применив навыки ООП, так как посчитал это более интересным методом решения подобного рода задач.

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

class Circle {
private:
    double x, y, r;

public:
    Circle(double cx, double cy, double radius) : x(cx), y(cy), r(radius) {}

    // Определение положения точки относительно окружности.
    int checkPoint(double px, double py) const;
};

int Circle::checkPoint(double px, double py) const {
    double dx = px - x;
    double dy = py - y;
    double dist_sq = dx * dx + dy * dy;
    double r_sq = r * r;

    if (std::abs(dist_sq - r_sq) == 0)
        return 0; // на окружности
    else if (dist_sq < r_sq)
        return 1; // внутри
    else
        return 2; // снаружи
};

int main() {
    std::ifstream circle_file("circle.txt");
    std::ifstream points_file("points.txt");

    if (!circle_file || !points_file) {
        std::cerr << "Failed to open input files." << std::endl;
        return 1;
    }

    double cx, cy, radius;
    circle_file >> cx >> cy >> radius;

    Circle circle(cx, cy, radius);

    double px, py;
    while (points_file >> px >> py) {
        double result = circle.checkPoint(px, py);
        std::cout << result << std::endl;
    }

    return 0;
}