#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,t,m;
    cin >> t >> m;
    for(int i=0;i<t;i++){
        cin >> a >> b >> c;
        if(b*b-4*a*c<0){
            cout << "NO" << endl;
            continue;
        }
        int x;
        for(int i=m;i>=-m;i--){
            if(a*i*i+b*i+c==0){
                x=i;
                break;
            }
        }
        int p=-m,q=1;
        while(p/q!=x&&q<=m){
            p=-m;
            while(p<=m&&p/q!=x) p++;
            if(p/q==x) break;
            q++;
        }
        if(p/q==x&&q<=m&&p<=m){
            cout << p;
            if(q!=1) cout << "/" << q;
        }
        else{
            p=-m,q=1;
            int r=2;
            for(r=2;r<=m;r++){
                int smflag=1;
                for(int d=2;d*d<=r;d++){
                    int d2=d*d;
                    if(r%d2==0){
                        smflag=0;
                        break;
                    }
                }
                if(smflag==0) continue;
                while(p+q*sqrt(r)!=x&&q<=m){
                    p=-m;
                    while(p<=m&&p+q*sqrt(r)!=x&&p<=m) p++;
                    if(p/q==x) break;
                    q++;
                }
                if(p<=m&&p+q*sqrt(r)!=x) break;
            }
            if(p!=0){
                while(p/q!=x&&q<=m){
                    p=-m;
                    while(p<=m&&p/q!=x) p++;
                    if(p/q==x) break;
                    q++;
                }
                if(p/q==x&&q<=m&&p<=m) cout << p << "/" << q;
            }
            if(q==1){
                cout << "sqrt(" << q << ")";
            }
            else if(q==int(q)){
                cout << q << "*sqrt(" << r << ")";
            }
            else{
                int c,d;
                for(c=2;c<=m;c++){
                    for(d=2;d<=m;d++){
                        if(c/d==q){
                            cout << c << "*sqrt(" << r << ")/" << d;
                            break;
                        }
                    }
                    if(c/d==q){
                        break;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}
