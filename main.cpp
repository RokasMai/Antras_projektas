#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>

int main() {
    char pasirinkimas;
    std::list<Studentas> studentai;

    std::cout << "Pasirinkite buda, kaip vesti duomenis (I - ivesti ranka, S - skaityti is failo, G - generuoti atsitiktinai, F - generuoti failus): ";
    std::cin >> pasirinkimas;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Išvalo buferį

    auto startViso = std::chrono::high_resolution_clock::now(); // Pradedame matuoti laiką

    if (pasirinkimas == 'I') {
        auto startNuskaitymas = std::chrono::high_resolution_clock::now();
        ivestiDuomenisRanka(studentai);
        auto endNuskaitymas = std::chrono::high_resolution_clock::now();
        auto durationNuskaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endNuskaitymas - startNuskaitymas);
        std::cout << "Duomenu nuskaitymas uztruko " << durationNuskaitymas.count() << "ms" << std::endl;
    } else if (pasirinkimas == 'S') {
        auto startNuskaitymas = std::chrono::high_resolution_clock::now();
        std::string failoPavadinimas;
        std::cout << "Iveskite failo pavadinima (su pilnu keliasu, jei failas yra kitoje vietoje): ";
        std::cin >> failoPavadinimas;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Išvalo buferį

        skaitytiDuomenisIsFailo(studentai, failoPavadinimas);
        auto endNuskaitymas = std::chrono::high_resolution_clock::now();
        auto durationNuskaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endNuskaitymas - startNuskaitymas);
        std::cout << "Duomenu nuskaitymas uztruko " << durationNuskaitymas.count() << "ms" << std::endl;
    } else if (pasirinkimas == 'G') {
        auto startNuskaitymas = std::chrono::high_resolution_clock::now();
        generuotiDuomenis(studentai);
        auto endNuskaitymas = std::chrono::high_resolution_clock::now();
        auto durationNuskaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endNuskaitymas - startNuskaitymas);
        std::cout << "Duomenu nuskaitymas uztruko " << durationNuskaitymas.count() << "ms" << std::endl;
    } else if (pasirinkimas == 'F') {
        auto startNuskaitymas = std::chrono::high_resolution_clock::now();
        generuotiFailus();
        auto endNuskaitymas = std::chrono::high_resolution_clock::now();
        auto durationNuskaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endNuskaitymas - startNuskaitymas);
        std::cout << "Duomenu nuskaitymas uztruko " << durationNuskaitymas.count() << "ms" << std::endl;
        return 0;  // Programa baigia darbą po failų generavimo.
    } else {
        std::cout << "Neteisingas pasirinkimas. Programa baigia darbą." << std::endl;
        return 1;
    }

    std::string skaiciavimoBudas;
    std::cout << "Pasirinkite skaiciavimo buda (Vid arba Med): ";
    std::cin >> skaiciavimoBudas;

    auto startRusiavimas = std::chrono::high_resolution_clock::now();//pradedamas matuoti rusiavimo laikas
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.vardas < b.vardas;
    });
    auto endRusiavimas = std::chrono::high_resolution_clock::now();//baigia matuoti rusiavimo laika
    auto durationRusiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas);
    std::cout << "Rusiavimas uztruko " << durationRusiavimas.count() << "ms" << std::endl;

    std::cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << skaiciavimoBudas << std::endl;
    std::cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << std::endl;

    auto startIsvedimas = std::chrono::high_resolution_clock::now();
    for (const auto& studentas : studentai) {
        std::cout << std::left << std::setw(20) << studentas.vardas << std::setw(20) << studentas.pavarde
                  << std::fixed << std::setprecision(2) << skaiciuotiGalutiniBala(studentas, skaiciavimoBudas) << std::endl;
    }
    auto endIsvedimas = std::chrono::high_resolution_clock::now();//baigia matuoti isvedimo laika
    auto durationIsvedimas = std::chrono::duration_cast<std::chrono::milliseconds>(endIsvedimas - startIsvedimas);
    std::cout << "Isvedimas uztruko " << durationIsvedimas.count() << "ms" << std::endl;

    auto endViso = std::chrono::high_resolution_clock::now(); // Baigti matuoti laiką
    auto durationViso = std::chrono::duration_cast<std::chrono::milliseconds>(endViso - startViso);
    std::cout << "Visas vykdymas uztruko " << durationViso.count() << "ms" << std::endl;

    return 0;
}
