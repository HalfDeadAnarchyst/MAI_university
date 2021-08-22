typedef struct arr{
	int b[6];
};
int combination(int* a);
arr find_m(int *a);

int combination(int* a)
{
	arr comb;
	int z = 0;
	int i = 0;
	bool m_street, house, dole, b_street,n;
	b_street = m_street = house = dole = n = false;
	comb = find_m(a);
	printf("\n");
	while (i != 6)
	{
		if (comb.b[i] == 0)
		{
			i++;
		}
		if (comb.b[i] == 5)
		{
			return 9;
		}
		if (comb.b[i] == 4)
		{
			return 8;
		}
		if (comb.b[i] == 3)
		{
			z = i;
			while (z != 6)
			{
				z++;
				if (comb.b[z] == 2)
				{
					house = true;
				}
			}
			if (house == true)
			{
				return 7;
			}
			else
			{
				return 4;
			}
		}
		if (comb.b[i] == 2)
		{
			z = i;
			while (z != 6)
			{
				z++;
				if (comb.b[z] == 3)
				{
					house = true;
				}
				if (comb.b[z] == 2)
				{
					dole = true;
				}
			}
			if (house == true)
			{
				return 7;
			}
			if (dole == true)
			{
				return 3;
			}
			else   { return 2; }
		}
		if (comb.b[0] == 1 && comb.b[1] == 1 && comb.b[2] == 1 && comb.b[3] == 1 && comb.b[4] == 1)
		{
			return 5;
		}
		if (comb.b[1] == 1 && comb.b[2] == 1 && comb.b[3] == 1 && comb.b[4] == 1 && comb.b[5] == 1)
		{
			return 6;
		}
		i++;
	}
	return 1;
}
arr find_m(int *a)
{
	arr s;
	s.b[0] = s.b[1] = s.b[2] = s.b[3] = s.b[4] = s.b[5] = 0;
	for (int i = 0; i<6; i++)
	{
		switch (a[i])
		{
		case 1:{
				   s.b[0]++; break; }
		case 2:{
				   s.b[1]++; break; }
		case 3:{
				   s.b[2]++; break; }
		case 4:{
				   s.b[3]++; break; }
		case 5:{
				   s.b[4]++; break; }
		case 6:{
				   s.b[5]++; break; }
		}
	}
	return s;
}

void res(int a){
	switch (a)
	{
	case 1:
	{printf("Nothing\n"); break; }
	case 2:
	{printf("Pair\n"); break; }
	case 4:
	{printf("Set\n"); break; }
	case 8:
	{printf("Karre\n"); break; }
	case 9:
	{printf("Poker\n"); break; }
	case 5:
	{printf("Small Street\n"); break; }
	case 6:
	{printf("Big Street\n"); break; }
	case 7:
	{printf("Full-house\n"); break; }
	case 3:
	{printf("Double pair\n"); break; }
	}
}
void display (int a)
{
switch (a)
	{
	case 1:
	{printf("___\n"); printf("| . |\n"); printf("|   |\n");printf("___\t");break; }
	case 2:
	{printf("___\n"); printf("|. .|\n"); printf("|   |\n");printf("___\t");break; }
	case 3:
	{printf("___\n"); printf("|...|\n"); printf("|   |\n");printf("___\t");break; }
	case 4:
	{printf("___\n"); printf("|...|\n"); printf("| . |\n");printf("___\t");break; }
	case 5:
		{printf("___\n"); printf("|...|\n"); printf("|. .|\n");printf("___\t");break; }
	case 6:
	{printf("___\n"); printf("|...|\n"); printf("|...|\n");printf("___\t");break; }
	}	
}
