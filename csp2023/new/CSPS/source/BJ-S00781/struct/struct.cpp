#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, op, t, tot = 0;
string str, str2, name;

string Name[3];

struct{
	int now;
	string na;
}p[210];

signed main()
{
	//freopen("struct.in", "r", stdin);
    //freopen("struct.out", "w", stdout);
    
	return 0;
}
/*
struct{
	string na;
	pair<int, string> inf[110];
	int a;
}p[110];
* 
* 
* 
* 
* 
int n;
    while(n--)
    {
		cin >> op;
		if(op == 1)
		{
			cin >> str >> t;
			for(int i = 1; i <= t; i++)
			{
				cin >> str2 >> name;
				int num = 1;
				if(str2 == "short") num = 2;
				if(str2 == "int") num = 4;
				if(str2 == "long") num = 8;
				p[++tot].inf[i].first = num;
				p[tot].inf[i].second = name;
				p[tot].na = str;
			}
		}else if(op == 2)
		{
			cin >> str2 >> name;
			int num = 1;
			if(str2 == "short") num = 2;
			if(str2 == "int") num = 4;
			if(str2 == "long") num = 8;
			p[++tot].inf[1].first = num;
			p[tot].inf[1].second = name;
		}else if(op == 3)
		{
			getline(cin, Name, '.');
			getchar();
			
		}	
	}
 */