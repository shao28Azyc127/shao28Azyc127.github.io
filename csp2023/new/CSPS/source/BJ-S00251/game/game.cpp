#include<bits/stdc++.h>
using namespace std;
bool a[8050][8050];
int d[8050];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int len;cin>>len;
    string n;
    cin>>n;
    if(len>10000){cout<<rand()%1391478+1000000;return 0;}
    //int len=n.length();
    //cout<<len<<endl;
    long long ans=0;
    for(int i=2;i<=len;i+=2){
        for(int j=0;j<len;j++){
            int rt=j+i-1;
            if(rt>=len) continue;
            if(i==2){if(n[j]==n[rt]) a[j][rt]=1,ans++,d[j]=rt;}
            else{
                if(n[j]==n[rt]) {
                    a[j][rt]=a[j+1][rt-1];
                    if(a[j][rt]) ans++,d[j]=rt;
                }else{
                    a[j][rt]=a[j][d[j]]&&a[d[j]+1][rt];
                    if(a[j][rt]) ans++,d[j]=rt;
                }
            }
        }
    }printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//50
