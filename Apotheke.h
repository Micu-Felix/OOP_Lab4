//
// Created by Bond on 3/24/2020.
//
#pragma once
#ifndef LAB4_APOTHEKE_H
#define LAB4_APOTHEKE_H

#include <string>
#include <vector>
class Apotheke{

protected:
    class Medikation{
    private:int anzahl;float concentrare,pret;std::string name;

    public:
        int get_anz(){return anzahl;};
        float get_pret(){ return pret;};
        float get_concentrare(){ return concentrare;};
        std::string get_name(){ return name;};
        void set_anz(int anz){anzahl=anz;};
        void set_name(std::string nume){name=nume;};
        void set_concent(float concent){concentrare=concent;};
        void set_pr(float pr){pret=pr;};
        Medikation(std::string name, float concentrare, int anzahl, float pret ){set_anz(anzahl);
        set_concent(concentrare);set_pr(pret);
        set_name(name);

        };
    };
private:
    std::vector<Medikation*> medicamente;

public:
    void add_med(std::string name, float concentrare, int anzahl, float pret );
    void bearbeiten(std::string name, float concentrare);
    void loschen(std::string name, float concentrare);
    void anzeigen(std::string substring);
    void sort_preis();


};
#endif //LAB4_APOTHEKE_H
