#include "Group.h"

Group::Group() : capacity(0), speciality(Speciality::UNKNOWN), entrancedMinute(-1)
{
}

Group::Group(const Student& student, int capacity) 
	: capacity(capacity), speciality(student.getSpeciality())
{
	addStudent(student);
	setEntrancedMinute(student.getArrivalMinute());
}


void Group::addStudent(const Student& student)
{
	if (!hasSpace()) {
		throw std::runtime_error("");
	}
	students.push_back(student);
	setEntrancedMinute(student.getArrivalMinute());
}

void Group::setEntrancedMinute(int entrancedMinute)
{
	this->entrancedMinute = entrancedMinute;
}
int Group::getEntrancedMinute() const
{
	return entrancedMinute;
}

int Group::size() const
{
	return students.size();
}

bool Group::hasSpace() const
{
	return !(capacity == size());
}

Speciality Group::getSpeciality() const
{
	return speciality;
}

const DoublyLinkedList<Student>::Const_Iterator Group::getStudentsStart() const
{
	return students.cbegin();
}

const DoublyLinkedList<Student>::Const_Iterator Group::getStudentsEnd() const
{
	return students.cend();
}