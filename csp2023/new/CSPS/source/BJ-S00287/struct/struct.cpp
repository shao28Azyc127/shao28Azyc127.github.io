#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

#define BT 1
#define ST 2
#define IT 4
#define LG 8

/*
struct TPS{
	int sta;
	vector <int> mb;	//member
	vector <int> mm;	//memory
};*/

//map <string,TPS> tp;
struct S{
	int type;
	int start;
};

int ttl=0;
map <string,S> vr;
vector <S> data;

int main()
{
	int T;
	ifstream ifile("./struct.in");
	ofstream ofile("./struct.out");
	for(int i=0;i<T;i++)
	{
		int op;
		ifile>>op;
		if(op==2)
		{
			string a,b;
			S t;
			ifile>>a>>b;
			t.type=((a=="byte")?BT:(a=="short")?ST:(a=="int")?IT:LG);
			t.start=ttl;
			ttl+=t.type;
			vr[b]=t;
			data.push_back(t);
		}
		else if(op==3)
		{
			string s;
			S t;
			ifile>>s;
			t=vr[s];
			ofile<<t.start<<endl;
		}
		else if(op==4)
		{
			int addr;
			ifile>>addr;
			for(int j=0;j<i;j++)
			{
				if(addr<data[j].start)
					cout<<data[j-1].start<<endl;
				else if(addr==data[j].start)
                                        cout<<addr<<endl;;

			}
		}
		
	}
	return 0;
}