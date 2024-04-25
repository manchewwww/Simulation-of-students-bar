#pragma once
#include "Tail.h"

class Bar {
private:
	struct Node {
		friend class Bar;
		int FN;
		int timeIn;
		int timeOut;
		Node(int FN = -1, int timeIn = -1, int timeOut = -1) : FN(FN), timeIn(timeIn), timeOut(this->timeIn + timeOut) {}
	};
	DoublyLinkedList<Node> studentsInBar;
	int size;
	const int capacity;
	int minMinuteOut;
private:
	int freeSpaceInBar() const;
	void setMinMinuteOut();

	void printInStudent(const Node& node, std::ostream& output) const;
	void printExitStudent(const DoublyLinkedList<Node>::Iterator& node, std::ostream& output) const;

	void finishProgram(std::ostream& output);
	void addStudent(const Student& student, std::ostream& ofs, int entrancedMinute);
public:
	Bar(int capacity);

	bool hasSpase() const;
	void simulate(Tail& tail, std::ostream& ofs, Group** groups);
	void removeStudents(std::ostream& ofs);
	int getMinimumMinute() const;
	void finish(Tail& tail, std::ostream& output, Group** groups);
};