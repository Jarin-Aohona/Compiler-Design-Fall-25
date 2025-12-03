#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPunctuation(char c) {
    string punct = ";:,(){}[]+-*/=<>";
    for (int i = 0; i < punct.length(); i++) {
        if (c == punct[i]) return true;
    }
    return false;
}

void printSample(string sample) {
    cout << sample;
    for (int i = sample.length(); i < 15; i++)
        cout << " ";

    if (sample.length() == 1 && isPunctuation(sample[0]))
        cout << "Punctuation\n";
    else
        cout << "Identifier\n";
}

void processLine(string line) {

    string sample = "";

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        if (isPunctuation(c)) {
            if (sample != "") {
                printSample(sample);
                sample = "";
            }
            string p(1, c);
            printSample(p);
        }
        else if (c == ' ' || c == '\t') {
            if (sample != "") {
                printSample(sample);
                sample = "";
            }
        }
        else {
            sample += c;
        }
    }

    if (sample != "")
        printSample(sample);

    cout << "\n";
}

bool readTxtFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Cannot open file.\n";
        return false;
    }

    string line;

    while(getline(file, line)) {
        processLine(line);
    }

    file.close();
    return true;
}

int main() {
    string filename = "sample.txt";

    if (readTxtFile(filename)) {
        cout << "Sample processing successful" << endl;
    } else {
        cout << "Error reading file.\n";
    }

    return 0;
}
