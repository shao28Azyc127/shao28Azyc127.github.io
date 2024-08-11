#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

void pian3()
{
	long long admx = 0;
	map<string , int> table;
	map<int , int> tb;
	vector<int> type;
	vector<string> name;
	vector<long long> ads;
	int n;
	int op;
	int cnt_s = 1;
	type.push_back(0);
	name.push_back("");
	ads.push_back(0);
	long long tmp;
	string s;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> op;
		if(op == 2)
		{
			cin >> s;
			if(s == "byte") type.push_back(1);
			else if(s == "short") type.push_back(2);
			else if(s == "int") type.push_back(4);
			else if(s == "long") type.push_back(8);
			cin >> s;
			table[s] = cnt_s;
			name.push_back(s);
			if(admx % type[cnt_s] == 0)
			{
				cout << admx << endl;
				ads.push_back(admx);
				tb[admx] = cnt_s;
				admx += type[cnt_s];
			}
			else
			{
				admx = (admx / type[cnt_s] + 1) * type[cnt_s];
				cout << admx << endl;
				ads.push_back(admx);
				tb[admx] = cnt_s;
				admx += type[cnt_s];
			}
			cnt_s ++;
		}
		else if(op == 3)
		{
			cin >> s;
			cout << ads[table[s]] << endl;
		}
		else if(op == 4)
		{
			cin >> tmp;
			bool flag = 0;
			for(int j = tmp ; j >= 0 ; j --)
			{	
				if(tb[j] != 0)
				{
					cout << name[tb[j]] << endl;
					flag = 1;
					break;
				}
			}
			if(!flag) cout << "ERR" << endl;
		}
	}
}
int main()
{
	freopen("struct.in" , "r" , stdin);
	freopen("struct.out" , "w" , stdout);	
	pian3();
	return 0;
}