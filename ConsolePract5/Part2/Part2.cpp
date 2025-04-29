#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Student {
private:
    string id;
    string name;
    string email;
public:
    Student(const string& i, const string& n, const string& e)
        : id(i), name(n), email(e) {
    }

    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
};

class Instructor {
private:
    string id;
    string name;
    string department;
public:
    Instructor(const string& i, const string& n, const string& d)
        : id(i), name(n), department(d) {
    }

    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
};

class Course {
private:
    string code;
    string title;
    int credits;
    Instructor* instructor;
public:
    Course(const string& c, const string& t, int cr, Instructor* i)
        : code(c), title(t), credits(cr), instructor(i) {
    }

    string getCode() const { return code; }
    string getTitle() const { return title; }
    int getCredits() const { return credits; }
    Instructor* getInstructor() const { return instructor; }
};

class Enrollment {
private:
    Student* student;
    Course* course;
    char grade;
public:
    Enrollment(Student* s, Course* c)
        : student(s), course(c), grade(' ') {
    }

    void setGrade(char g) { grade = toupper(g); }

    Student* getStudent() const { return student; }
    Course* getCourse() const { return course; }
    char getGrade() const { return grade; }
};

class Schedule {
private:
    Course* course;
    string day;
    string time;
    string room;
public:
    Schedule(Course* c, const string& d, const string& t, const string& r)
        : course(c), day(d), time(t), room(r) {
    }

    Course* getCourse() const { return course; }
    string getDay() const { return day; }
    string getTime() const { return time; }
    string getRoom() const { return room; }
};

class GradeReport {
public:
    static void generateReport(const vector<Enrollment*>& enrollments) {
        map<Student*, vector<pair<Course*, char>>> studentGrades;

        for (const auto& enroll : enrollments) {
            studentGrades[enroll->getStudent()].emplace_back(
                enroll->getCourse(), enroll->getGrade());
        }
    }
};

int main() {
    // Создаем преподавателей
    Instructor* profSmith = new Instructor("I001", "Prof. Smith", "Computer Science");
    Instructor* profJohnson = new Instructor("I002", "Prof. Johnson", "Mathematics");

    // Создаем курсы
    Course* cs101 = new Course("CS101", "Introduction to Programming", 4, profSmith);
    Course* math201 = new Course("MATH201", "Linear Algebra", 3, profJohnson);

    // Создаем студентов
    Student* student1 = new Student("S001", "Alice", "alice@univ.edu");
    Student* student2 = new Student("S002", "Bob", "bob@univ.edu");

    // Регистрация на курсы
    vector<Enrollment*> enrollments;
    Enrollment* enroll1 = new Enrollment(student1, cs101);
    Enrollment* enroll2 = new Enrollment(student1, math201);
    Enrollment* enroll3 = new Enrollment(student2, cs101);

    enrollments.push_back(enroll1);
    enrollments.push_back(enroll2);
    enrollments.push_back(enroll3);

    // Выставляем оценки
    enroll1->setGrade('A');
    enroll2->setGrade('B');
    enroll3->setGrade('C');

    // Создаем расписание
    Schedule* csSchedule = new Schedule(cs101, "Mon/Wed", "10:00-11:30", "Room 101");
    Schedule* mathSchedule = new Schedule(math201, "Tue/Thu", "13:00-14:30", "Room 205");

    // Генерируем отчет
    GradeReport::generateReport(enrollments);

    // Очистка памяти
    delete profSmith;
    delete profJohnson;
    delete cs101;
    delete math201;
    delete student1;
    delete student2;
    delete enroll1;
    delete enroll2;
    delete enroll3;
    delete csSchedule;
    delete mathSchedule;

    return 0;
}