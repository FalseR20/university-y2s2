#ifndef CLASSES_H
#define CLASSES_H

#include <string>


class Place {
public:
    static Place **places;
    static unsigned int nPlaces;

    void add();

    Place();
    Place(std::string name);
    Place(Place &place);
    ~Place();

protected:
    std::string name_;
};

class Region : Place {
public:

protected:
    std::string country_;
};

class City : Place {
public:

protected:
    Region region_;
    unsigned int nPeoples_;
};

class Metropolis : City {
public:

protected:
    unsigned short top_;
};


#endif //CLASSES_H
