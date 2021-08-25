#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string nama, Inventory<Engimon> engimons, Inventory<Skill> skillItems, Engimon A) : Entities(5, 4){
    this->namaPlayer = nama;
    this->myEngimons = engimons;
    this->mySkillItems = skillItems;
    this->activeEngimon = A;
    activeEngimon.setActive();
}

string Player::getNamaPlayer() const{
    return this->namaPlayer;
}

Inventory<Engimon> Player::getMyEngimons() const{
    return this->myEngimons;
}

Inventory<Skill> Player::getMySkillItems() const{
    return this->mySkillItems;
}

Engimon Player::getActiveEngimon() const{
    return this->activeEngimon;
}

void Player::setNamaPlayer(string nama){
    this->namaPlayer = nama;
}

void Player::setMyEngimons(Inventory<Engimon> engimons){
    this->myEngimons = engimons;
}

void Player::setMySkillItems(Inventory<Skill> skillItems){
    this->mySkillItems = skillItems;
}

void Player::setActiveEngimon(Engimon A){
    this->activeEngimon = A;
}

void Player::interact(){
    cout << "Halo guyss, " << this->activeEngimon.getSpecies() << " disini, dengan siapa dimana ??" << endl;
}

void Player::battle(Engimon* Enemy){
    bool isWin = this->isWinBattle(this->activeEngimon, *Enemy);

    if (isWin){
        Enemy->tame();
        this->myEngimons.addItem(Enemy);
        Skill **skillEnemy = Enemy->getSkill();
        Skill randomSkill = *skillEnemy[0];
        this->mySkillItems.addItem(&randomSkill); 
        this->activeEngimon.addExp(Enemy->getLevel()*50);
    } else{
        this->activeEngimon.setMati();
        this->myEngimons.removeItem(&this->activeEngimon);
    }
}

void printEngimon(Engimon A){
    A.printInfoEngimon();
}

void Player::printMyEngimons(){
    cout << "Halo " << this->namaPlayer << "!" << endl;
    cout << "Berikut adalah Engimon yang kamu miliki :" << endl;
    this->myEngimons.printInventory();
}

void Player::printMySkillItems(){
    cout << "Halo " << this->namaPlayer << "!" << endl;
    cout << "Berikut adalah Skill Item yang kamu miliki :" << endl;
    this->mySkillItems.printInventory();
}

void Player::switchActiveEngimon(Engimon switchEngimon){
    switchEngimon.setActive();
    this->activeEngimon.setInactive();
    this->activeEngimon = switchEngimon;
}

void Player::useSkillItem(Engimon* A, Skill *S){
    if (A->countSkill() < 4){
        A->learnSkill(S);
    } else{
        int choose;
        cout << "Pilih skill yang ingin di-remove :" << endl;
        A->printSkill();
        cin >> choose;
        Skill **skillA = A->getSkill();
        A->replaceSkill(skillA[choose], S);
    }
}

Engimon* Player::breeding(Engimon* A, Engimon* B){
    if (A->countElement() > 1 || B->countElement() > 1 || A->getLevel() < 30 || B->getLevel() < 30){
        throw "Tidak dapat melakukan breeding!";
    } else{
        string *pname = new string[2]{A->getNamaEngimon(), B->getNamaEngimon()};
        string *pspecies = new string[2]{A->getSpecies(), B->getSpecies()};
        string namaEngimon;
        string species;
        int i;
        cin >> namaEngimon;
        if (A->getSpecies() == B->getSpecies()){
            species = A->getSpecies();
        } else{
            float aAdv, bAdv;
            this->getAdvantage(*A, *B, &aAdv, &bAdv);
            if (aAdv > bAdv){
                species = A->getSpecies();
            } else if (aAdv < bAdv){
                species = B->getSpecies();
            } else{
                if (A->getSpecies() == "watermon" && B->getSpecies() == "icemon"){
                    species = "watericemon";
                } else if (A->getSpecies() == "icemon" && B->getSpecies() == "watermon"){
                    species = "watericemon";
                } else if (A->getSpecies() == "watermon" && B->getSpecies() == "groundmon"){
                    species = "watergroundmon";
                } else if (A->getSpecies() == "groundmon" && B->getSpecies() == "watermon"){
                    species = "watergroundmon";
                } else if (A->getSpecies() == "firemon" && B->getSpecies() == "electricmon"){
                    species = "fireelectricmon";
                } else if (A->getSpecies() == "electricmon" && B->getSpecies() == "firemon"){
                    species = "fireelectricmon";
                }
            }
        }
        Engimon* C;
        if (species == "electricmon"){
            C = new Electricmon(namaEngimon, false, pname, pspecies);
        } else if (species == "fireelectricmon"){
            C = new FireElectricmon(namaEngimon, false, pname, pspecies);
        } else if (species == "firemon"){
            C = new Firemon(namaEngimon, false, pname, pspecies);
        } else if (species == "groundmon"){
            C = new Groundmon(namaEngimon, false, pname, pspecies);
        } else if (species == "icemon"){
            C = new Icemon(namaEngimon, false, pname, pspecies);
        } else if (species == "watergroundmon"){
            C = new WaterGroundmon(namaEngimon, false, pname, pspecies);
        } else if (species == "watericemon"){
            C = new WaterIcemon(namaEngimon, false, pname, pspecies);
        } else if (species == "watermon"){
            C = new Watermon(namaEngimon, false, pname, pspecies);
        }

        // ngasih skill
        Skill **skillC;
        if (C->getSpecies() == A->getSpecies()){
            skillC = A->getSkill();
            for (int i = 0; i < A->countSkill(); i++){
                C->learnSkill(skillC[i]);
            }
        } else if (C->getSpecies() == B->getSpecies()){
            skillC = B->getSkill();
            for (int i = 0; i < B->countSkill(); i++){
                C->learnSkill(skillC[i]);
            }   
        } else{
            Skill **skillCB = B->getSkill();
            skillC = A->getSkill();
            bool *visited = new bool[4];
            for (int i = 0; i < 4; i++){
                visited[i] = false;
            }
            for (int i = 0; i < A->countSkill(); i++){
                for (int j = 0; j < B->countSkill(); j++){
                    if ((skillC[i]->getMasteryLevel() < skillCB[j]->getMasteryLevel()) && !visited[j]){
                        skillC[i] = skillCB[j];
                        visited[j] = true;
                    }
                }
            }
            for (int i = 0; i < A->countSkill(); i++){
                C->learnSkill(skillC[i]);
            }
        }
        
        A->setLevel(A->getLevel()-30);
        B->setLevel(B->getLevel()-30);

        cout << "Berhasil melakukan breeding!" << endl;
        return C;
    }
}

void Player::getAdvantage(Engimon& active,Engimon& wild,float *activeAdv,float *wildAdv){
    string *elmt1 = active.getElement();
    string *elmt2 = wild.getElement();
    float adv1[sizeof(elmt1)/sizeof(elmt1)[0]];
    float adv2[sizeof(elmt2)/sizeof(elmt2)[0]];

    for (int i=0; i < (sizeof(elmt1)/sizeof(elmt1)[0]); i++){
        for (int j=0; j < sizeof(elmt2)/sizeof(elmt2[0]); j++){
            if (elmt1[i]=="Fire"){
                if (elmt2[j] == "Fire") {   
                    adv1[i] = 1;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 0;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 0.5;
                }  else if (elmt2[j] == "Ice") { 
                    adv1[i] = 2;
                }     
            } else if (elmt1[i]=="Water") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 2;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 0;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1;
                }
            } else if (elmt1[i]=="Electric") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 2;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 0;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1.5;
                }
            } else if (elmt1[i]=="Ground") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 1.5;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 2;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 0;
                }
            } else if (elmt1[i]=="Ice") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 0;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 0.5;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 2;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1;
                }
            }
        }
    }

    for (int i=0; i < sizeof(elmt2)/sizeof(elmt2[0]); i++){
        for (int j=0; j < sizeof(elmt1)/sizeof(elmt1[0]); j++){
            if (elmt2[i]=="Fire"){
                if (elmt1[j] == "Fire") {   
                    adv2[i] = 1;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 0;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 0.5;
                }  else if (elmt1[j] == "Ice") { 
                    adv2[i] = 2;
                }     
            } else if (elmt2[i]=="Water") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 2;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 0;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1;
                }
            } else if (elmt2[i]=="Electric") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 2;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 0;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1.5;
                }
            } else if (elmt2[i]=="Ground") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 1.5;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 2;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 0;
                }
            } else if (elmt2[i]=="Ice") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 0;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 0.5;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 2;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1;
                }
            }
        }
    }

    *activeAdv = *max_element(adv1,adv1+(sizeof(adv1)/sizeof(adv1)[0]));
    *wildAdv = *max_element(adv2,adv2+(sizeof(adv2)/sizeof(adv2)[0]));
}

bool Player::isWinBattle(Engimon& active,Engimon& wild){
    int lvActive = active.getLevel(); 
    int lvWild = wild.getLevel();
    string *elmt1 = active.getElement();
    string *elmt2 = wild.getElement();
    float adv1[sizeof(elmt1)/sizeof(elmt1)[0]];
    float adv2[sizeof(elmt2)/sizeof(elmt2)[0]];
    float advAct = *max_element(adv1,adv1+(sizeof(adv1)/sizeof(adv1)[0]));
    float advWild = *max_element(adv2,adv2+(sizeof(adv2)/sizeof(adv2)[0]));

    for (int i=0; i < (sizeof(elmt1)/sizeof(elmt1)[0]); i++){
        for (int j=0; j < sizeof(elmt2)/sizeof(elmt2[0]); j++){
            if (elmt1[i]=="Fire"){
                if (elmt2[j] == "Fire") {   
                    adv1[i] = 1;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 0;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 0.5;
                }  else if (elmt2[j] == "Ice") { 
                    adv1[i] = 2;
                }     
            } else if (elmt1[i]=="Water") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 2;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 0;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1;
                }
            } else if (elmt1[i]=="Electric") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 2;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 0;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1.5;
                }
            } else if (elmt1[i]=="Ground") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 1.5;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 2;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 1;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 0;
                }
            } else if (elmt1[i]=="Ice") {
                if (elmt2[j] == "Fire") {  
                    adv1[i] = 0;
                } else if (elmt2[j] == "Water") {  
                    adv1[i] = 1;
                } else if (elmt2[j] == "Electric") {
                    adv1[i] = 0.5;
                } else if (elmt2[j] == "Ground") {
                    adv1[i] = 2;
                } else if (elmt2[j] == "Ice") {
                    adv1[i] = 1;
                }
            }
        }
    }

    for (int i=0; i < sizeof(elmt2)/sizeof(elmt2[0]); i++){
        for (int j=0; j < sizeof(elmt1)/sizeof(elmt1[0]); j++){
            if (elmt2[i]=="Fire"){
                if (elmt1[j] == "Fire") {   
                    adv2[i] = 1;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 0;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 0.5;
                }  else if (elmt1[j] == "Ice") { 
                    adv2[i] = 2;
                }     
            } else if (elmt2[i]=="Water") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 2;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 0;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1;
                }
            } else if (elmt2[i]=="Electric") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 2;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 0;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1.5;
                }
            } else if (elmt2[i]=="Ground") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 1.5;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 2;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 1;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 0;
                }
            } else if (elmt2[i]=="Ice") {
                if (elmt1[j] == "Fire") {  
                    adv2[i] = 0;
                } else if (elmt1[j] == "Water") {  
                    adv2[i] = 1;
                } else if (elmt1[j] == "Electric") {
                    adv2[i] = 0.5;
                } else if (elmt1[j] == "Ground") {
                    adv2[i] = 2;
                } else if (elmt1[j] == "Ice") {
                    adv2[i] = 1;
                }
            }
        }
    }

    Skill **actEng = active.getSkill();
    Skill **wildEng = wild.getSkill();
    float sumSkillActive=0;
    float sumSkillWild=0;
    for (int i=0; i<(sizeof(actEng)/sizeof(actEng)[0]); i++){
        sumSkillActive += (actEng[i]->getBasePower())*(actEng[i]->getMasteryLevel());
    }

    for (int i=0; i<(sizeof(wildEng)/sizeof(wildEng)[0]); i++){
        sumSkillWild += (wildEng[i]->getBasePower())*(wildEng[i]->getMasteryLevel());
    }

    float sumPowerActive = lvActive*advAct + sumSkillActive;
    float sumPowerWild = lvWild*advWild + sumSkillWild;

    cout << "Power Level Active Engimon = " << sumPowerActive << endl;
    cout << "Power Level Engimon Lawan = " << sumPowerWild << endl;

    if (sumPowerActive >= sumPowerWild){
        return true;
    } else {
        return false;
    } 
}