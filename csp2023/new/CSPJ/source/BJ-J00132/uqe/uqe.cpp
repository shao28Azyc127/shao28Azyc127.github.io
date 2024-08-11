#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,M,a[5500]={ },b[5500]={ },c[5500]={ };
	double derta=0;
	cin>>T>>M;
	for(int i=0;i<5500;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<5500;i++)
	{
		derta=b[i]*b[i]-4*a[i]*c[i];
		if(derta<0)
			cout<<"NO"<<endl;
		else
		{
			if((int)(derta)==derta)
			{
				cout<<derta<<endl;
			}
			else
			{
				for(int i=2;i<=6000;i++)
				{
					if((int)(derta*i)==derta*i)
					{
						cout<<derta*i<<"/"<<i;
					}
				}
				
			}
		}
	}
}
