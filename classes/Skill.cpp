#include "Skill.h"
#include <iostream>
#include <cstring>
using namespace std;

Skill::Skill(){
    this->namaSkill = default_nama_skill;
    this->basePower = default_base_power;
    this->masteryLevel = 1;
    this->reqElements = default_req_elmt;
}
Skill::Skill(string _namaSkill,int _basePower,string _reqElement){
    this->namaSkill = _namaSkill;
    this->basePower = _basePower;
    this->masteryLevel = 1;
    this->reqElements = _reqElement;
}
// Skill::Skill(const Skill& skill){
//     this->namaSkill = skill.namaSkill;
//     this->basePower = skill.basePower;
//     this->masteryLevel = 1;
//     this->reqElements = skill.reqElements;
// }


void Skill::setMasteryLevel(int _masteryLevel){
    this->masteryLevel = _masteryLevel;
}

int Skill::getBasePower(){
    return this->basePower;
}

int Skill::getMasteryLevel(){
    return this->masteryLevel;
}

void Skill::printInfo(){
    cout << "Nama Skill : " << this->namaSkill << endl;
    cout << "Base Power : " << this->basePower << endl;
    cout << "Mastery Level : " << this->masteryLevel << endl;
    cout << "Element : " << this->reqElements << endl;

}
string Skill::getNamaSkill(){
    return namaSkill;
}
