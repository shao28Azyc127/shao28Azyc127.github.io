#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
using namespace std;
int gsqrt(int a){
    if(a==0)return 0;
    for(int i=1;i*i<=a;i++)if(i*i==a)return i;
    return -1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)printf("NO\n");
        else{
            int sq=gsqrt(b*b-4*a*c);
            if(sq!=-1)
                if((-b+sq)%(2*a)==0)printf("%d\n",(-b+sq)/2/a);
                else {
                    int x=(-b+sq),y=a*2;
                    bool f=0;
                    if(x<0)f=1;
                    if(y<0)f=!f;
                    x=abs(x);
                    y=abs(y);
                    for(int i=2;i*i<=x;i++)
                        while(x%i==0&&y%i==0)x/=i,y/=i;
                    if(f)printf("-");
                    if(x==2&&y==4)x=1,y=2;
                    printf("%d/%d\n",x,y);
                }
            else{
                int i,del=b*b-4*a*c;
                if(b!=0){
                    if(b%(2*a)==0)printf("%d+",-b/2/a);
                    else{
                        int x=-b,y=a*2;
                        bool f=0;
                        if(x<0)f=1;
                        if(y<0)f=!f;
                        x=abs(x);
                        y=abs(y);
                        for(int i=2;i*i<=x;i++)
                            while(x%i==0&&y%i==0)x/=i,y/=i;
                        if(f)printf("-");
                        if(x==2&&y==4)x=1,y=2;
                        printf("%d/%d+",x,y);
                    }
                }
                bool gg=0;
                for(i=ceil(sqrt(del));i>1;i--){
                    if(del%(i*i)==0&&!gg){
                        if(i%(2*a)==0)printf("%d*sqrt(%d)\n",i/(2*a),del/(i*i));
                        else {
                            int x=i,y=a*2;
                            bool f=0;
                            x=abs(x);
                            y=abs(y);
                            for(int j=2;j*j<=x;i++)
                                while(x%i==0&&y%i==0)x/=j,y/=j;
                    if(x==2&&y==4)x=1,y=2;
                            if(x==1&&y==1) printf("sqrt(%d)\n",del/(i*i));
                            else if(x==1) printf("sqrt(%d)/%d\n",del/(i*i),y);
                            else if(y==1) printf("%d*sqrt(%d)\n",del/(i*i));
                            else printf("%d*sqrt(%d)/%d\n",x,del/(i*i),y);
                        }
                        gg=1;
                    }
                }
                if(!gg)printf("sqrt(%d)/%d\n",del,2*a);
            }
        }
    }
    return 0;
}
