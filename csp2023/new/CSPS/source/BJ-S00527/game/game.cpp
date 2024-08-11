
#include<bits/stdc++.h>

using namespace std;

const long long Maxn=2*1e6;
long long N;
char Str[Maxn+10];
long long Ans;
long long flag[Maxn+10]={0};//if this var can be ignored
long long Cnt=1;
bool Cnts[Maxn+10]={0};
void Solve(){
    for(long long i=2;i<=N;i+=2){//length
        for(long long j=1;j<=N;j++){
            bool Ignore=1;
            memset(Cnts,0,Maxn+10);
            for(long long k=j+1;k<j+i-1;k++){
                Cnts[flag[k]]=!Cnts[flag[k]];
            }
            for(long long k=j+1;k<j+i-1;k++){
                if(Cnts[flag[k]]){
                    Ignore=0;
                    break;
                }
            }
            if(Str[j]==Str[j+i-1]&&Ignore||(flag[j]==flag[j+i-1]&&flag[j]!=0)){
                flag[j]=flag[j+i-1]=Cnt;
                if(Str[j]==Str[j+1]&&Str[j]!=Str[j-1]&&j-1>=1){
                    Cnt++;
                }
                //cout<<"index:"<<j<<" "<<j+i-1<<endl;
                //cout<<"flagn:"<<flag[j]<<" "<<flag[j+i-1]<<endl;
                Ans++;
            }
        }
    }
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&N);
    for(long long i=1;i<=N;i++){
        cin>>Str[i];
    }
    Solve();
    cout<<Ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
