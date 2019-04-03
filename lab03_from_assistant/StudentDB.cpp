#include "StudentDB.h"

Student::Student(){}

Student::Student(std::string name, unsigned int id)
{
    this->name = name;
    this->id = id;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << s.id;
    return os;
}


StudentDB::StudentDB()
{
    head = nullptr;
}

void StudentDB::insertFront(Student s){}
void StudentDB::insertBack(Student s)
{
    if(head == nullptr) //empty list
    {
        head = new Node;
        head->s = s;
        head->next = nullptr;
    }
    else //nonempty list
    {
        Node* it = head;
        while(it->next != nullptr)
        {
            it = it->next;
        }
        it->next = new Node;
        it=it->next;
        it->s = s;
        it->next = nullptr;
    }
}
void StudentDB::insertMiddle(Student s)
{

}

void StudentDB::deleteFront()
{

}
void StudentDB::deleteMiddle()
{

}
void StudentDB::deleteBack()
{
    
}
void StudentDB::print() const
{
    Node* it = head;
    while(it != nullptr)
    {
        std::cout << it->s << std::endl;
        it = it->next; 
    }
}
