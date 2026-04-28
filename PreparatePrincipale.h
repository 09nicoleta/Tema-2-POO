#ifndef PREPARATEPRINCIPALE_H
#define PREPARATEPRINCIPALE_H

#include<vector>
#include<memory>
#include<utility>
#include<string>
#include "Meniu.h"

class PreparatePrincipale: public Meniu{
    
    // pair<nume preparat, pret>
    std::vector<std::pair<std::string, float>> comanda;
    void afisare(std::ostream &os) const override;
    float total_plata_()const override;
    public:
    //Constructor
    PreparatePrincipale(std::vector<std::pair<std::string,float>>comanda);
    PreparatePrincipale()=default;    
    //La declararea obiectelor, utilizarea acoladelor atrage folosirea acestui constructor
    PreparatePrincipale(std::initializer_list<std::pair<std::string,float>>comanda);

    std::shared_ptr<Meniu> clone() const override;
    void citire(std::istream &in) override;
};

#endif