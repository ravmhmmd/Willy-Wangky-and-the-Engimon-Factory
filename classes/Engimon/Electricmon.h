#ifndef ELECTRICMON_H
#define ELECTRICMON_H

#include "../Engimon.h"

// E/e: Electric engimon

using namespace std;

class Electricmon : public Engimon{
private:
    string species;
    string *element;

public:
    //ctor
    Electricmon();
    Electricmon(string _namaEngi, bool _isLiar);
    Electricmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);

    //dtor
    ~Electricmon();

    //getter setter
    string *getElement();
    string getSpecies();
    int countElement();
};
#endif