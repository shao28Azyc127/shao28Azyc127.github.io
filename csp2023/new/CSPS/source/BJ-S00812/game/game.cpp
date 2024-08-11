#include<iostream>
#include<cstdio>
using namespace std;
bool kex[1000];
int n,sum=0,zhi[1000];
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]==s[i+1]){
            sum++;
            kex[i]=kex[i+1]=1;
            zhi[i]=i+1;
            zhi[i+1]=i;
        }
    }
    for(int k=4;k<=n;k+=2){
    for(int i=0;i<=n-k;i++){
        if(s[i]==s[i+k-1]&&kex[i]==false&&kex[i+k-1]==false){
            bool pan=true;
            for(int l=i+1;l<i+k-1;l++){
                if(!kex[l]){
                    pan=false;
                    break;
                }
            }
            if(pan){
                kex[i]=kex[i+k-1]=true;
                sum++;
                zhi[i]=i+k-1;
                zhi[i+k-1]=i;
            }
        }
        if(zhi[i]>i&&zhi[i]<i+k-1&&zhi[i+k-1]<i+k-1&&zhi[i+k-1]>i&&kex[i]==true&&kex[i+k-1]==true){
            bool pan=true;
            for(int l=i+1;l<i+k-1;l++){
                if(zhi[l]<i||zhi[l]>i+k-1){
                    pan=false;
                    break;
                }
            }
            if(!pan){
                continue;
            }
            sum++;
        }
    }
    }
    cout<<sum;

    return 0;
}
