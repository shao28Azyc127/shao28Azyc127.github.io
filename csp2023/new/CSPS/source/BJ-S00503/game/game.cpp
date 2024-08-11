#include <bits/stdc++.h>
using namespace std;
const int maxn=2*100000+5;
char s[maxn];
int n,sum,t=1;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }// ‰»Î

    for(int i=1;i<=n-1;++i){
        for(int j=i+1;j<=n;++j){
            int a[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//Õ∞
            for(int k=i;k<=j;++k){
                a[int(s[k])-96]++;
                //cout<<s[k]<<int(s[k])-96<<endl;
            }
            for(int g=1;g<=26;++g){
                t=1;

                if(a[g]%2==1){
                    t=2;
                    break;
                }
            }

            if(t==1){
                //cout<<i<<" "<<j<<endl;
                sum++;
            }
        }
    }

    cout<<sum;
    return 0;
}
