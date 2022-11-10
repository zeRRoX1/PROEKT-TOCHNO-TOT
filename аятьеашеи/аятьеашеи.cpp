#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

typedef enum Direction { up, down, right, left } Direction;
char Pole[4][4];
char X, Y;


//Создание игровой площадки 3x3
void Pole3x3() {
	char arr[9], buf, k = 0;
	bool flag = false;
	srand(time(NULL));
	for (int n = 0; n < 9;) {
		flag = false;
		buf = rand() % 9 + 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] == buf) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			arr[n] = buf;
			n++;
		}
	}
	for (int n = 0; n < 3; n++)
		for (int i = 0; i < 3; i++) {
			Pole[n][i] = arr[k];
			k++;
		}
	Pole[2][2] = 0;
	X = 2; Y = 2;
}

//Создание игровой площадки 4x4
void Pole4x4() {
	char arr[16], n, i, buf, k = 0;
	bool flag = false;
	srand(time(NULL));
	for (n = 0; n < 16; ) {
		flag = false;
		buf = rand() % 16 + 1;
		for (i = 0; i < n; i++) {
			if (arr[i] == buf) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			arr[n] = buf;
			n++;
		}
	}
	for (n = 0; n < 4; n++) {
		for (i = 0; i < 4; i++) {
			Pole[n][i] = arr[k];
			k++;
		}
	}
	Pole[3][3] = 0;
	X = 3; Y = 3;

}

// Организация перемещений
void Move(Direction dir) {
	switch (dir) {
	case up:
		if (Y > 0)
		{
			Pole[Y][X] = Pole[Y - 1][X];
			Pole[Y - 1][X] = 0;
			Y--;
		}
		else
			std::cout << "ИДИ В ДРУГУЮ СТОРОНУ" << std::endl;
		break;
	case down:
		if (Y < 3)
		{
			Pole[Y][X] = Pole[Y + 1][X];
			Pole[Y + 1][X] = 0;
			Y++;
		}
		else
			std::cout << "ИДИ В ДРУГУЮ СТОРОНУ" << std::endl;
		break;
	case right:
		if (X < 3){
		
			Pole[Y][X] = Pole[Y][X + 1];
			Pole[Y][X + 1] = 0;
			X++;
		}
		else
			std::cout << "ИДИ В ДРУГУЮ СТОРОНУ" << std::endl;
		break;
	case left:
		if (X > 0){
		
			Pole[Y][X] = Pole[Y][X - 1];
			Pole[Y][X - 1] = 0;
			X--;
		}
		else
			std::cout << "ИДИ В ДРУГУЮ СТОРОНУ" << std::endl;
		break;
	}
}

//ВЫВОД ПОЛЯ 3x3
void coutArr3x3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("   %d   ", Pole[i][j]);
			
		}
		std::cout << "\n\n";
	}	
}
//ВЫВОД ПОЛЯ 4x4
void coutArr4x4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("   %d   ", Pole[i][j]);
		}
		std::cout << "\n\n";
	}
}

//Проверка на выигрыш 
bool Proverka_Win() {
	int k = 1;
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; i++) {
			if (Pole[i][j] != k % 16)
				flag = true;
			else {
				flag = false;
				break;
			}
			k++;
		}
	}
	return flag;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int f = 2;
	std::cout << "\tПятнашки\t" << std::endl;
	std::cout << "Выберите поле(3x3 - 1; 4x4 - 2)" << std::endl;
	std::cin >> f;

		
	if (f == 1) {
		Pole3x3();
		coutArr3x3();
		printf("Куда двигаться? 'w,a,s,d'\n");
		while (!Proverka_Win()) {
			char key = getchar();
			switch (key)
			{
			case 119:
				Move(up);
				break;
			case 115:
				Move(down);
				break;
			case 100:
				Move(right);
				break;
			case 97:
				Move(left);
				break;
			}
			coutArr3x3();
			std::cout << "-----------------" << std::endl;
		}
		printf("	МАЛАДЕЦ ТЫ ВЫЙГРАЛ!!!! ЮХУУУУУ	");
	}
	else if (f == 2) {
		Pole4x4();
		coutArr4x4();
		printf("Куда двигаться? 'w,a,s,d'\n");
		while (!Proverka_Win()) {
			char key = getchar();
			switch (key)
			{
			case 119:
				Move(up);
				break;
			case 115:
				Move(down);
				break;
			case 100:
				Move(right);
				break;
			case 97:
				Move(left);
				break;
			}
			coutArr4x4();
		}
		printf("	МАЛАДЕЦ ТЫ ВЫЙГРАЛ!!!! ЮХУУУУУ	");
	}
}