#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


enum {
	COMMAND_ATTACK,
	COMMAND_SPEL,
	COMMAND_DEFENCE,
	COMMAND_MAX
};

char commandName[][4 * 2 + 1] = {
	"たたかう",	//COMMAND_ATTACK,
	"ベホイミ", //COMMAND_SPEL,
	"ぼうぎょ"  //COMMAND_DEFENCE
};

int command;


typedef struct {
	int strength;
	int agility;
	int maxHP;
	int maxMP;

	int level;
	int attack;
	int defence;
	int HP;
	int MP;
}CHARACTER;


CHARACTER statusTable[] = {
	//力、素早さ、HP、MP
 {4, 4, 15, 0},
 {5, 4, 94, 35},
 {7, 6, 98, 45}

};

CHARACTER player;

CHARACTER enemy;


void display() {

	system("cls");

	printf("＋－勇者－＋\n"
		"|レベル%4d|\n"
		"|HP　　%4d|\n"
		"|MP　　%4d|\n"
		"＋ーーー－＋\n"
		,player.level
		,player.HP
		,player.MP

	
	);

#include "dorakue.txt"
	printf(aa);
	printf("(ＨＰ%4d)\n", enemy.HP);
}

int main() {
	srand((unsigned int)time(NULL));

	{
		int level = 2;
		player = statusTable[level - 1];
		player.level = level;
		player.attack = player.strength + 40;
		player.defence = player.agility / 2 + 28 + 20;
		player.HP = player.maxHP;
		player.MP = player.maxMP;
	}

	{
		enemy.attack = 60;
		enemy.defence = 25;
		enemy.HP = 100;
	}


	display();
	printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
		"｜りゅうおうが　しょうたいを　　　　　　｜\n"
		"｜あらわした！　　　　　　　　　　　　　｜\n"
		"｜　　　　　　　　　　　　　　　　　　　｜\n"
		"＋ーーーーーーーーーーーーーーーーーーー＋\n"

	);
	_getch();

	while (1) {

		while (1) {
			display();
			printf("＋－コマンド－＋\n");
			for (int i = 0; i < COMMAND_MAX; i++)
				printf("｜%s%s　｜\n", (i == command) ? "＞" : "　", commandName[i]);
			printf("＋－ーーーー－＋\n");

			int ch = _getch();
			if (ch == 0x0d)
				break;

			else
				switch (ch) {
				case 'w': command--; break;
				case 's': command++; break;
				}
			command = (COMMAND_MAX + command) % COMMAND_MAX;

		}

		switch (command) {

		case COMMAND_ATTACK: {
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜ゆうしゃの　こうげき！　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

			int damageBase = player.attack - enemy.defence / 2;
			int damageMin = damageBase / 4;
			int damageMax = damageBase / 2;
			int damage = damageMin + rand() % (damageMax - damageMin);
			enemy.HP -= damage;
			if (enemy.HP < 0) {
				enemy.HP = 0;
			}

			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜ゆうしゃの　こうげき！　　　　　　　　｜\n"
				"｜りゅうおうに　%2dポイントの　　　　　　｜\n"
				"｜ダメージをあたえた　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n",
				damage
			);
			_getch();
		}

						   break;
		case COMMAND_SPEL: {
			player.MP -= 10;
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜ゆうしゃは　ベホイミの　　　　　　　　｜\n"
				"｜じゅもんを　となえた！　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

			int heal = 85 + rand() % 14;
			if (heal + player.HP > player.maxHP) {
				heal = player.maxHP - player.HP;
			}
			player.HP += heal;

			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜ゆうしゃは　ベホイミの　　　　　　　　｜\n"
				"｜じゅもんを　となえた！　　　　　　　　｜\n"
				"｜%2dポイント　かいふくした！　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n",
				heal

			);
			_getch();

		}
						 break;

		case COMMAND_DEFENCE: {
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜ゆうしゃは　ぼうぎょした！　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

		}
							break;
		}
		if (enemy.HP <= 0) {
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜りゅうおうの　たおした！　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜せかいに　へいわが　　　　　　　　　　｜\n"
				"｜もどったのだ！　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();
			break;
		}




		if (rand() % 2) {
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜りゅうおうの　こうげき！　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

			int damageBase = enemy.attack - player.defence / 2;
			int damageMin = damageBase / 4;
			int damageMax = damageBase / 2;
			int damage = damageMin + rand() % (damageMax - damageMin);
			
		
			if (command == COMMAND_DEFENCE) {
				damage = damage / 2;
				player.HP -= damage;
				if (player.HP < 0) {
					player.HP = 0;
				}
				display();
				printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
					"｜りゅうおうの　こうげき！　　　　　　　｜\n"
					"｜ゆうしゃは　%2dポイントの　　　　　　　｜\n"
					"｜ダメージを　うけた　　　　　　　　　　｜\n"
					"＋ーーーーーーーーーーーーーーーーーーー＋\n",
					damage

				);
				_getch();
			}


			else {
				display();
				player.HP -= damage;
				if (player.HP < 0) {
					player.HP = 0;
				}
				printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
					"｜りゅうおうの　こうげき！　　　　　　　｜\n"
					"｜ゆうしゃは　%2dポイントの　　　　　　　｜\n"
					"｜ダメージを　うけた　　　　　　　　　　｜\n"
					"＋ーーーーーーーーーーーーーーーーーーー＋\n",
					damage

				);
				_getch();

			}
		}

		else {
			display();
			printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
				"｜りゅうおうは　ほのうをはいた！　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"｜　　　　　　　　　　　　　　　　　　　｜\n"
				"＋ーーーーーーーーーーーーーーーーーーー＋\n"

			);
			_getch();

			int damage = (64 + (rand() % 8)) * 2 / 3;


			if (command == COMMAND_DEFENCE) {
				damage = damage / 2;
				player.HP -= damage;
				if (player.HP < 0) {
					player.HP = 0;
				}
				display();
				printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
					"｜りゅうおうは　ほのうをはいた！　　　　｜\n"
					"｜ゆうしゃは　%2dポイントの　　　　　　　｜\n"
					"｜ダメージを　うけた！　　　　　　　　　｜\n"
					"＋ーーーーーーーーーーーーーーーーーーー＋\n",
					damage

				);

				_getch();
			}
			else {
				player.HP -= damage;
				if (player.HP < 0) {
					player.HP = 0;
				}
				display();
				printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
					"｜りゅうおうは　ほのうをはいた！　　　　｜\n"
					"｜ゆうしゃは　%2dポイントの　　　　　　　｜\n"
					"｜ダメージを　うけた！　　　　　　　　　｜\n"
					"＋ーーーーーーーーーーーーーーーーーーー＋\n",
					damage

				);

				_getch();
			}

			if (player.HP <= 0) {
				display();
				printf("＋－－－－－－－－－－－－－－－－－－－＋\n"
					"｜あなたは　しにました・・　　　　　　　｜\n"
					"｜　　　　　　　　　　　　　　　　　　　｜\n"
					"｜　　　　　　　　　　　　　　　　　　　｜\n"
					"＋ーーーーーーーーーーーーーーーーーーー＋\n"

				);
				_getch();
				break;
			}


			_getch();
		}
	}
}