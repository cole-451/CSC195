

#include <iostream>
using namespace std;
int main()
{
    // a reference is another name for a variable, and is signified by &
    int i1 = 5;
    int* p1 = &i1;
    // unlike pointers, refs need to be initialized
    int& r1 = i1;
    r1 = 5; //you cannot change references once initialized
    cout << &r1 << endl;
    cout << &i1 << endl;

}
