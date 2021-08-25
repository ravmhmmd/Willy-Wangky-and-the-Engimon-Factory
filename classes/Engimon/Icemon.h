#ifndef ICEMON_H
#define ICEMON_H

#include "../Engimon.h"

// I/i : Ice engimon

using namespace std;

class Icemon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    Icemon();
    Icemon(string _namaEngi, bool _isLiar);
    Icemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~Icemon();

    //getter setter
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif