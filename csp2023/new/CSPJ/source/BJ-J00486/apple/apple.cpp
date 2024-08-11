#include<bits/stdc++.h>
using namespace std;

int  a[1000005];

bool flag=0;

int n,c=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(!flag){
        flag=1;
        c++;
        for(int i=1,cnt=2;i<=n;i++){
            if(a[i]==0)cnt++;
            if(cnt==3){
                a[i]=c;
                cnt=0;
                flag=0;
            }
        }
    }
    cout<<c-1<<" "<<a[n]<<endl;
    return 0;
}
