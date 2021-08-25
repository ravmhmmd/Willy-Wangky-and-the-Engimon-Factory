#include "Icemon.h"

Icemon::Icemon(){
    species = "icemon";
    element = new string[max_elements]{"Ice"};
    learnSkill(new Skill("esKiko",100,"Ice"));
}
Icemon::Icemon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "icemon";
    element = new string[max_elements]{"Ice"};
    learnSkill(new Skill("esKiko",100,"Ice"));
}
Icemon::Icemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "icemon";
    element = new string[max_elements]{"Ice"};
    learnSkill(new Skill("esKiko",100,"Ice"));
}
Icemon::~Icemon(){
    delete[] element;
}
string* Icemon::getElement(){
    return element;
}
string Icemon::getSpecies(){
    return species;
}
int Icemon::countElement(){
    return 1;
}