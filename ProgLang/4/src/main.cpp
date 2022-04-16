#include "classes.h"

int main() {
    Region brest_region("Brest region", "BLR");
    Region minsk_region("Minsk region", "BLR");
    City brest("Brest", brest_region, 340000);
    Region::showAll();
}
