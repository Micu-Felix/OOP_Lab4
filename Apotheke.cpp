//
// Created by Bond on 3/24/2020.
//
#include "Apotheke.h"
#include <algorithm>
#include <iostream>
#include <string.h>

void Apotheke::add_med(std::string name, float concentrare, int anzahl, float pret) {
    int already_exists = 0;
    for (auto iter = medicamente.begin(); iter != medicamente.end(); iter++) {
        if ((*iter)->get_name() == name && (*iter)->get_concentrare() == concentrare) {
            already_exists = 1;
            (*iter)->set_anz((*iter)->get_anz() + anzahl);
        }
    }
    if (!already_exists) {
        medicamente.push_back(new Medikation(name, concentrare, anzahl, pret));
    }

}

void Apotheke::anzeigen(std::string substring) {
    if (substring=="" )
        for (auto iter = medicamente.begin(); iter != medicamente.end(); iter++) {
            std::cout << "Das Medikament: " << (*iter)->get_name() << " mit der Konzentration: "
                      << (*iter)->get_concentrare() << '\n';
        }
}

void Apotheke::knapp() {
    int x;
    std::cout << "Knapp bedeutet kleiner als: ";
    std::cin >> x;
    std::cout << '\n' << "Die Medikamente die knapp sind, sind: " << '\n';
    for (auto iter = medicamente.begin(); iter != medicamente.end(); iter++) {
        if ((*iter)->get_anz() < x) {
            std::cout << "Das Medikament: < " << (*iter)->get_name() << " > mit der Konzentration: "
                      << (*iter)->get_concentrare() << '\n';
        }
    }
}
