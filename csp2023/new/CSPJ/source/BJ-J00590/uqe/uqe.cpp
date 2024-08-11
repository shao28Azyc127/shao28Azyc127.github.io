#include<bits/stdc++.h>
using namespace std;
int T,M;

double solve_delta(int a,int b,int c){
    double delta=b*b-4*a*c;
    return delta;
}
/*
int gcd(int a,int b){
    return a==0?b:gcd(b%a,a);
}
string inttostring(int x){
    string ans;
    if(x<0){
        ans+='-';
        x=-x;
    }
    int digitcnt=log(x)/log(10);
    for(int i=digitcnt+1;i>=1;i--){
        int digit=(x%int(pow(10,i)))/pow(10,i-1);
        ans+=char('0'+digit);
    }
    return ans;
}
string result(int i1,int p1,int delta,int p2){
    string res;
    int gcd1=gcd(i1,p1);
    i1/=gcd1,p1/=gcd1;
    if(int(i1/p1+delta/p2)==(double)((double)i1/p1+(double)sqrt(delta)/p2)){
        return inttostring(i1/p1+delta/p2);
    }
    if(i1==0){

    }
    else if(p1==1){
        res+=inttostring(i1);
    }else{
        res+=inttostring(i1);
        res+='/';
        res+=inttostring(p1);
    }
    int i2=sqrt(delta);
    
    if(i2*i2==delta){
        int gcd2=gcd(i2,p2);
        if(i2==0){

        }else{
            res+='+';
            if(p2==1){
                res+=inttostring(i2);
            }else{
                res+=inttostring(i2);
                res+='/';
                res+=inttostring(p2);
            }
        }
    }
    return res;
}*/
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=solve_delta(a,b,c);
        if(delta<0){
            printf("NO\n");
            continue;
        }
       // cout<<"KKKKKK"<<endl;
        cout<<max((-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a))<<endl;
    }
    return 0;
}