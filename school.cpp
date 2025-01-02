#include <iostream>
#include <vector>
#include <string>
#include <bits/algorithmfwd.h>

class Person
{
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

class Student : public Person
{
public:
    int studentID;

    Student(std::string n, int a, int id) : Person(n, a), studentID(id) {}
};

class Teacher : public Person
{
public:
    int teacherID;

    Teacher(std::string n, int a, int id) : Person(n, a), teacherID(id) {}
};

class Class
{
public:
    std::string className;
    std::vector<Student> students;
    std::vector<Teacher> teachers;

    Class(std::string name) : className(name) {}

    void addStudent(const Student &student)
    {
        students.push_back(student);
    }

    void addTeacher(const Teacher &teacher)
    {
        teachers.push_back(teacher);
    }

    void displayDetails()
    {
        std::cout << "Class: " << className << std::endl;
        std::cout << "Students: " << std::endl;
        for (const auto &student : students)
        {
            std::cout << "Name: " << student.name << ", Age: " << student.age << ", ID: " << student.studentID << std::endl;
        }
        std::cout << "Teachers: " << std::endl;
        for (const auto &teacher : teachers)
        {
            std::cout << "Name: " << teacher.name << ", Age: " << teacher.age << ", ID: " << teacher.teacherID << std::endl;
        }
    }

    void deleteStudent(int id)
    {
        students.erase(std::remove_if(students.begin(), students.end(), [id](Student &s)
                                      { return s.studentID == id; }),
                       students.end());
    }

    void deleteTeacher(int id)
    {
        teachers.erase(std::remove_if(teachers.begin(), teachers.end(), [id](Teacher &t)
                                      { return t.teacherID == id; }),
                       teachers.end());
    }
};

int main()
{
    Class class1("Mathematics");

    Student student1("Alice", 20, 1);
    Student student2("Bob", 21, 2);
    Teacher teacher1("Mr. Smith", 40, 101);
    Teacher teacher2("Ms. Johnson", 35, 102);
