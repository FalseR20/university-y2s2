#include <string>
#include <iostream>
#include "classes.h"


Place **Place::places = nullptr;
unsigned int Place::nPlaces = 0;

void Place::add() {
    Place **temp = places;
    places = new Place *[nPlaces + 1];
    for (int i = 0; i < nPlaces; i++)
        places[i] = temp[i];
    delete[] temp;
    places[nPlaces++] = this;

}

void Place::showAll() {
    for (int i = 0; i < nPlaces; i++) {
        places[i]->print();
    }
}

Place::Place() : name_("TOP SECRET") {
    add();
}

Place::Place(std::string name, bool doAdd) : name_(std::move(name)) {
    if (doAdd)
        add();
}

Place::Place(Place &place) : name_(std::move(place.name_)) {
    add();
}

Place::~Place() = default;


Region::Region() : Place(), country_("Abobia") {}

Region::Region(std::string name, std::string country, bool doAdd) : Place(std::move(name), doAdd),
                                                                    country_(std::move(country)) {}

Region::Region(Region &region) : Place(region.name_), country_(region.country_) {}

Region::~Region() = default;

void Region::print() const {
    std::cout << "Region \"" << name_ << "\" of " << country_ << "\n";
}


City::City() : Place(), region_(), nPeoples_(0) {}

City::City(std::string name, Region &region, unsigned int nPeoples) :
        Place(std::move(name)), region_(region), nPeoples_(nPeoples) {}

City::City(City &city) :
        Place(std::move(city.name_)), region_(city.region_), nPeoples_(city.nPeoples_) {}

void City::print() const {
    std::cout << "City \"" << name_ << "\" with " << nPeoples_ << " people in " << region_.name_ << " of "
              << region_.country_ << "\n";
}

City::~City() = default;


Metropolis::Metropolis() : City(), top_(0) {}

Metropolis::Metropolis(std::string name, Region &region, unsigned int nPeoples, unsigned short top) :
        City(std::move(name), region, nPeoples), top_(top) {}

Metropolis::Metropolis(Metropolis &metropolis) :
        City(metropolis.name_, metropolis.region_, metropolis.nPeoples_), top_(metropolis.top_) {}

void Metropolis::print() const {
    std::cout << "Metropolis #" << top_ << " \"" << name_ << "\" with " << nPeoples_ << " people in " << region_.name_
              << " of " << region_.country_
              << "\n";
}

Metropolis::~Metropolis() = default;
