#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int grade;
};

int getStudentsAmount() {
    std::cout << "How many students do you want to enter? ";
    int input{};
    std::cin >> input;

    return input;
}

Student getStudent() {
    Student s{};
    std::cin >> s.name;
    std::cin >> s.grade;

    return s;
}

int main() {
    int studentsAmount{getStudentsAmount()};
    Student s{};
    std::vector<Student> students{};

    for (int i{}; i < studentsAmount; i++) {
        if (i == 0) {
            s = {getStudent()};
            students.push_back(s);
        } else {
            s = {getStudent()};
            if (s.grade > students[i - 1].grade) {
                students.insert(students.begin(), s);
            } else {
                students.push_back(s);
            }
        }
    }

    for (int i{}; i < studentsAmount; i++) {
        std::cout << students[i].name << " got a grade of " << students[i].grade << '\n';
    }
    return 0;
}
