#include "PreparatePrincipale.h"
#include<iostream>

//Constructor
PreparatePrincipale::PreparatePrincipale(std::vector<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();
}
PreparatePrincipale::PreparatePrincipale(std::initializer_list<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();
}

//Vezi dc trb Meniu acolo dar cred ca e asa ca e efectiv polimorfism si suprascrii functia cu =0;
std::shared_ptr<Meniu> PreparatePrincipale::clone() const{
    return std::make_shared<PreparatePrincipale>(*this);
}

void PreparatePrincipale::afisare(std::ostream &os) const{
    if(!comanda.empty()){
    std::cout<<"\n<Meniu Principal>\n";
    for (auto &com:comanda)          
        os<<" - "<<com.first<<"\n";
    }
}

float PreparatePrincipale::total_plata_() const{
    float plata=0;
    for (auto &com:comanda)
        plata+=com.second;

    return plata;
}

void PreparatePrincipale::citire(std::istream & in){
    int n;
    in >> n;
    for(int i = 0; i < n; i++) {
        std::string nume;
        float pret;
        in >> nume >> pret;
        comanda.emplace_back(nume, pret);
    }
}