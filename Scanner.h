#ifndef SCANNER_H
#define SCANNER_H

using namespace std;

class Scanner {
    private:
    int replacementCount = 0;
    vector<string> lines;
    string inputFile;
    string findString;
    string replaceString;

    public:
    Scanner(string inputFile, string findString, string replaceString) {
        this->inputFile = inputFile;
        this->findString = findString;
        this->replaceString = replaceString;
    }
    Scanner() {
        this->inputFile = "";
    }

    void ThrowError(string error) {
        throw std::invalid_argument(error);
    }

    vector<string> GetLines() {
        return lines;
    }

    int GetReplacementCount() {
        return replacementCount;
    }

    void RunScan() {
        ifstream inFile;
        string inputLine;
        inFile.open(inputFile);
        if (!inFile.is_open()) {
            ThrowError("Unable to open " + inputFile);
        }
        while (getline(inFile, inputLine)) {
            size_t location = inputLine.find(findString);
            while (location != string::npos) {
                ++replacementCount;
                inputLine.replace(location, findString.length(), replaceString);
                location = inputLine.find(findString, location + 1);
            }
            lines.push_back(inputLine);
        }
    }


};




#endif