#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
char c[3005][3005];
int main(){
    char a;
    int i,n,m,ans=27,y;
    int f[30];
    freopen("r","dict.in",stdin);
    freopen("w","dict.out",stdout);
    cin>>n>>m;
    if(m==1){
        if(n==1){
            cout<<1;
            return 0;
        }else{
            for(i=0;i<n;i++){
                cin>>c[n];
            }
            for(i=0;i<n;i++){
                y=ans;
                ans=min(ans,c[i][1]-'a');
            }
            for(i=0;i<n;i++){
                if(c[i][1]-'a'==ans){
                    f[i]=1;
                }
            }
            for(i=0;i<n;i++){
                cout<<f[i];
            }
            return 0;
        }
    }else{
        cout<<0;
    }
 return 0;
}
