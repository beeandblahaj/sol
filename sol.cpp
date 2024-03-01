#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void read(string name) {

    string str;
    ifstream file("Text/" + name + ".txt");

    while (getline (file, str)) {
        cout << str + "\n";
    }

}

string config(int line) {

    int curr = 0;
    string str;
    ifstream file("Text/!config.txt");

    while (getline (file, str)) {

        if (curr == line) {

            return str;

        }

        curr++;

    }

    return "";
}

int main() {

    string version = config(0);
    string name = config(1);
    string welcome = config(2);

    cout << welcome << name <<"\nVersion: " << version << "\n---\n\n";

    return 0;

}