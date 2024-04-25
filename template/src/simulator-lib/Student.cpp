#include "Student.h"

Student::Student() : facultyNumber(-1), arrivalMinute(-1), minutesStay(-1), speciality(Speciality::UNKNOWN)
{

}

Student::Student(int FN, int minute, const std::string& speciality, int minutesInBar)
{
	setFacultyNumber(FN);
	setArrivalMinute(minute);
	setSpeciality(speciality);
	setMinutesStay(minutesInBar);
}

long int Student::getFacultyNumber() const
{
	return facultyNumber;
}

int Student::getArrivalMinute() const
{
	return arrivalMinute;
}

Speciality Student::getSpeciality() const
{
	return speciality;
}

int Student::getMinutesStay() const
{
	return minutesStay;
}

void Student::setFacultyNumber(int facultyNumber)
{
	if (facultyNumber < 0 || facultyNumber > 999'999'999) {
		throw incorrect_simulation("FN is incorrect");
	}
	this->facultyNumber = facultyNumber;
}

void Student::setArrivalMinute(int arrivalMinute)
{
	if (arrivalMinute < 0) {
		throw incorrect_simulation("Minute is incorrect");
	}
	this->arrivalMinute = arrivalMinute;
}

void Student::setSpeciality(const std::string& speciality)
{
	if (speciality == "Fraud") {
		this->speciality = Speciality::Fraud;
	}
	else if (speciality == "International Schemes")
	{
		this->speciality = Speciality::InternationalSchemes;
	}
	else if (speciality == "Creative Nihilism")
	{
		this->speciality = Speciality::CreativeNihilism;
	}
	else if (speciality == "Subjective Researches")
	{
		this->speciality = Speciality::SubjectiveResearches;
	}
	else if (speciality == "File Analizis")
	{
		this->speciality = Speciality::FileAnalizis;
	}
	else if (speciality == "Micromanagement")
	{
		this->speciality = Speciality::Micromanagement;
	}
	else if (speciality == "Applied Materialization")
	{
		this->speciality = Speciality::AppliedMaterialization;
	}
	else if (speciality == "Subjectivistics")
	{
		this->speciality = Speciality::Subjectivistics;
	}
	else if (speciality == "Magnetism and Clearing")
	{
		this->speciality = Speciality::MagnetismAndClearing;
	}
	else {
		throw incorrect_simulation("Speciality is incorrect");
	}
	

}

void Student::setMinutesStay(int minutesStay)
{
	if (minutesStay <= 0) {
		throw incorrect_simulation("Minutes in bar are incorrect");
	}
	this->minutesStay = minutesStay;
}
