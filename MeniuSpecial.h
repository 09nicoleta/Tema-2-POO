#ifndef MENIUSPECIAL_H
#define MENIUSPECIAL_H

#include<vector>
#include<memory>
#include<utility>
#include<string>
#include "Meniu.h"

class MeniuSpecial: public Meniu{
    
    // pair<nume preparat, pret>
    std::vector<std::pair<std::string, float>> comanda;
    void afisare(std::ostream &os) const override;
    float total_plata_()const override;

    public:
    //Constructor
    MeniuSpecial(std::vector<std::pair<std::string,float>>comanda);
    MeniuSpecial()=default;
    //La declararea obiectelor, utilizarea acoladelor atrage folosirea acestui constructor
    MeniuSpecial(std::initializer_list<std::pair<std::string,float>>comanda);

    std::shared_ptr<Meniu> clone() const override;
    void citire(std::istream &in) override;
};

#endif