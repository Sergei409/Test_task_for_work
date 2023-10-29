#include "CurvesLibrary.h"

//����������� ��������� ����������� 
void Vec3::operator=(const Vec3& p) {
	xyz[0] = p.x;
	xyz[1] = p.y;
	xyz[2] = p.z;
}

//����������� ��������� ��� ������ � �����
std::ostream& operator << (std::ostream& os, const Vec3& vec) {
	return os << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
}

//����������� ������ ������������� ����� ������
Vec3 Curve::getCenter() {
	return center;
}

//����������� ������ ������������� ����� ���������� �� ��������� t
Vec3 Circle::getPoint(const double& t) {
	Vec3 point(center.x + radii * cos(t), center.y + radii * sin(t), center.z);
	return point;
}

//����������� ������ ������������� ������ ����������� ���������� �� ��������� t
Vec3 Circle::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii * sin(t), radii * cos(t), 0.0);
	return derivative;
}

//����������� ������ ������������� ������ ����������
double Circle::getRadii() {
	return radii;
}

//����������� ������ ������������� ����� ������� �� ��������� t
Vec3 Ellipse::getPoint(const double& t) {
	Vec3 point(center.x + radii_a * cos(t), center.y + radii_b * sin(t), center.z);
	return point;
}

//����������� ������ ������������� ������ ����������� ������� �� ��������� t
Vec3 Ellipse::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii_a * sin(t), radii_b * cos(t), 0.0);
	return derivative;
}

//����������� ������ ������������� ������ a �������
double Ellipse::getRadii_a() {
	return radii_a;
}

//����������� ������ ������������� ������ b �������
double Ellipse::getRadii_b() {
	return radii_b;
}

//����������� ������ ������������� ����� ������� �� ��������� t
Vec3 Helix::getPoint(const double& t) {
	Vec3 point(center.x + radii * cos(t), center.y + radii * sin(t), center.z + step * t);
	return point;
}

//����������� ������ ������������� ������ ����������� ������� �� ��������� t
Vec3 Helix::getFirstDerivative(const double& t) {
	Vec3 derivative(-1 * radii * sin(t), radii * cos(t), step);
	return derivative;
}

//����������� ������ ������������� ������ �������
double Helix::getRadii() {
	return radii;
}

//����������� ������ ������������� ��� �������
double Helix::getStep() {
	return step;
}