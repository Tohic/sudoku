#include<windows.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
		{
			MoveToEx(hdc, x1, y1, NULL);
			return LineTo(hdc, x2, y2);
		}
UINT H = 550;
UINT W = 500;
class setka
{
public:
	int **num;
	int scr[9][9];
	setka()
	{
		int i = 0, j = 0;
		num = new int *[9];
		for (i = 0; i < 9; i++)
			num[i] = new int[9];
		nul();
	}
	~setka()
	{
		for (int i = 0; i < 9; i++)
			delete num[i];
		delete num;
	}
	void nul()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				scr[i][j] = 0;
				num[i][j] = 0;
			}
	}
};
class sudoku_decision
{
protected:
	setka dec;
public:
	sudoku_decision()
	{

	};
	~sudoku_decision()
	{
	};
	void create()
	{
		int i, j, k = 1;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				dec.num[i][j] = k;
				k++;
			}
		create_line(0, 3);
		create_line(0, 6);
		create_colomn(3, 0);
		create_line(3, 3);
		create_line(3, 6);
		perenos_line(3);
		create_colomn(6, 0);
		create_line(6, 3);
		create_line(6, 6);

		create_transporting1();
		perenos_hor();
		perenos_ver();
		create_transporting2();
	}
	void create_line(int x, int y)
	{
		int i, j, k = x + 1;
		for (i = x; i < (x + 3); i++)
		{
			for (j = y; j < (y + 3); j++)
				dec.num[i][j] = dec.num[k][j - 3];
			if (k < (x + 2))k++; else k = x;
		}
		k = 1 + rand() % 2;

	}
	void create_colomn(int x, int y)
	{
		int i, j, k = y + 1, a, q;
		for (j = y; j < (y + 3); j++)
		{
			for (i = x; i < (x + 3); i++)
				dec.num[i][j] = dec.num[i - 3][k];
			if (k < (y + 2)) k++; else k = y;
		}
		q = 1 + rand() % 2;
		a = dec.num[x][y];
		dec.num[x][y] = dec.num[x + q][y];
		dec.num[x + q][y] = a;

	}
	void create_transporting1()//главная диагональ
	{
		int i, j, a;
		for (i = 0; i < 9; i++)
			for (j = i; j < 9; j++)
			{
				a = dec.num[i][j];
				dec.num[i][j] = dec.num[j][i];
				dec.num[j][i] = a;
			}
	}
	void create_transporting2()//побочная диагональ
	{
		int i, j, a;
		for (i = 0; i < 9; i++)
			for (j = 0; j < (9 - i); j++)
			{
				a = dec.num[i][j];
				dec.num[i][j] = dec.num[8 - j][8 - i];
				dec.num[8 - j][8 - i] = a;
			}
	}
	void perenos_hor()
	{
		int *c;
		int k, l, m, i;
		k = 3 * (1 + rand() % 3) - 1;
		m = 3 * (2 + rand() % 2) - 1;
		for (i = 0; i < 3; i++)
		{
			c = dec.num[k - i];
			dec.num[k - i] = dec.num[m - i];
			dec.num[m - i] = c;
		}
		for (k = 2; k < 9; k = k + 3)
		{
			l = k - (1 + rand() % 2);
			c = dec.num[k];
			dec.num[k] = dec.num[l];
			dec.num[l] = c;
		}
	}
	void perenos_line(int k)
	{
		int *c, m;
		m = 1 + rand() % 2;
		c = dec.num[k];
		dec.num[k] = dec.num[k + m];
		dec.num[k + m] = c;
	}
	void perenos_ver()
	{
		int c;
		int k, l, m, i;
		k = 3 * (1 + rand() % 2) - 1;
		m = 3 * (2 + rand() % 2) - 1;
		for (i = 0; i < 3; i++)
		{
			for (l = 0; l < 9; l++)
			{
				c = dec.num[l][k - i];
				dec.num[l][k - i] = dec.num[l][m - i];
				dec.num[l][m - i] = c;
			}
		}
		for (k = 2; k < 9; k = k + 3)
		{
			l = k - (1 + rand() % 2);
			for (i = 0; i < 9; i++)
			{
				c = dec.num[i][k];
				dec.num[i][k] = dec.num[i][l];
				dec.num[i][l] = c;
			}
		}
		perenos_hor();
	}
	void draw_dec(HDC hdc, int xb, int x, int y)
	{
		int i, j;
		char st[10] = "";
		RECT r1, r2;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (dec.scr[i][j])
				{
					sprintf(st, "%d", dec.num[i][j]);
					if (dec.num[i][j] == xb && x != i && y != j)
					{
						r1.left = j * 40 + 60;
						r1.top = i * 40 + 68;
						r1.right = r1.left + 40;
						r1.bottom = r1.top + 40;
						r2 = r1;
						r2.left += 5;
						r2.top += 5;
						r2.bottom -= 4;
						r2.right -= 4;
						FillRect(hdc, &r1, HBRUSH(CreateSolidBrush(RGB(80, 80, 80))));
						FillRect(hdc, &r2, HBRUSH(CreateSolidBrush(RGB(255, 255, 255))));
					}
				}
				else strcpy(st, " ");
				TextOut(hdc, W / 2 - 225 + j * 40, 75 + i * 40, (LPCWSTR)st, 1);
			}
		}
	}
};
class sudoku_user : public sudoku_decision
{
protected:
	setka  user;
	int nn, count, cnt;
public:
	sudoku_user()
	{
		count = nn = 0;
	}
	~sudoku_user()
	{}
	void tooltip(int i, int j)
	{
		if (!dec.scr[i][j])
		{
			user.scr[i][j] = 1;
			user.num[i][j] = dec.num[i][j];
			nn++;
		}
	}
	int kolvo()
	{
		return nn;
	}
	void hide()
	{
		if (nn)
		{
			int qq, fl, i, j;
			qq = rand() % nn + 1;
			for (i = 0; i < 9; i++)
				for (j = 0; j < 9; j++)
				{
					if (user.scr[i][j] == 1)
					{
						qq--;
						if (!qq)
						{
							user.scr[i][j] = 0;
							user.num[i][j] = 0;
							nn--;
						}
					}
				}
		}
	}
	void show(int k)
	{
		int cc, kk, kk1, i = 0, j, q;

		switch (k)
		{
		case 1: cnt = count = 40;
			nn = 0;
			kk = 2; kk1 = 4;
			user.nul();
			create();
			break;
		case 2: cnt = count = 31;
			kk = 2; kk1 = 3;
			nn = 0;
			user.nul();
			create();
			break;
		case 3: cnt = count = 28;
			kk = 1; kk1 = 3;
			nn = 0;
			user.nul();
			create();
			break;
		case 4:
			for (i = 0; i < 9; i++)
				for (j = 0; j < 9; j++)
				{
					if (!dec.scr[i][j])
						if (!user.num[i][j])
						{
							user.scr[i][j] = -1;
							user.num[i][j] = dec.num[i][j];
						}
				}
			return;

		}
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				dec.scr[i][j] = 0;
		i = j = 0;
		while (count > 0 && i < 9)
		{
			cc = rand() % kk + kk1;
			if (((count - cc) > 0) && i == 8 || (count - cc) < 0) cc = count;

			for (j = 0; j < cc && j < 9; j++)
			{
				q = rand() % 10;
				if (!dec.scr[i][q])
					dec.scr[i][q] = 1;
				else if (!dec.scr[i][j])
					dec.scr[i][j] = 1;
				else j--;
			}
			count -= cc;
			i++;
		}

	}
	int  add_us(int x, int y, int zn)
	{
		if (!dec.scr[x][y])
		{
			user.num[x][y] = zn;
			if (dec.num[x][y] == zn)
			{
				user.scr[x][y] = 1;
				nn++;
				return 1;
			}
			else
			{
				if (user.scr[x][y] == 1) nn--;
				user.scr[x][y] = -1;
				return 0;
			}

		}
		return 0;
	}
	void del(int x, int y)
	{
		user.scr[x][y] = 0;
	}
	void draw_us(HDC hdc, int xa, int x, int y)
	{
		int i, j;
		char st[10] = "";
		RECT r1, r2;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (!dec.scr[i][j] && user.num[i][j])
				{
					if (user.scr[i][j] > 0) SetTextColor(hdc, RGB(0, 0, 255));
					else
						if (user.scr[i][j] < 0) SetTextColor(hdc, RGB(255, 0, 0));
					if (user.num[i][j] == xa && x != i && y != j)
					{
						r1.left = j * 40 + 60;
						r1.top = i * 40 + 68;
						r1.right = r1.left + 40;
						r1.bottom = r1.top + 40;
						r2 = r1;
						r2.left += 5;
						r2.top += 5;
						r2.bottom -= 4;
						r2.right -= 4;
						FillRect(hdc, &r1, HBRUSH(CreateSolidBrush(RGB(80, 80, 80))));
						FillRect(hdc, &r2, HBRUSH(CreateSolidBrush(RGB(255, 255, 255))));
					}
					sprintf(st, "%d", user.num[i][j]);
					TextOut(hdc, W / 2 - 225 + j * 40, 75 + i * 40, (LPCWSTR)st, 1);
				}


			}
		}
	}
};
class sudoku : public sudoku_user
{
public:
	FILE *f, *f1;
	bool flag;
	sudoku()
	{
		sudoku_user();
		sudoku_decision();
		flag = 1;
		f = fopen("data.txt", "r");
		int i = 0, j = 0;
		if (f != NULL)
			for (i = 0; i < 9; i++)
				for (j = 0; j < 9; j++)
				{
					fscanf(f, "%d", &dec.num[i][j]);
					fscanf(f, "%d", &dec.scr[i][j]);
					if (dec.scr[i][j] == 1) count++;
					fscanf(f, "%d", &user.num[i][j]);
					fscanf(f, "%d", &user.scr[i][j]);
					if (user.scr[i][j] == 1) nn++;
				}
		if (i == 0 || j == 0) flag = 1;
		else flag = 0;

	}
	~sudoku()
	{
		int i, j;
		f1 = fopen("data.txt", "w");
		if (f1 == NULL)
			return;
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
			{
				fprintf(f1, "%d ", dec.num[i][j]);
				fprintf(f1, "%d ", dec.scr[i][j]);
				fprintf(f1, "%d ", user.num[i][j]);
				fprintf(f1, "%d ", user.scr[i][j]);
			}
	}

	void draw(HDC hdc, int x, int y)
	{
		int i, j;
		char st[50] = "", *s;
		int xxx = 0;
		if (dec.scr[x][y]) xxx = dec.num[x][y];
		else if (user.scr[x][y]) xxx = user.num[x][y];
		draw_dec(hdc, xxx, x, y);
		draw_us(hdc, xxx, x, y);
		for (i = 0; i < 9; i++)
		{
			Line(hdc, 60, (i + 1) * 40 - 7 + 35, 420, (i + 1) * 40 - 7 + 35);
			Line(hdc, 60 + i * 40, 33 + 35, 60 + i * 40, 393 + 35);
			if (i % 3 == 0)
			{
				Line(hdc, 59, (i + 1) * 40 - 6 + 35, 421, (i + 1) * 40 - 6 + 35);
				Line(hdc, 60 + i * 40 - 1, 33 + 35, 60 + i * 40 - 1, 393 + 36);
				Line(hdc, 60, (i + 1) * 40 - 8 + 35, 420, (i + 1) * 40 - 8 + 35);
				Line(hdc, 60 + i * 40 + 1, 33 + 35, 60 + i * 40 + 1, 393 + 35);
			}
		}
		Line(hdc, 60, (i + 1) * 40 - 7 + 35, 421, (i + 1) * 40 - 7 + 35);
		Line(hdc, 60 + i * 40, 33 + 34, 60 + i * 40, 393 + 37);
		Line(hdc, 60, (i + 1) * 40 - 6 + 35, 420, (i + 1) * 40 - 6 + 35);
		Line(hdc, 60 + i * 40 - 1, 33 + 35, 60 + i * 40 - 1, 393 + 35);
		Line(hdc, 60, (i + 1) * 40 - 8 + 35, 420, (i + 1) * 40 - 8 + 35);
		Line(hdc, 60 + i * 40 + 1, 33 + 35, 60 + i * 40 + 1, 393 + 36);

	}
	double procent()
	{

		double xxx;
		if (nn < (81 - cnt))
		{
			xxx = (double)nn / (81 - cnt) * 100;
			return xxx;

		}
		else
			return 100.00;

	}
	void nnul()
	{
		user.nul();
		dec.nul();
	}
};
