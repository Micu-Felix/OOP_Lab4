//
// Created by Bond on 3/25/2020.
//
#include "RepoMedikament.h"
#include "assert.h"

void Teste() {
    RepoMedikament Smile;
    assert(Smile.Grosse() == 0);
    Smile.add_med("Xanax", 50, 21, 300);
    assert(Smile.Grosse() == 1);
    Smile.add_med("Xanax", 50, 21, 300);
    Smile.add_med("Paracetamol", 25, 2, 30);
    assert(Smile.Grosse() == 2);
    Smile.add_med("Parasinus", 25, 2, 30);
    assert(Smile.Grosse() == 3);
    Smile.undo();
    assert(Smile.Grosse() == 2);
    Smile.redo();
    assert(Smile.Grosse() == 3);
    Smile.loschen("Paracetamol", 25);

    assert(Smile.Grosse() == 2);
    Smile.add_med("Danax", 50, 21, 300);
    Smile.add_med("Ranax", 50, 21, 300);
    Smile.loschen("Danax", 50);
    assert(Smile.Grosse() == 3);
    //Smile.anzeigen("*");
    Smile.sort_preis();
    //Smile.anzeigen("*");
    std::cout << '\n' << "Tests over" << '\n';
}