#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;


string indt[3005];
string maxs[3005];
void gtmx(string &data,int num)
{
	int table[26]={0};
	for(int i=0,sz=data.size();i<sz;i++)
	{
		table[(data[i]-'a')]++;
	}
	for(int i=25;i>=0;i--)
	{
		while(table[i]--)
			maxs[num]+=(char)(i+'a');
	}
}

int main()
{
	ifstream ifile("./dict.in");
	ofstream ofile("./dict.out");

	int n,m;
	ifile>>n>>m;
	for(int i=0;i<n;i++)
	{
		ifile>>indt[i];
		gtmx(indt[i],i);
	}

	for(int i=0;i<n;i++)
	{
		bool flag=true;
		string tmp=maxs[i];
		reverse(tmp.begin(),tmp.end());
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(tmp>=maxs[j])
				flag=false;
		}
		if(flag)
			ofile<<1;
		else
			ofile<<0;
	}
	ofile<<endl;

	return 0;
}