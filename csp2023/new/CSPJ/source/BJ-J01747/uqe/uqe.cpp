#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int getFlag(int fenzi,int fenmu){
    if(fenzi<0&&fenmu<0) return 1;
    if(fenzi<0) return -1;
    if(fenmu<0) return -1;
    return 1;
}
void flag_fenzi_fenmu(int& flag,int& fenzi,int& fenmu){
    int gcdres;
    flag=getFlag(fenzi,fenmu);
    if(fenzi<0) fenzi=-fenzi;
    if(fenmu<0) fenmu=-fenmu;
    gcdres=gcd(fenzi,fenmu);
    fenzi/=gcdres;
    fenmu/=gcdres;
    return;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,delta;
    int fenzi,fenmu,flag,cnt,tmp,rc;
    double sqrtd,solve1,solve2;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        delta=b*b-((a*c)<<2);
        if(delta<0){
            cout<<"NO"<<endl;
        }
        else{
            sqrtd=sqrt(delta*1.0);
            solve1=(-b+sqrtd)/(a<<1);
            solve2=(-b-sqrtd)/(a<<1);
            if(int(sqrtd)==sqrtd){
                //cout<<sqrtd<<endl;
                if(solve1>solve2) fenzi=-b+sqrtd;
                else fenzi=-b-sqrtd;
                fenmu=(a<<1);
                //cout<<fenzi<<' '<<fenmu<<endl;
                flag_fenzi_fenmu(flag,fenzi,fenmu);
                if(fenzi%fenmu){
                    cout<<flag*fenzi<<'/'<<fenmu<<endl;
                }
                else{
                    cout<<flag*fenzi/fenmu<<endl;
                }
            }
            else{
                rc=1;
                tmp=delta;
                for(int i=2;i*i<=delta;i++){
                    cnt=0;
                    while(!(tmp%(i*i))){
                        cnt++;
                        tmp/=i*i;
                        rc*=i;
                    }
                    //cout<<"i:"<<i*i<<" cnt:"<<cnt<<endl;
                }
                delta/=rc*rc;
                fenzi=-b;
                fenmu=(a<<1);
                flag_fenzi_fenmu(flag,fenzi,fenmu);
                if(fenzi%fenmu){
                    cout<<flag*fenzi<<'/'<<fenmu<<'+';
                }
                else if(fenzi){
                    cout<<flag*fenzi/fenmu<<'+';
                }
                fenzi=rc;
                fenmu=(a<<1);
                flag_fenzi_fenmu(flag,fenzi,fenmu);
                if(fenzi%fenmu){
                    if(fenzi!=1){
                        cout<<fenzi<<'*';
                    }
                    cout<<"sqrt("<<delta<<")/"<<fenmu<<endl;
                }
                else{
                    if(fenzi/fenmu!=1){
                        cout<<fenzi/fenmu<<'*';
                    }
                    cout<<"sqrt("<<delta<<')'<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
