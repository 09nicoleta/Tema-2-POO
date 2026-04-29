#include "MasaRestaurant.h"
#include "Meniu.h"
#include "MeniuSpecial.h"
#include "Bauturi.h"
#include "PreparatePrincipale.h"
#include "Exceptii.h"
#include<iostream>

//Constructor
MasaRestaurant::MasaRestaurant(const std::vector<std::shared_ptr<Meniu>> &meniuri={},int id_masa=0, int timp=0): 
                                                                meniuri{meniuri},id_masa{id_masa}, timp{timp}{}
//Constructor copiere
MasaRestaurant::MasaRestaurant(const MasaRestaurant &masa):id_masa{masa.id_masa},timp{masa.timp}{
    for(auto & meniu:masa.meniuri)
        meniuri.emplace_back(meniu->clone());
}

float MasaRestaurant::consum_total()const{
    int total=0;
    for(auto &meniu:meniuri)
        total+=meniu->total_plata();
    return total;
}

MasaRestaurant &MasaRestaurant::operator=(MasaRestaurant m) {
    swap(*this, m);
    return *this;
}

void swap(MasaRestaurant &m1, MasaRestaurant &m2){
    std::swap(m1.meniuri,m2.meniuri);
    std::swap(m1.id_masa,m2.id_masa);
    std::swap(m1.timp,m2.timp);
}

std::ostream &operator<<(std::ostream & os, const MasaRestaurant &m){
    int ora=10+m.timp/60;
    int min=m.timp%60;
    os<<"Clientii de la masa "<<m.id_masa;
    os<< " la ora "<<ora<<(min<10 ? ":0":":")<<min<<" au comandat :\n";

    for(const auto &men : m.meniuri)
        os<<*men;
    return os; 
}

std::shared_ptr<Meniu> MasaRestaurant::creeazaMeniu(const std::string & tip){
    if(tip=="MeniuSpecial")
        return std::make_shared<MeniuSpecial>();
    if (tip == "Bauturi")
        return std::make_shared<Bauturi>();
    if (tip == "PreparatePrincipale")
        return std::make_shared<PreparatePrincipale>();

    throw EroareMeniu("Tip necunoscut");
}


std::istream &operator>>(std::istream &in, MasaRestaurant &m){
    int nr;
    in>>nr;
    for(int i=0;i<nr;i++){
        std::string tip;
        in>>tip;
        //Alocarea memoriei pentru meniu
        auto meniu=m.creeazaMeniu(tip);
        meniu->citire(in);
        m.meniuri.emplace_back(meniu);   
    }
    in>>m.id_masa>>m.timp;
    return in;
}

std::vector<int> MasaRestaurant::rezumat_comanda(){
    int nr_msp=0, nr_b=0, nr_pp=0;

    for(const auto &m : meniuri){
        //m.get() returneaza pointerul "brut", m fiind de tip shared_ptr, altfel ar da eroare
        if(dynamic_cast<MeniuSpecial*>(m.get()))
            nr_msp++;
        else if(dynamic_cast<Bauturi*>(m.get()))
            nr_b++;
        else if(dynamic_cast<PreparatePrincipale*>(m.get()))
            nr_pp++;
    }

    return {nr_pp,nr_msp, nr_b,};
}