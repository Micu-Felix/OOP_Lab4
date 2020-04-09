//
// Created by Bond on 3/24/2020.
//
#include "RepoMedikament.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "Medikament.h"

void RepoMedikament::update() {
    update_vect = medicamente;
}


void RepoMedikament::add_med(const std::string &name, float concentrare, int anzahl, float pret) {
    update();
    /*int already_exists = 0;
    for (auto &iter : medicamente) {
        if (iter->get_name() == name && iter->get_concentrare() == concentrare) {
            already_exists = 1;
            iter->set_anz(iter->get_anz() + anzahl);
        }
    }
    if (!already_exists) {
        medicamente.push_back(new Medikament(name, concentrare, anzahl, pret));
    }
*/

    auto it = find_if(medicamente.begin(), medicamente.end(), [=](Medikament *obj) {
        return (obj->get_name() == name && obj->get_concentrare() == concentrare);
    });
    if (it != medicamente.end()) {
        int index = std::distance(medicamente.begin(), it);
        medicamente[index]->set_anz(medicamente[index]->get_anz() + anzahl);
    } else {
        medicamente.push_back(new Medikament(name, concentrare, anzahl, pret));
    }
}


struct greater_than_key_name {
    inline bool operator()(Medikament *struct1, Medikament *struct2) {
        return ((struct1)->get_name() > (struct2)->get_name());
    }
};

void RepoMedikament::anzeigen(const std::string &substring) {
    if (substring == "*") {
        /*for (auto iter = medicamente.begin(); iter != medicamente.end() - 1; iter++) {
            for (auto itersec = medicamente.begin() + 1; itersec != medicamente.end(); itersec++) {
                if ((*iter)->get_name() > (*itersec)->get_name()) {
                    iter_swap(iter, itersec);
                }
            }
        }*/
        std::sort(medicamente.begin(), medicamente.end(), greater_than_key_name());
        for (auto &iter : medicamente) {
            std::cout << "Das Medikament: " << iter->get_name() << " mit der Konzentration: "
                      << iter->get_concentrare() << '\n';
        }
    } else {
        for (auto &iter : medicamente) {
            if ((iter->get_name()).find(substring) != std::string::npos) {
                std::cout << "Val este: " << (iter->get_name()).find(substring) << '\n';
                std::cout << "Das Medikament: " << iter->get_name() << " mit der Konzentration: "
                          << iter->get_concentrare() << '\n';
            }
        }
    }
}

void RepoMedikament::knapp(int x) {

    std::cout << '\n' << "Die Medikamente die knapp sind, sind: " << '\n';
    for (auto &iter : medicamente) {
        if (iter->get_anz() < x) {
            std::cout << "Das Medikament: < " << iter->get_name() << " > mit der Konzentration: "
                      << iter->get_concentrare() << '\n';
        }
    }
}

void RepoMedikament::loschen(const std::string &name, float concentrare) {
    update();
    /*for (auto iter = medicamente.begin(); iter != medicamente.end(); iter++) {
        if ((*iter)->get_name() == name && (*iter)->get_concentrare() == concentrare) {
            medicamente.erase(iter);
            break;
        }
    }*/
    auto endv_med = std::remove_if(begin(medicamente), end(medicamente), [=](Medikament *med) {
        return ((med->get_name() == name) && (med->get_concentrare() == concentrare));
    });
    medicamente.erase(endv_med, end(medicamente));
}

struct greater_than_key_preis {
    inline bool operator()(Medikament *struct1, Medikament *struct2) {
        return ((struct1)->get_preis() > (struct2)->get_preis());
    }
};

void RepoMedikament::sort_preis() {
    std::cout << '\n' << "Liste der Medikamente wurde gruppiert!! " << '\n';
    /*for (auto iter = medicamente.begin(); iter != medicamente.end() - 1; iter++) {
        for (auto itersec = medicamente.begin() + 1; itersec != medicamente.end(); itersec++) {
            if ((*iter)->get_preis() > (*itersec)->get_preis()) {
                iter_swap(iter, itersec);
            }
        }
    }*/
    std::sort(medicamente.begin(), medicamente.end(), greater_than_key_preis());
}


void RepoMedikament::undo() {
    medicamente.swap(update_vect);
    undone = true;
}

void RepoMedikament::redo() {
    if (undone)
        undo();
    else
        std::cout << "No action to redo" << '\n';
}

int RepoMedikament::Grosse() {
    return medicamente.size();
}

bool RepoMedikament::bearbeiten(const std::string &name, float concentrare, int anz, float pret) {

    for (auto &iter : medicamente) {
        if (iter->get_name() == name && iter->get_concentrare() == concentrare) {
            iter->set_anz(anz);
            iter->set_preis(pret);
            return true;


        }
    }
    return false;
}