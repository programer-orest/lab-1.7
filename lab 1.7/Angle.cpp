#include "Angle.h"

void Angle::SetGrades(double grades) { this->grades = grades; }
void Angle::SetMinutes(double minutes) { this->minutes = minutes; }

double Angle::GetGrades() const { return grades; }
double Angle::GetMinutes() const { return minutes; }

void Angle::Init(double grades, double minutes)
{
	this->grades = grades;
	this->minutes = minutes;
}
void Angle::Read()
{
	cout << "\nGrades = "; cin >> grades;
	cout << "Minutes = "; cin >> minutes;
}
void Angle::Display()
{
	cout << "\nGrades = " << GetGrades() << endl;
	cout << "Minutes = " << GetMinutes() << endl;
}
string Angle::toString() const
{
	stringstream sout;

	sout << "\nGrades = " << GetGrades() << endl;
	sout << "Minutes = " << GetMinutes() << endl;

	return sout.str();
}

double Angle::to360() const { return GetGrades() + GetMinutes() / 60.; }
double Angle::toRadian()const { return (to360() * 3.141592) / 180.; }
void Angle::Increase(Angle X, Angle& A, Angle& B, Angle& C, int tmp)
{
	switch (tmp)
	{
	case 1:
		A.grades = (A.GetGrades() + X.GetGrades());
		A.minutes = (A.GetMinutes() + X.GetMinutes());
		B.grades = (B.GetGrades() - X.GetGrades() / 2.);
		B.minutes = (B.GetMinutes() - X.GetMinutes() / 2.);
		C.grades = (C.GetGrades() - X.GetGrades() / 2.);
		C.minutes = (C.GetMinutes() - X.GetMinutes() / 2.);
		break;
	case 2:
		B.grades = (B.GetGrades() + X.GetGrades());
		B.minutes = (B.GetMinutes() + X.GetMinutes());
		A.grades = (A.GetGrades() - X.GetGrades() / 2.);
		A.minutes = (A.GetMinutes() - X.GetMinutes() / 2.);
		C.grades = (C.GetGrades() - X.GetGrades() / 2.);
		C.minutes = (C.GetMinutes() - X.GetMinutes() / 2.);
		break;
	case 3:
		C.grades = (C.GetGrades() + X.GetGrades());
		C.minutes = (C.GetMinutes() + X.GetMinutes());
		B.grades = (B.GetGrades() - X.GetGrades() / 2.);
		B.minutes = (B.GetMinutes() - X.GetMinutes() / 2);
		A.grades = (A.GetGrades() - X.GetGrades() / 2.);
		A.minutes = (A.GetMinutes() - X.GetMinutes() / 2.);
		break;
	}
}
void Angle::Decrease(Angle X, Angle& A, Angle& B, Angle& C, int tmp)
{
	Angle minus;
	minus.SetGrades(-1 * X.GetGrades());
	minus.SetMinutes(-1 * X.GetMinutes());
	minus.Increase(minus, A, B, C, tmp);
}
double Angle::getSin() const { return sin(toRadian() * 1.); }
void Angle::Comparison(Angle A, Angle B)
{
	if (A.to360() > B.to360())
		cout << "The largest angle = " << A.to360() << endl;
	else if (A.to360() == B.to360())
		cout << "Angles are equal" << endl;
	else
		cout << "The largest angle = " << B.to360() << endl;
}
void Angle::Comparison(Angle A, Angle B, Angle C)
{
	double arr[3] = { A.to360(), B.to360(), C.to360() };
	double max = arr[0];

	if ((A.to360() == B.to360()) && (B.to360() == C.to360()))
		cout << "Angles are equal" << endl;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		cout << "The largest angle = " << max << endl;
	}
}

