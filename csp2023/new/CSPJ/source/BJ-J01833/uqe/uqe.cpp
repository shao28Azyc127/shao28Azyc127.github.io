#include<iostream>
#include<cmath>
using namespace std;

int _d(int a,int b){
    int su;
    for(int i=2;i<min(a,b);i++){
        if(i%a==0 && i%b==0)su=i;
    }
    return su;
}

bool pd(double a){
    if(a>int(a)){
        return 1;
    }
    return 0;
}

int main(){
    int a,b,c;
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(a<0){
            a*=-1;
            b*=-1;
            c*=-1;
        }
        int fl=b*b-4*a*c;
        if(fl<0)cout<<"NO\n";
        if(fl==0){
            int flag=_d(b,2*a);
            double s=b/2/a*-1;
            if(pd(s))cout<<b*-1/flag<<"/"<<2*a/flag<<endl;
            else cout<<s;
        }
        if(fl>0){
            if(pd(fl)){
                int s=b*-1+fl;
                if(pd(s/2/a))cout<<s<<"/"<<2*a<<endl;
            else cout<<s;
            }
        }
    }
    return 0;
}
