#ifndef CLASSES_H
#define CLASSES_H

#include <string>


class Place {
public:
    Place();

    Place(std::string name);

    Place(Place &place);

    ~Place();

    static Place **places;
    static unsigned int nPlaces;

    virtual void print() const = 0;

    virtual void add() final;

    static void showAll();

protected:
    std::string name_;
};

class Region : public Place {
public:
    Region();

    Region(std::string name, std::string country);

    Region(Region &region);

    ~Region();

    void print() const override;

protected:
    std::string country_;

    friend class City;
    friend class Metropolis;
};

class City : public Place {
public:
    City();

    City(std::string name, Region &region, uint nPeoples);

    City(City &city);

    ~City();

    void print() const override;

protected:

    Region region_;
    uint nPeoples_;
};

class Metropolis : public City {
public:
    Metropolis();

    Metropolis(std::string name, Region &region, uint nPeoples, ushort top);

    Metropolis(Metropolis &metropolis);

    void print() const override;

    ~Metropolis();

protected:
    ushort top_;
};


#endif //CLASSES_H