#include "Groundmon.h"

Groundmon::Groundmon(){
    species = "groundmon";
    element = new string[max_elements]{"Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));
}
Groundmon::Groundmon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "groundmon";
    element = new string[max_elements]{"Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));
}
Groundmon::Groundmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "groundmon";
    element = new string[max_elements]{"Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));;
}  
Groundmon::~Groundmon(){
    delete[] element;
}
string* Groundmon::getElement(){
    return element;
}
string Groundmon::getSpecies(){
    return species;
}
int Groundmon::countElement(){
    return 1;
}