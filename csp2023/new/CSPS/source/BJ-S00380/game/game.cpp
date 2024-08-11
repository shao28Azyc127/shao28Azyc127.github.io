#include<bits/stdc++.h>
using namespace std;
char a[2000005]={};
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string s;
    int n,i,j,ans=0,l;
    cin >> n >> s;
    for (i=0;i<n-1;i++)
    {
         l=0;
         for (j=i+1;j<n;j++)
         {
             l++;
             a[l]=s[j];
             while (l>0 && a[l]==a[l-1])
             {
                    l=l-2;
             }
             if (l==0)
             {
                 ans++;
             }
         }
    }
    cout << ans;
    return 0;
}
