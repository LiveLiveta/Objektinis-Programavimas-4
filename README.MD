# Egzamino užduotis

##  Aprašymas

Ši C++ programa analizuoja tekstinį failą `tekstas.txt`:
- Suranda visus žodžius, jų pasikartojimų kiekį ir eilučių numerius, kur jie pasirodė.
- Atpažįsta interneto nuorodas (URL) ir išsaugo jas atskirame faile.

Programa veikia su lietuviška lokalizacija ir gali apdoroti UTF-8 simbolius.

##  Projekto struktūra

```
Egzamino uzduotis/
│
├── main.cpp              - pagrindinis programos failas
├── funkcijos.cpp         - pagalbinės funkcijos žodžių filtravimui ir URL tikrinimui
├── funkcijos.h           - funkcijų antraštės
├── pagalbines.h          - bibliotekų įtraukimas ir bendros pagalbinės funkcijos
├── tekstas.txt           - pradiniai duomenys analizei
├── zodziai.txt           - žodžių statistika
├── zodziuVietos.txt      - žodžių pozicijos tekste (eilučių numeriai)
├── nuorodos.txt          - atskirai surinktos interneto nuorodos
├── Egzamino uzduotis.sln - Visual Studio sprendinio failas
└── .gitignore            - ignoruojami Git failai
```

##  Funkcionalumas

-  Filtruoja žodžius – pašalina skyrybos ženklus, skaičius, simbolius.
-  Aptinka URL (pvz., `https://...`) ir įrašo juos į `nuorodos.txt`.
-  Skaičiuoja žodžių pasikartojimus ir fiksuoja jų atsiradimo eilutes.

##  Įvestis

Failas `tekstas.txt` turi būti UTF-8 koduotėje ir turėti paprastą tekstą su sakiniais ar URL.

##  Išvestis

- `zodziai.txt`: žodžiai, kurie pasirodo daugiau nei vieną kartą ir jų kiekis.
- `zodziuVietos.txt`: žodžiai su jų kiekiais ir eilučių numeriais.
- `nuorodos.txt`: visos aptiktos nuorodos.

##  Paleidimas

1. Atidaryk sprendimą `Egzamino uzduotis.sln` naudodamas **Visual Studio**.
2. Įsitikink, kad failas `tekstas.txt` yra tame pačiame kataloge kaip ir `.exe`.
3. Paleisk projektą (Ctrl + F5).
4. Po paleidimo sukuriami 3 išvesties failai.

##  Reikalavimai

- C++20 palaikymas
- Visual Studio 2019 ar naujesnė versija
- UTF-8 palaikymas sistemoje
