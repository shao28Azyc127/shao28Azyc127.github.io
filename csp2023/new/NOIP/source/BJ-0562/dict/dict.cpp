#include<bits/stdc++.h>
using namespace std;
int t[3001][26]={};
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char a[n][m]={};
    int ans[n]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            t[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int ti[26]={};
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            ti[int(a[i][j]-'a')]++;
        }
        for(int j=0;j<26;j++){
            t[i][j]=ti[j];
            //cout<<t[i][j]<<' ';
        }
        //cout<<endl;
    }
    for(int i=0;i<n;i++){
        int is=1,mini=26;
        for(int j=0;j<n&&is==1;j++){
            if(j==i){
                continue;
            }
            for(int k=0;k<26;k++){
                if(t[i][k]>0){
                    mini=k;
                    //cout<<char(mini+'a')<<' ';
                    break;
                }
            }
            for(int h=25;h>=mini;h--){
                if(h==mini){
                    is=0;
                    //cout<<'/'<<' ';
                    break;
                }
                if(t[j][h]>0){
                    //cout<<char(h+'a')<<t[j][h]<<' ';
                    break;
                }
            }
        }
        ans[i]=is;
        //cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
