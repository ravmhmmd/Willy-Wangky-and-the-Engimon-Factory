#include "WaterGroundmon.h"

WaterGroundmon::WaterGroundmon(){
    species = "watergroundmon";
    element = new string[max_elements]{"Water, Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));
    learnSkill(new Skill("lumpurLapindo",100,"Water"));
}
WaterGroundmon::WaterGroundmon(string _namaEngi, bool _isLiar) : Engimon( _namaEngi, _isLiar){
    species = "watergroundmon";
    element = new string[max_elements]{"Water, Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));
    learnSkill(new Skill("lumpurLapindo",100,"Water"));
}
WaterGroundmon::WaterGroundmon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Engimon(_namaEngi, _isLiar, _namaParent, _speciesParent){
    species = "watergroundmon";
    element = new string[max_elements]{"Water, Ground"};
    learnSkill(new Skill("azabKubur",100,"Ground"));
    learnSkill(new Skill("lumpurLapindo",100,"Water"));
}
WaterGroundmon::~WaterGroundmon(){
    delete[] element;
}
string* WaterGroundmon::getElement(){
    return element;
}
string WaterGroundmon::getSpecies(){
    return species;
}
int WaterGroundmon::countElement(){
    return 1;
}