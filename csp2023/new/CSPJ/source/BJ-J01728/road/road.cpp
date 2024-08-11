#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,mina,many,tmp;
    cin>>n>>d;
    long long x,sum=0,ans=0;
    for(long long i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    for(long long i=0;i<n;i++){
        cin>>x;
        if(!i)min=x;
    }
    if(sum%d==0){
        ans=sum/d*mina;
    }else{
        tmp=sum/d*d+1;
        ans=tmp*mina;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
