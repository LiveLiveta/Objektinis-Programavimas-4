#include "funkcijos.h"
#include "pagalbines.h"

bool YraURL(const string& zodis) {
    static const regex url_regex(R"((https?://)?(www\.)?[a-zA-Z0-9\-]+\.(lt|com|org|net|edu|gov|io|co)(/\S*)?)");
    return regex_match(zodis, url_regex);
}

string tikZodis(const string& zodis) {
    string rezultatas;
    for (char ch : zodis) {
        if (isalpha(ch)) {
            rezultatas += tolower(ch); // paliekamos tik raidės
        }
    }
    return rezultatas;
}

