#pragma once
#include "Student.h"
#include "DoublyLinkedList.hpp"

class Group {
public:
	Group();
	Group(const Student& student, int capacity);

	void addStudent(const Student& student);
	void setEntrancedMinute(int entrancedMinute);
	int getEntrancedMinute() const;
	int size() const;
	bool hasSpace() const;
	Speciality getSpeciality() const;
	const DoublyLinkedList<Student>::Const_Iterator getStudentsStart() const;
	const DoublyLinkedList<Student>::Const_Iterator getStudentsEnd() const;
private:
	DoublyLinkedList<Student> students;
	int capacity;
	Speciality speciality;
	int entrancedMinute;
};