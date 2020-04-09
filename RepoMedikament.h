//
// Created by Bond on 3/24/2020.
//
#pragma once
#ifndef LAB4_REPOMEDIKAMENT_H
#define LAB4_REPOMEDIKAMENT_H

#include <string>
#include <vector>
#include "Medikament.h"

class RepoMedikament {
private:
    bool undone = false;
    std::vector<Medikament *> medicamente, update_vect;

    void update();

public:
    /**
     * Einfugen Medikament
     * @param name
     * @param concentrare
     * @param anzahl
     * @param pret
     */
    void add_med(const std::string& name, float concentrare, int anzahl, float pret);

    /**
     * Loschen eines Medikaments
     * @param name
     * @param concentrare
     */
    void loschen(const std::string& name, float concentrare);

    /**
     * Anzeigen alle Medikamente, dessen Anzahl kleiner ist als der eingegebene Wert
     * @param x
     */
    void knapp(int x);

    /**
     * Zeigt alle Medikamente falls der Eingabewert * ist, andernfalls der Medikament der den eingegebenen String in den Namen
     *   enthalt
     * @param substring
     */
    void anzeigen(const std::string& substring);

    /**
     * Gruppiert die Medikamente nach dem Preis
     */
    void sort_preis();

    void undo();

    void redo();

/**
 * Methode benutzt fur die Tests
 * @return
 */
    int Grosse();

/**
 * Bearbeitet die Daten eines Medikaments(ausser den unique id: name und konzentration)
 * @param name
 * @param concentrare
 * @param anz
 * @param pret
 * @return
 */
    bool bearbeiten(const std::string& name, float concentrare, int anz, float pret);
};

#endif //LAB4_REPOMEDIKAMENT_H
