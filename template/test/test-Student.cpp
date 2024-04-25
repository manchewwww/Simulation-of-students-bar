#include "catch2/catch_all.hpp"
#include "simulator-lib/Student.h"

TEST_CASE("invalid student")
{
	REQUIRE_THROWS_AS(Student(0, -1, "Fraud", 5), incorrect_simulation);
	REQUIRE_THROWS_AS(Student(-1, 10, "File Analizis", 5), incorrect_simulation);
	REQUIRE_THROWS_AS(Student(0, 0, "ABC", 5), incorrect_simulation);
	REQUIRE_THROWS_AS(Student(0, 10, "Fraud", 0), incorrect_simulation);
}
TEST_CASE("valid student")
{
	Student student(0, 0, "Fraud", 5);
	REQUIRE(student.getFacultyNumber() == 0);
	REQUIRE(student.getArrivalMinute() == 0);
	REQUIRE(student.getSpeciality() == Speciality::Fraud);
	REQUIRE(student.getMinutesStay() == 5);
}
TEST_CASE("valid student1")
{
	Student student(999'999'999, 200, "File Analizis", 55);
	Student student1 = student;
	REQUIRE(student.getFacultyNumber() == 999'999'999);
	REQUIRE(student.getArrivalMinute() == 200);
	REQUIRE(student.getSpeciality() == Speciality::FileAnalizis);
	REQUIRE(student.getMinutesStay() == 55);
	REQUIRE(student1.getFacultyNumber() == 999'999'999);
	REQUIRE(student1.getArrivalMinute() == 200);
	REQUIRE(student1.getSpeciality() == Speciality::FileAnalizis);
	REQUIRE(student1.getMinutesStay() == 55);
}