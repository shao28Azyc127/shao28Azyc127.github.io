#include<bits/stdc++.h>
using namespace std;
int n,m,minn=1;
char a[3005][3005],s[3005][3005],b[3005][3005];
bool flag=true;
int t[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1) cout<<1;
    else if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i][1];
        }
        for(int i=2;i<=n;i++){
            if(a[i][1]<a[minn][1]) minn=i;
        }
        for(int i=1;i<=n;i++){
                if(i==minn) continue;
            else if(a[i][1]==a[minn][1]) flag=false;
        }
        if(flag==false){
            for(int i=1;i<=n;i++) cout<<0;
        }
        else{
            for(int i=1;i<=n;i++){
                if(i==minn) cout<<1;
                else cout<<0;
            }

        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                t[j]=int(a[i][j]);
            }
            sort(t+1,t+1+m);
            for(int j=1;j<=m;j++){
                 s[i][j]=char(t[j]);
                b[i][m+1-j]=s[i][j];
            }
        }
        for(int i=1;i<=n;i++){
                flag=true;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    for(int k=1;k<=m;k++){
                        if(s[i][k]==b[j][k]) continue;
                        else if(s[i][k]>b[j][k]){
                            flag=false;
                            break;
                        }
                        else break;
                    }
                }
            }
           if(flag==false) cout<<0;
           else cout<<1;
        }
    }
return 0;
}
