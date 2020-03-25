//
// Created by Bond on 3/25/2020.
//

#ifndef LAB4_MEDIKAMENT_H
#define LAB4_MEDIKAMENT_H


class Medikament {
private:
    int anzahl;
    float concentrare, pret;
    std::string name;

public:
    int get_anz() { return anzahl; };

    float get_preis() { return pret; };

    float get_concentrare() { return concentrare; };

    std::string get_name() { return name; };

    void set_anz(int anz) { anzahl = anz; };

    void set_name(std::string nume) { name = nume; };

    void set_concentrare(float concent) { concentrare = concent; };

    void set_preis(float pr) { pret = pr; };
//Konstruktor
    Medikament(std::string name, float concentrare, int anzahl, float pret) {
        set_anz(anzahl);
        set_concentrare(concentrare);
        set_preis(pret);
        set_name(name);

    };

};


#endif //LAB4_MEDIKAMENT_H
