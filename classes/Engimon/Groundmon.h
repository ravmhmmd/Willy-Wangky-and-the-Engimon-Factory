#ifndef GROUNDMON_H
#define GROUNDMON_H

#include "../Engimon.h"

// G/g: Ground engimon

using namespace std;

class Groundmon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    Groundmon();
    Groundmon(string _namaEngi, bool _isLiar);
    Groundmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~Groundmon();

    //getter setter
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif