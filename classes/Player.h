#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Inventory.cpp"
#include "Engimon/Electricmon.h"
#include "Engimon/FireElectricmon.h"
#include "Engimon/Firemon.h"
#include "Engimon/Groundmon.h"
#include "Engimon/Icemon.h"
#include "Engimon/WaterGroundmon.h"
#include "Engimon/WaterIcemon.h"
#include "Engimon/Watermon.h"
#include "Skill.h"
#include <string>

using namespace std;

class Player : public Entities {
private:
    string namaPlayer;
    Inventory<Engimon> myEngimons;
    Inventory<Skill> mySkillItems;
    Engimon activeEngimon;

public:
    // Ctor
    Player(string nama, Inventory<Engimon> engimons, Inventory<Skill> skillItems, Engimon A);

    // Getter dan setter
    string getNamaPlayer() const;
    Inventory<Engimon> getMyEngimons() const;
    Inventory<Skill> getMySkillItems() const;
    Engimon getActiveEngimon() const;
    void setNamaPlayer(string nama);
    void setMyEngimons(Inventory<Engimon> engimons);
    void setMySkillItems(Inventory<Skill> skillItems);
    void setActiveEngimon(Engimon A);

    // Method
    void interact();
    void battle(Engimon* Enemy);
    void printEngimon(Engimon A);
    void printMyEngimons();
    void printMySkillItems();
    void switchActiveEngimon(Engimon switchEngimon);
    void useSkillItem(Engimon* A, Skill *S);
    Engimon* breeding(Engimon* A, Engimon* B);
    void getAdvantage(Engimon& active,Engimon& wild,float *activeAdv,float *wildAdv);
    bool isWinBattle(Engimon& active,Engimon& wild);
};

#endif