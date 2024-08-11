#include<bits/stdc++.h>
using namespace std;
char a[2000005];
int b[2000005];
char c[2000005];
int d[2000005];
bool check1[200];
int  check2[200];
int top=0;
int ans=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	c[top]=a[0];
	d[top]=0;
	for(int i=1;i<n;i++)
	{
		c[++top]=a[i];
		d[top]=i;
		if(a[i]==a[i-1]){
			b[i]=1+b[i-2];
			check1[a[i]-1]=true;
			check2[a[i]-1]=i;
			top-=2;
		}
		else{ 
			if(c[top]==c[top-1]){
				b[i]=1+b[d[top-1]-1];
				top-=2;
			}
			else if(check1[a[i]-1]==true){
				b[i]=1+b[check2[a[i]-1]-1];
				check1[a[i]-1]=false;
			}
		}
		ans+=b[i];
	}
	cout<<ans;
	return 0;
}
