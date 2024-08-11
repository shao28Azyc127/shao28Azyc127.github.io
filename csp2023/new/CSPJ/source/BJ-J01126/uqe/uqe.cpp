#include<bits/stdc++.h>
using namespace std;
int T,M;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void huajian(int p,int q){
    int gcdpq=gcd(p,q);
    p/=gcdpq;
    q/=gcdpq;
    if(q<0) p=-p,q=-q;
    if(q==1) cout<<p;
    else printf("%d/%d",p,q);

}
void hjsqrt(int p,int q,int r){//(p/q)*sqrt(r)
    for(int i=2;i*i<=r;i++){
        while((r%(i*i))==0){
            r=r/(i*i);
            p=p*i;
        }
    }

    int gcdpq=gcd(p,q);
    p/=gcdpq;
    q/=gcdpq;
    if(q<0) p=-p,q=-q;

    if((p==1)&&(q==1)){
        printf("sqrt(%d)",r);
        return;
    }else if(q==1){
        printf("%d*sqrt(%d)",p,r);
        return;
    }else if(p==1){
        printf("sqrt(%d)/%d",r,q);
        return;
    }else{
        printf("%d*sqrt(%d)/%d",p,r,q);
        return;
    }

}
void solve(int a,int b,int c){
    int derta,sqrtderta;
    derta=(b*b)-(4*a*c);
    if(derta<0){
        cout<<"NO";
        return;
    }
    if(derta==0){
        huajian(-b,2*a);
        return;
    }

    sqrtderta=sqrt(derta);
    if((sqrtderta*sqrtderta)==derta){
        if(a<0){
            huajian(-b-sqrtderta,2*a);
            return;
        }else if(a>0){
            huajian(-b+sqrtderta,2*a);
            return;
        }
        return;
    }else{
        if(a<0){
            if(b!=0){
                huajian(-b,2*a);
                cout<<"+";
            }
            hjsqrt(1,-2*a,derta);
        }else{
            if(b!=0){
                huajian(-b,2*a);
                cout<<"+";
            }
            hjsqrt(1,2*a,derta);
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;

    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        solve(a,b,c);
        cout<<endl;
    }
    return 0;
}
