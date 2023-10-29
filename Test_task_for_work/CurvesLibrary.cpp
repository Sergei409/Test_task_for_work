#include "CurvesLibrary.h"

//Определение оператора копирования 
void Vec3::operator=(const Vec3& p) {
	xyz[0] = p.x;
	xyz[1] = p.y;
	xyz[2] = p.z;
}

//Определение оператора для вывода в поток
std::ostream& operator << (std::ostream& os, const Vec3& vec) {
	return os << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
}

//Определение метода возвращающего центр фигуры
Vec3 Curve::getCenter() {
	return center;
}

//Определение метода возвращающего точку окружности по параметру t
Vec3 Circle::getPoint(const double& t) {
	Vec3 point(center.x + radii * cos(t), center.y + radii * sin(t), center.z);
	return point;
}

//Определение метода возвращающего первую производную окружности по параметру t
Vec3 Circle::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii * sin(t), radii * cos(t), 0.0);
	return derivative;
}

//Определение метода возвращающего радиус окружности
double Circle::getRadii() {
	return radii;
}

//Определение метода возвращающего точку эллипса по параметру t
Vec3 Ellipse::getPoint(const double& t) {
	Vec3 point(center.x + radii_a * cos(t), center.y + radii_b * sin(t), center.z);
	return point;
}

//Определение метода возвращающего первую производную эллипса по параметру t
Vec3 Ellipse::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii_a * sin(t), radii_b * cos(t), 0.0);
	return derivative;
}

//Определение метода возвращающего радиус a эллипса
double Ellipse::getRadii_a() {
	return radii_a;
}

//Определение метода возвращающего радиус b эллипса
double Ellipse::getRadii_b() {
	return radii_b;
}

//Определение метода возвращающего точку спирали по параметру t
Vec3 Helix::getPoint(const double& t) {
	Vec3 point(center.x + radii * cos(t), center.y + radii * sin(t), center.z + step * t);
	return point;
}

//Определение метода возвращающего первую производную спирали по параметру t
Vec3 Helix::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii * sin(t), radii * cos(t), step);
	return derivative;
}

//Определение метода возвращающего радиус спирали
double Helix::getRadii() {
	return radii;
}

//Определение метода возвращающего шаг спирали
double Helix::getStep() {
	return step;
}