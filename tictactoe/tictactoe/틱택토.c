#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define up 72
#define down 80
#define left 75
#define right 77
#define spacebar 32
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(int text, int bakground) {
	int color = (bakground << 4) | text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int gameboard[3][3] = {
 0,0,0,
 0,0,0,
 0,0,0,
};
void drawgameboard(int x, int y) {
	printf("忙式式式式式式式式式式式成式式式式式式式式式式式成式式式式式式式式式式式忖\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("戍式式式式式式式式式式式托式式式式式式式式式式式托式式式式式式式式式式式扣\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("戍式式式式式式式式式式式托式式式式式式式式式式式托式式式式式式式式式式式扣\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("弛           弛           弛           弛\n");
	printf("戌式式式式式式式式式式式扛式式式式式式式式式式式扛式式式式式式式式式式式戎\n");
	setColor(7, 0);
	gotoxy(6 * (x + x) - 6, (y * 6) + y + 1);
	printf("∪");
	gotoxy(6 * (x + x) - 2, (y * 6) + y + 3);
	printf("９");
	gotoxy(6 * (x + x) - 6, (y * 6) + y + 6);
	printf("～");
	gotoxy(6 * (x + x) - 10, (y * 6) + y + 3);
	printf("Ⅱ");
}
int checkfinish(int check) {
	if (gameboard[0][1] == gameboard[0][2] && gameboard[0][2] == gameboard[0][3] && gameboard[0][3] == 1 || gameboard[1][1] == gameboard[1][2] && gameboard[1][2] == gameboard[1][3] && gameboard[1][3] == 1 || gameboard[2][1] == gameboard[2][2] && gameboard[2][2] == gameboard[2][3] && gameboard[2][3] == 1 || gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] && gameboard[2][1] == 1 || gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] && gameboard[2][2] == 1 || gameboard[0][3] == gameboard[1][3] && gameboard[1][3] == gameboard[2][3] && gameboard[2][3] == 1 || gameboard[0][1] == gameboard[1][2] && gameboard[1][2] == gameboard[2][3] && gameboard[2][3] == 1 || gameboard[0][3] == gameboard[1][2] && gameboard[1][2] == gameboard[2][1] && gameboard[2][1] == 1) {
		return 1;
	}
	if (gameboard[0][1] == gameboard[0][2] && gameboard[0][2] == gameboard[0][3] && gameboard[0][3] == 2 || gameboard[1][1] == gameboard[1][2] && gameboard[1][2] == gameboard[1][3] && gameboard[1][3] == 2 || gameboard[2][1] == gameboard[2][2] && gameboard[2][2] == gameboard[2][3] && gameboard[2][3] == 2 || gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] && gameboard[2][1] == 2 || gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] && gameboard[2][2] == 2 || gameboard[0][3] == gameboard[1][3] && gameboard[1][3] == gameboard[2][3] && gameboard[2][3] == 2 || gameboard[0][1] == gameboard[1][2] && gameboard[1][2] == gameboard[2][3] && gameboard[2][3] == 2 || gameboard[0][3] == gameboard[1][2] && gameboard[1][2] == gameboard[2][1] && gameboard[2][1] == 2) {
		return 2;
	}
	if (check == 9) {
		return 3;
	}
	return 0;
}

int main() {
	int key;
	int x = 1, y = 0;
	int px[9], py[9];
	int b = 1;
	int check = 0;
	int c, q;
	drawgameboard(x, y);
	while (1) {
		q = checkfinish(check);
		if (q == 1 || q == 2 || q == 3) { Sleep(500); setColor(7, 0); break; }
		if (kbhit() == 1) {
			gotoxy(6 * (x + x) - 6, (y * 6) + y + 1);
			printf("  ");
			gotoxy(6 * (x + x) - 2, (y * 6) + y + 3);
			printf("  ");
			gotoxy(6 * (x + x) - 6, (y * 6) + y + 6);
			printf("  ");
			gotoxy(6 * (x + x) - 10, (y * 6) + y + 3);
			printf("  ");
			key = getch();
			if (key == up) {
				if (y > 0) {
					y--;
				}
			}
			else if (key == down) {
				if (y < 2) {
					y++;
				}
			}
			else if (key == right) {
				if (x < 3) {
					x++;
				}
			}
			else if (key == left) {
				if (x > 1) {
					x--;
				}
			}
			else if (key == spacebar) {
				for (int i = 0; i < 9; i++) {
					if (x == px[i] && y == py[i]) {
						c = 0;
						break;
					}
					else c = 1;
				}
				if (c == 1) {
					gotoxy(6 * (x + x) - 6, (y * 6) + y + 3);
					if (b == 1)setColor(9, 0);
					if (b == 2)setColor(12, 0);
					printf("≒");
					gameboard[y][x] = b;
					px[check] = x;
					py[check] = y;
					b = 2 - check % 2;
					check += 1;
				}
			}
			setColor(7, 0);
			gotoxy(6 * (x + x) - 6, (y * 6) + y + 1);
			printf("∪");
			gotoxy(6 * (x + x) - 2, (y * 6) + y + 3);
			printf("９");
			gotoxy(6 * (x + x) - 6, (y * 6) + y + 6);
			printf("～");
			gotoxy(6 * (x + x) - 10, (y * 6) + y + 3);
			printf("Ⅱ");
		}
	}
	if (q == 1 || q == 2) {
		gotoxy(37, 10);
		printf("忙式式式式式式式式式式忖");
		gotoxy(37, 11);
		printf("弛 %dp陛 檜梯弛", q);
		gotoxy(37, 12);
		printf("戌式式式式式式式式式式戎");
		gotoxy(20, 20);
		Sleep(1000);
	}
	else if (q == 3) {
		gotoxy(37, 10);
		printf("忙式式式式式式式式式式忖");
		gotoxy(37, 11);
		printf("弛   綠梯   弛");
		gotoxy(37, 12);
		printf("戌式式式式式式式式式式戎");
		gotoxy(20, 20);
		Sleep(1000);
	}
}