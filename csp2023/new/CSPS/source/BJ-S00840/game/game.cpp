#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;
long long f[N];
int vis[N];
char s[N];
vector <int> p[26];
stack <int> t;
int n;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&s[i]);
    long long cnt=0;
    for(int i=1;i<=n;i++){
        t.push(s[i]-'a');
        for(int j=i-1;j>=1;j--){
            if(t.size() && t.top()==s[j]-'a')
                t.pop();
            else t.push(s[j]-'a');
            if(t.size()==0) cnt++;
        }
        while(t.size()) t.pop();
    }
    printf("%lld\n",cnt);
    return 0;
}
