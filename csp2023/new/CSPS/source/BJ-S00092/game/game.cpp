#include<iostream>
using namespace std;
int n,f[10001][10001]={0};
long long ans=0;

char c[1000001];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(i){
            if(c[i]==c[i-1]){
                f[i-1][i]=1;
                ans++;
                //cout<<c[i]<<'\t'<<c[i+1]<<endl;
            }
        }
    }//====================================================
    for(int cr=4;cr<=n;cr+=2){
        for(int i=0;i+cr-1<n;i++){
                          //  cout<<i<<'\t'<<i+cr-1<<endl;

            if(f[i+1][i+cr-1-1]&&c[i]==c[i+cr-1]){
                f[i][i+cr-1]=1;ans++;
               // cout<<i<<'\t'<<i+cr-1<<endl;
                continue;
            }
            for(int cu=0;cu<cr;cu+=2){
                if(f[i][i+cu-1]&&f[i+cu][i+cr-1]){
                    f[i][i+cr-1]=1;ans++;
                  // cout<<i<<'\t'<<i+cr-1<<endl;
                    break;
                }
            }



        }
    }

    cout<<ans<<endl;

    return  0;

}
