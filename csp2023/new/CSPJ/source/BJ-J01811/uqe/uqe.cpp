#include<bits/stdc++.h>
using namespace std;
int gcd(int a,b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
bool judge(long double x1){
    int p,q,i;
    for(i=1;i<=ceil(x1);i++){
        q++;
        p=q*x1;
        if(q>0&&gcd(p,q)==1) break;
    }
    if(i==ceil(x1)) return false;
    return true;
}
bool judge1(int r){
    for(int i=2;i<=r;i++){
        if(r%d*d==0) return false;
    }
    return true;
}
bool judge2(long double x){
    if(x%1==0) return true;
    return false;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c;
    int n,t;
    cin>>n>>t;
    while(n--){
        cin>>a>>b>>c;
        int ansuqe=pow(b,2)-4*a*c;
        if(ansuqe<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(ansque==0){
            long double x1=(-b+fabs(sqrt(ansque)))/(2*a);
            int p,q;
            int i;
            for(i=1;i<=ceil(x1);i++){
                q++;
                p=q*x1;
                if(q>0&&gcd(p,q)==1) break;
            }
            if(i==ceil(x1)){
                if(q==1){
                    cout<<p<<endl;
                    continue;
                }else{
                    cout<<p<<"/"<<q;
                    continue;
                }
            }
            long double q1,q2;
            int r;
            for(int i=1;i<=ceil(x1);i++){
                r++;
                for(int j=1;j<=ceil(x1);j++){
                    q2++;
                    q1=x1-q2*fabs(sqrt(r));
                    if(judge(q1)&&judge(q2)&&q2>0) break;
                }
                if(r>1&&judge1(r)) break;
            }
            int q3,p3;
            for(i=1;i<=ceil(x1);i++){
                q3++;
                p3=q3*x1;
                if(q3>1&&p3>1&&gcd(p3,q3)==1) break;
            }
            if(q1!=0) cout<<q1<<"+";
            if(q2==1) cout<<"sqrt("<<r<<")";
            else if(judge2(q2)) cout<<q2<<"*sqrt("<<r<<")";
            else if(judge2(1/q2)) cout<<"sqrt("<<r<<")/"<<1/q2;
            else cout<<q3<<"*sqrt("<<r<<")/"<<p3;
            continue;
        }
        long double x1=(-b+fabs(sqrt(ansque)))/(2*a);
        long double x2=(-b-fabs(sqrt(ansque)))/(2*a);
        long double x3=(x1>x2?x1:x2);
        int p,q;
        int i;
        for(i=1;i<=ceil(x3);i++){
            q++;
            p=q*x1;
            if(q>0&&gcd(p,q)==1) break;
        }
        if(i==ceil(x3)){
            if(q==1){
                cout<<p<<endl;
                continue;
            }else{
                cout<<p<<"/"<<q;
                continue;
            }
        }
        long double q1,q2;
        int r;
        for(int i=1;i<=ceil(x3);i++){
            r++;
            for(int j=1;j<=ceil(x3);j++){
                q2++;
                q1=x1-q2*fabs(sqrt(r));
                if(judge(q1)&&judge(q2)&&q2>0) break;
            }
            if(r>1&&judge1(r)) break;
        }
        int q3,p3;
        for(i=1;i<=ceil(x3);i++){
            q3++;
            p3=q3*x1;
            if(q3>1&&p3>1&&gcd(p3,q3)==1) break;
        }
        if(q1!=0) cout<<q1<<"+";
        if(q2==1) cout<<"sqrt("<<r<<")";
        else if(judge2(q2)) cout<<q2<<"*sqrt("<<r<<")";
        else if(judge2(1/q2)) cout<<"sqrt("<<r<<")/"<<1/q2;
        else cout<<q3<<"*sqrt("<<r<<")/"<<p3;
        continue;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}