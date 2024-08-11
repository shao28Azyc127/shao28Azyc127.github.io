#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,
double x1,x2;
int main(){
    freoprn("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        if((b*b-4*a*c)>=0){
            x1=(-b+sqrt(b*b-4*a*c))/2/a;
            x2=(-b-sqrt(b*b-4*a*c))/2/a;
            if(sqrt(b*b-4*a*c)==(double)(int)sqrt(b*b-4*a*c)){
                if((double)(b/2/a)==(double)(int)(b/2/a)&&(double)(sqrt(b*b-4*a*c)/2/a)==(double)(int)(sqrt(b*b-4*a*c)/2/a))printf("%d",max((int)x1,(int)x2));
                else if((double)(b/2/a)!=(double)(int)(b/2/a)&&(double)(sqrt(b*b-4*a*c)/2/a)!=(double)(int)(sqrt(b*b-4*a*c)/2/a))printf("%d/%d",max(-b+(int)sqrt(b*b-4*a*c),-b-(int)sqrt(b*b-4*a*c)),2*a);
                else if((double)(b/2/a)==(double)(int)(b/2/a)&&(double)(sqrt(b*b-4*a*c)/2/a)!=(double)(int)(sqrt(b*b-4*a*c)/2/a))printf("%d+%d/%d",-b/2/a,max(-b+(int)sqrt(b*b-4*a*c),-b-(int)sqrt(b*b-4*a*c)),a*2);
                else if((double)(b/2/a)!=(double)(int)(b/2/a)&&(double)(sqrt(b*b-4*a*c)/2/a)==(double)(int)(sqrt(b*b-4*a*c)/2/a))printf("%d/%d+%d",-b,2*a,max(-b+(int)sqrt(b*b-4*a*c),-b-(int)sqrt(b*b-4*a*c))/2/a);
            }else{
                if((double)(b/2/a)==(double)(int)(b/2/a)&&x2>x1)printf("%d-sqrt(%d)/%d",-b/a/2,b*b-4*a*c,2*c);
                else if((double)(b/2/a)==(double)(int)(b/2/a)&&x2<=x1)printf("%d+sqrt(%d)/%d",-b/a/2,b*b-4*a*c,2*c);
                else if((double)(b/2/a)!=(double)(int)(b/2/a)&&x2>x1)printf("%d/%d-sqrt(%d)",-b,2*a,b*b-4*a*c);
                else if((double)(b/2/a)!=(double)(int)(b/2/a)&&x2<=x1)printf("%d/%d+sqrt(%d)",-b,2*a,b*b-4*a*c);
            }
        }else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}