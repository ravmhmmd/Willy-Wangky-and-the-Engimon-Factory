#ifndef WATERMON_H
#define WATERMON_H

#include "../Engimon.h"

// W/w: Water engimon

using namespace std;

class Watermon : public Engimon
{
private:
    string species;
    string *element;

public:
    //ctor
    Watermon();
    Watermon(string _namaEngi, bool _isLiar);
    Watermon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~Watermon();

    //getter setter
    string *getElement();
    string getSpecies();
    int countElement();
};
#endif