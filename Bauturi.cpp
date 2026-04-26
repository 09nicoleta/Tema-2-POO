#include "Bauturi.h"
#include<iostream>

//Constructor
Bauturi::Bauturi(std::vector<std::pair<std::string,float>>comanda={}):comanda{comanda}{}
Bauturi::Bauturi(std::initializer_list<std::pair<std::string,float>>comanda={}):comanda{comanda}{}

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