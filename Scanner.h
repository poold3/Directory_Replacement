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
    string beginSearch;
    string endSearch;

    public:
    Scanner(string inputFile, string findString, string replaceString, string beginSearch, string endSearch) {
        this->inputFile = inputFile;
        this->findString = findString;
        this->replaceString = replaceString;
        this->beginSearch = beginSearch;
        this->endSearch = endSearch;
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
    
    void RunSelectiveScan() {
        ifstream inFile;
        string inputLine;
        inFile.open(inputFile);
        bool inScript = false;
        string newLine = "";
        if (!inFile.is_open()) {
            ThrowError("Unable to open " + inputFile);
        }
        while (getline(inFile, inputLine)) {
            if ((inScript == false && inputLine.find(beginSearch) != string::npos) || (inScript == true && inputLine.find(endSearch) != string::npos)) {
                string inputLineCopy = inputLine;
                string newLine = "";
                int size = 1;
                while (inputLineCopy.length() > 0) {
                    if (inScript == false && inputLineCopy.substr(0, beginSearch.length()) == beginSearch) {
                        inScript = true;
                        size = beginSearch.length();
                    }
                    else if (inScript == true && inputLineCopy.substr(0, endSearch.length()) == endSearch) {
                        inScript = false;
                        size = endSearch.length();
                    }
                    else if (inScript == true && inputLineCopy.substr(0, findString.length()) == findString) {
                        ++replacementCount;
                        inputLineCopy.replace(0, findString.length(), replaceString);
                        size = replaceString.length();
                    }
                    else {
                        size = 1;
                    }
                    newLine.append(inputLineCopy.substr(0, size));
                    inputLineCopy = inputLineCopy.substr(size);
                }
                lines.push_back(newLine);
            }
            else if (inScript == true) {
                size_t location = inputLine.find(findString);
                while (location != string::npos) {
                    ++replacementCount;
                    inputLine.replace(location, findString.length(), replaceString);
                    location = inputLine.find(findString, location + replaceString.length());
                }
                lines.push_back(inputLine);
            }
            else {
                lines.push_back(inputLine);
            }
            
        }
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
                location = inputLine.find(findString, location + replaceString.length());
            }
            lines.push_back(inputLine);
        }
    }
    

};




#endif