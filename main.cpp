#include <iostream>
#include "Apotheke.h"
int main() {
    std::cout << "Hello Lab4" << std::endl;
    Apotheke Smile;
    Smile.add_med("Xanax",50,21,300);
    Smile.add_med("Xanax",50,21,300);
    Smile.add_med("Paracetamol",25,2,30);
    Smile.anzeigen("ceva");
    Smile.knapp();
    return 0;
}
