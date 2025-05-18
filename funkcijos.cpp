#include <funkcijos.h>

bool YraURL(const string& zodis) {
    static const regex url_regex(R"((https?://)?(www\.)?[a-zA-Z0-9\-]+\.(lt|com|org|net|edu|gov|io|co)(/\S*)?)");
    return regex_match(zodis, url_regex);
}
