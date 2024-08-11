#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;

int mabsl(int x)
{
	if(x>0)
		return x;
	return -x;
}

int gtsgn(int x)
{
	if(x>0)
		return 1;
	return -1;
}

int trying(int exc[],int ob)
{
	int sgn=gtsgn(exc[ob]);
	int cur=mabsl(exc[ob])/10;

	while(cur!=ob)
	{
		sgn*=gtsgn(exc[cur]);
		cur=mabsl(exc[cur])/10;
	}
	if(sgn==-1)
		return exc[ob]=0;
	return exc[ob]=1;
}

int trace(int n,int exc[],int ob,bool tcd[])
{
	if(ob/10==0)	//value only
		return ob;
	ob=mabsl(ob)/10;
	if(tcd[ob])
		if(exc[ob]/10)
			return trying(exc,ob);
		else
			return exc[ob];
	tcd[ob]=1;
	if(exc[ob]==ob*10)	//P-circle
		return 1;
	if(exc[ob]==(-1)*ob*10)      //N-circle
                return 0;
	return exc[ob]=trace(n,exc,exc[ob],tcd);
}

int main()
{
	ifstream ifile("./tribool.in");
	ofstream ofile("./tribool.out");
	int c,T;
	ifile>>c>>T;
	for(int tt=0;tt<T;tt++)
	{
		int ans=0;
		int n,m;
		ifile>>n>>m;
		int except[100005]={0};
		bool vis[100005]={0};
		bool tcd[100005]={0};
		for(int i=0;i<m;i++)
		{
			char tp;
			ifile>>tp;
			if(tp=='T' || tp =='F' || tp=='U')
			{
				int val=((tp=='T')?1:(tp=='F')?-1:0);
				int a;
				ifile>>a;
				vis[a]=true;except[a]=val;
			}
			else if(tp=='+' || tp=='-')
			{
				int sgnv=((tp=='+')?1:-1);
				int a,b;
				ifile>>a>>b;
				if(vis[b])
				{
					vis[a]=true;except[a]=except[b]*sgnv;
				}
				else
				{
					vis[a]=true;except[a]=b*10*sgnv;
				}
			}
		}
	
//cout<<"OK"<<endl;
//for(int i=1;i<=n;i++)	cout<<except[i]<<endl;

//		for(int k=0;k<n;k++)
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==false)
				except[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(except[i]/10==0)
				continue;
			else except[i]=(except[i]>0?1:-1)*trace(n,except,except[i],tcd);
		}

//cout<<"traced"<<endl;
//for(int i=1;i<=n;i++)	cout<<except[i]<<endl;

		for(int i=1;i<=n;i++)
			if(except[i]!=1 && except[i]!=(-1))
			{
				if(except[i]==0)
					ans++;
			}
		ofile<<ans<<endl;

	}
}