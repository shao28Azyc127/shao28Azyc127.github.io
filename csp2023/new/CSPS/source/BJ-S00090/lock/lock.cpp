#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("game1.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;

    cin >> n;
    int left = n;
    string a;
    int cbf[n];


    cin >> a;
    
    int i = 1;

    while(i<n){




        if(a[i]==a[i-1]){cbf[i]=n;}



        i++;
    }



    for(int i = 1;i < n;i ++){
        if(!cbf[i]) continue;
        ans++;
        left-=2;
        while(left!=0){
            int cnt=1;
            if(a[(i-cnt)-1]==a[i+cnt]){
                ans++;
                cnt++;
                left-=2;
            }
            else break;
        }
    }
    if(!left){
        ans++;
    }
    cout << ans;
    return 0;
}
