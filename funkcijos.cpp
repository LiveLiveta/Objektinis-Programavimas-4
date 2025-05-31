#include "funkcijos.h"
#include "pagalbines.h"


bool YraURL(const wstring& zodis, const string& NuoroduPabaigosSuformatuotos) {
    // Turi būti: \. prieš grupę (reikalinga pabėgti tašką!)
    string RegexSablonas = R"((https?://)?(?:[a-zA-Z0-9\-]+\.)+)" + NuoroduPabaigosSuformatuotos + R"((/\S*)?)";

    wstring Sablonas(RegexSablonas.begin(), RegexSablonas.end());
    wregex RegexNuoroda(Sablonas, regex_constants::icase);

    return regex_match(zodis, RegexNuoroda);
}


wstring tikZodis(const wstring& zodis) {
    
    const set<wchar_t> simboliai = {
        L'.', L',', L';', L':', L'!', L'?', L'-', L'(', L')', L'[', L']', L'{', L'}', L'\'', L'"', L'/', L'\\', L'|', L'@', L'#', L'$', L'%', L'^', L'&', L'*', L'_', L'+', L'=', L'<', L'>', L'`', L'~',
        L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'0',
        L'\x2014',  // : (em dash)
        L'\x2013',  // : (en dash)
        L'\x2212',  // : (minus sign)
        L'\x2010',  // : (hyphen)
        L'\x2012',  // : (figure dash)
        L'\x2015',  // : (horizontal bar)

        // Ypatingos kabutes
        L'\x201E',  // „ (double low-9 quotation mark)
        L'\x201C',  // " (double high-6 quotation mark)
    };

    wstring rezultatas;
    for (wchar_t ch : zodis) {
        if (!simboliai.contains(ch)) {
            rezultatas += towlower(ch); // paliekamos tik raidės
        }
    }
    return rezultatas;
}

