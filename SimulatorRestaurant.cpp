#include "SimulatorRestaurant.h"
#include "MeniuSpecial.h"
#include "Bauturi.h"
#include "PreparatePrincipale.h"
#include<memory>


std::shared_ptr<Meniu> SimulatorRestaurant::genereazaMeniu() {
    std::uniform_int_distribution<int> tipDist(0, 2);
    //se genereaza random ce tip de meniu s-a comandat
    int tip = tipDist(rng);

    std::vector<std::pair<std::string, float>>com_meniu;

    if(tip==0){ 
    std::vector<std::pair<std::string, float>>preparate_princip={{"Burger",20},{"Paste",38},{"Pizza",35},{"Salata",20},
    {"Papanasi",20},{"Inghetata",10}};
    //Cate elemente din meniu au fost cumparate: 
    int nr_el = std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, preparate_princip.size()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        //generare random a produsului comandat din meniu
        ind_rand=ind(rng);
        com_meniu.emplace_back(preparate_princip[ind_rand]);
    }

    return std::make_shared<PreparatePrincipale>(com_meniu);
    }
    else if(tip==1){ 

    std::vector<std::pair<std::string, float>> men_sp={{"Business", 45},{"Family",70}, {"Fitness",55}};

    //Cate elemente din meniu au fost cumparate: 
    int nr_el = std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, men_sp.size()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        //generare random a produsului comandat din meniu
        ind_rand=ind(rng);
        com_meniu.emplace_back(men_sp[ind_rand]);
    }  
    
    return std::make_shared<MeniuSpecial>(com_meniu);

    }
    else{
    std::vector<std::pair<std::string, float>> bauturi={{"Limonada", 15},{"Pepsi",5}, {"Apa",3}, {"Cappuccino",15}, {"Ceai",10}};
    
    //Cate elemente din meniu au fost cumparate: 
    int nr_el = std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, bauturi.size()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        //generare random a produsului comandat din meniu
        ind_rand=ind(rng);
        com_meniu.emplace_back(bauturi[ind_rand]);
    }
    return std::make_shared<Bauturi>(com_meniu);
    }
}

MasaRestaurant SimulatorRestaurant::genereazaMasa(int id) {
    std::vector<std::shared_ptr<Meniu>> meniuri;

    int n = std::uniform_int_distribution<int>(1,3)(rng);

    for(int i=0;i<n;i++)
        meniuri.push_back(genereazaMeniu());

    int timp =std::uniform_int_distribution<int>(0,600)(rng);
    return MasaRestaurant(meniuri, id, timp);
}

Zi SimulatorRestaurant::genereazaZi(const std::string& nume_zi) {
    Zi zi(nume_zi);
    //Generarea numarului de clienti in ziua respectiva
    int n_clienti = std::uniform_int_distribution<int>(1,5)(rng);
    for(int i = 0; i < n_clienti; i++)
        zi.adaugare(genereazaMasa(i+1));

    return zi;
}