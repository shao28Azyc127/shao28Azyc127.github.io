#include<bits/stdc++.h>

using namespace std;

int m,t;

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	
	cin>>m>>t;
	double a,b,c;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		if(b==0&&c==0)
		{
			cout<<'0'<<endl;
			continue;
		}
		else
		{
			if(pow(b,2)-4*a*c<0)
			{
				cout<<"NO"<<endl;
				continue;
			}
			else if(b==0)
			{
				if(fmod(c/a,1.0==0))
				{
					if(fmod(sqrt(-c/a),1.0)==0)
					{
						cout<<sqrt(-c/a)<<endl;
					}
					else
					{
						cout<<"sqrt("<<-c/a<<')'<<endl;
					}
				}
				else
				{
					if(c<0)
					{
						cout<<"sqrt("<<-c<<'/'<<a<<')'<<endl;
					}
					else
					{
						cout<<"sqrt("<<c<<'/'<<-a<<')'<<endl;
					}
				}
				continue;
			}
			else if(c==0)
			{
				if(b<0)
				{
					if(fmod(b,a)==0)
					{
						cout<<-b/a<<endl;
					}
					else
					{
						cout<<-b<<'/'<<a<<endl;
					}
				}
				else
				{
					cout<<'0'<<endl;
				}
			}
			else
			{
				if(fmod((-b+sqrt(pow(b,2)-4*a*c))/(2*a),1.0)==0)
				{
					cout<<(-b+sqrt(pow(b,2)-4*a*c))/(2*a)<<endl;
				}
				else
				{
					if(fmod(-b/(2*a),1.0)==0)
					{
						cout<<-b/(2*a,1.0)<<'+';
						if(fmod(sqrt(pow(b,2)-4*a*c),1.0)==0)
						{
							cout<<sqrt(pow(b,2)-4*a*c)<<endl;
						}
						else
						{
							int o=pow(b,2)-4*a*c;
							int p=2*a;
							o/=__gcd(o,p);
							p/=__gcd(o,p);
							cout<<o<<'/'<<p<<endl;
						}
					}
					else
					{
						int x=b,y=2*a;
						x/=__gcd(x,y);
						y/=__gcd(x,y);
						if(fmod(sqrt(pow(b,2)-4*a*c),1.0)==0)
						{
							cout<<'-'<<x<<'/'<<y<<'+'<<sqrt(pow(b,2)-4*a*c)<<endl;
						}
						else
						{
							int o=pow(b,2)-4*a*c;
							int p=2*a;
							o/=__gcd(o,p);
							p/=__gcd(o,p);
							if(y<0)
							{
								cout<<x<<'/'<<-y;
							}
							else
							{
								cout<<-x<<'/'<<y;
							}
							
							if(bool(sqrt(o))!=bool(p))
							{
								cout<<"-sqrt("<<abs(o)<<")/"<<abs(p)<<endl;
							}
							else
							{
								cout<<"+sqrt("<<abs(o)<<")/"<<abs(p)<<endl;
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}