#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n, m;
char s[N][N];
int tack[2];
priority_queue<int> q;
int cmp(int a, int b)
{
    for(int i=1; i<=m; i++){
        if(s[a][i] == s[b][i]) continue;
        else if(s[a][i] < s[b][i]) return a;
        else return b;
    }
    return a;
}
bool judge(int x)
{
    int y=tack[0];
    if(x==y) y=tack[1];
    while(!q.empty()) q.pop();
    for(int i=1; i<=m; i++){
        q.push(-(s[x][i]-'a'));
    }
    for(int i=1; i<=m; i++)
    {
        char h=(-q.top())+'a';
        q.pop();
        if(h==s[y][i]) continue;
        else if(h<s[y][i]) return true;
        else return false;
    }
    return false;
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
            scanf("%s", s[i]+1);
    }

    int p=1;
    for(int i=2; i<=n; i++){
        p=cmp(p, i);
    }
    tack[0]=p;
    if(p==1){
        p=2;
        for(int i=3; i<=n; i++){
            p=cmp(p, i);
        }
        tack[1]=p;
    }
    else {
        p=1;
        for(int i=2; i<=n; i++){
            if(i==tack[0]) continue;
            p=cmp(p, i);
        }
        tack[1]=p;
    }

    for(int i=1; i<=n; i++){
        if(judge(i)) printf("1");
        else printf("0");
    }

    return 0;

}


