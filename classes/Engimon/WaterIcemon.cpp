#include "WaterIcemon.h"

WaterIcemon::WaterIcemon(){
    species = "watericemon";
    element = new string[max_elements]{"Water, Ice"};
    learnSkill(new Skill("esBatu",100,"Water"));
    learnSkill(new Skill("esCair",100,"Ice"));
}
WaterIcemon::WaterIcemon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "watericemon";
    element = new string[max_elements]{"Water, Ice"};
    learnSkill(new Skill("esBatu",100,"Water"));
    learnSkill(new Skill("esCair",100,"Ice"));
}
WaterIcemon::WaterIcemon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "watericemon";
    element = new string[max_elements]{"Water, Ice"};
    learnSkill(new Skill("esBatu",100,"Water"));
    learnSkill(new Skill("esCair",100,"Ice"));
}
WaterIcemon::~WaterIcemon(){
    delete[] element;
}
string* WaterIcemon::getElement(){
    return element;
}
string WaterIcemon::getSpecies(){
    return species;
}
int WaterIcemon::countElement(){
    return 1;
}