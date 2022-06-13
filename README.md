# Directory_Replacement
Use this program to replace all instances of a word/phrase within a directory with another word/phrase
## Set Up
All edits to be made before you run the program are found in `main.cpp` lines 15-18:
```
string START_DIRECTORY = "/mnt/e/theWebRoot";
set<string> EXTENSIONS_TO_READ({".js", ".css", ".htm", ".html", ".txt", ".config"});
string FIND = "alumnitoolsdev";
string REPLACE_WITH = "alumnitools";
```
The `START_DIRECTORY` is the directory from which to recursively search for more directories and files.
The `EXTENSIONS_TO_READ` is a set containing all filetypes from which to look for words that need to be replaced.
The `FIND` string is the word/phrase to be found and replaced within the `EXTENSIONS_TO_READ` filetypes.
The `REPLACE_WITH` string is the word/phrase that will replace every instance of the `FIND` string.
## Compile
`make`
## Run
`make run`
## Notes
The running of this program will generate two additional files in the `Directory_Replacement` directory:

`Files_Read.txt` contains a list of all files that were searched for the `FIND` string.
`Files_Written.txt` contains a list of all files that contained the `FIND` string and were thus rewritten with the `REPLACE_WITH` string.

Finally, when the program terminates, the number of replacements made is displayed.