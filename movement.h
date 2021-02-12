#ifndef MOVEMENT_H
#define MOVEMENT_H

class movement {
    public:
       virtual void move(int a[4][4]){}
    protected:
         int i, j, li, ri;

};

class up: public movement{
   public:
       void move(int a[4][4]){
	for (j = 0; j < 4; j++)
	{
		li = 0, ri = j;
		for (i = 1; i < 4; i++)
		{
			if (a[i][j] != 0)
			{
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j])
				{
					if (a[li][ri] == a[i][j])
					{
						a[li][ri] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[li][ri] == 0)
						{
							a[li][ri] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[++li][ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else li++;
			}
		}
	}
}
};

class down: public movement{
   public:
       void move(int a[4][4]){
	for (j = 0; j < 4; j++)
	{
		li = 3, ri = j;
		for (i = 2; i >= 0; i--)
		{
			if (a[i][j] != 0)
			{
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j])
				{
					if (a[li][ri] == a[i][j])
					{
						a[li][ri] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[li][ri] == 0)
						{
							a[li][ri] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[--li][ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else li--;
			}
		}
	}
       }
};

class Left: public movement{
   public:
       void move(int a[4][4]){
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 0;
		for (j = 1; j < 4; j++)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j])
				{
					if (a[li][ri] == a[i][j])
					{
						a[li][ri] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[li][ri] == 0)
						{
							a[li][ri] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[li][++ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else ri++;
			}
		}
	}
       }
};

class Right: public movement{
   public:
       void move(int a[4][4]){
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 3;
		for (j = 2; j >= 0; j--)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j])
				{
					if (a[li][ri] == a[i][j])
					{
						a[li][ri] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[li][ri] == 0)
						{
							a[li][ri] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[li][--ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else ri--;
			}
		}
	    }
       }
};
#endif // MOVEMENT_H
