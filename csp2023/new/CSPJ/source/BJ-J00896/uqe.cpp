#include<bits/stdc++.h>
using namespace std;
int T,m,a,b,c;
bool chksq(int x){
    int c=sqrt(x);
    if(c*c==x) return true;
    else return false;
}
int cs(int x){
    int ans=0;
    for(int i=1;i*i<=x;i++){
        if(x%(i*i)==0) ans=i;
    }
    return ans;
}
int gcd(int x,int y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
void printyl(int x,int y){
    if((x>0 && y<0) || (x<0 && y>0)) cout<<"-";
    x=abs(x);y=abs(y);
    if(y/gcd(x,y)==1) cout<<x/gcd(x,y);
    else cout<<x/gcd(x,y)<<"/"<<y/gcd(x,y);
}
void printwl(int x,int y,int z){
    if(chksq(z)==true){
        if(y>0) printyl(x+sqrt(z),y);
        if(y<0) printyl(x-sqrt(z),y);
    }else{
        if(x!=0){
            printyl(x,y);
            cout<<"+";
        }
        int changshu=cs(z);
        x=abs(x);y=abs(y);z=abs(z);
        if(changshu==y){
            cout<<"sqrt("<<z/changshu/changshu<<")";
        }else if(gcd(changshu,y)==y){
            cout<<changshu/y<<"*sqrt("<<z/changshu/changshu<<")";
        }else if(gcd(changshu,y)==changshu){
            cout<<"sqrt("<<z/changshu/changshu<<")/"<<y/changshu;
        }else{
            int f=gcd(changshu,y);
            cout<<changshu/f<<"*sqrt("<<z/changshu/changshu<<")/"<<y/f;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>m;
    while(T--){
        cin>>a>>b>>c;
        int derta=b*b-4*a*c;
        //cout<<derta;
        if(derta<0) cout<<"NO"<<endl;
        else if(derta==0){
            printyl(-b,2*a);
            cout<<endl;
        }else{
            printwl(-b,2*a,derta);
            cout<<endl;
        }
    }
    return 0;
}
