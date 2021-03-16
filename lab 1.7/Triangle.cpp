#include "Triangle.h"

void Triangle::SetA(Angle A)
{
	this->A.Angle::SetGrades(A.GetGrades());
	this->A.Angle::SetMinutes(A.GetMinutes());
}
void Triangle::SetB(Angle B)
{
	this->B.Angle::SetGrades(B.GetGrades());
	this->B.Angle::SetMinutes(B.GetMinutes());
}
void Triangle::SetC(Angle C)
{
	this->C.Angle::SetGrades(C.GetGrades());
	this->C.Angle::SetMinutes(C.GetMinutes());
}

void Triangle::Set_a(double value) { a = value; }
void Triangle::Set_b(double value) { b = value; }
void Triangle::Set_c(double value) { c = value; }

Angle Triangle::GetA() const { return A; }
Angle Triangle::GetB() const { return B; }
Angle Triangle::GetC() const { return C; }

double Triangle::Get_a() const { return a; }
double Triangle::Get_b() const { return b; }
double Triangle::Get_c() const { return c; }

void Triangle::DisplayAngles()
{
	cout << "\nAngle A" << endl;
	A.Display();
	cout << "\nAngle B" << endl;
	B.Display();
	cout << "\nAngle C" << endl;
	C.Display();
}
void Triangle::DisplaySides()
{
	cout << "\na = " << Get_a() << endl;
	cout << "\nb = " << Get_b() << endl;
	cout << "\nc = " << Get_c() << endl;
}

void Triangle::InitAngles(Angle A, Angle B, Angle C)
{
	SetA(A);
	SetB(B);
	SetC(C);
}
void Triangle::InitSides(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Triangle::ReadSides()
{
	cout << "\na = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
}

double Triangle::Square() const
{
	double p = Perimeter() / 2.;
	return sqrt(p * (p - Get_a()) * (p - Get_b()) * (p - Get_c()));
}
double Triangle::Perimeter() const { return Get_a() + Get_b() + Get_c(); }
double Triangle::Altitude(int tmp) const
{
	switch (tmp)
	{
	case 1:
		return (2 * Square()) / (Get_a() * 1.);
	case 2:
		return (2 * Square()) / (Get_b() * 1.);
	case 3:
		return (2 * Square()) / (Get_c() * 1.);
	}
}
void Triangle::TypeOFTriangle()
{
	if ((Get_a() == Get_b()) && (Get_b() == Get_c()))
		cout << "Equilateral triangle" << endl; //рівносторонній
	else if ((Get_a() == Get_b() && Get_a() != Get_c()) ||
		(Get_a() == Get_c() && Get_a() != Get_b()) ||
		(Get_c() == Get_b() && Get_c() != Get_a()))
		cout << "Isosceles triangle" << endl;//рівнобедрений
	else if (A.to360() == 90 || B.to360() == 90 || C.to360() == 90)
		cout << "Rectangular triangle" << endl;//прямокутний
	else if (A.to360() > 90 || B.to360() > 90 || C.to360() > 90)
		cout << "Obtuse triangle" << endl;// тупокутний 
	else if (A.to360() < 90 && B.to360() < 90 && C.to360() < 90)
		cout << "Oxygon" << endl;// гострокутний
}

void Triangle::Equalizetriangle(int tmp)
{
	switch (tmp)
	{
	case 1:
		Set_b((Get_a() * B.getSin()) / (A.getSin() * 1.));
		Set_c((Get_a() * C.getSin()) / (A.getSin() * 1.));
		break;
	case 2:
		Set_a((Get_b() * A.getSin()) / (B.getSin() * 1.));
		Set_c((Get_b() * C.getSin()) / (B.getSin() * 1.));
		break;
	case 3:
		Set_a((Get_c() * A.getSin()) / (C.getSin() * 1.));
		Set_b((Get_c() * B.getSin()) / (C.getSin() * 1.));
		break;
	}
}
