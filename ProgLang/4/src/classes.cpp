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

Place::Place(std::string name) : name_(std::move(name)) {
    add();
}

Place::Place(Place &place) : name_(std::move(place.name_)) {
    add();
}

Place::~Place() = default;

Region::Region() : Place(), country_("Abobia") {
    add();
}

Region::Region(std::string name, std::string country) : Place(std::move(name)), country_(std::move(country)) {
    add();
}

Region::Region(Region &region) : Place(region.name_), country_(region.country_) {
    add();
}

Region::~Region() = default;

void Region::print() const {
    std::cout << "Region " << name_ << " in " << country_ << "\n";
}

City::City() : Place(), region_(), nPeoples_(0) {
    add();
}

City::City(std::string name, Region region, unsigned int nPeoples) :
        Place(std::move(name)), region_(region), nPeoples_(nPeoples) {
    add();
}

City::City(City &city) :
        City(city.name_, city.region_, city.nPeoples_) {
    add();
}

void City::print() const {
    std::cout << "City " << name_ << " in " << region_.name_ << " of " << region_.country_ << "\n";
}

City::~City() = default;

Metropolis::Metropolis() : City(), top_(0) {
    add();
}

Metropolis::Metropolis(std::string name, Region &region, unsigned int nPeoples, unsigned short top) :
        City(std::move(name), region, nPeoples), top_(top) {
    add();
}

Metropolis::Metropolis(Metropolis &metropolis) :
        Metropolis(metropolis.name_, metropolis.region_, metropolis.nPeoples_, metropolis.top_) {
    add();
}

void Metropolis::print() const {
    std::cout << "Metropolis #" << top_ << ": " << name_ << " in " << region_.name_ << " of " << region_.country_
              << "\n";
}

Metropolis::~Metropolis() = default;
