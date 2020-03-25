//
// Created by Bond on 3/25/2020.
//
#include <iostream>
#include "Controller.cpp"
#include <stdio.h>
#include <string>
std::string menu() {
    return "\nMenu Apotheke Smile :-)\n"
           "Wahlen Sie ein: \n"
           "1 - Einfugen\n"
           "2 - Bearbeitung der Daten\n"
           "3 - Loschen\n"
           "4 - Undo\n"
           "5 - Redo \n"
           "6 - Gruppieren nach Preis\n"
           "7 - Anzeigen substring\n"
           "8 - Knapp\n"
           "0 - Exit\n"
           "\n";
}

bool UI() {
    std::cout << menu();
    int option;
    std::string name;
    float concentrare;
    int anzahl;
    float pret;
    while (true) {
        std::cout<<"Option:\n";
        std::cin >> option;
        switch (option) {
            case 0:
                return false;
            case 1:
                std::cout << "\nGeben Sie den Namen des Medikaments ein: ";
                std::cin >> name;
                std::cout << "\nGeben Sie die Konzentration des Medikaments ein: ";
                std::cin >> concentrare;
                std::cout << "\nGeben Sie die Anzahl des Medikaments ein: ";
                std::cin >> anzahl;
                std::cout << "\nGeben Sie den Preis des Medikaments ein: ";
                std::cin >> pret;
                Smile.add_med(name, concentrare, anzahl, pret);
                break;
            case 2:
                std::cout << "\nGeben Sie den Namen des Medikaments ein: ";
                std::cin >> name;
                std::cout << "\nGeben Sie die Konzentration des Medikaments ein: ";
                std::cin >> concentrare;
                std::cout << "\nGeben Sie die neue Anzahl des Medikaments ein: ";
                std::cin >> anzahl;
                std::cout << "\nGeben Sie den neuen Preis des Medikaments ein: ";
                std::cin >> pret;
                if (Smile.bearbeiten(name, concentrare, anzahl, pret))
                    std::cout << "Daten wurden bearbeitet\n";
                else
                    std::cout << "Nicht gefunden!!!\n";
                break;

            case 3:

                std::cout << "\nGeben Sie den Namen des Medikaments ein: ";
                std::cin >> name;
                std::cout << "\nGeben Sie die Konzentration des Medikaments ein: ";
                std::cin >> concentrare;
                Smile.loschen(name, concentrare);
                break;
            case 4:
                Smile.undo();
                break;
            case 5:
                Smile.redo();
                break;
            case 6:
                Smile.sort_preis();
                break;
            case 7:
                std::cout
                        << "Geben Sie den Substring ein oder * um alle Medikamente anzuzeigen(nach Name sortiert): \n";
                std::cin>>name;
                Smile.anzeigen(name);
                break;
            case 8:
                int x;
                std::cout << "Knapp bedeutet kleiner als: ";
                std::cin >> x;
                Smile.knapp(x);
                break;
            default:
                break;

        }
    }
}
