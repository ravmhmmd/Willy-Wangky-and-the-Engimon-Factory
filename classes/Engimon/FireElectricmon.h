#ifndef FIREELECTRICMON_H
#define FIREELECTRICMON_H

#include "../Engimon.h"

// L/l: Fire/Electric engimon

using namespace std;

class FireElectricmon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    FireElectricmon();
    FireElectricmon(string _namaEngi, bool _isLiar);
    FireElectricmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //cctor

    //dtor
    ~FireElectricmon();

    //getter setter
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif