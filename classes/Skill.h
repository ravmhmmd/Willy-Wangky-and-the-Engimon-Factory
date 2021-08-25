#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>
using namespace std;

#define default_nama_skill "SemburanMaut"
#define default_base_power 69
#define default_req_elmt "SWAG"
class Skill {
    private :
        string namaSkill;
        int basePower;
        int masteryLevel;
        string reqElements;
    
    public :
        Skill();
        Skill(string _namaSkill,int _basePower,string _reqElement);
        //Skill(const Skill&);
        void setMasteryLevel(int _masteryLevel);
        int getBasePower();
        int getMasteryLevel();
        void printInfo();
        string getNamaSkill();
};

#endif