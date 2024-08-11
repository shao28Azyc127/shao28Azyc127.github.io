#include<bits/stdc++.h>
using namespace std;
int arr[2000005],ans;
int S[2000005],sz=0;
void mypush(int x){
    S[sz++]=x;
}
void mypop(){
    S[--sz]=0;
}
int mytop(){
    return S[sz-1];
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    char q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q;
        arr[i]=q-'0';
    }
    for(int st=1;st<=n;st++){
        while(sz>0){
            mypop();
        }
        for(int i=st;i<=n;i++){
            if(sz>0&&mytop()==arr[i]){
                mypop();
            }else{
                mypush(arr[i]);
            }
            if(!sz){
                //cout<<st<<" "<<i<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
