#include "Watermon.h"

Watermon::Watermon(){
    species = "watermon";
    element = new string[max_elements]{"Water"};
    learnSkill(new Skill("airMancur",100,"Water"));
}
Watermon::Watermon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "watermon";
    element = new string[max_elements]{"Water"};
    learnSkill(new Skill("airMancur",100,"Water"));
}
Watermon::Watermon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "watermon";
    element = new string[max_elements]{"Water"};
    learnSkill(new Skill("airMancur",100,"Water"));
}
Watermon::~Watermon(){
    delete[] element;
}
string* Watermon::getElement(){
    return element;
}
string Watermon::getSpecies(){
    return species;
}
int Watermon::countElement(){
    int size = 1;
    return size;
}