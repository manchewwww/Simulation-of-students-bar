#include "bar-simulator.h"
#include "Bar.h"

void validate(int barCapacity, int groupCapacity, int studentsCount, std::istream& input)
{
	if ((barCapacity == 0 || studentsCount == 0) && !input.eof()) {
		throw std::runtime_error("");
	}
}

int parseInt(std::string& speciality)
{
	int minutesStay = 0;
	int multiplier = 1;

	while (speciality.back() != ' ') {
		minutesStay = (speciality.back() - '0') * multiplier + minutesStay;
		multiplier *= 10;
		speciality.pop_back();
	}

	speciality.pop_back();

	return minutesStay;
}

void simulate_bar(std::istream& input, std::ostream& output)
{
	int barCapacity, groupCapacity, studentsCount;
	input >> barCapacity >> groupCapacity >> studentsCount;

	validate(barCapacity, groupCapacity, studentsCount, input);

	Bar bar(barCapacity);
	Tail tail(groupCapacity);

	Group* groups[9]{ nullptr };

	for (size_t i = 0; i < studentsCount; i++) {
		int facultyNumber, arrivalMinute;
		input >> facultyNumber >> arrivalMinute;
		input.get();

		std::string speciality;
		std::getline(input, speciality);

		int minutesStay = parseInt(speciality);

		while (arrivalMinute > bar.getMinimumMinute() && !tail.isEmpty()) {
			int tailSize = tail.getSize();
			bar.simulate(tail, output, groups);
			if (tailSize == tail.getSize()) {
				bar.removeStudents(output);
			}
		}

		tail.addStudent(Student(facultyNumber, arrivalMinute, speciality, minutesStay), groups);

		if (bar.hasSpase()) {
			bar.simulate(tail, output,	groups);
		}
	}
	bar.finish(tail, output, groups);
}
