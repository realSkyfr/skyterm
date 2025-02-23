#include "commands.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

//? NOTE: At the moment another terminal (bash, zsh, fish) is required.
//* This will be fixed on a later update when a custom CLEAR function is implemented.
//? This program and all derivatives are licensed under the BSD 3-Clause License.

int main() {
    println("SkyTerminal v0.2 Alpha \nType 'help' for info on commands");
    println("Last Login: " + getTime());
    string command;
    string currentdir;
    string prompt;
    while (true) {
        currentdir = fs::current_path();
        prompt = currentdir + " $> ";
        command = read(prompt);
        if (command == "exit") {
            break;
        } else if (startsWith(command, "rd")) {
            try {
                string path = split(command, ' ')[1];
                printFile(path);
            } catch (const std::exception& e) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "wt")) {
            try {
                string path = split(command, 32)[1];
                string text = read("Text? ");
                writeFile(path, text);
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "print")) {
            int i;
            for (i = 1; i < split(command, ' ').size(); i++) {
                print(split(command, ' ')[i]);
                print(" ");
            }
            print("\n");
        } else if (startsWith(command, "sd")) {
            try {
                string path = split(command, 32)[1];
                switchDir(path);
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "rm")) {
            try {
                string path = split(command, 32)[1];
                remove(path);
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "md")) {
            try {
                string path = split(command, 32)[1];
                makeDir(path);
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "mf")) {
            try {
                string path = split(command, 32)[1];
                makeFile(path);
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (startsWith(command, "run")) {
            try {
                string path = split(command, 32)[1];
                system(path.c_str());
            } catch (...) {
                println("Invalid path: " + split(command, 32)[1]);
            }
        } else if (command == "cs") {
            system("clear");
        } else if (command == "ls") {
            listDir("./");
        } else if (command == "help") {
            println("Commands: \n sd (dir) - switch directory \n rd (file) - read file \n wt - write file (file); txt = to write (will be prompted)\n mf (path) - creates blank file \n md (path) - makes blank dir \n rm (dir) - deletes file \n print (text) - print text \n ls - lists contents in current directory \n time - gets current time \n cs - clear screen \n exit - exit terminal \n > is the prompt \n () is an argument");
        } else if (command == "time") {
            println(getTime());
        } else {
            println("Bad command: " + command);
            println("Type 'help' for command info");
        }
    }

    println("Exited with a code of 0 (success)");
    return 0;
}