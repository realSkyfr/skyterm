#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <filesystem>

using std::string;
using std::vector;

namespace fs = std::filesystem;

void print(string input) {
    using std::cout;
    cout << input;
}

void println(string input) {
    using std::cout;
    cout << input << "\n";
}

string read(string text) {
    using std::cin;
    string end;
    print(text);
    getline(cin, end);
    return end;
}

vector<string> split(string input, char delimiter) {
    using std::stringstream;
    using std::string;
    vector<string> tokens;
    string token;
    stringstream tokenStream(input);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

string parsePf(string input) {
    vector<string> out;
    out = split(input, ' ');
    return out[0], out[1];
}

void printFile(string path) {
    using std::ifstream;
    
    ifstream file(path);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            print(line);
        }
        print("\n");
        file.close();
    } else {
        println("Invalid path: " + path);
    }
}

string readToVar(string path) {
    using std::ifstream;
    
    ifstream file(path);

    if (file.is_open()) {
        string line;
        string out;
        while (getline(file, line)) {
            out += line;
        }
        file.close();
        return out;
    } else {
        println("Invalid path: " + path);
        return "-|ERROR|InvalidPath";
    }
}

void writeFile(string path, string text) {
    using std::ofstream;
    
    ofstream file(path, ofstream::out | ofstream::trunc);

    if (file.is_open()) {
        file << text;
        file.close();
        println("Write success to: " + path);
    } else {
        println("Invalid path: " + path);
    }
}

string getTime() {
    using std::time_t;
    using std::asctime;
    time_t result = time(nullptr);
    return asctime(localtime(&result));
}

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.rfind(prefix, 0) == 0;
}

void listDir(string path) {
    for (const auto & entry : fs::directory_iterator(path)) {
        println(entry.path());
    }
}

void switchDir(string path) {
    using std::filesystem::current_path;
    try {
        current_path(path);
    } catch(...) {
        println("Invalid path: " + path);
    }
}

void remove(string path) {
    using std::filesystem::remove;
    try {
        remove(path);
    } catch(...) {
        println("Invalid path: " + path);
    }
}

void makeDir(string path) {
    using std::filesystem::create_directory;
    try {
        create_directory(path);
    } catch(...) {
        println("An error has occoured while creating the directory: " + path);
    }
}

void makeFile(string path) {
    using std::ofstream;
    ofstream file(path);
    file.close();
}