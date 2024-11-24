#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List list;
    list.push_back(10);
    list.push_back(1);
    list.push_back(-5);

    cout << "Initial: ";
    list.show();

    List copy = list;
    cout << "Copied: ";
    copy.show();

    list.pop_back();
    cout << "After pop_back: ";
    list.show();

    list.pop_front();
    cout << "After pop_front: ";
    list.show();

    list.push_back(50);
    list.push_back(30);
    cout << "Before reverse: ";
    list.show();

    list.reverse();
    cout << "After reverse: ";
    list.show();

    list.clear();
    cout << "After clear: ";
    list.show();

}
