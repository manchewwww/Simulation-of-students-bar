#include "catch2/catch_all.hpp"
#include "simulator-lib/Group.h"

TEST_CASE("Invalid group")
{
	Student student(0, 0, "Fraud", 5);
	Group group;
	REQUIRE(group.size() == 0);
	REQUIRE(group.hasSpace() == false);
	REQUIRE(group.getSpeciality() == Speciality::UNKNOWN);
	REQUIRE_THROWS_AS(group.addStudent(student), std::runtime_error);
}

TEST_CASE("Valid group")
{
	Student student(1, 0, "Fraud", 5);
	Group group(student, 5);
	REQUIRE(group.size() == 1);
	REQUIRE(group.hasSpace() == true);
	REQUIRE(group.getSpeciality() == Speciality::Fraud);

	Student student1(2, 1, "Fraud", 5);
	group.addStudent(student1);
	REQUIRE(group.size() == 2);
	REQUIRE(group.hasSpace() == true);
	REQUIRE(group.getSpeciality() == Speciality::Fraud);
}
TEST_CASE("Valid group1")
{
	Student student(1, 0, "Fraud", 5);
	Student student1(2, 1, "Fraud", 5);
	Group group(student, 5);
	group.addStudent(student1);
	REQUIRE(group.size() == 2);
	REQUIRE(group.hasSpace() == true);
	REQUIRE(group.getSpeciality() == Speciality::Fraud);
}