#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <iostream>
#include <string>
//#include "classes/Entities.h"
//#include "classes/Engimon.h"
//#include "classes/Inventory.h"
//#include "classes/Inventory.cpp"
#include "classes/Player.h"
//#include "classes/Skill.h"
#include "classes/Map.h"

using namespace std;

class Game
{
private:
	Map *map;
	Player *player;
	Inventory<Engimon> *invEngimon;
	Inventory<Skill> *invSkill;
	Engimon *engimonDefault;
	bool newgame;
	int turn;

	void play()
	{
		string cmd = "";
		while (cmd != "exit")
		{
			map->printMap();
			cout << endl;
			cout << "> ";
			cin >> cmd;
			handleCMD(cmd);
			turn++;
			//if(turn%5 == 0)
			//	moveRandom();
		}
		cout << "thanks" << endl;
	}

	void intro()
	{
		cout << "Welcome" << endl;
	}

	void init()
	{
		string name;
		cout << "Input your name: ";
		cin >> name;
		cout << "Hello, " << name << endl;
		newgame = true;

		// init player
		cout << "Mau engimon nomor berapa nih bang:" << endl;
		cout << "[1] Firemon" << endl;
		cout << "[2] Watermon" << endl;
		cout << "[3] Groundmon" << endl;
		cout << "[4] Icemon" << endl;
		cout << "[5] Electricmon" << endl;
		int engi = -1;
		while (!(engi > 0 && engi < 6))
		{
			cout << "Mau engimon nomor berapa nih bang: ";
			cin >> engi;
		}
		string namaEngi;
		cout << "Cakepp bet dah, kasih nama siapa nih: ";
		cin >> namaEngi;
		switch (engi)
		{
		case 1:
			engimonDefault = new Firemon(namaEngi, false);
			break;
		case 2:
			engimonDefault = new Watermon(namaEngi, false);
			break;
		case 3:
			engimonDefault = new Groundmon(namaEngi, false);
			break;
		case 4:
			engimonDefault = new Icemon(namaEngi, false);
			break;
		case 5:
			engimonDefault = new Electricmon(namaEngi, false);
			break;
		default:
			break;
		}
		invEngimon->addItem(engimonDefault);
		player = new Player(name, *invEngimon, *invSkill, *engimonDefault);
		//player = new Player(name, engi)
		//player = p;
	}

	void handleCMD(string cmd)
	{
		if (!newgame)
		{
			cout << "Game not initialized";
			return;
		}
		if (cmd == "help")
		{
			cout << "List command: " << endl
				 << "- move" << endl
				 << "- inventory" << endl;
		}
		else if (cmd == "exit")
		{
		}
		else if (cmd == "breed")
		{

			player->getMyEngimons().addItem(player->breeding(player->getMyEngimons().listItem.at(0), player->getMyEngimons().listItem.at(1)));
		}
		else if (cmd == "move")
		{
			int dir[8][2] = {
				{0, 1},	  // N
				{1, 1},	  // NE
				{1, 0},	  // E
				{1, -1},  // SE
				{0, -1},  // S
				{-1, -1}, // SW
				{-1, 0},  // W
				{-1, 1}	  // NW
			};
			int id;
			string input;
			cout << "Insert direction (N/NE/E/SE/S/SW/W/NW)" << endl;
			cin >> input;
			if (input == "N")
			{
				id = 0;
			}
			else if (input == "NE")
			{
				id = 1;
			}
			else if (input == "E")
			{
				id = 2;
			}
			else if (input == "SE")
			{
				id = 3;
			}
			else if (input == "S")
			{
				id = 4;
			}
			else if (input == "SW")
			{
				id = 5;
			}
			else if (input == "W")
			{
				id = 6;
			}
			else if (input == "NW")
			{
				id = 7;
			}
			else
			{
				id = -1;
			}
			if (id == -1)
			{
				cout << "Undefined direction" << endl;
			}
			else
			{
				try
				{
					//int x = player.getX(), y = player.getY();
					//player.move(player.getX()+dir[id][0], player.getY()+dir[id][1]);
					//map.pseudomovePlayer(x,y,player);
					//cout << "move ok" << endl;
				}
				catch (string e)
				{
					cout << e << endl;
				}
			}
		}
		else if (cmd == "inventory")
		{
			int choose;
			cout << "[1] Engimon" << endl;
			cout << "[2] Skill Item" << endl;
			cout << "mau liat apaan nih: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				int pil;
				int i;
				for (int i = 0; i < player->getMyEngimons().listItem.capacity(); i++)
				{
					cout << "[" << i + 1 << "] ";
					cout << invEngimon->listItem.at(i)->getNamaEngimon() << endl;
				}
				cout << "Lihat detail engimon nomor: ";
				cin >> pil;
				invEngimon->listItem.at(pil - 1)->printInfoEngimon();
				cout << endl;
				break;
			case 2:
				for (int i = 0; i < player->getMySkillItems().listItem.capacity(); i++)
				{
					cout << "[" << i + 1 << "] ";
					cout << invSkill->listItem.at(i)->getNamaSkill() << endl;
				}
			default:
				break;
			}
		}
    else if (cmd == "useskill"){
      int pil, pil2;
      int i;
      for (int i = 0; i < player->getMyEngimons().listItem.capacity(); i++)
      {
        cout << "[" << i + 1 << "] ";
        cout << invEngimon->listItem.at(i)->getNamaEngimon() << endl;
      }
      cout << "Mau pakein skill ke siapa nih: ";
      cin >> pil;
      for (int i = 0; i < player->getMySkillItems().listItem.capacity(); i++)
      {
        cout << "[" << i + 1 << "] ";
        cout << invSkill->listItem.at(i)->getNamaSkill() << endl;
      }
      cout << "Mau pake yang mana: ";
      cin >> pil2;
      
      invEngimon->listItem.at(pil - 1)->learnSkill(invSkill->listItem.at(pil2-1));
    }
		else
		{
			cout << "Unknown command" << endl;
		}
	}

	void moveRandom(Engimon *e)
	{
		int dir[8][2] = {
			{0, 1},	  // N
			{1, 1},	  // NE
			{1, 0},	  // E
			{1, -1},  // SE
			{0, -1},  // S
			{-1, -1}, // SW
			{-1, 0},  // W
			{-1, 1}	  // NW
		};
		bool condition = false;
		int deltaX, deltaY;

		while (!condition)
		{
			srand(time(0));
			int acak = rand() % 8;
			int *diracak = dir[acak];
			deltaX = e->getX() + diracak[0];
			deltaY = e->getY() + diracak[1];
			condition = map->isGrassLand(deltaX, deltaY);
			// sesuaiin sama element masing2 anak
			// kl electric,ground,fire pake isgrassland
			// kl water/ice pake issea
			// kl dua element,
			// electrice fire isground
			// water ice issea
			// kl ground/water condition = true aj
		}

		e->move(deltaX, deltaY);
	}

public:
	Game()
	{
		turn = 0;
		newgame = false;
		/* init player, map, engimon, dll */
		// inventory
		//Inventory engimons1();
		//Inventory skillItems1();
		//engimons = engimons1;
		//skillItems = skillItems1;
		//Engimons def();
		//engimonDefault = def;

		// map
		map = new Map();
		engimonDefault = new Engimon();
		invEngimon = new Inventory<Engimon>();
		invSkill = new Inventory<Skill>();
	}

	~Game()
	{
		/* destroy all */
	}

	void start()
	{
		intro();
		init();
		play();
	}
};

#endif