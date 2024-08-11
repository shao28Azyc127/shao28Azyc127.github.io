#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> yls(long long x){
    pair<long long,long long>ans=make_pair(0,0);
    long long minn=1e9;
    for(long long i=1;i*i<=x;i++){
        if(x%i==0){
            long long now=abs(x/i-i);
            if(now<minn){
                minn=now;
                ans=make_pair(i,x/i);
            }
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long T,m;
    cin>>T>>m;
    while(T--){
        double a,b,c;
        cin>>a>>b>>c;
        if(b==0&&c==0) cout<<0<<endl;
        else{
            double dir=b*b-4*a*c;
            if(dir<0){
                cout<<"NO"<<endl;
            }else{
                pair<long long,long long>ans;
                double x1=((0-b)+sqrt(dir))/(2*a);
                double x2=((0-b)-sqrt(dir))/(2*a);
                double x=max(x1,x2);
                if(x==(long long)x){
                    ans=yls((long long)x);
                    if(ans.first==0&&ans.second==0) cout<<"NO"<<endl;
                    else if(ans.first==1||ans.second==1) cout<<max(ans.first,ans.second)<<endl;
                    else cout<<max(ans.first,ans.second)<<"/"<<min(ans.first,ans.second)<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
