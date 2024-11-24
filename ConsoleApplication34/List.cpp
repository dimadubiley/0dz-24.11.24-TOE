#include "List.h"

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    *this = other;
}

List& List::operator=(const List& other) {
    if (this == &other) return *this;
    clear();
    Node* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

void List::push_back(int value)
{
    Node* new_node = new Node(value);
    if (tail)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    else
    {
        head = new_node;
    }
    tail = new_node;
    size++;
}

void List::push_front(int value)
{
    Node* new_node = new Node(value);
    if (head) {
        head->prev = new_node;
        new_node->next = head;
    }
    else {
        tail = new_node;
    }
    head = new_node;
    size++;
}

void List::pop_back()
{
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete temp;
    size--;
}

void List::pop_front()
{
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void List::reverse()
{
    if (!head || size < 2) return;
    Node* current = head;
    Node* temp = nullptr;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
}

void List::clear()
{
    while (head)
    {
        pop_front();
    }
}

void List::show() const
{
    Node* current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
