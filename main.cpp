#include <iostream>
#include "Meniu.h"
#include "MeniuSpecial.h"
#include "PreparatePrincipale.h"
#include "Bauturi.h"
#include "MasaRestaurant.h"
#include "MasaRestaurant.h"
#include "Zi.h"

int main(){
    MasaRestaurant x1{{MeniuSpecial{{"fel1",12},{"fel2",20}}.clone(),
    Bauturi{{"b1",10},{"b2",3}}.clone()},
    10,20};

    MasaRestaurant x2{{MeniuSpecial{{"fel1",12},{"fel2",20}}.clone(),
    Bauturi{{"b1",10},{"b2",3}}.clone()},
    5,20};

    MasaRestaurant x3{{PreparatePrincipale{{"fel1",12},{"fel2",20}}.clone(),
    Bauturi{{"b1",10},{"b2",3}}.clone()},
    8,20};
  
    Zi z1{"luni"};
    z1.adaugare(x1);
    z1.adaugare(x2);
    z1.adaugare(x3);
    std::cout<<z1;
    
    return 0;
}