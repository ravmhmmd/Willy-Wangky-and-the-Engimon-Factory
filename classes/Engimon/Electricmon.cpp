#include "Electricmon.h"

Electricmon::Electricmon(){
    species = "electricmon";
    element = new string[max_elements]{"Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
}
Electricmon::Electricmon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "electricmon";
    element = new string[max_elements]{"Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
}
Electricmon::Electricmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "electricmon";
    element = new string[max_elements]{"Electric"};
    learnSkill(new Skill("genHalilintar",100,"Electric"));
}
Electricmon::~Electricmon(){
    delete[] element;
}
string* Electricmon::getElement(){
    return element;
}
string Electricmon::getSpecies(){
    return species;
}
int Electricmon::countElement(){
    return 1;
}