#include "Zi.h"
#include<iostream>

//Constructor
Zi::Zi(const std::string & zi="null"):zi{zi}{}

void Zi::adaugare(const MasaRestaurant &m){
    mese_ocupate.emplace_back(m);
}

std::ostream &operator<<(std::ostream & os, const Zi & z){
    std::cout<<"Activitatea restaurantului in ziua de "<<z.zi<<'\n';
    for(const auto &activitate: z.mese_ocupate){
        os<<activitate;
    }
    return os;
}


