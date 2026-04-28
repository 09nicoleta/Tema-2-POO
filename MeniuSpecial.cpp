#include "MeniuSpecial.h"
#include<iostream>

//Constructor
MeniuSpecial::MeniuSpecial(std::vector<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();
}
MeniuSpecial::MeniuSpecial(std::initializer_list<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();

}

std::shared_ptr<Meniu> MeniuSpecial::clone() const{
    return std::make_shared<MeniuSpecial>(*this);
}

void MeniuSpecial::afisare(std::ostream &os) const{
    if(!comanda.empty()){
    std::cout<<"\n<Meniu Special>\n";
    for (auto &com:comanda)          
        os<<" - "<<com.first<<"\n";
}
}
float MeniuSpecial::total_plata_() const{
    float plata=0;
    for (auto &com:comanda)
        plata+=com.second;

    return plata;
}

void MeniuSpecial::citire(std::istream& in) {
    int n;
    in >> n;
    for(int i = 0; i < n; i++) {
        std::string nume;
        float pret;
        in >> nume >> pret;
        comanda.emplace_back(nume, pret);
    }
}

