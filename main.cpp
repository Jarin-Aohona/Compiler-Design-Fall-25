#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("sample.txt");
    string word;

    if (!file) {
        cout << "Error: Could not open sample.txt file!" << endl;
        return 0;
    }

    cout << "Checking identifiers from sample.txt:\n\n";

    while (file >> word) {


        int len = word.length();
        if (word[len - 1] == ';')
            word = word.substr(0, len - 1);

        // skip keywords
        if (word == "int" || word == "float" || word == "double" ||
            word == "char" || word == "string")
            continue;

        bool valid = true;


        if (!((word[0] >= 'A' && word[0] <= 'Z') ||
              (word[0] >= 'a' && word[0] <= 'z') ||
               word[0] == '_')) {
            valid = false;
        }


        for (int i = 1; i < word.length(); i++) {
            char ch = word[i];
            if (!((ch >= 'A' && ch <= 'Z') ||
                  (ch >= 'a' && ch <= 'z') ||
                  (ch >= '0' && ch <= '9') ||
                   ch == '_')) {
                valid = false;
                break;
            }
        }

        if (valid)
            cout << word << " ---> Valid Identifier " << endl;
        else
            cout << word << " ---> Invalid Identifier " << endl;
    }

    file.close();
    return 0;
}
