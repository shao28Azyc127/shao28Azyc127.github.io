#include<bits/stdc++.h>
using namespace std;
int n,m,strtot[3010][30],state[3010],tot[30];
bool check(int id){
    int idfpos=0;
    for(int i=0;i<25;i++){
        if(strtot[id][i]!=0){
            idfpos=i;
            break;
        }
    }for(int i=1;i<=n;i++){
        if(i==id) continue;
        int otherpos=0;
        for(int j=25;j>=0;j--){
            if(strtot[i][j]!=0){
                otherpos=j;
                break;
            }
        }if(idfpos==otherpos){
            if(strtot[id][idfpos]<=strtot[id][idfpos]){
                return 0;
            }
        }else{
            if(idfpos>otherpos){
                return 0;
            }
        }
    }return 1;
}int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        memset(tot,0,sizeof(tot));
        for(int j=1;j<=m;j++){
            char ch=getchar();
            //cout<<i<<' '<<j<<'\n';
            while(ch<'a'||ch>'z') ch=getchar();
            tot[ch-'a']++;
        }for(int j=0;j<26;j++){
            strtot[i][j]=tot[j];
        }
    }for(int i=1;i<=n;i++){
        state[i]=check(i);
        cout<<state[i];
    }fclose(stdin);
    fclose(stdout);
    return 0;
}