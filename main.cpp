#include "funkcijos.h"
#include "pagalbines.h"

int main() {

    ifstream ivestis("tekstas.txt");

    if (!ivestis.is_open()) {
        cout << "Nepavyko atidaryti failo tekstas.txt" << endl;
        return 1;
    }

    ofstream zodzioIrasymas("zodziai.txt");
    ofstream nuorodosIrasymas("nuorodos.txt");
    ofstream zodziuVietuIrasymsa("zodziuVietos.txt");

    unordered_map<string, pair<int, set<int>>> zodzioInfo;
    set<string> nuorodos;

    string eilute;
    int eilesNumeris = 0;

    while (getline(ivestis, eilute)) {
        eilesNumeris++;
        stringstream ss(eilute);
        string zodis;

        while (ss >> zodis) {
            string isvalytas = zodis;
            while (!isvalytas.empty() && ispunct(isvalytas.back())) {
                isvalytas.pop_back();
            }
            if (YraURL(isvalytas)) {
                nuorodos.insert(isvalytas);
                continue;
            }

            string tikrasZodis = tikZodis(zodis);
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
               << "Eilutės" << endl;

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

    for (const string& nuoroda : nuorodos) {
        nuorodosIrasymas << nuoroda << endl;
    }

    ivestis.close();
    zodzioIrasymas.close();
    nuorodosIrasymas.close();
    zodziuVietuIrasymsa.close();

    cout << "Sekmingai baigta." << endl;


    return 0;
}