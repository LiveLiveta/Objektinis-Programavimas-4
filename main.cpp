#include "funkcijos.h"
#include "pagalbines.h"

int main() {

    try {
        locale::global(locale(::setlocale(LC_ALL, "lt_LT.UTF-8")));
    }
    catch (runtime_error& e) {
        cout << "Kai kurie tarptautiniø kalbø simboliai gali bûti rodomi ne taip, kaip tikëtasi.." << e.what() << endl;
    }

    wifstream ivestis("tekstas.txt");

    if (!ivestis.is_open()) {
        cout << "Nepavyko atidaryti failo text.txt" << endl;
        return 1;
    }

    ifstream NuoroduPabaiguFailas("NuoroduPabaigos.txt");
    if (!NuoroduPabaiguFailas) {
        cout << "Nepavyko atidaryti NuoroduPabaigos.txt" << endl;
        return 1;
    }

    ostringstream NuoroduPabaigos;
    NuoroduPabaigos << "(";

    string NuoroduPabaigosEilutesIndeksas;
    bool first = true;

    while (getline(NuoroduPabaiguFailas, NuoroduPabaigosEilutesIndeksas)) {
        if (!NuoroduPabaigosEilutesIndeksas.empty()) {
            if (!first) {
                NuoroduPabaigos << "|";
            }
            NuoroduPabaigos << NuoroduPabaigosEilutesIndeksas;
            first = false;
        }
    }

    NuoroduPabaigos << ")";
    NuoroduPabaiguFailas.close();

    string NuoroduPabaigosSuformatuotos = NuoroduPabaigos.str();

    wofstream zodzioIrasymas("zodziai.txt");
    wofstream nuorodosIrasymas("nuorodos.txt");
    wofstream zodziuVietuIrasymsa("zodziuVietos.txt");

    unordered_map<wstring, pair<int, set<int>>> zodzioInfo;
    set<wstring> nuorodos;

    wstring eilute;
    int eilesNumeris = 0;

    while (getline(ivestis, eilute)) {
        eilesNumeris++;
        wstringstream ss(eilute);
        wstring zodis;

        while (ss >> zodis) {
            if (YraURL(zodis, NuoroduPabaigosSuformatuotos)) {
                nuorodos.insert(zodis);
                continue;
            }

            wstring tikrasZodis = tikZodis(zodis);
            if (!tikrasZodis.empty()) {
                zodzioInfo[tikrasZodis].first++;
                zodzioInfo[tikrasZodis].second.insert(eilesNumeris);
            }
        }
    }

    zodzioIrasymas << left << setw(15) << "Zodis"
        << setw(10) << "Kiekis" << endl;

    for (const auto& [zodis, info] : zodzioInfo) {
        if (info.first > 1) {
            zodzioIrasymas << left << setw(15) << zodis
                << setw(10) << info.first << endl;
        }
    }

    zodziuVietuIrasymsa << left << setw(15) << "Zodis"
        << setw(10) << "Kiekis"
        << "Eilutës" << endl;

    for (const auto& [zodis, info] : zodzioInfo) {
        if (info.first > 1) {
            zodziuVietuIrasymsa << left << setw(15) << zodis
                << setw(10) << info.first;

            for (int eilNumeris : info.second) {
                zodziuVietuIrasymsa << eilNumeris << " ";
            }
            zodziuVietuIrasymsa << endl;
        }
    }

    for (const wstring& nuoroda : nuorodos) {
        nuorodosIrasymas << nuoroda << endl;
    }

    ivestis.close();
    zodzioIrasymas.close();
    nuorodosIrasymas.close();
    zodziuVietuIrasymsa.close();

    cout << "Sëkmingai baigta." << endl;


    return 0;
}