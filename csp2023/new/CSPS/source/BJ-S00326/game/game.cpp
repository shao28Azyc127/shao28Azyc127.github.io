

#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
int a,sum=0,u,y;
bool o=true;
char q[10001];
cin>>a;
for(int i=1;i<=a;i++)
cin>>q[i];
for(int i=1;i<=a;i++)
{
u=i;
y=i+1;
o=true;
while(o)
{
if(u>0&&y<a+1){
if(q[u]==q[y])
{
sum++;
u=u-1;
y=y+1;
}

}
else
{
o=false;
}



}
o=true;
y=y+y-2;
u=y/2+1;
while(u<y&&q==true)
{
	if(q[u]==q[y])
	{
		y--;
		u++;
		if(u+1==y){
			sum++;
		}
	}
	else
	{
		o=false;
	}
}


}
cout<<sum;
return 0;
}

