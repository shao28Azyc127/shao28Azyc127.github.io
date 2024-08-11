#include<iostream>
using namespace std;
int n,ans=0;
string s;
int v[2000005]={};
void find(int loc,int lon)//loc:head location  lon:string length-1
{
	int dis=1;
	while(loc-dis>=0&&loc+dis+lon<n)
	{
		//cout<<loc<<" "<<dis<<endl;
		if(s[loc-dis]==s[loc+dis+lon])
		{
			v[loc-dis]=max(v[loc-dis],loc+dis+lon);
			ans++;
			dis++;
		}
		else break;
	}
	dis--;
	//if(v[loc-dis]==loc+dis+lon)ans--;
	//cout<<"find "<<lon<<endl;
	//v[loc-dis]=max(v[loc-dis],loc+dis+lon);
}
int main()
{
	freopen("r","game.in",stdin);
	freopen("w","game.out",stdout);
	cin>>n>>s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			v[i]=i+1;
			find(i,1);
			ans++;
		}
	}
	

	
	bool flag=1,islink=0;
	int root=-1,num=0,t;
	while(flag)
	{	/*for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;*/
		flag=0;
		//cout<<"link:"<<islink<<endl;
		for(int i=0;i<n;i++)
		{
			//cout<<i<<" "<<root<<" "<<ans<<endl;
			if(islink)
			{
				if(v[i]!=0&&v[i]!=v[root])
				{
					//cout<<"ok"<<endl;
					ans++;
					v[root]=v[i];
					i=v[i];
					//t=i;
					//i=v[i]+1;
					//v[t]=0;
					find(root,v[root]-root);
				}
				else
				{
					//cout<<"nop"<<endl;
					//ans+=num;
					islink=0;
					v[root]=0;
					num=0;
				}
			}
			else if(v[i]!=0)
			{
				flag=1;
				root=i;
				i=v[i];
				islink=1;
				num++;
			}
		}
		/*
		if(islink)
		{
			ans++;
			islink=0;
		}
		*/
	}
	cout<<ans;
	return 0;
}
