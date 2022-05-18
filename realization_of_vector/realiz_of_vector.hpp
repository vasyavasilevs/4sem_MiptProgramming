#pragma once
#include <iostream>
#include <math.h>

// realization_of_vector.cpp
// 
//����������� ����� Vector2 �� ���������� ��������:
//�
//operator <<, >> (���������� ����� � ������)   
//�
//Vector2 operator+(const Vector2& other) const;
//�
//Vector2& operator+=(const Vector2& other);
//�
//���������� - � -=
//�
//float operator*(const Vector2 & other) const; (��������� ������������)
//�
//float operator^(const Vector2& other) const; (��������� ������������)
//�
//* �� ������ � �2� ���� ������
//�
/// �� ������
//�
//��������� ������ norm()
//�
//�������������(y, -x)
//�
//len(), squareLen()
//�
//������� ����� Vector2 operator-() const
//�
//������������
//�
//������� �� ���� 2��.: rotate � getRotated(������ ������ ����, ������ �
//    ���������� ����� �������� � �� �������� � += � + )
//    ������ ������� ����� ��������� : � main�� ������� ������ ���� �� �� ����.

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




