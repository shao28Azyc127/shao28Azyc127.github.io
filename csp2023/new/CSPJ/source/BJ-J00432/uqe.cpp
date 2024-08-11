#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
int a,b,c;
int T,M;
int delta;
int ans;
int q1,q2,q31,q32;
int qall;
int d;
int qgcd(int a,int b)
{
	for(int i=min(a,b);i>=1;i--)
	{
		if(a%i==0&&b%i==0)
		    return i;
	}
	return 1;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%d%d",&T,&M);
	while(T--)
	{
	    scanf("%d%d%d",&a,&b,&c);
	    if(a<0)
	    {
			a=0-a;
			b=0-b;
			c=0-c;
		}
	    delta=b*b-4*a*c;
	    if(delta<0)
	        cout<<"NO"<<endl;
	    else if(delta==0)
	    {
			q1=0-b;
			q2=2*a;
			int g=qgcd(abs(q1),abs(q2));
			if(g!=1)
			{
				q1/=g;
				q2/=g;
			}
			if(q2>0&&q2!=1)
			    cout<<q1<<"/"<<q2<<endl;
			else if(q2==1)
			    cout<<q1<<endl;
		}
		else if(delta>0)
		{
			q1=0-b;
			q2=1;
			q31=2*a;
			for(int i=(int)sqrt(delta);i>=1;i--)
			{
				if(delta%(i*i)==0)
				{
				    q2*=i;
				    delta/=(i*i);
				    break;
			    }
			}
			if(delta==1)
			{
				qall=q2+q1;
				int g=qgcd(abs(qall),abs(q31));
			    if(g!=1)
			    {
				    qall/=g;
				    q31/=g;
			    }
			    if(q31!=1)
			        cout<<qall<<"/"<<q31<<endl;
			    else if(q31==1)
			        cout<<qall<<endl;
			    continue;
			}
			int g1=qgcd(abs(q1),abs(q31));
			if(g1!=1)
			{
				q1/=g1;
				q31/=g1;
			}
			
			
			if(q31!=1&&q1!=0)
			    cout<<q1<<"/"<<q31<<"+";
			else if(q31==1&&q1!=0)
			    cout<<q1<<"+";
			    
			q32=2*a;
			int g2=qgcd(abs(q2),abs(q32));
			if(g2!=1)
			{
				q2/=g2;
				q32/=g2;
			}
			if(q2==1&&q32==1)
			    cout<<"sqrt("<<delta<<")"<<endl;
			else if(q2!=1&&q32!=1)
			    cout<<q2<<"*sqrt("<<delta<<")"<<"/"<<q32<<endl;
			else if(q2!=1&&q32==1)
			    cout<<q2<<"*sqrt("<<delta<<")"<<endl;
			else if(q2==1&&q32!=1)
			    cout<<"sqrt("<<delta<<")"<<"/"<<q32<<endl;
		}
    }
    return 0;
}
