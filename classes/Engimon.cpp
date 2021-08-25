#include "Engimon.h"
Engimon::Engimon() : Entities(0, 0){
    namaEngimon = default_engimon_name;
    level = 0;
    exp = 0;
    cumExp = max_cumExp;
    isLiar = true;
    isActive = false;
    namaParent = new string[2];
    speciesParent = new string[2];
    for (int i=0; i < 2; i++){
        namaParent[i] = default_parent_name;
        speciesParent[i] = default_parent_species;
    } 
}
Engimon::Engimon(string _namaEngi, bool _isLiar) : Entities(0, 0){
    namaEngimon = _namaEngi;
    level = 0;
    exp = 0;
    cumExp = max_cumExp;
    isLiar = _isLiar;
    isActive = false;
    namaParent = new string[2];
    speciesParent = new string[2];
    for (int i=0; i < 2; i++){
        namaParent[i] = default_parent_name;
        speciesParent[i] = default_parent_species;
    }
}
Engimon::Engimon(string _namaEngi, bool _isLiar, string *_namaParent, string *_speciesParent) : Entities(0, 0){
    namaEngimon = _namaEngi;
    level = 0;
    exp = 0;
    cumExp = max_cumExp;
    isLiar = _isLiar;
    isActive = false;
    namaParent = new string[2];
    speciesParent = new string[2];
    for (int i=0; i < 2; i++){
        namaParent[i] = _namaParent[i];
        speciesParent[i] = _speciesParent[i];
    }
}
Engimon::~Engimon() {
    delete[] namaParent;
    delete[] speciesParent;
}
void Engimon::setNamaEngimon(string newname){
    namaEngimon = newname;
}
void Engimon::setLevel(int newlvl){
    level = newlvl;
}
void Engimon::setActive(){
    if (isActive == false){
        isActive = true;
    }
}
void Engimon::setInactive(){
    if (isActive == true){
        isActive = false;
    }
}
void Engimon::setMati(){
    this->~Engimon();
}
void Engimon::setParentName(string *_namaParent){
    for (int i = 0; i < 2; i++){
        namaParent[i] = _namaParent[i];
    }
}
void Engimon::setParentSpecies(string *_speciesParent){
    for (int i = 0; i < 2; i++){
        speciesParent[i] = _speciesParent[i];
    }
}
string Engimon::getNamaEngimon(){
    return namaEngimon;
}
bool Engimon::getisLiar(){
    return isLiar;
}
bool Engimon::getisActive(){
    return isActive;
}
int Engimon::getLevel(){
    return level;
}
Skill **Engimon::getSkill(){
    Skill** skills;
    //skills[skillEngimon.size()];
    std::copy(skillEngimon.begin(), skillEngimon.end(), skills);
    return skills;
}
string* Engimon::getElement(){return 0;}
string Engimon::getSpecies(){return 0;}
int Engimon::countElement(){return 0;}

int Engimon:: countSkill(){
    return skillEngimon.size();
    }

void Engimon::addExp(int added_exp){
    exp += added_exp;
    if (exp % 100 == 0)
    {
        levelUp();
    }
    if (exp >= max_cumExp)
    {
        setMati();
    }
}
void Engimon::levelUp(){
    level += 1;
}

void Engimon::learnSkill(Skill *newskill){
    if(skillEngimon.size() <  4){
        skillEngimon.push_back(newskill);
    }
}
void Engimon::replaceSkill(Skill *removedskill, Skill *newskill){
    removeSkill(removedskill);
    learnSkill(newskill);
}
void Engimon::removeSkill(Skill *removedskill){
    skillEngimon.erase(remove(skillEngimon.begin(), skillEngimon.end(), removedskill), skillEngimon.end());
}
void Engimon::tame(){
    isLiar = false;
}
void Engimon::printSkill(){
    cout << "Skill: " << endl;
    if (skillEngimon.size() > 0){
        int i;
        for (i = 0; i < skillEngimon.capacity(); i++) {
            cout << "[" << i+1 << "] ";
            cout << skillEngimon.at(i)->getNamaSkill() + '\n';
        }
    } else {
        cout << "Engimon kamu cupu, gapunya skill :(" << endl;
    }
    cout << endl;
    cout << endl;
}
void Engimon::printInfoEngimon(){
    string* elmt = getElement();
    cout << "-ENGIMON INFO-" << endl;
    cout << "Nama: " << namaEngimon << endl;
    cout << "Species: " << getSpecies() << endl;
    cout << "Nama dan Species Parent: " << endl;
    cout << namaParent[0] << " Species: " << speciesParent[0] << endl;
    cout << namaParent[1] << " Species: " << speciesParent[1] << endl;
    cout << "Level: " << level << endl;
    cout << "EXP: " << exp << endl;
    cout << "Cum EXP: " << cumExp << endl;
    cout << "Element: ";
    for (int i = 0; i < countElement(); i++){
        cout << elmt[i];
    }
    cout << endl;
    printSkill();
    cout << endl;
}
// void Engimon::move(int x, int y)
// {
// 	int deltaX = x - posX, deltaY = y - posY;
//     int tempx = posX, tempy = posY;

// 	if (!((deltaX == 0 && deltaY == 1)		// N
// 		  || (deltaX == 1 && deltaY == 1)	// NE
// 		  || (deltaX == 1 && deltaY == 0)	// E
// 		  || (deltaX == 1 && deltaY == -1)	// SE
// 		  || (deltaX == 0 && deltaY == -1)	// S
// 		  || (deltaX == -1 && deltaY == -1) // SW
// 		  || (deltaX == -1 && deltaY == 0)	// W
// 		  || (deltaX == -1 && deltaY == 1)))
// 	{ // NW
// 		return;
// 	}

// 	posX = x;
// 	posY = y;
// 	//map->pseudomoveEngimon(tempx, tempy, this);
// }


// void Engimon::moveRandom(){
// 	int dir[8][2] = {
// 		{0, 1},	  // N
// 		{1, 1},	  // NE
// 		{1, 0},	  // E
// 		{1, -1},  // SE
// 		{0, -1},  // S
// 		{-1, -1}, // SW
// 		{-1, 0},  // W
// 		{-1, 1}	  // NW
// 	};
// 	bool condition = false;
// 	int deltaX, deltaY;
// 	srand(time(0));
// 	int acak = rand() % 8;
// 	int *diracak = dir[acak];
// 	deltaX = posX + diracak[0];
// 	deltaY = posY + diracak[1];

// 	move(deltaX, deltaY);
// }