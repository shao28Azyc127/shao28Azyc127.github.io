#include<bits/stdc++.h>
using namespace std;

unsigned long long int n,x=1,y=0,ans=0;
int sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        x=(x+3);
        if(x>=n){
            x=x%n;
            ans++;
        }
        sum++;
        if(x==0){
            y=sum;
        }
    }
    cout<<ans+2<<y;
//    for(int i=1;i<=n;i+=3){
//        //    cout<<i;
//        if(i+3>n){
//            i=tot+1;
//            tot++;sort(vis+1,vis+1+n);
//        }
//        if(vis[i]==90000){
//            break;
//        }if(i==n)x=sum.size();
//        for(int j=1;j<=n;j++){
//            if(vis[j]==i){
//                sum.push_back(vis[j]);vis[j]=90000;break;
//            }
//        }
//
//    }
//    cout<<sum.size()<<tot+1;
    return 0;
}
