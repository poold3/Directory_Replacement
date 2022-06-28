# Directory_Replacement
Use this program to replace all instances of a word/phrase within a directory with another word/phrase
## Set Up
All edits to be made before you run the program are found in `main.cpp` lines 13-19:
```
string START_DIRECTORY = "/mnt/c/Documents/Project1";
set<string> EXTENSIONS_TO_READ({".cpp", ".h", ".txt"});
string FIND = "testfile.txt";
string REPLACE_WITH = "file.txt";

string BEGIN_SEARCH = ".open(";
string END_SEARCH = ")";
```
The `START_DIRECTORY` is the directory from which to recursively search for more directories and files.
The `EXTENSIONS_TO_READ` is a set containing all filetypes from which to look for words that need to be replaced.
The `FIND` string is the word/phrase to be found and replaced within the `EXTENSIONS_TO_READ` filetypes.
The `REPLACE_WITH` string is the word/phrase that will replace every instance of the `FIND` string.
The `BEGIN_SEARCH` and `END_SEARCH` strings are optional constants that when defined will tell the program to only search for the `FIND` string after the `BEGIN_SEARCH` string and before the `END_SEARCH` string.
## Example One:
Set Constants:
```
string START_DIRECTORY = "/mnt/c/Documents/Project1";
set<string> EXTENSIONS_TO_READ({".cpp", ".h", ".txt"});
string FIND = "testfile.txt";
string REPLACE_WITH = "file.txt";

string BEGIN_SEARCH = "";
string END_SEARCH = "";
```
Original version of a .cpp file within the `Project1` directory:
```
ifstream inFile;
inFile.open("testfile.txt");
if (!inFile.is_open()) {
    ThrowError("Unable to open testfile.txt);
}
```
Updated version of the .cpp file within the `Project1` directory:
```
ifstream inFile;
inFile.open("file.txt");
if (!inFile.is_open()) {
    ThrowError("Unable to open file.txt);
}
```
## Example Two:
Set Constants:
```
string START_DIRECTORY = "/mnt/c/Documents/Project1";
set<string> EXTENSIONS_TO_READ({".cpp", ".h", ".txt"});
string FIND = "testfile.txt";
string REPLACE_WITH = "file.txt";

string BEGIN_SEARCH = ".open(";
string END_SEARCH = ")";
```
Original version of a .cpp file within the `Project1` directory:
```
ifstream inFile;
inFile.open("testfile.txt");
if (!inFile.is_open()) {
    ThrowError("Unable to open testfile.txt);
}
```
Updated version of the .cpp file within the `Project1` directory:
```
ifstream inFile;
inFile.open("file.txt");
if (!inFile.is_open()) {
    ThrowError("Unable to open testfile.txt);
}
```
## Notes
The running of this program will generate two additional files in the `Directory_Replacement` directory:

`Files_Read.txt` contains a list of all files that were searched for the `FIND` string.
`Files_Written.txt` contains a list of all files that contained the `FIND` string and were thus rewritten with the `REPLACE_WITH` string.

Finally, when the program terminates, the number of replacements made is displayed.