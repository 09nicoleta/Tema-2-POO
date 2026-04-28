#ifndef BAUTURI_H
#define BAUTURI_H

#include<vector>
#include<memory>
#include<utility>
#include<string>
#include "Meniu.h"

class Bauturi: public Meniu{
    
    // pair<nume preparat, pret>
    std::vector<std::pair<std::string, float>> comanda;
    void afisare(std::ostream &os) const override;
    float total_plata_()const override;
    public:
    //Constructor
    Bauturi(std::vector<std::pair<std::string,float>>comanda);
    Bauturi()=default;
    //La declararea obiectelor, utilizarea acoladelor atrage folosirea acestui constructor
    Bauturi(std::initializer_list<std::pair<std::string,float>>comanda);

    std::shared_ptr<Meniu> clone() const override;
    void citire(std::istream & in ) override;
};

#endif