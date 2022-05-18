#include <iostream>
#include "realiz_of_vector.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    realiz_of_vector vector(0, 0);
    realiz_of_vector other(1, 2);
    float scalar = 0;
    float zcomp = 0;
    std::cout << "Other = 1 2" << std::endl;
    std::cout << "Vector = ";
    std::cin >> vector;
    vector = vector + other;
    std::cout << "Vector + other: " << vector << std::endl;
    vector = vector - other;
    std::cout << "Vector - other: " << vector << std::endl;
    vector += other;
    std::cout << "Vector += other: " << vector << std::endl;
    vector -= other;
    std::cout << "Vector -= other: " << vector << std::endl;
    scalar = vector * other;
    std::cout << "Vector * other: " << scalar << std::endl;
    zcomp = vector ^ other;
    std::cout << "Vector ^ other (z-component): " << zcomp << std::endl;
    vector = 0.5 * vector * 2;
    std::cout << "0.5 * vector * 2 other: " << vector << std::endl;
    std::cout << "Lenght: " << vector.len() << std::endl;
    std::cout << "Norm: " << vector.norm() << std::endl;
    std::cout << "Perp: " << vector.perp() << std::endl;
    std::cout << "Square length: " << vector.squareLen() << std::endl;
    std::cout << "Unary m: " << -vector << std::endl;
    vector = -(-vector);
    std::cout << "Rotate (90deg): " << vector.rotate(90 * M_PI / 180) << std::endl;
    vector.rotate(-90 * M_PI / 180);
    std::cout << "Get rotated (90deg): " << vector.getRotated(90 * M_PI / 180) << std::endl;
    return 0;
}