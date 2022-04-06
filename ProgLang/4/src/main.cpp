#include "classes.h"

int main() {
    Region brest_region("Brest region", "BLR");
    City brest("Brest", brest_region, 340000);
    brest_region.showAll();
}
