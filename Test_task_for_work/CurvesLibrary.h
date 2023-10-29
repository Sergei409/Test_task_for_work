#pragma once
#include <iostream>

//����� ��� ������ � ������� � ������������ ��� ��������� � ������������
class Vec3 {
public:
	//������������
	Vec3() :xyz{ 0.0, 0.0, 0.0 } {}
	Vec3(double _x, double _y, double _z) :xyz{ _x, _y, _z } {}
	Vec3(const Vec3& p) :xyz{ p.x, p.y, p.z } {}

	//���������� ��������� �����������
	void operator=(const Vec3& p);

	double xyz[3];
	const double& x = xyz[0];
	const double& y = xyz[1];
	const double& z = xyz[2];

};

//���������� ��������� ��� ������ � �����
std::ostream& operator << (std::ostream& os, const Vec3& vec);

//����������� ����� ������
class Curve {
protected:
	//������� ������ ������
	Vec3 center;
public:
	//������������
	Curve() {}
	Curve(const Vec3& _center) : center(_center) {}

	//���������� ������ ������������� ����� ������
	Vec3 getCenter();

	//������ ����������� �������
	virtual	Vec3 getPoint(const double& t) = 0;
	virtual Vec3 getFirstDerivative(const double& t) = 0;
};

//����� ������, ����������� �� ������������ ������ ������
class Circle : public Curve {
public:
	//�����������
	Circle(const Vec3& _center, const double& _radii) :
		Curve(_center), radii(_radii) {}

	//���������� ������� ������������ �����, ������ ����������� � ������� ����������
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii();

private:
	//������ ����������
	double radii;
};

//����� ��������, ����������� �� ������������ ������ ������
class Ellipse : public Curve {
public:
	//�����������
	Ellipse(const Vec3& _center, const double& _radii_a, const double& _radii_b) :
		Curve(_center), radii_a(_radii_a), radii_b(_radii_b) {}

	//���������� ������� ������������ �����, ������ ����������� � �������� �������
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii_a();
	double getRadii_b();

private:
	//������� �������
	double radii_a, radii_b;
};

//����� ��������, ����������� �� ������������ ������ ������
class Helix : public Curve {
public:
	//�����������
	Helix(const Vec3& _center, const double& _radii, const double& _step) :
		Curve(_center), radii(_radii), step(_step) {}

	//���������� ������� ������������ �����, ������ �����������, ������� ������� � ����
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii();
	double getStep();

private:
	//������ ������� � ���
	double radii;
	double step;
};

