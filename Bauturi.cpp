#include "Bauturi.h"
#include<iostream>

//Constructor
Bauturi::Bauturi(std::vector<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();
}
Bauturi::Bauturi(std::initializer_list<std::pair<std::string,float>>comanda={}):comanda{comanda}{
    venit_total+=total_plata_();
}

std::shared_ptr<Meniu> Bauturi::clone() const{
    return std::make_shared<Bauturi>(*this);
}

void Bauturi::afisare(std::ostream &os) const{
    if(!comanda.empty()){
    std::cout<<"\n<Bauturi>\n";
    for (auto &com:comanda)          
        os<<" - "<<com.first<<"\n";
}
}

float Bauturi::total_plata_() const{
    float plata=0;
    for (auto &com:comanda)
        plata+=com.second;

    return plata;
}

void Bauturi::citire(std::istream & in ){
    int n;
    in >> n;
    for(int i = 0; i < n; i++) {
        std::string nume;
        float pret;
        in >> nume >> pret;
        comanda.emplace_back(nume, pret);
    }
}