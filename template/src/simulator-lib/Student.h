#pragma once
#include <string>
#include <iostream>
#include "bar-simulator.h"

enum Speciality {
	Fraud,
	InternationalSchemes,
	CreativeNihilism,
	SubjectiveResearches, 
	FileAnalizis,
	Micromanagement,
	AppliedMaterialization,
	Subjectivistics,
	MagnetismAndClearing,
	UNKNOWN
};

class Student {
public:
	Student();
	Student(int facultyNumber, int arrivalMinute, const std::string& speciality, int minutesStay);

	long int getFacultyNumber() const;
	int getArrivalMinute() const;
	Speciality getSpeciality() const;
	int getMinutesStay() const;
private:
	void setFacultyNumber(int facultyNumber);
	void setArrivalMinute(int arrivalMinute);
	void setSpeciality(const std::string& speciality);
	void setMinutesStay(int minutesInBar);
private:
	int facultyNumber;
	int arrivalMinute;
	Speciality speciality;
	int minutesStay;
};