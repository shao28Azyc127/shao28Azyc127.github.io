#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int n;
const int N=809;
namespace _25pts
{
    int a[N][N];
    int mem[N][N];
    bool f(int l, int r)
    {
        if(a[l][r]) return mem[l][r];
        if(f(l+1,r-1)&&(s[l]==s[r])) return a[l][r]=mem[l][r]=1;
        for(int k=l+1; k<r; k++)
            if(f(l,k)&&f(k+1,r)) return a[l][r]=mem[l][r]=1;
        a[l][r]=1;
        mem[l][r]=0;
        return 0;
    }

    void mian()
    {
        for(int i=0; i<n; i++) a[i][i]=1, mem[i][i]=0;
        for(int i=0; i<n-1; i++) a[i][i+1]=1, mem[i][i+1]=(int)(s[i]==s[i+1]);
        for(int i=1; i<n-2; i++) a[i][i+2]=1, mem[i][i+2]=0;
        int ans=0;
        for(int l=0; l<=n-1; l++)
        {
            for(int r=l+1; r<=n-1; r++)
            {
                if(f(l, r)) ans++;
            }
        }
        cout << ans << '\n';
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    _25pts::mian();
    return 0;
}
