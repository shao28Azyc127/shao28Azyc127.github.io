#include<bits/stdc++.h>
using namespace std;
const int M=1e6+100;
int n,ans1,ans2,k;
bool f[M];
int serch(int x){
    int cnt=0,i;
    for(i=x+1;i<n;i++){
        //cout<<f[i]<<" "<<cnt<<" "<<i<<endl;
        if(!f[i])cnt++;
        if(cnt==3)return i;
    }
    return -1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<4){
        cout<<n<<" "<<n<<endl;
        return 0;
    }
    if(n==4){
        cout<<"3 1"<<endl;
        return 0;
    }
    int i=3,t=n;
    while(t>0){
        t-=i,i++;
    }
    ans1=i-1;
    if((n-1)%3==0){
        ans2=1;
        cout<<ans1<<" "<<ans2<<endl;
        return 0;
    }else{
        while(ans2==0){
            int p=0;
            k++;
            for(p=0;p<n;p++)
                if(!f[p])
                    break;
            if(p==n){
                ans2=ans1;
                break;
            }
            for(int i=p;i<n;){
                f[i]=1;
                i=serch(i);
                //cout<<i<<endl;
                if(i==-1)break;
                if(i==n-1){
                    ans2=k;
                    break;
                }
            }
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}
