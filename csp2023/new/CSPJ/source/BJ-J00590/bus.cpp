#include<bits/stdc++.h>
using namespace std;
int T,M;
bool rflag=0;
double solve_delta(int a,int b,int c){
    double delta=b*b-4*a*c;
    return delta;
}
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
int temp;
string genshihuajian(int delta,int p2){
    string ans;
    int s=sqrt(delta),out=1,in=delta;
    for(int i=1;i<=s;i++){
        if(delta%(i*i)==0){
            out=i;
            in=delta/(i*i);
        }
    }
    int gcd1=gcd(out,p2);
    out/=gcd1;
    p2/=gcd1;
    if(out!=1){
        ans+=inttostring(out);
        if(in!=1)
        ans+='*';
    }
    if(in!=1){
        ans+="sqrt(";
    ans+=inttostring(in);
    ans+=")";
    }
    if(p2!=1){
        ans+='/';
        ans+=inttostring(p2);
    }
    if(in==1)
    temp=p2;
    return ans;
}
string result(int i1,int p1,int delta,int p2){
    string res;
    int gcd1=gcd(i1,p1);
    i1/=gcd1,p1/=gcd1;
    
    if(p1<0){
        i1*=-1;
        p1*=-1;
    }
    /*if(sqrt(delta)*sqrt(delta)==delta){
        temp=p1;
        delta*=p1*p1;
    }*/
    /*if(p1==1){
        res+=inttostring(i1*temp+sqrt(delta));
        if(p1!=1){
            res+='/';
            res+=inttostring(p1);
        }
        return res;
    }*/
    if(temp==p1){
        res+=inttostring(i1+sqrt(delta));
        if(p1!=1){
            res+='/';
            res+=inttostring(p1);
        }
        return res;
    }
    if(temp==-p1){
        temp*=-1;
        res+=inttostring(i1-sqrt(delta));
        if(p1!=1){
            res+='/';
            res+=inttostring(p1);
        }
        return res;
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
    int gcd2=gcd(i2,p2);
    i2/=gcd2;
    if(i2*i2==delta)
    p2/=gcd2;
    if(i2*i2==delta){
        
        if(i2==0){

        }else{
            if(i1!=0)
                res+='+';
            if(p2==1){
                res+=inttostring(i2);
            }else{
                res+=inttostring(i2);
                res+='/';
                res+=inttostring(p2);
            }
        }
    }else{
        if(i1!=0)
            res+='+';
        if(p2<0) p2*=-1;
        res+=genshihuajian(delta,p2);
    }
    return res;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int delta=solve_delta(a,b,c);
        if(delta<0){
            printf("NO\n");
            continue;
        }
        int x=max(int((-b+sqrt(delta))/(2*a)),int((-b-sqrt(delta))/(2*a)));
        if((x*x*a+x*b+c)==0){
            cout<<x<<"\n";
            continue;
       }
        cout<<result(-b,2*a,delta,2*a)<<"\n";
    }
    return 0;
}