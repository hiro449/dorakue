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
	"��������",	//COMMAND_ATTACK,
	"�x�z�C�~", //COMMAND_SPEL,
	"�ڂ�����"  //COMMAND_DEFENCE
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
	//�́A�f�����AHP�AMP
 {4, 4, 15, 0},
 {5, 4, 94, 35},
 {7, 6, 98, 45}

};

CHARACTER player;

CHARACTER enemy;


void display() {

	system("cls");

	printf("�{�|�E�ҁ|�{\n"
		"|���x��%4d|\n"
		"|HP�@�@%4d|\n"
		"|MP�@�@%4d|\n"
		"�{�[�[�[�|�{\n"
		,player.level
		,player.HP
		,player.MP

	
	);

#include "dorakue.txt"
	printf(aa);
	printf("(�g�o%4d)\n", enemy.HP);
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
	printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
		"�b��イ�������@���傤�������@�@�@�@�@�@�b\n"
		"�b����킵���I�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
		"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
		"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

	);
	_getch();

	while (1) {

		while (1) {
			display();
			printf("�{�|�R�}���h�|�{\n");
			for (int i = 0; i < COMMAND_MAX; i++)
				printf("�b%s%s�@�b\n", (i == command) ? "��" : "�@", commandName[i]);
			printf("�{�|�[�[�[�[�|�{\n");

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
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�䂤����́@���������I�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

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
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�䂤����́@���������I�@�@�@�@�@�@�@�@�b\n"
				"�b��イ�����Ɂ@%2d�|�C���g�́@�@�@�@�@�@�b\n"
				"�b�_���[�W�����������@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
				damage
			);
			_getch();
		}

						   break;
		case COMMAND_SPEL: {
			player.MP -= 10;
			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�䂤����́@�x�z�C�~�́@�@�@�@�@�@�@�@�b\n"
				"�b���������@�ƂȂ����I�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

			);
			_getch();

			int heal = 85 + rand() % 14;
			if (heal + player.HP > player.maxHP) {
				heal = player.maxHP - player.HP;
			}
			player.HP += heal;

			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�䂤����́@�x�z�C�~�́@�@�@�@�@�@�@�@�b\n"
				"�b���������@�ƂȂ����I�@�@�@�@�@�@�@�@�b\n"
				"�b%2d�|�C���g�@�����ӂ������I�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
				heal

			);
			_getch();

		}
						 break;

		case COMMAND_DEFENCE: {
			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�䂤����́@�ڂ����債���I�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

			);
			_getch();

		}
							break;
		}
		if (enemy.HP <= 0) {
			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b��イ�����́@���������I�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

			);
			_getch();

			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b�������Ɂ@�ւ��킪�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b���ǂ����̂��I�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

			);
			_getch();
			break;
		}




		if (rand() % 2) {
			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b��イ�����́@���������I�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

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
				printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
					"�b��イ�����́@���������I�@�@�@�@�@�@�@�b\n"
					"�b�䂤����́@%2d�|�C���g�́@�@�@�@�@�@�@�b\n"
					"�b�_���[�W���@�������@�@�@�@�@�@�@�@�@�@�b\n"
					"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
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
				printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
					"�b��イ�����́@���������I�@�@�@�@�@�@�@�b\n"
					"�b�䂤����́@%2d�|�C���g�́@�@�@�@�@�@�@�b\n"
					"�b�_���[�W���@�������@�@�@�@�@�@�@�@�@�@�b\n"
					"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
					damage

				);
				_getch();

			}
		}

		else {
			display();
			printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
				"�b��イ�����́@�ق̂����͂����I�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
				"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

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
				printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
					"�b��イ�����́@�ق̂����͂����I�@�@�@�@�b\n"
					"�b�䂤����́@%2d�|�C���g�́@�@�@�@�@�@�@�b\n"
					"�b�_���[�W���@�������I�@�@�@�@�@�@�@�@�@�b\n"
					"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
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
				printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
					"�b��イ�����́@�ق̂����͂����I�@�@�@�@�b\n"
					"�b�䂤����́@%2d�|�C���g�́@�@�@�@�@�@�@�b\n"
					"�b�_���[�W���@�������I�@�@�@�@�@�@�@�@�@�b\n"
					"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n",
					damage

				);

				_getch();
			}

			if (player.HP <= 0) {
				display();
				printf("�{�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�{\n"
					"�b���Ȃ��́@���ɂ܂����E�E�@�@�@�@�@�@�@�b\n"
					"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
					"�b�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�b\n"
					"�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{\n"

				);
				_getch();
				break;
			}


			_getch();
		}
	}
}