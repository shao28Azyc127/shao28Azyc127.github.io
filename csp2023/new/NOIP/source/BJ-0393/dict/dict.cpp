#include<bits/stdc++.h>
using namespace std;
int n,m;
char w[3001][3001];
int c[3001][27],a[3001];
int minc[3001];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        minc[i]=26;
        for(int j=0;j<m;j++){
            c[i][w[i][j]-'a']++;
            minc[i]=min(minc[i],w[i][j]-'a');
        }
    }
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(minc[i]<minc[j])continue;
                else{
                    int cnt=0;
                    for(int k=minc[i]+1;k<26;k++)cnt+=c[j][k];
                    if(cnt>0)continue;
                    else{
                        f=0;
                        break;
                    }
                }
            }
        }
        a[i]=f;
    }
    for(int i=1;i<=n;i++)cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
