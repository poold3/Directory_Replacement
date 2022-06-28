#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <filesystem>

#include "Scanner.h"

using namespace std;
namespace fs = std::filesystem;

string START_DIRECTORY = "/mnt/c/Documents/Project1";
set<string> EXTENSIONS_TO_READ({".cpp", ".h", ".txt"});
string FIND = "testsite.com";
string REPLACE_WITH = "site.com";

string BEGIN_SEARCH = ".open(";
string END_SEARCH = ")";

void WriteToFile(string filePath, vector<string> lines) {
    ofstream outFile;
    outFile.open(filePath);
    if (outFile.is_open()) {
        for (string line : lines) {
            outFile << line << endl;
        }
    }
    else {
        cout << "ERROR: Writing to " << filePath << " failed!" << endl;
    }
    outFile.close();

    return;
}

int main() {
    
    set<string> filesRead;
    set<string> filesWritten;
    int totalReplacementCount = 0;

    for (auto const& dir_entry : fs::recursive_directory_iterator(START_DIRECTORY)) {
        try {
            fs::path tempPath = dir_entry;
            string extension = tempPath.extension();
            if (EXTENSIONS_TO_READ.find(extension) != EXTENSIONS_TO_READ.end()) {
                //Read from files
                cout << "Reading from " << tempPath << endl << endl;
                Scanner scanner(tempPath.string(), FIND, REPLACE_WITH, BEGIN_SEARCH, END_SEARCH);
                if (BEGIN_SEARCH == "" && END_SEARCH == "") {
                    scanner.RunScan();
                }
                else {
                    scanner.RunSelectiveScan();
                }
                int replacementCount = scanner.GetReplacementCount();
                if (replacementCount > 0) {
                    totalReplacementCount += replacementCount;
                    vector<string> lines = scanner.GetLines();
                    WriteToFile(tempPath.string(), lines);
                    filesWritten.insert(tempPath.string());
                }
                filesRead.insert(tempPath.string());
            }
        }
        catch (exception& e) {
            cout << endl << e.what() << endl << endl;
            cout << "ERROR: Could not process " << dir_entry << endl;
        }
    }

    ofstream outFile;
    outFile.open("Files_Read.txt");
    if (outFile.is_open()) {
        for (string file : filesRead) {
            outFile << file << endl;
        }
    }
    outFile.close();

    outFile.open("Files_Written.txt");
    if (outFile.is_open()) {
        for (string file : filesWritten) {
            outFile << file << endl;
        }
    }
    outFile.close();

    cout << endl << "Operation performed successfully: " << totalReplacementCount << " replacements made." << endl;

    return 0;

}