#include<bits/stdc++.h>
using namespace std;
char a[2000010];
bool vis[2000010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,k,sum=0;
    bool f,f1;
    char x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            for(int x=i;x<=j;x+=2) {
                f=1;
                f1=1;
                for(int y=i;y<x;y++) {
                    if(a[x-y]!=a[y]) {
                        f=0;
                        break;
                    }
                }
                for(int y=x;y<j;y++) {
                    if(a[j-y]!=a[y]) {
                        f=0;
                        break;
                    }
                }
                if(f==1&&f1==1) {
                    sum++;
                    break;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
