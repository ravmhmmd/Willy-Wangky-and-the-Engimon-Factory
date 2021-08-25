#ifndef WATERGROUNDMON_H
#define WATERGROUNDMON_H

#include "../Engimon.h"

// N.n: Water/Ground engimon

using namespace std;

class WaterGroundmon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    WaterGroundmon();
    WaterGroundmon(string _namaEngi, bool _isLiar);
    WaterGroundmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~WaterGroundmon();

    //getter setter
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif