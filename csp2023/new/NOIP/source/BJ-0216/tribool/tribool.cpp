#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int V = 6e4+5;
int v[V][11],cnt,nowv[11],now[11],ans = 1e9+5;
int nowTUF[N],nowq[N];
bool vis[N];
int n,m,c,T,x,y;
char opt;
struct Node
{
    char op;
    int a,b;
}cz[15];//T->1 U->2 F->3
void dfs(int i)
{
    if(i==11)
    {
        cnt++;
        for(int i = 1;i <= 10;i++)
			v[cnt][i] = nowv[i];
        return ;
    }
    nowv[i] = 1;
    dfs(i+1);
    nowv[i] = 2;
    dfs(i+1);
    nowv[i] = 3;
    dfs(i+1);
    nowv[i] = 0;
}
bool check(int x)
{
    for(int i = 1;i <=n;i++)
        now[i] = v[x][i-n+10];
    for(int i = 1;i <= m;i++)
    {
        if(cz[i].op=='+')
            now[cz[i].a] = now[cz[i].b];
        if(cz[i].op=='-')
            now[cz[i].a] = 4-now[cz[i].b];
        if(cz[i].op=='T')
            now[cz[i].a] = 1;
        if(cz[i].op=='U')
            now[cz[i].a] = 2;
        if(cz[i].op=='F')
            now[cz[i].a] = 3;
    }
    bool flag = 1;
    for(int i = 1;i <= n;i++)
        if(now[i]!=v[x][i-n+10])
        {
            flag = 0;
            break;
        }
    return flag;
}
int count(int x)
{
    int sum = 0;
    for(int i = 10-n+1;i <= 10;i++)
        if(v[x][i]==2)
            sum++;
    return sum;
}
void dfs1(int now,int fa,vector<int >Adj[N])
{
//	cout<<now<<endl;
	if(vis[now]) return;
	vis[now] = 1;
	ans++;
	for(int i = 0;i < Adj[now].size();i++)
		dfs1(Adj[now][i],now,Adj);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    if(c==1||c==2)
    {
        dfs(1);
/*         cout<<cnt<<endl;
        for(int i = 1;i <= 10;i++)
        {
            for(int j = 1;j <= 10;j++)
                cout<<v[i][j];
            cout<<endl;
        }*/
       while(T--)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!duo ce qing kong
        {
			ans = 1e9+5;
            cin>>n>>m;
            for(int i = 1;i <= m;i++)
            {
                cin>>cz[i].op;
                if(cz[i].op=='+'||cz[i].op=='-')
                    cin>>cz[i].a>>cz[i].b;
                if(cz[i].op=='T'||cz[i].op=='U'||cz[i].op=='F')
                    cin>>cz[i].a;
            }
            for(int i = 1;i <= pow(3,n);i++)
            {
                if(check(i))
                    ans = min(ans,count(i));
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    if(c==3||c==4)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!duo ce qing kong
    {
		while(T--)
		{
			ans = 0;
			memset(nowTUF,0,sizeof(nowTUF));
			cin>>n>>m;
			for(int i = 1;i <= m;i++)
			{
				cin>>opt>>x;
				if(opt=='T')
					nowTUF[x] = 1;
				if(opt=='U')
					nowTUF[x] = 2;
				if(opt=='F')
					nowTUF[x] = 3;
			}
			for(int i = 1;i <= n;i++)
				if(nowTUF[i]==2)
					ans++;
			cout<<ans<<endl;
		}
        return 0;
    }
	while(T--)
	{
		vector<int >Adj[N];
		ans = 0;
		cin>>n>>m;
//		cout<<n<<"!"<<endl;
//		if(n==1000)	continue;
		for(int i = 1;i <= n;i++)
			nowq[i] = i,vis[i] = 0;
		vis[100002] = 0;
		for(int i = 1;i <= m;i++)
		{
			cin>>opt>>x;
			if(opt=='U')
				nowq[x] = 100002;
			if(opt=='+')
			{
				cin>>y;
				nowq[x] = nowq[y];
			}
		}
		for(int i = 1;i <= n;i++)
		{
			Adj[i].push_back(nowq[i]);
			Adj[nowq[i]].push_back(i);
//			cout<<i<<' '<<nowq[i]<<endl;
		}
		dfs1(1e5+2,-1,Adj);
//		for(int i = 1;i <= n;i++)
//			if(vis[i])	cout<<i<<' ';
		cout<<ans-1<<endl;
	}
    return 0;
}
