#include "realiz_of_vector.hpp"
#include <math.h>

realiz_of_vector::realiz_of_vector(double x = 0, double y = 0): x(x), y(y)
{}

//output operator overload
std::ostream& operator<<(std::ostream& output, const realiz_of_vector& op) {
	return output << op.x << " " << op.y << std::endl;
}

//input operator overload
std::istream& operator>>(std::istream& input, realiz_of_vector& ip) {
	return input >> ip.x >> ip.y;
}

//overload operator+
realiz_of_vector realiz_of_vector::operator+(const realiz_of_vector& other) const {
	realiz_of_vector res = 0;
	res.x = x + other.x;
	res.y = y + other.y;
	return res;
}

//overload operator-
realiz_of_vector realiz_of_vector::operator-(const realiz_of_vector& other) const {
	realiz_of_vector res = 0;
	res.x = x - other.x;
	res.y = y - other.y;
	return res;
}

//overload operator+=
realiz_of_vector realiz_of_vector::operator+=(const realiz_of_vector& other) {
	x += other.x;
	y += other.y;
	return *this;
}

//overload operator-=
realiz_of_vector realiz_of_vector::operator-=(const realiz_of_vector& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

//scalar product
float realiz_of_vector::operator*(const realiz_of_vector& other) const {
	return x * other.x + y * other.y;
}

//vector product (z - component)
float realiz_of_vector::operator^(const realiz_of_vector& other) const {
	return x * other.y - other.x * y;
}

//product of *scalar (both sides)
//left
realiz_of_vector realiz_of_vector::operator*(const float c) {
	realiz_of_vector res = 0;
	res.x = c * x;
	res.y = c * y;
	return res;
}
//right
realiz_of_vector operator*(const float c, const realiz_of_vector& other) {
	realiz_of_vector res = 0;
	res.x = other.x * c;
	res.y = other.y * c;
	return res;
}

//length
double realiz_of_vector::len() const {
	return sqrt(pow(x, 2) + pow(y, 2));
}

//norm
realiz_of_vector realiz_of_vector::norm() const {
	realiz_of_vector res = 0;
	res.x = x / len();
	res.y = y / len();
	return res;
}

//perp
realiz_of_vector realiz_of_vector::perp() const {
	realiz_of_vector res = 0;
	res.x = y;
	res.y = -x;
	return res;
}

//square of length
double realiz_of_vector::squareLen() const {
	return pow(x, 2) + pow(y, 2);
}

//unary minus
realiz_of_vector realiz_of_vector::operator-() const {
	realiz_of_vector res = 0;
	res.x = -x;
	res.y = -y;
	return res;
}

//rotate (clockwise)
realiz_of_vector realiz_of_vector::rotate(const float rad) {
	float x1 = x;
	float y1 = y;
	x = x1 * cos(rad) - y1 * sin(rad);
	y = x1 * sin(rad) + y1 * cos(rad);
	return *this;
}

//getRotated (clockwise)
realiz_of_vector realiz_of_vector::getRotated(const float rad) {
	return realiz_of_vector(x, y).rotate(rad);
}





