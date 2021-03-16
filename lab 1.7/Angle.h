#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Angle
{
	double grades, minutes;
public:
	void SetGrades(double grades);
	void SetMinutes(double minutes);

	double GetGrades() const;
	double GetMinutes() const;

	void Init(double grades, double minutes);
	void Read();
	void Display();

	string toString() const;

	double to360() const;
	double toRadian() const;
	void Increase(Angle X, Angle& A, Angle& B, Angle& C, int tmp);
	void Decrease(Angle X, Angle& A, Angle& B, Angle& C, int tmp);
	double getSin() const;
	void Comparison(Angle A, Angle B);
	void Comparison(Angle A, Angle B, Angle C);
};

