#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void reader(string folder, string name) {

    string str;
    ifstream file(folder + "/" + name + ".txt");

    while (getline (file, str)) {
        cout << str + "\n";
    }

    file.close();

}

void writer() {

    string folder;
    string name;
    string text;

    cout << "Entering author mode.\n---\n\n";
    cout << "Where would you like to add this new entry? ";
    cin >> folder;

    cout << "What should the file be called? ";
    cin >> name;

    cout << "Enter file text:\n\n";
    cin.ignore();
    std::getline(std::cin, text);

    ofstream file(folder + "/" + name + ".txt");
    file << text;

    cout << "Writing complete.";
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

    string version = config(0);
    string name = config(1);
    string welcome = config(2);
    string phrase = config(3);
    string op;
    bool write = false;

    cout << welcome << name <<"\nVersion: " << version << "\n---\n\n";

    cout << "What would you like to do today? ";
    cin >> op;
    /*
    switch (op) {

        case phrase:


    }
    */
    if (op == phrase) {

        write = true;

    }

    cout << "\n\n";

    if (write) {
        writer();
    }

    return 0;

}