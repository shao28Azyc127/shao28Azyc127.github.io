#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
bool prime(int a,int b,int c){
    if((b*b-4*a*c)<0){
         return false;
    }else{
         return true;
    }
}
bool im(int n){
    for(int i=0;i<=500;i++){
        if(i*i==n){
            return true;
        }else if(i*i>n){
            return false;
        }
    }
}
void p(int a,int b,int c){
    int n=2*a,m=b*b-4*a*c;
    if(!im(m)){
        if(b!=0){
            cout<<-b<<"/"<<n<<"+sqrt("<<m<<")/"<<n<<endl;
        }else{
            cout<<"sqrt("<<m<<")/"<<n<<endl;
        }
    }else{
        int z=(-b+sqrt(m))/n;
        if(z!=(-b+sqrt(m))/n){
            cout<<-b+sqrt(m)<<"/"<<n<<endl;
        }else if(z==(-b+sqrt(m))/n){
            cout<<(-b+sqrt(m))/n<<endl;
        }
    }
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m,a[5000][4]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i=1;i<=n;i++){
        if(!prime(a[i][1],a[i][2],a[i][3])){
            cout<<"NO"<<endl;
        }else{
            p(a[i][1],a[i][2],a[i][3]);
        }
    }

    return 0;
}
