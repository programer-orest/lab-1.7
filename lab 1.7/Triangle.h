#pragma once
#include "Angle.h"

class Triangle
{
	Angle A, B, C;
	double a, b, c;
public:
	void SetA(Angle A);
	void SetB(Angle B);
	void SetC(Angle C);

	void Set_a(double value);
	void Set_b(double value);
	void Set_c(double value);

	Angle GetA() const;
	Angle GetB() const;
	Angle GetC() const;

	double Get_a() const;
	double Get_b() const;
	double Get_c() const;

	void DisplayAngles();
	void DisplaySides();

	void InitAngles(Angle A, Angle B, Angle C);
	void InitSides(double a, double b, double c);
	void ReadSides();

	double Square() const;
	double Perimeter() const;
	double Altitude(int tmp) const;
	void TypeOFTriangle();
	void Equalizetriangle(int tmp);
};

