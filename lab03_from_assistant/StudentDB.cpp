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
    size = 0;
}

void StudentDB::insertFront(Student s)
{
    Node* newNode = new Node;
    newNode->s = s;
    newNode->next = head;
    head = newNode;
    ++size;
}

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
    ++size;
}
void StudentDB::insertMiddle(Student s)
{
    if(head==nullptr) insertFront(s);
    else
    {
        Node* newNode = new Node;
        newNode->s = s;

        Node* it = head;
        size_t cnt = 0;

        while(cnt < size/2-1)
        {
            it = it->next;
            ++cnt;
        }

        newNode->next = it->next;
        it->next = newNode;

        ++size;
    }
    
}

void StudentDB::deleteFront()
{
    if(head==nullptr) throw "cannot delete from empty list";
    else
    {
        Node* tmp = head;

        head = head->next;
        --size;

        delete tmp;
    }
    
}
void StudentDB::deleteMiddle()
{
    if(head==nullptr) throw "cannot delete from empty list";
    else
    {
        Node* it = head;
        size_t cnt = 0;

        while(cnt < size/2-1)
        {
            it = it->next;
            ++cnt;
        }

        Node* tmp = it->next;
        it->next = it->next->next;
        delete tmp;
        --size;

    }
    
}
void StudentDB::deleteBack()
{
    Node* it = head;

    //empty case
    if(head==nullptr) throw "cannot delete from empty list";

    //one element case
    if(it->next == nullptr)
    {
        delete it;
        head = nullptr;
        return;
    }

    //regular case
    while(it->next->next != nullptr)
    {
        it = it->next;
    }

    delete it->next;
    it->next = nullptr;


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
