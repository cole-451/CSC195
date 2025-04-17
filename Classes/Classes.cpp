#include <iostream>
#include "Classes.h"
#include <vector>
using namespace std;

class Database {
public:
vector<Media*> objects;

~Database() {
    for (Media* obj : objects) {
        delete obj;
    }
}
void Create(Media::type type) {
    Media* obj = nullptr;
    switch (type) {
    case Media::type::VIDEO_GAME:
        obj = new VideoGame();
        break;
    case Media::type::MOVIE:
        obj = new Movie();
        break;
    }
    obj->Read(cout, cin);  // might be a problem with looping here
    objects.push_back(obj);
}

void DisplayAll() {
    for (Media* obj : objects) {
        obj->Write(cout);
    }
}

void Display(const string& name) {
    for (Media* obj : objects) {
        if (obj->getTitle() == name) {
            obj->Write(cout);
        }
    }
}

void Display(Media::type type) {
    for (Media* obj : objects) {
        if (obj->getType() == type) {
            obj->Write(cout);
        }
    }
}



};

Database database;



int main()
{
 
    bool quit = false;
    string name;
    while (!quit)
    {
        int choice = 0;
        //IF THE CIN INPUT IS NOT AN INT, THIS WILL FUCK UP THE WHOLE PROGRAM
        
        cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
        cin.clear();
        cin >> choice;
        

        switch (choice)
        {
        case 1: // Create object by type  (call the function)
            cout << "Enter type (0 for VIDEO_GAME, 1 for MOVIE): ";
            int t;
            cin >> t;
            cin.clear();
            database.Create(static_cast<Media::type>(t));
            break; 
        case 2: 
            database.DisplayAll();
            break;
        case 3: // Ask for name, then call database.Display(name) break; 
            
            cout << "Enter name:" << endl; 
            cin >> name;
            database.Display(name);
            break;
        case 4:
        {
            cout << "Enter type (0 for VIDEO_GAME, 1 for MOVIE): ";
            int t;
            cin >> t;
            database.Display(static_cast<Media::type>(t)); break;
        }
        case 5:
            quit = true;
            break;
        default:
            cout << "WRONG. try again" << endl;
        }
    }


}
