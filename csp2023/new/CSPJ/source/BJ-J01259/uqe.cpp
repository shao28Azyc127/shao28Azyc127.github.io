#include<bits/stdc++.h>
using namespace std;
double T,M,dert,x1,x2,x,q1,q2,r;
int gcd(int a1,int b1){
if(b1==0){
    return a1;
}else{
gcd(b1,a1%b1);
}
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
cin >> T >> M;
for(int i = 0;i < T;i++){
    int a,b,c;
    cin >> a >>b >> c;
    dert=b*b-4*a*c;
    if(dert<0){
        cout << "NO" << endl;
        continue;
    }else if(dert==0){
        x=(-b+sqrt(dert))/(2*a);
        if(sqrt(dert)-floor(sqrt(dert))==0){
        if(gcd(-b,2*a)==1&&2*a==1){
            cout << -b;
        }else if(abs(-b)%abs(2*a)==0){
            cout << (-b)/(2*a);
            }else if(gcd(-b,2*a)!=1){
            if(x<0){
                cout << "-" << abs(-b/gcd(-b,2*a))<<"/"<<abs(2*a/gcd(-b,2*a));
            }else{
            cout << -b/gcd(-b,2*a)<<"/"<<2*a/gcd(-b,2*a);
            }
        }
        }else{
        q1=(-b)/(2*a);
        q2=1/2*a;
        if(q1!=0){
            cout <<q1<<"+";
        }else{
        if(q2==1){
            cout << "sqrt("<< dert << ")";
        }else if(q2-floor(q2)==0){
        cout << q2 << "*" << "sqrt("<< dert << ")";
        }else if(1/q2-floor(1/q2==0)){
        cout <<"sqrt("<< dert << ")/"<<1/q2;
        }else{

        }
        }
        }
    }else{
    x1=(-b+sqrt(dert))/(2*a);
    x2=(-b-sqrt(dert))/(2*a);
    if(x1>x2){
    if(sqrt(dert)-floor(sqrt(dert))==0){
        if(gcd(-b,2*a)==1&&2*a==1){
            cout << -b;
        }else if(abs(-b)%abs(2*a)==0){
            cout << (-b)/(2*a);
            }else if(gcd(-b,2*a)!=1){
            if(x1<0){
                cout << "-" << abs(-b/gcd(-b,2*a))<<"/"<<abs(2*a/gcd(-b,2*a));
            }else{
            cout << -b/gcd(-b,2*a)<<"/"<<2*a/gcd(-b,2*a);
            }
        }
        }else{
        q1=(-b)/(2*a);
        q2=1/2*a;
        if(q1!=0){
            cout <<q1<<"+";
        }else{
        if(q2==1){
            cout << "sqrt("<< dert << ")";
        }else if(q2-floor(q2)==0){
        cout << q2 << "*" << "sqrt("<< dert << ")";
        }else if(1/q2-floor(1/q2==0)){
        cout <<"sqrt("<< dert << ")/"<<1/q2;
        }else{

        }
        }
        }
    }else{
    if(sqrt(dert)-floor(sqrt(dert))==0){
        if(gcd(-b,2*a)==1&&2*a==1){
            cout << -b;
        }else if(abs(-b)%abs(2*a)==0){
            cout << (-b)/(2*a);
            }else if(gcd(-b,2*a)!=1){
            if(x<0){
                cout << "-" << abs(-b/gcd(-b,2*a))<<"/"<<abs(2*a/gcd(-b,2*a));
            }else{
            cout << -b/gcd(-b,2*a)<<"/"<<2*a/gcd(-b,2*a);
            }
        }
        }else{
        q1=(-b)/(2*a);
        q2=-1/2*a;
        if(q1!=0){
            cout <<q1<<"+";
        }else{
        if(q2==1){
            cout << "sqrt("<< dert << ")";
        }else if(q2-floor(q2)==0){
        cout << q2 << "*" << "sqrt("<< dert << ")";
        }else if(1/q2-floor(1/q2==0)){
        cout <<"sqrt("<< dert << ")/"<<1/q2;
        }else{

        }
        }
        }
    }
    }
}
fclose(stdin);
fclose(stdout);
return 0;
}