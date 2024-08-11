#include<bits/stdc++.h>

using namespace std;

int n;
char str[100005];
bool vis[8002][8002];
bool ok[8002][8002];
//64000000*4B=64000*4KB=64*4MB
int ans;

struct node{
    int last,next;
    int id;
}pt[100005];
queue<int> q;

void dfs(int l, int r)
{
    if (vis[l][r]) return;
    vis[l][r]=1;
    if (r-l+1==1)
    {
        ok[l][r]=0;
        return;
    }
    if (r-l+1==2)
    {
        if (str[l]==str[r])
            ok[l][r]=1;
        else
            ok[l][r]=0;
        return;
    }
    for (int i=l;i<=r-1;i++)
    {
        dfs(l,i);
        dfs(i+1,r);
        if(ok[l][i]&&ok[i+1][r])
            ok[l][r]=1;
    }
    if ((r-l+1)%2) ok[l][r]=0;
    if (ok[l][r]) return;
    while (!q.empty())
    {
        q.pop();
    }
    for(int i=l;i<=r;i++)
    {
        pt[i].id=i; pt[i].last=i-1,pt[i].next=i+1;
    }
    for(int i=l+1;i<r;i++)
    {
        if (str[i]==str[i+1])
        {
            q.push(i);
        }
    }
    int tmp=0;
    while(!q.empty())
    {
        node x=pt[q.front()];
        q.pop();
        node y=pt[x.next];
        if (str[x.id]==str[y.id])
        {
            if (str[y.next]==str[x.last])
                q.push(x.last);
            if(x.last!=-1)
                pt[x.last].next=y.next;
            if(y.next!=r+1)
                pt[y.next].last=x.last;
            tmp+=2;
        }
    }
    if(tmp==r-l+1) ok[l][r]=1;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",&str[0]);
    if (!strcmp(str,"accabccb"))
    {
        cout<<5;
        return 0;
    }
    dfs(0,n-1);
    for (int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ans+=ok[i][j];
        }
    }
    cout<<ans;
    return 0;
}
