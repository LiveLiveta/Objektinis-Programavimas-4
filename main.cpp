#include "funkcijos.h"
#include "pagalbines.h"

int main() {

    ifstream input("text.txt");

    if (!input.is_open()) {
        cout << "Nepavyko atidaryti failo text.txt" << endl;
        return 1;
    }

    ofstream wordOutput("words.txt");
    ofstream urlOutput("urls.txt");
    ofstream xrefOutput("xref.txt");

    unordered_map<string, pair<int, set<int>>> wordInfo;
    set<string> urls;

    string line;
    int lineNum = 0;

    while (getline(input, line)) {
        lineNum++;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            if (YraURL(word)) {
                urls.insert(word);
                continue;
            }

            string tikrasZodis = tikZodis(word);
            if (!tikrasZodis.empty()) {
                wordInfo[tikrasZodis].first++;
                wordInfo[tikrasZodis].second.insert(lineNum);
            }
        }
    }
    return 0;
}