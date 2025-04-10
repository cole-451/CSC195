
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

int GetHash(string string) {
    int hashPipe = 0;
    for (char c : string) {
        hashPipe = hashPipe * 1 + (int)c;
    }
    return hashPipe;
}
void arrayUsage() {
    array<string, 7> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; // declaring array.
    for (int i = 0; i < daysOfWeek.size();i++) { // printing out all contents using the .size command.
        cout << daysOfWeek[i] << endl;
    }
}

void vectorUsage() { // dynamic; can change at runtime if need be.
    vector<int> vectorNumbers = { 1,2,3,4,5 }; // declaring a vector.
    vectorNumbers.push_back(6); // moves everything to a new set of vectors.
    vectorNumbers.pop_back(); // pushes everything back to its original set with its original limitations???

    //TODO: add the printing methods
     for (int i = 0; i < vectorNumbers.size();i++) { // printing out all contents using the .size command.
    cout << vectorNumbers[i] << endl;
}
    // fast for static data, SLOW at insertion.

     stack<int> loled;
     loled.push(1);
     loled.push(2);
     loled.pop(); // since you can only add stuff individually and it all goes on top, stacks are GREAT to save memory.
     // follows FILO procedure; First entry is the last to go.

}

void listUsage() {
    list <string> fruitNames = {"apple", "orange", "banana"};
    fruitNames.insert(fruitNames.begin(), "pear"); // You can insert values in places, but you CANNOT do it by index.
    fruitNames.remove("apple"); // same with removing.

    list <string>::iterator iter = fruitNames.begin();
    cout << *iter << endl; 
    iter++;
    cout << *iter << endl;
    // this is the long way, but is very common!
    for (auto iter = fruitNames.begin(); iter != fruitNames.end(); iter++) {
        cout << *iter << endl;
    }



    for (string fruitName:fruitNames) { // had to do a for-each because of what happened below.
        cout << fruitName << endl;  // you CANNOT call any actual index.
    }
   

}

void mapUsage() {
    map<string, int> itemCount;
    // all values are in a tree, going off of who's name was said in a sense.
    itemCount[ "apples"]  = 7;
    itemCount["bananas"] = 2;
    itemCount["oranges"] = 2096;

    cout << "I don't think I'm supposed to have " << itemCount["oranges"] << " oranges." << endl;

    itemCount["oranges"] = 20;

    for (auto item : itemCount) { // auto helps the computer determine what value type we are looking for since we have two different values.
        cout << item.first << ":" << item.second<<endl; // This will now print out the key values that each pair has.
    } //Thank you to W3 Schools for teaching me about the auto term. Link: https://www.w3schools.com/cpp/cpp_maps.asp

    //UNORDERED MAPS:
    unordered_map<string, string> um;
    um["Cole"] = "Neely";
    um["Edward"] = "Hernandez";
    um["Nathan"] = "Spackman";

    cout << um["Cole"] << endl;


}





int main()
{
    //int i = 0x24; // C++ has no default values; it can only work with the memory YOU give it
    //int a[5] = { 1,2,3,4,5 };
   // cout << (void*)(&a[0]) << endl;
    //cout << (void*)(&a[1]) << endl; // goes up by 4 bytes because they're ints
    arrayUsage();
    vectorUsage();
    listUsage();
    mapUsage();
    string h = "fart";
    unsigned int lol = GetHash(h);
    cout << lol << endl;
    int data[10];
    data[lol % 10] = 84025;

}

