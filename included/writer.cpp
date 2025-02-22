// Writer.cpp
// Simple Writer CUI

#include "strmstd.hpp"
#include <iostream>
#include <fstream>

void save(string file, string text) {
    using std::ofstream;
    try {
        ofstream writer;
        writer.open(file);
        writer << text;
        writer.close();
    } catch(...) {
        println("Error: Cannot write to file");
    }
}

string load(string file) {
    using std::fstream;
    string text;
    try {
        fstream reader;
        reader.open(file);
        reader >> text;
        reader.close();
        return text;
    } catch(...) {
        println("Error: Cannot read file");
        return "";
    }
}

int main() {
    string file;
    string text;
    println("Writer CUI");
    file = read("Enter filename: ");
    text = read("Enter Text: ");
    save(file, text);
    println("File saved");
    println("File content: ");
    println(load(file));
    return 0;
}