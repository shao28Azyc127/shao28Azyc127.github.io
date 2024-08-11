#include <bits/stdc++.h>
using namespace std;

int n;
int f[1000000+10];
int day,ans,x;
int flag=0;
int tmp=0;

bool F=false;

int main()
{
    ios::sync_with_stdio(false);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while (tmp<n-1){
        ans++;
        flag=0;
        for (int i=1;i<=n;i++){
            if (f[i]){
                continue;
            }
            if (flag==0){
                // cout << ans << ":" << i << endl; 
                if (i==n){
                    F=true;
                    goto abc;
                }
                flag=2;
                f[i]=true;
                tmp++;
            }
            else{
                flag--;
            }
        }
    }
    abc:;
    int nn=n;
    while (n>0){
        flag=0;
        day++;
        tmp=0;
        x=n/3;//di i tian tan x ge
        if (x*3!=n){
            x++;
        }
        // cout<< x << endl;
        n-=x;
    }
    if (F==true){
        cout << day << " " << ans << endl;
    }
    else{
        cout << day << " " << ans+1 << endl;
    }
    return 0;
}