// File: Engimon.h
#ifndef ENGIMON_H
#define ENGIMON_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Skill.h"
#include "Entities.h"
// #include "Map.h"
#include <stdlib.h>
#include <time.h>

// W/w: Water engimon
// I/i : Ice engimon
// F/f: Fire engimon
// G/g: Ground engimon
// E/e: Electric engimon
// L/l: Fire/Electric engimon
// S/s: Water/Ice engimon
// N.n: Water/Ground engimon

#define max_cumExp 9999
#define default_engimon_name "kasihNamaDongg"
#define default_parent_name "yatimpiatu"
#define default_parent_species "LGBTQ"
#define max_elements 2
#define max_skills 4


using namespace std;

class Engimon : public Entities
{
private:
    string namaEngimon;
    string *namaParent;
    string *speciesParent;
    // string species;
    // string *element;
    vector<Skill*>  skillEngimon;
    int level;
    int exp;
    int cumExp;
    bool isActive;
    bool isLiar;

public:
    //ctor
    Engimon(); //default engimon liar
    Engimon(string _namaEngi, bool _isLiar);
    // Engimon (string _namaEngi, bool _isLiar, Engimon, string *_speciesParent); ide aja siapa tau bisa
    Engimon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent);
    
    //dtor
    virtual ~Engimon();

    //getter setter
    void setNamaEngimon(string newname);
    void setLevel(int newlvl);
    void setActive();
    void setInactive();
    void setMati();
    void setParentName(string *_namaParent);
    void setParentSpecies(string *speciesParent);
    string getNamaEngimon();
    bool getisLiar();
    bool getisActive();
    int getLevel();
    Skill **getSkill();

    virtual string* getElement();
    virtual string getSpecies();
    virtual int countElement();

    //other methods
    void addExp(int);
    void levelUp();
    void learnSkill(Skill* newskill);
    void replaceSkill(Skill* removedskill, Skill* newskill);
    void removeSkill(Skill* removedskill);
    void tame();
    //void move(int, int);
    //virtual void moveRandom();
    int countSkill();

    //print print an
    void printSkill();
    void printInfoEngimon();
};
#endif