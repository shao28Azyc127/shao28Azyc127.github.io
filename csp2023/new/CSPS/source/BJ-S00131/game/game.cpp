#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
char s[2000000];
bool vis[2000000];
stack<char> stk;
bool des(int h,int t)
{
	stack<char> stk;
	stk.push('#');
	//for(int i=h;i<=t;i++) printf("%c",s[i]);
	//printf("\n");
	for(int i=h;i<=t;i++)
	{
		//printf("%c %c\n",stk.top(),s[i]);
		if(stk.top()==s[i]) stk.pop();
		else stk.push(s[i]);
	}
	if(stk.top()=='#') return true;
	else return false;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s; 
	for(int i=2;i<=n;i+=2)
	{
		for(int j=0;j<=n-i;j+=1)
		{
			//int flag=0;
			//for(int k=i;k<=j;k++)
			//{
				//if(vis[k]==0) flag++;
			//}
			//if(!flag) ans++;
			/*else*/ if(des(j,j+i-1))
				{
					//for(int k=i;k<=j;k++) vis[k]=true;
					ans++;
				}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}