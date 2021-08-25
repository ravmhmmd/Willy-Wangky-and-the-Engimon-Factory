#ifndef WATERICEMON_H
#define WATERICEMON_H

#include "../Engimon.h"

// S/s: Water/Ice engimon

using namespace std;

class WaterIcemon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    WaterIcemon();
    WaterIcemon(string _namaEngi, bool _isLiar);
    WaterIcemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~WaterIcemon();

    //getter sette
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif