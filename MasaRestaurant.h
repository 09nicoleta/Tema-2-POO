#ifndef MASARESTAURANT_H
#define MASARESTAURANT_H
#include "Meniu.h"
#include <memory>
#include <vector>

class MasaRestaurant{
    std::vector<std::shared_ptr<Meniu>> meniuri;
    int id_masa, timp;
    public:
    float consum_total() const;
    //Constructor
    MasaRestaurant(const std::vector<std::shared_ptr<Meniu>> &meniuri, int id_masa, int timp);
    //Constructor de copiere
    MasaRestaurant(const MasaRestaurant & masa);

    MasaRestaurant &operator=(MasaRestaurant m);
    friend void swap(MasaRestaurant &m1, MasaRestaurant &m2);
    friend std::ostream &operator<<(std::ostream & os, const MasaRestaurant &m);

    //Destructor
    ~MasaRestaurant()=default;

};

#endif