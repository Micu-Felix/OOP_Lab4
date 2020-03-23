//
// Created by Bond on 3/24/2020.
//

#ifndef LAB4_APOTHEKE_H
#define LAB4_APOTHEKE_H

#include <string>

class Apotheke{
protected:
    class Medikation{
    private:int anzahl;float concentrare,pret;std::string name;
    public:
        Medikation(){anzahl=0;};
    };

public:
    void add_med(std::string name, float concentrare, int anzahl, float pret );
    void bearbeiten(std::string name, float concentrare);
    void loschen(std::string name, float concentrare);
    void anzeigen(std::string substring);
    void sort_preis();


};
#endif //LAB4_APOTHEKE_H
