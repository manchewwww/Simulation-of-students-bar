#pragma once
#include "Group.h"

class Tail {
public:
	Tail(int maxGroupSize);
	void addStudent(const Student& student, Group** groups);
	void removeGroup(DoublyLinkedList<Group>::Iterator& itGroups);
	DoublyLinkedList<Group>& getGroups();
	DoublyLinkedList<Group>::Iterator getGroupsStart();
	DoublyLinkedList<Group>::Iterator getGroupsEnd();
	const int getSize() const;
	bool isEmpty() const;
private:
	DoublyLinkedList<Group> groups;
	int maxGroupSize;
};