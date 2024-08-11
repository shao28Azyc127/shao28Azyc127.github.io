#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pll;
pll hjgh(int x){
    int a=1;
    for(int i=2;i<=x/i;i++){
        while(x%(i*i)==0){
            x/=i*i;
            a*=i;
        }
    }
    return make_pair(a,x);
}

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

pll yf(int x,int y){
    //Ô¼·Ö
    int z=gcd(abs(x),y);
    return make_pair(x/z,y/z);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;

    while(T--){
        int a,b,c;
        int delta;
        pll gen,ans;
        cin>>a>>b>>c;
        if(a<0)
            a=-a,b=-b,c=-c;

        delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        else if(delta==0){
            ans=yf(-b,2*a);
            if(ans.second==1)
                cout<<ans.first<<endl;
            else
                cout<<ans.first<<'/'<<ans.second<<endl;
            continue;
        }
        gen=hjgh(delta);

        if(gen.second==1){
            ans=yf(-b+gen.first,2*a);
            if(ans.second==1)
                cout<<ans.first<<endl;
            else
                cout<<ans.first<<'/'<<ans.second<<endl;
            continue;
        }

        ans=yf(-b,2*a);
        if(ans.first!=0){
            if(ans.second==1)
                cout<<ans.first<<'+';
            else
                cout<<ans.first<<'/'<<ans.second<<'+';
        }

        ans=yf(gen.first,2*a);

        if(ans.first!=1)
            cout<<ans.first<<'*';
        cout<<"sqrt("<<gen.second<<')';
        if(ans.second!=1)
            cout<<'/'<<ans.second;
        cout<<endl;
    }
    return 0;
}
