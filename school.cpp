#include <iostream>
#include <vector>
#include <string>

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
