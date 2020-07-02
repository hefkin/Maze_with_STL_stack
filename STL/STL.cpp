#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cout << "Choose the difficulty of the maze:\n1. Eazy:\n\n@-@@@\n@ @ |\n@ @ @\n@   @\n@@@@@\n\n";
	cout << "2. Hard:\n\n@-@@@@@@\n@ @@   @\n@    @ @\n@@@@@  @\n@     @@\n@ @@@@ |\n@      @\n@@@@@@@@\n\n";
	cout << "Your choice: ";
	int dif = 0;
	cin >> dif;
	if (dif == 1) dif = 5;
	else dif = 8;
	int** n;
	n = new int* [dif];
	int k = 0;
	int eazy_maze[25] =
	{ 1,2,1,1,1,
		1,0,1,0,4,
		1,0,1,0,1,
		1,0,0,0,1,
		1,1,1,1,1,
	};
	int hard_maze[64] =
	{ 1,2,1,1,1,1,1,1,
		1,0,1,1,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,1,1,1,1,0,0,1,
		1,0,0,0,0,0,1,1,
		1,0,1,1,1,1,0,4,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};
	for (int i = 0; i < dif; i++)
	{
		n[i] = new int[dif];
	}
	if (dif == 5)
	{
		for (int i = 0; i < dif; i++)
		{
			for (int j = 0; j < dif; j++)
			{
				n[j][i] = eazy_maze[k];
				k++;
			}
		}
	}
	else
	{
		for (int i = 0; i < dif; i++)
		{
			for (int j = 0; j < dif; j++)
			{
				n[j][i] = hard_maze[k];
				k++;
			}
		}
	}
	system("pause");
	system("cls");
	if (dif == 5)
	{
		cout << "Eazy:\n\n@-@@@\n@ @ |\n@ @ @\n@   @\n@@@@@\n\n";
	}
	else
	{
		cout << "Hard:\n\n@-@@@@@@\n@ @@   @\n@    @ @\n@@@@@  @\n@     @@\n@ @@@@ |\n@      @\n@@@@@@@@\n\n";
	}
	stack<int> ss;
	int l_x = 1, l_y = 1, cord = 0;
	ss.push(l_y + 1); ss.push(l_x);
	ss.push(l_y + 1); ss.push(l_x + 1);
	ss.push(l_y); ss.push(l_x + 1);
	ss.push(l_y); ss.push(l_x);
	while (!((n[l_x + 1][l_y] == 4) || (n[l_x - 1][l_y] == 4) || (n[l_x][l_y + 1] == 4) || (n[l_x][l_y - 1] == 4)))
	{
		if (n[l_x - 1][l_y] == 0)
		{
			n[l_x][l_y] = 3;
			l_x = l_x - 1;
			cout << "Left!\n";
		}
		else
		{
			if (n[l_x + 1][l_y] == 0)
			{
				n[l_x][l_y] = 3;
				l_x = l_x + 1;
				cout << "Right!\n";
			}
			else
			{
				if (n[l_x][l_y - 1] == 0)
				{
					n[l_x][l_y] = 3;
					l_y = l_y - 1;
					cout << "Up!\n";
				}
				else
				{
					n[l_x][l_y] = 3;
					l_y = l_y + 1;
					cout << "Down!\n";
				}
			}
		}
		ss.push(l_y + 1); ss.push(l_x);
		ss.push(l_y + 1); ss.push(l_x + 1);
		ss.push(l_y); ss.push(l_x + 1);
		ss.push(l_y); ss.push(l_x);
	}
	cout << "\nDone!\n";
	int xy = 0, count = 1, count_8 = 8, count_quad = 1, temp = 0;
	int q = ss.size();
	for (int i = 0; i < q; i++)
	{
		if (count_8 == 8)
		{
			cout << endl << "Quadrate number " << count_quad << endl;
			count_8 = 0;
			count = 1;
			count_quad++;
		}
		if (xy == 0)
		{
			temp = ss.top();
			cout << "x" << count << " " << temp << '\t';
			ss.pop();
			xy = 1;
		}
		else
		{
			temp = ss.top();
			cout << "y" << count << " " << temp << endl;
			ss.pop();
			xy = 0;
			count++;
			count_8 += 2;
		}

	}
}