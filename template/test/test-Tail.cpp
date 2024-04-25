#include "catch2/catch_all.hpp"
#include "simulator-lib/Tail.h"

TEST_CASE("Valid tail")
{
	Tail tail(3);
	Group* groups[9]{ nullptr };
	Student student(1, 0, "Fraud", 5);
	Student student1(2, 1, "Fraud", 5);
	Student student2(2, 1, "International Schemes", 5);
	REQUIRE(tail.getGroups().size() == 0);
	tail.addStudent(student, groups);
	REQUIRE(tail.getGroups().size() == 1);
	tail.addStudent(student1, groups);
	REQUIRE(tail.getGroups().size() == 1);
	tail.addStudent(student2, groups);
	REQUIRE(tail.getGroups().size() == 2);
}