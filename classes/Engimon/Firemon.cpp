#include "Firemon.h"

Firemon::Firemon(){
    species = "Firemon";
    element = new string[max_elements]{"Fire"};
    learnSkill(new Skill("apineraka",100,"Fire"));
}
Firemon::Firemon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "Firemon";
    element = new string[max_elements]{"Fire"};
    learnSkill(new Skill("apineraka",100,"Fire"));
}
Firemon::Firemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "Firemon";
    element = new string[max_elements]{"Fire"};
    learnSkill(new Skill("apineraka",100,"Fire"));
}
Firemon::~Firemon(){
    delete[] element;
}
string* Firemon::getElement(){
    return element;
}
string Firemon::getSpecies(){
    return species;
}
int Firemon::countElement(){
    return 1;
}