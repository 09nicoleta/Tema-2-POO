#include <iostream>
#include<fstream>
#include "Meniu.h"
#include "MeniuSpecial.h"
#include "PreparatePrincipale.h"
#include "Bauturi.h"
#include "MasaRestaurant.h"
#include "Zi.h"

int main(){

    std::vector<Zi> saptamana;
    std::ifstream f("tastatura.in");
    std::vector<std::string> zile_sapt={"luni","marti","miercuri","joi","vineri","sambata","duminica"};
    if(f){
    int x,i,n;
    //Se citeste ordinul zilei din saptamana

    while(f>>x){
    Zi zi{zile_sapt[x-1]};  
    //Se citeste numarul de mese la care au stat clientii
    f>>n;
    for(i=0;i<n;i++){
        MasaRestaurant masa;
        f>>masa;
        zi.adaugare(masa);
    }
    saptamana.emplace_back(zi);
    }
    
    for(auto &zii:saptamana)
        std::cout<<zii;
}
    f.close();

    return 0;
}
