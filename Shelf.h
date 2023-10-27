#include "DiskClass.h"

class Shelf {
    public:
    void populateShelf(vector<Disk*>& disks);

    //print
    void displayAllDisks() const;

    private:
        vector<Disk*> allDisks;
};