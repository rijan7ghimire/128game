#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include"movement.h"
using namespace std;

void addblock(int a[4][4])
{
	int li, ri;
	srand(time(0));
	while (1)
	{
		li = rand() % 4;
		ri = rand() % 4;
		if (a[li][ri] == 0)
		{
			a[li][ri] = pow(2, li % 2 + 1);
			break;
		}
	}

}

int disp(int a[4][4])
{
	cout << "\t\t\t\t\tPress Esc anytime to quit the game";
	cout << "\n\n\n\n";
	int i, j;
	for (i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t_________________\n\t\t\t\t";
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 0) cout << "|   ";
			else
				cout << "| " << a[i][j] << " ";
				if (a[i][j] == 128 )
                return 0;
		}
		cout << "|" << endl;
	}
	cout << "\t\t\t\t_________________\n";
}

int check(int tmp[4][4], int a[4][4])
{
	int fl = 1, i, j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++)
			if (tmp[i][j] != a[i][j])
			{
				fl = 0;
				break;
			}
			}
	return fl;
}

int checkover(int a[4][4])
{
	int fl = 0, gl = 0, i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (a[i][j] == 0)
			{
				fl = 1;
				break;
			}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
			{
				gl = 1;
				break;
			}

	if (fl || gl) return 1;
	else return 0;
}

int main()
{
	cout << "\n\n\n\n\t\t\t128 GAME\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1, i2, i3, i4, i, j;
	int a[4][4] = { 0 }, tmp[4][4] = { 0 };
	srand(time(0));
	i1 = rand() % 4;
	i2 = rand() % 4;
	while (1)
	{
		i3 = rand() % 4;
		i4 = rand() % 4;
		if (i3 != i1 && i4 != i2) break;
	}
	a[i1][i2] = 2;
	a[i3][i4] = 4;
	disp(a);

	int ch,gameWin;
	up ArrowUp;
	down ArrowDown;
	Left ArrowLeft;
	Right ArrowRight;
	movement *UP= &ArrowUp;
	movement *DOWN= &ArrowDown;
	movement *LEFT = &ArrowLeft;
	movement *RIGHT= &ArrowRight;
	while (1)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				tmp[i][j] = a[i][j];
		ch = getch();
		system("cls");
		if (ch == 72) UP->move(a);
		if (ch == 80) DOWN->move(a);
		if (ch == 75) LEFT->move(a);
		if (ch == 77) RIGHT->move(a);
		if (ch == 27) break;

		if (!check(tmp, a))
			addblock(a);
			gameWin = disp(a);
			if(gameWin == 0){
                system("cls");
                cout << "\n\n\t\t\tYOU WON!!\n\n\n";
                break;
			}


		if (!checkover(a))
		{
			cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}
	}
	return 0;
}

