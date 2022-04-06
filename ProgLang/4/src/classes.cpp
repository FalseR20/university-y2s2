#include <string>
#include <utility>
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
    places[++nPlaces] = this;
}

void Place::showAll() {
    for (int i = 0; i < nPlaces; i++) {
        places[i]->print();
    }
}

Place::Place() : name_("TOP SECRET") {
    add();
}

Place::Place(std::string name) : name_(std::move(name)) {
    add();
}

Place::Place(Place &place) : name_(std::move(place.name_)) {
    add();
}

Place::~Place() = default;

Region::Region() : Place(), country_("Abobia") {}

Region::Region(std::string name, std::string country) : Place(name), country_(country) {}

Region::Region(Region &region) : Place(region.name_), country_(region.country_) {}

Region::~Region() = default;

void Region::print() const {
    std::cout << "Region " << name_ << " in " << country_ << "\n";
}

City::City() : Place(), region_(), nPeoples_(0) {}

City::City(std::string name, Region &region, uint nPeoples) :
        Place(name), region_(region.name_, region.country_), nPeoples_(nPeoples) {}

City::City(City &city) :
        City(city.name_, city.region_, city.nPeoples_) {}

void City::print() const {
    std::cout << "City " << name_ << " in " << region_.name_ << " of " << region_.country_ << "\n";
}

City::~City() = default;

Metropolis::Metropolis() : City(), top_(0) {}

Metropolis::Metropolis(std::string name, Region &region, uint nPeoples, ushort top) :
        City(name, region, nPeoples), top_(top) {}

Metropolis::Metropolis(Metropolis &metropolis) :
        Metropolis(metropolis.name_, metropolis.region_, metropolis.nPeoples_, metropolis.top_) {
}

void Metropolis::print() const {
    std::cout << "Metropolis #" << top_ << ": " << name_ << " in " << region_.name_ << " of " << region_.country_ << "\n";
}

Metropolis::~Metropolis() = default;
