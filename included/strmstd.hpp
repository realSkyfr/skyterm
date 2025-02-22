//Sky Terminal Standard Library v0.1

#include <iostream>
#include <string>

using std::string;
using std::cout;

void print(string str) {
    cout << str;
}

void println(string str) {
    cout << str << "\n";
}

string read(string text) {
    using std::cin;
    string end;
    print(text);
    getline(cin, end);
    return end;
}