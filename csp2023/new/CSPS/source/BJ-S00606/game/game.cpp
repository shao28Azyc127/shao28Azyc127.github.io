#include<bits/stdc++.h>
using namespace std;
const long long RP=1e18+7,rp=1e18+7,Rp=1e18+7,rP=1e18+7;
string s;
long long n,sum;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    cin>>s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string tmp=s;
            while(1){
                char t;
                int q=0,S=0;
                bool flag=0,Flag=0;
                for(int k=i;k<=j;k++){
                    if(tmp[k]=='A'){
                        S++;
                        continue;
                    }
                    if(Flag==0){
                        Flag=1;
                        t=tmp[k];
                        q=k;
                    }else{
                        if(Flag==1&&t==tmp[k]){
                            Flag=0;
                            flag=1;
                            tmp[q]='A';
                            tmp[k]='A';
                        }else if(Flag==1){
                            t=tmp[k];
                            q=k;
                        }
                    }
                }
                if(!flag||S==j-i+1){
                    if(S==j-i+1){
                        sum++;
                    }
                    break;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}//All hail the great god of the sky Zeus!
//IAKIOI
//GREAT RDFZ YYDS
//GREAT XXX YYDS