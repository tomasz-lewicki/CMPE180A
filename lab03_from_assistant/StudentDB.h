
#include <string>
#include <iostream>

class Student
{
    public:

    Student();
    Student(std::string name, unsigned int id);

    private:

    std::string name;
    unsigned int id;

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

class Node
{
    public:
    Student s;
    Node* next;
};

class StudentDB
{
    public:
    StudentDB();
    void insertFront(Student s);
    void insertBack(Student s);
    void insertMiddle(Student s);
    
    void deleteFront();
    void deleteMiddle();
    void deleteBack();

    void print() const;

    private:
    Node* head;
    size_t size;
};