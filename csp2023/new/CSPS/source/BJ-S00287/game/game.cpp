#include<iostream>
#include<fstream>
using namespace std;

int ans=0;
bool ok[8005][8005];

void init(int n,string data)
{
	for(int i=0;i<n-1;i++)
		if(data[i]==data[i+1])
			ok[i][i+1]=true;
}

void cnt(int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(ok[i][j])
				ans++;
	return;
}

bool lnk(int l,int r)
{
	for(int i=l+1;i<r-1;i++)
		if(ok[l][i] && ok[i+1][r])
			return ok[l][r]=true;
	return false;
}

void imps(int n,string data,int l,int r)
{
        for(int i=1;l-i>=0 && r+i<n && data[l-i]==data[r+i];i++)
		ok[l-i][r+i]=true;
}

void solve(int n,string data)
{
	for(int l=1;l<n;l++)
	{
		for(int i=0;i+l<n;i++)
		{
			if(ok[i][i+l] || lnk(i,i+l))
				imps(n,data,i,i+l);
		}
		
	}
}

int main()
{
	ifstream ifile("./game.in");
	ofstream ofile("./game.out");
	int n;	//under 1900
	string data;
	ifile>>n;
	ifile>>data;

	init(n,data);
	solve(n,data);
	cnt(n);

	ofile<<ans<<endl;
	return 0;
}