#include "classes.h"

int main() {
    Region brest_region("Brest region", "Belarus", false);
    brest_region.add();
    City brest("Brest", brest_region, 340000);
    Region mid_atlantic("Mid-Atlantic", "USA");
    Metropolis new_york("New York City", mid_atlantic, 10700000, 15);
    Place::showAll();
}
