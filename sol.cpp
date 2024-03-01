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

    string check = config(0);

    read("welcome");
    cout << check;

    return 0;

}