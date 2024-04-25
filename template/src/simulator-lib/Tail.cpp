#include "Tail.h"

Tail::Tail(int maxGroupSize) : maxGroupSize(maxGroupSize)
{
}

void Tail::addStudent(const Student& student, Group** groups)
{
	int index = student.getSpeciality();

	if (groups[index] == nullptr) {
		this->groups.push_back(Group(student, maxGroupSize));
		groups[index] = &(*(--this->groups.end()));

		if (!groups[index]->hasSpace()) {
			groups[index] = nullptr;
		}
	}
	else {
		groups[index]->addStudent(student);

		if (!groups[index]->hasSpace()) {
			groups[index] = nullptr;
		}
	}
}

void Tail::removeGroup(DoublyLinkedList<Group>::Iterator& itGroups)
{
	groups.erase(itGroups);
}

DoublyLinkedList<Group>& Tail::getGroups()
{
	return groups;
}

DoublyLinkedList<Group>::Iterator Tail::getGroupsStart()
{
	return groups.begin();
}
DoublyLinkedList<Group>::Iterator Tail::getGroupsEnd()
{
	return groups.end();
}

const int Tail::getSize() const
{
	return groups.size();
}

bool Tail::isEmpty() const
{
	return getSize() == 0;
}
