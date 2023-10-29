#pragma once
#include <iostream>

//Класс для работы с точками в пространстве или вектарами в пространстве
class Vec3 {
public:
	//Конструкторы
	Vec3() :xyz{ 0.0, 0.0, 0.0 } {}
	Vec3(double _x, double _y, double _z) :xyz{ _x, _y, _z } {}
	Vec3(const Vec3& p) :xyz{ p.x, p.y, p.z } {}

	//Объявление оператора копирования
	void operator=(const Vec3& p);

	double xyz[3];
	const double& x = xyz[0];
	const double& y = xyz[1];
	const double& z = xyz[2];

};

//Объявление оператора для вывода в поток
std::ostream& operator << (std::ostream& os, const Vec3& vec);

//Абстрактный класс кривых
class Curve {
protected:
	//Позиция центра фигуры
	Vec3 center;
public:
	//Конструкторы
	Curve() {}
	Curve(const Vec3& _center) : center(_center) {}

	//Объявление метода возвращающего центр фигуры
	Vec3 getCenter();

	//Чистые виртуальные функции
	virtual	Vec3 getPoint(const double& t) = 0;
	virtual Vec3 getFirstDerivative(const double& t) = 0;
};

//Класс кругов, производный от абстрактного класса кривых
class Circle : public Curve {
public:
	//Конструктор
	Circle(const Vec3& _center, const double& _radii) :
		Curve(_center), radii(_radii) {}

	//Объявление методов возвращающих точку, первую производную и радиуса окружности
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii();

private:
	//Радиус окружности
	double radii;
};

//Класс эллипсов, производный от абстрактного класса кривых
class Ellipse : public Curve {
public:
	//Конструктор
	Ellipse(const Vec3& _center, const double& _radii_a, const double& _radii_b) :
		Curve(_center), radii_a(_radii_a), radii_b(_radii_b) {}

	//Объявление методов возвращающих точку, первую производную и радиусов эллипса
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii_a();
	double getRadii_b();

private:
	//Радиусы эллипса
	double radii_a, radii_b;
};

//Класс спиралей, производный от абстрактного класса кривых
class Helix : public Curve {
public:
	//Конструктор
	Helix(const Vec3& _center, const double& _radii, const double& _step) :
		Curve(_center), radii(_radii), step(_step) {}

	//Объявление методов возвращающих точку, первую производную, радиуса спирали и шага
	Vec3 getPoint(const double& t) override;
	Vec3 getFirstDerivative(const double& t) override;
	double getRadii();
	double getStep();

private:
	//Радиус спирали и шаг
	double radii;
	double step;
};

