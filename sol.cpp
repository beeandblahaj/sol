#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void reader() {

    string name;
    string str;

    cout << "Entering reader mode.\n---\n";

    ifstream contents("Entries/!contents.txt");

    while (getline (contents, str)) {
        cout << str + "\n";
    }

    contents.close();

    cout << "\nWhat story would you like to read? ";
    cin >> name;

    ifstream file("Entries/" + name + ".txt");

    cout << "\nEntry Contents:\n\n";

    while (getline (file, str)) {
        cout << str + "\n";
    }

    file.close();

}

void writer() {

    string name;
    string text;

    cout << "Entering author mode.\n---\n\n";

    cout << "What should the file be called? ";
    cin >> name;

    cout << "Enter file text:\n\n";
    cin.ignore();
    std::getline(std::cin, text);

    ofstream file("Entries/" + name + ".txt");
    file << text;

    cout << "Writing complete.\n";

    ifstream contents("Entries/!contents.txt");
    if (!contents.is_open()) {

        ofstream contents("Entries/!contents.txt");
        contents << "Table of Contents:\n---\n\n";
        contents.close();

    }
    
    ofstream newContents("Entries/!contents.txt", ofstream::app);
    string line = name + "\n";
    newContents << line;

    newContents.close();
    contents.close();    
    file.close();

}

string config(int line) {

    int curr = 0;
    string str;
    ifstream file("Text/!config.txt");

    while (getline (file, str)) {

        if (curr == line) {

            file.close();
            return str;

        }

        curr++;

    }

    file.close();
    return "";
}

int main() {

    // Config variables
    string version = config(0);
    string name = config(1);
    string welcome = config(2);
    string author = config(3);
    string read = config(4);
    string contString = config(5);
    string op;
    
    bool write = false;
    bool cont = true;

    cout << welcome << name <<"\nVersion: " << version << "\n---\n";

    while (cont) {

        cout << "\nWhat would you like to do today? ";
        cin >> op;

        // Optimize this, if possible
        if (op == author)
            writer();
        else if (op == read)
            reader();
        else
            cout << "Sorry, " + name + ", this command doesn't seem to exist.";
        
        string contResponse;
        cout << "\n---\nContinue? ";
        cin >> contResponse;
        cont = contResponse == contString;

    }

    return 0;

}