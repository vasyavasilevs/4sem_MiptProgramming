#pragma once
#include <iostream>
#include <math.h>

// realization_of_vector.cpp
// 
//–еализовать класс Vector2 со следующими методами:
//Х
//operator <<, >> (перегрузка ввода и вывода)   
//Х
//Vector2 operator+(const Vector2& other) const;
//Х
//Vector2& operator+=(const Vector2& other);
//Х
//аналогично - и -=
//Х
//float operator*(const Vector2 & other) const; (скал€рное произведение)
//Х
//float operator^(const Vector2& other) const; (векторное произведение)
//Х
//* на скал€р с Ђ2х двух сторонї
//Х
/// на скал€р
//Х
//единичный вектор norm()
//Х
//перпендикул€р(y, -x)
//Х
//len(), squareLen()
//Х
//унарный минус Vector2 operator-() const
//Х
//конструкторы
//Х
//поворот на угол 2шт.: rotate и getRotated(первый мен€ет себ€, второй Ц
//    возвращает новое значение Е по аналогии с += и + )
//    –аботу методов нужно проверить : в mainТе вызвать каждый хот€ бы по разу.

//class of vector realization
class realiz_of_vector
{
	double x = 0, y = 0;
	public:
	//constructors of the class
	realiz_of_vector() = default;//constructor without parameters
	realiz_of_vector(double x, double y); //constructor with param

	//methods of the class
    friend std::ostream& operator<<(std::ostream& output, const realiz_of_vector& op);
    friend std::istream& operator>>(std::istream& input, realiz_of_vector& ip);
    realiz_of_vector operator+(const realiz_of_vector& other) const;
    realiz_of_vector operator-(const realiz_of_vector& other) const;
    realiz_of_vector operator+=(const realiz_of_vector& other);
    realiz_of_vector operator-=(const realiz_of_vector& other);
    float operator*(const realiz_of_vector& other) const;
    float operator^(const realiz_of_vector& other) const;
    realiz_of_vector operator*(const float c);
    friend realiz_of_vector operator*(const float c, const realiz_of_vector& other);
    realiz_of_vector norm() const;
    double len() const;
    realiz_of_vector perp() const;
    double squareLen() const;
    realiz_of_vector operator-() const;
    realiz_of_vector rotate(const float rad);
    realiz_of_vector getRotated(const float rad);

    //destructor
    ~realiz_of_vector() = default;
};




