#include<bits/stdc++.h>
using namespace std;
char dict[3005][3005];
char mn[3005];
int idx;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dict[i];
        sort(dict[i],dict[i]+m);
        if(i==1){
            for(int j=0;j<m;j++){
                mn[j]=dict[i][j];
            }
            idx=1;
        }
        else{
            int flag=0;
            for(int j=m-1;j>=0;j--){
                if(mn[j]>dict[i][j]){
                    flag=1;
                    break;
                }
                if(mn[j]<dict[i][j]){
                    break;
                }
            }
            if(flag==1){
                idx=i;
                for(int j=0;j<m;j++){
                    mn[j]=dict[i][j];
                }
            }
        }
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int flag=0;
        if(i==idx){
            flag=1;
        }
        else{
            for(int j=0;j<m;j++){
                if(dict[i][j]<mn[m-j-1]){
                    flag=1;
                    break;
                }
                if(dict[i][j]>mn[m-j-1]){
                    break;
                }
            }
        }
        cout<<flag;
    }
    return 0;
}
