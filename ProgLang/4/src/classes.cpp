#include <string>
#include <utility>

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


Place::Place() : name_("TOP SECRET") {}

Place::Place(std::string name) : name_(std::move(name)) {}

Place::Place(Place &place) : name_(std::move(place.name_)) {}

Place::~Place() = default;



