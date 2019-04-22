#include "StudentDB_DLL.h"

Student::Student(){}

Student::Student(std::string name, unsigned int id)
{
    this->name = name;
    this->id = id;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << s.name << ", id: " << s.id;
    return os;
}

StudentDB::StudentDB()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

StudentDB::~StudentDB()
{
    while(head != nullptr)
    {
        Node* tmp = head;
        head=head->next;
        delete tmp;
    }
}

void StudentDB::insertBack(Student s)
{
    if(head == nullptr) //empty list case:
    {
        head = new Node;
        head->s = s;
        head->prev = nullptr;
        head->next = nullptr;
    }
    else if(tail == nullptr) //just one element
    {
        tail = new Node;
        tail->s = s;
        tail->prev = head;
        tail->next = nullptr;

        head->next = tail;
    }
    else // "regular" case
    {
        Node* newNode = new Node;
        newNode->next = nullptr;
        newNode->prev = tail;
        newNode->s = s;

        tail->next = newNode;
        tail = newNode;
    }
    ++size;

}

void StudentDB::insertFront(Student s)
{
    if(head == nullptr) insertBack(s); //empty list
    else //one element or "normal" case
    {
        Node* newNode = new Node;
        newNode->s = s;
        newNode->next = head;
        newNode->prev = nullptr;

        head->prev = newNode;
        head = newNode;
        ++size;
    }
}

Node* StudentDB::getMiddle()
{
    size_t size_it = 1;
    size_t halfSize = (size-1)/2;
    Node* it = head;
    while(size_it <= halfSize)
    {
        it=it->next;
        ++size_it;
    }
    return it;
}

void StudentDB::insertMiddle(Student s)
{
    if(head == nullptr || tail == nullptr) insertFront(s);

    Node* it = getMiddle();

    Node* newNode = new Node;
    newNode->s = s;
    newNode->next = it->next;
    newNode->prev = it;

    newNode->next->prev = newNode;
    it->next = newNode;

    ++size;
}

void StudentDB::deleteFront()
{
    if(head==nullptr) throw "Cannot delete from empty list";
    else if(tail == nullptr) //delete from one-element list
    {
        delete tail;
        --size;
        head = tail = nullptr;
    }
    else
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        --size;
    }
}
void StudentDB::deleteMiddle()
{
    //deleting for empty or one-element list boils down to deleteFront
    if(head==nullptr || tail == nullptr || size==2) deleteFront();
    else
    {
        Node* mid = getMiddle();
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        delete mid;
        --size;
    }
}
void StudentDB::deleteBack()
{
    //deleting for empty or one-element list boils down to deleteFront
    if(head==nullptr or tail == nullptr) deleteFront();
    else
    {
        Node* tmp = tail;
        tail->prev->next = nullptr;
        delete tmp;
        --size;
    }
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
