#include <map>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#define N 5

map <int,bool> vis;
map <int,bool> rpt;

int ans=0;

void solve(int n)
{
	for(int i=0;i<N;i++)
	{
		int ck=1;
		for(int j=0;j<i;j++)
			ck*=10;
		for(int j=0;j<=9;j++)
		{
			int cn=n/ck;
			cn=cn%10;
			int cv=(n+(j-cn)*ck);
			if(vis.find(cv)==vis.end())
				vis[cv]=true;
			else
				rpt[cv]=true;
		}
	}

	for(int i=0;i<N-1;i++)
	{
		int ck=1;
                for(int j=0;j<i;j++)
                        ck*=10;
                for(int j=0;j<=9;j++)
                {
                        int cn1=n/ck;
                        cn1=cn1%10;
			int cn2=n/(ck*10);
                        cn2=cn2%10;
			int cv=n;
			if(j+cn1>9)
			{
				cv=cv-cn1*ck+((j+cn1)%10)*ck;
			}
			else
				cv=cv+j*ck;
			if(j+cn2>9)
                        {
                                cv=cv-cn2*ck*10+((j+cn2)%10)*ck*10;
                        }
			else
				cv=cv+j*ck*10;

                        if(vis.find(cv)==vis.end())
                                vis[cv]=true;
                        else
                                rpt[cv]=true;
                }
	}
	
}

int main()
{
	int n;
	int rldt=0;
	ifstream ifile("./lock.in");
	ofstream ofile("./lock.out");
	vector <int> data;
	ifile>>n;
	for(int i=0;i<n;i++)
	{
		int a=0;
		for(int j=0;j<5;j++)
		{
			int t;
			ifile>>t;
			a=a*10+t;
		}
		if(vis.find(a)==vis.end())
		{
			data.push_back(a);
			vis[a]=true;
		}
	}
	n=vis.size();
	for(int i=0;i<n;i++)
		solve(data[i]);

	if(n==1)
		ofile<<vis.size()-n<<endl;
	else
		ofile<<rpt.size()-n<<endl;
	return 0;
}