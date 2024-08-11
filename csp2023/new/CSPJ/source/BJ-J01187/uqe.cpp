#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int x,int y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
void printyls(int x,int y,bool p0){
    if(x==0){
        if(p0)cout<<0;
        return;
    }
    bool flag=0;
    if((x<0)+(y<0)==1)flag=1;
    x=abs(x);
    y=abs(y);
    int k=gcd(x,y);
    x/=k;
    y/=k;
    if(flag)cout<<"-";
    if(y==1){
        cout<<x;
    }else{
        cout<<x<<"/"<<y;
    }
    if(p0==0)cout<<"+";
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans1=-b,ans2=2*a,ans3=b*b-4*a*c;
        if(ans3<0){
            cout<<"NO"<<endl;
            continue;
        }
        int k=int(sqrt(ans3));
        if(k*k==ans3){
            if(ans2>0)ans1+=k;
            else ans1-=k;
            printyls(ans1,ans2,1);
            cout<<endl;
            continue;
        }
        printyls(ans1,ans2,0);
        int d=1;
        for(int i=1;i*i<=ans3;i++){
            if(ans3%(i*i)==0){
                d=i;
            }
        }
        ans3/=d*d;
        ans2=abs(ans2);
        int j=gcd(d,ans2);
        d/=j;
        ans2/=j;
        if(d==ans2){
            printf("sqrt(%d)",ans3);
        }else if(ans2==1){
            printf("%d*sqrt(%d)",d,ans3);
        }else if(d==1){
            printf("sqrt(%d)/%d",ans3,ans2);
        }else{
            printf("%d*sqrt(%d)/%d",d,ans3,ans2);
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
