#include "Bar.h"

Bar::Bar(int capacity) : capacity(capacity), size(0), minMinuteOut(0)
{
}

void Bar::simulate(Tail& tail, std::ostream& ofs, Group** groups)
{
	DoublyLinkedList<Group>::Iterator itGroups = tail.getGroupsStart();
	for (; itGroups != tail.getGroupsEnd(); ++itGroups) {
		if (freeSpaceInBar() >= itGroups->size()) {

			DoublyLinkedList<Student>::Const_Iterator itStudents = itGroups->getStudentsStart();
			for (; itStudents != itGroups->getStudentsEnd(); ++itStudents) {
				addStudent((*itStudents), ofs, itGroups->getEntrancedMinute());
			}

			groups[itGroups->getSpeciality()] = nullptr;
			tail.removeGroup(itGroups);
			return;
		}
		else if (itGroups->size() > capacity) {
			throw std::runtime_error("");
		}
		else {
			itGroups->setEntrancedMinute(minMinuteOut);
		}
	}
	setMinMinuteOut();
}

void Bar::removeStudents(std::ostream& ofs)
{
	DoublyLinkedList<Node>::Iterator it = studentsInBar.begin();
	while (it != studentsInBar.end()) {
		bool remove = false;
		if (it->timeOut == getMinimumMinute()) {
			remove = true;
			printExitStudent(it, ofs);
			it = studentsInBar.erase(it);
			--size;
		}
		if (!remove) {
			++it;
		}
	}
	setMinMinuteOut();
}

void Bar::addStudent(const Student& student, std::ostream& ofs, int entrancedMinute)
{
	Node studentIn(student.getFacultyNumber(), entrancedMinute, student.getMinutesStay());
	studentsInBar.push_back(studentIn);
	printInStudent(studentIn, ofs);
	++size;
	setMinMinuteOut();
}

void Bar::finish(Tail& tail, std::ostream& output, Group** groups)
{
	while (!tail.isEmpty()) {
		int tailSize = tail.getSize();
		simulate(tail, output,	groups);
		if (tailSize == tail.getSize()) {
			removeStudents(output);
		}
	}
	finishProgram(output);
}

void Bar::finishProgram(std::ostream& output)
{
	while (size != 0) {
		removeStudents(output);
	}
}

void Bar::setMinMinuteOut()
{
	DoublyLinkedList<Node>::Const_Iterator it = studentsInBar.cbegin();
	minMinuteOut = it->timeOut;
	++it;
	for (; it != studentsInBar.cend(); it++) {
		if (minMinuteOut > it->timeOut) {
			minMinuteOut = it->timeOut;
		}
	}
}

void Bar::printInStudent(const Node& node, std::ostream& output) const
{
	output << node.timeIn << " " << node.FN << " " << "enter" << std::endl;
}

void Bar::printExitStudent(const DoublyLinkedList<Node>::Iterator& node, std::ostream& output) const
{
	output << node->timeOut << " " << node->FN << " " << "exit" << std::endl;
}

int Bar::freeSpaceInBar() const
{
	return capacity - size;
}

int Bar::getMinimumMinute() const
{
	return minMinuteOut;
}

bool Bar::hasSpase() const
{
	return freeSpaceInBar();
}
