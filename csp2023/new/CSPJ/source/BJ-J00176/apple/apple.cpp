#include<bits/stdc++.h>
using namespace std;

int a[100000010];
bool flag[100000010];
int main(){
    int n;
    int i=2,sum=0,cnt=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;

    while(sum!=n){
        i++;
        for(int j=i-2;j<=n;j++){
            if(a[j]==0){
                sum++;
                a[j]=i-2;
                flag[j]=true;
                for(int z=j;z<=n;z++){
                    if(!flag[z]) cnt++;
                    if(cnt==2){
                        cnt=0;
                        j+=z-j+1;
                        break;
                    }
                }
            }
        }
    }
    cout<<i-2<<" "<<a[sum];
    return 0;
}
