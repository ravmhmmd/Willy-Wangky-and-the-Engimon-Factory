#ifndef FIREMON_H
#define FIREMON_H

#include "../Engimon.h"

// F/f: Fire engimon

using namespace std;

class Firemon : public Engimon
{
private:
    string species;
    string* element;

public:
    //ctor
    Firemon();
    Firemon(string _namaEngi, bool _isLiar);
    Firemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~Firemon();

    //getter setter
    string* getElement();
    string getSpecies();
    int countElement();
};
#endif