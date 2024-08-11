#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c,delta,x;
void PQ(int p,int q){
    if((p<0&&q<0)||(p>0&&q<0)){
        p*=-1;
        q*=-1;
    }else if(p==0){
        cout<<0;
        return ;
    }else if(q==1){
        cout<<1;
        return ;
    }
    cout<<p<<'/'<<q;
}
int kaipf(int x){
    for(int i=x;i>=2;i--){
        if(i*i)
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T;
    while(T){
        T--;
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        x=max(((-b-sqrt(delta))/(2*a)),((-b+sqrt(delta))/(2*a)));
        cout<<x<<endl;
    }
    return 0;
}
