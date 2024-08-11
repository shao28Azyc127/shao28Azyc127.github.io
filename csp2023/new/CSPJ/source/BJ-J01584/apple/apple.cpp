#include<bits/stdc++.h>
using namespace std;
int n,m;
bool k[int(1e6+5)];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    int cnt=0;
    while(n>0){
        n=n-1-(n-1)/3;
        cnt++;
    }
    cout<<cnt<<" ";
    if((m-1)%3==0){
        cout<<1;
    }else{
        int ans=0;
        while(1){
            ans++;
            int p=0;
            for(int i=1;i<=m;i++){
                if(k[i]){
                    continue;
                }else{
                    if(p==0){
                        k[i]=true;
                        if(i==m){
                            cout<<ans;
                            return 0;
                        }
                    }
                    p++;
                    if(p==3){
                        p=0;
                    }
                }
            }
        }
    }
	return 0;
}
