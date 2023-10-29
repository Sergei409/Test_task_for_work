#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <memory>
#include <typeinfo>
#include <math.h>
#include "CurvesLibrary.h"
//#include <omp.h>

//�������
constexpr double eps = 1e-6;

//������� ��������� ������ �������� ������ ������ � ��������� ������� �
// �� ���������� ����������
void random_machine(std::vector<std::shared_ptr<Curve>>& vec, int count) {

	srand(time(0));

	enum Curve_shape { circle_s, ellipse_s, helix_s };
	int shape = 0;
	Vec3 center;

	// ��������� ��������� ������������ �����
	std::uniform_real_distribution<double> distr_for_center(-10.0, 10.0);
	// ��������� ��������� ������������� ������������ �����
	std::uniform_real_distribution<double> pos_unif(eps, 10.0);

	std::default_random_engine re;

	for (int i = 0; i < count; i++) {

		shape = rand() % 3;

		switch (shape)
		{
		case circle_s:
			center = { distr_for_center(re), distr_for_center(re), 0.0 };
			vec.emplace_back(std::make_shared<Circle>(center, pos_unif(re)));
		case ellipse_s:
			center = { distr_for_center(re), distr_for_center(re), 0.0 };
			vec.emplace_back(std::make_shared<Ellipse>(center, pos_unif(re), pos_unif(re)));
		case helix_s:
			center = { distr_for_center(re), distr_for_center(re), distr_for_center(re) };
			vec.emplace_back(std::make_shared<Helix>(center, pos_unif(re), pos_unif(re)));
		default:
			break;
		};
	}
}

int main() {
	int count = 10;
	const double t = M_PI / 4;
	double totalSum = 0.0;

	//������ ���������� �� ������� �������� ������
	std::vector<std::shared_ptr<Curve>> curve_vector;

	//������ ���������� �� ������� ������ �����������
	std::vector<std::shared_ptr<Circle>> circle_vector;

	random_machine(curve_vector, count);

	//#pragma omp parallel for reduction(+:totalSum) 
	for (const auto& curve : curve_vector) {

		//������� ��� �������, ����� ������ � ������ ������ �����������, 
		// �������� ���������� 
		std::cout << "Object of " << typeid(*curve).name() << '\n' <<
			"3D point: " << curve->getPoint(t) << '\n' <<
			"3D vector of first derivative" << curve->getFirstDerivative(t) <<
			std::endl;

		//�������� ��������� �� ����������
		if (typeid(*curve).hash_code() == typeid(Circle).hash_code()) {

			//���������� ������� ��������� �� ���������� 
			// ������� �������� �������� ������ ������
			circle_vector.emplace_back(std::dynamic_pointer_cast<Circle>(curve));

			totalSum += circle_vector.back()->getRadii();
		}
	}
	//���������� �� �������
	std::sort(circle_vector.begin(), circle_vector.end(), [](const auto& a, const auto& b) {
		return (a->getRadii() < b->getRadii());
		});


	//����� �������� ���������������� ������� �����������
	std::cout << "=================================" << std::endl;
	for (const auto& _Circle : circle_vector) {
		std::cout << _Circle->getRadii() << std::endl;
	}

	//����� ����� �������� �����������
	std::cout << "=================================" << std::endl;
	std::cout << "Total sum: " << totalSum << std::endl;

	return 0;
}