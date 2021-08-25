#include "FireElectricmon.h"

FireElectricmon::FireElectricmon(){
    species = "fireelectricmon";
    element = new string[max_elements]{"Fire, Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
    learnSkill(new Skill("apineraka",100,"Fire"));
}   
FireElectricmon::FireElectricmon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "fireelectricmon";
    element = new string[max_elements]{"Fire, Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
    learnSkill(new Skill("apineraka",100,"Fire"));
}
FireElectricmon::FireElectricmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "fireelectricmon";
    element = new string[max_elements]{"Fire, Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
    learnSkill(new Skill("apineraka",100,"Fire"));
}
FireElectricmon::~FireElectricmon(){
    delete[] element;
}
string* FireElectricmon::getElement(){
    return element;
}
string FireElectricmon::getSpecies(){
    return species;
}
int FireElectricmon::countElement(){
    return 1;
}