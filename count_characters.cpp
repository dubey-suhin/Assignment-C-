#include <iostream>
#include <fstream>
#include <cctype> 

using namespace std;

void countFileContent(const string &filename, int &lines, int &whitespaces, int &characters)
{
    ifstream file(filename);
    if (!file){
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        ++lines;
        characters += line.length();
        for (char c : line){
            if (isspace(c))
                ++whitespaces;
        }
    }

    // Counting newline characters as characters
    characters += lines - 1;

    file.close();
}

int main()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    int lines = 0, whitespaces = 0, characters = 0;
    countFileContent(filename, lines, whitespaces, characters);

    cout << "Number of lines: " << lines << endl;
    cout << "Number of white space characters: " << whitespaces << endl;
    cout << "Total number of characters: " << characters << endl;

    return 0;
}
