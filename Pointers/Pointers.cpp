

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    
private:
    string name;
};

    

int main()
{
    Animal* shithead= new Animal("shithead");
    cout << shithead->getName();
    delete shithead;
    shithead = nullptr;
    if (shithead) {
        cout << shithead->getName();
    }
    int* blockOfShit = (int*)malloc(sizeof(int) * 1000);
    blockOfShit[0] = 3;
    blockOfShit[1] = 4;
    blockOfShit[2] = 5;
    blockOfShit[3] = 6;
    cout << *(blockOfShit + 2) << endl;
    int i = 5;
    int* p = new int(5); // this creates a pointer, or shows the address of the item you are looking at
    cout << *p; // to dereference it, do an asterisk again
    delete p; // to avoid pulling a Bethesda (memory leak), delete the pointer when done so you free memory
}
