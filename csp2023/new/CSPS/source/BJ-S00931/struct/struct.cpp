#include <bits/stdc++.h>
using namespace std;

int n;
string argname, argtype;
int argmem, argnum;
int op;
struct Struct;
struct type
{
	string name;
	int cost;
	Struct* iss;
	type(Struct* isss = NULL)
	{
		iss = isss;
	}
};
struct Struct
{
	vector<type> members;
	string name;
	int cost, single;
};

vector <Struct> Structs;

vector <type> memory;
type curr;

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin >> n;
	for (int IDX = 0; IDX < n; IDX++)
	{
		cin >> op;
		int currmem = 0;
		if(op == 1)
		{
			Struct st;
			string tname;
			int m = INT_MIN;
			cin >> tname >> argnum;
			for (int i = 0; i < argnum; i++)
			{
				type arg;
				cin >> argtype >> argname;
				arg.name = argname;
				if (argtype == "byte")
				{
					m = m < 1 ? m : 1;
					arg.cost = 1;
				}
				else if (argtype == "short")
				{
					m = m < 2 ? m : 2;
					arg.cost = 2;
				}
				else if (argtype == "int")
				{
					m = m < 4 ? m : 4;
					arg.cost = 4;
				}
				else if (argtype == "long")
				{
					m = m < 8 ? m : 8;
					arg.cost = 8;
				}
				else
				{
					for (auto j = Structs.begin(); j < Structs.end(); j++)
					{
						if ((*j).name == argtype)
						{
							m = m < (*j).cost ? m : (*j).cost;
							arg.cost = (*j).cost;
						}
					}
				}
				st.members.push_back(arg);
			}
			st.single = m;
			st.cost = m * argnum;
			st.name = tname;
			printf("%d %d\n", st.cost, st.single);
		}
		else if (op == 2)
		{
			cin >> argtype >> argname;
			curr.name = argname;
			if (argtype == "byte")
			{
				curr.cost = 1;
			}
			else if (argtype == "short")
			{
				curr.cost = 2;
			}
			else if(argtype == "int")
			{
				curr.cost = 4;
			}
			else if (argtype == "long")
			{
				curr.cost = 8;
			}
			else
			{
				for (auto i = Structs.begin(); i < Structs.end(); i++)
				{
					if ((*i).name == argtype)
					{
						curr.cost = (*i).cost;
						curr.iss = &(*i);
					}
				}
			}
			for (auto i = memory.begin(); i < memory.end(); i++)
			{
				currmem += (*i).cost;
			}
			printf("%d\n", currmem + 1);
			memory.push_back(curr);
		}
		else if (op == 3)
		{
			cin >> argname;
			string name = argname;
			string :: iterator it;
			bool hasdot = false;
			for (it = argname.begin(); it < argname.end(); it++)
			{
				if ((*it) == '.')
				{
					hasdot = true;
					argname = string(argname.begin(), it);
				}
			}
			if (!hasdot)
			{
				for (auto i = memory.begin(); i < memory.end(); i++)
				{
					if ((*i).name == argname)
					{
						printf("%d\n", currmem + 1);
					}
					currmem += (*i).cost;
				}
			}
			else
			{
				for (auto i = memory.begin(); i < memory.end(); i++)
				{
					if ((*i).name == argname)
					{
						for (auto j = (*i).iss->members.begin(); j < (*i).iss->members.end(); j++)
						{
							if (argname + "." + (*j).name == name)
							{
								printf("%d\n", currmem + 1);
							}
							currmem += (*i).iss->cost;
						}
					}
					currmem += (*i).cost;
				}
			}
		}
		else
		{
			vector<type> :: iterator ite = memory.begin();
			cin >> argmem;
			for (; ite < memory.end(); ite++)
			{
				if ((currmem < argmem) && (currmem + (*ite).cost >= argmem))
					break;
				currmem += (*ite).cost;
			}
			if ((currmem < argmem) && (currmem + (*ite).cost >= argmem))
			{
				if ((*ite).iss != NULL)
				{
					for (auto j = (*ite).iss->members.begin(); j < (*ite).iss->members.end(); j++)
					{
						if (currmem < argmem && currmem + (*j).cost >= argmem)
						{
							cout << (*ite).name << "." << (*j).name << endl;
						}
					}
				}
				else
				{
					cout << (*ite).name << endl;
				}
			}
			else
				cout << "ERR" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
