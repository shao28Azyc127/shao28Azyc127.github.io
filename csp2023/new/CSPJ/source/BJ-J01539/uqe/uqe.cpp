#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a,b,c;
int flag;
int P[2305];
int chk(int x)
{
    flag=1;
    for(int i=2;i<=2e9;i++)
    {
        if(P[i]>x) break;
        while(x%P[i]==0&&x>0)
        {
            flag*=i;
            x/=P[i];
            //cout<<i<<" ";
        }
    }
    //cout<<x<<endl;
    return x;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=sqrt(5*m*m)+1;i++)
    {
        P[i]=i*i;
    }
    while(n--)
    {
        scanf("%d %d %d",&a,&b,&c);
        int tri=b*b-4*a*c;
        if(tri<0)
        {
            printf("NO\n");
            continue;
        }
        int p=sqrt(tri);
        if(p*p==tri)
        {
            int up=-b+p;
            if(a<0) up=-b-p;
            int down=2*a;
            //cout<<endl;
            int g=__gcd(up,down);
            //cout<<tri<<endl;
            //cout<<p<<endl;
            //cout<<up<<"))"<<down<<endl;
            //cout<<a<<" "<<b<<" "<<c<<endl;
            up/=g;
            down/=g;
            if(down<0&&up<0) down*=-1,up*=-1;
            else if(down<0) down*=-1,up*=-1;
            if(down==1) printf("%d\n",up);
            else printf("%d/%d\n",up,down);
            //cout<<up<<"))"<<down<<endl;
            //cout<<endl;
            continue;
        }
        int Up=-b;
        int Down=2*a;
        int ggg=__gcd(Up,Down);
        Up/=ggg;
        Down/=ggg;
        if(Down<0&&Up<0) Down*=-1,Up*=-1;
        else if(Down<0) Down*=-1,Up*=-1;
        if(Down==1&&Up!=0) printf("%d+",Up);
        else if(Up!=0) printf("%d/%d+",Up,Down);
        //cout<<tri<<endl;
        int r=chk(tri);
        //cout<<r<<" "<<flag<<endl;
        double q2=flag*1.0/(2*a);
        if(q2<0) q2*=-1;
        //cout<<q2<<endl;
        double q3=1/q2;
        if(q2==1) printf("sqrt(%d)",r);
        else if(q2==int(q2)) printf("%d*sqrt(%d)",int(q2),r);
        else if(q3==int(q3)) printf("sqrt(%d)/%d",r,int(q3));
        else
        {
            int gg=__gcd(flag,2*a);
            //cout<<flag<<"%%%"<<gg<<endl;
            //cout<<"IAKIOI!"<<endl;
            printf("%d*sqrt(%d)/%d",flag/gg,r,2*a/gg);
        }
        printf("\n");
    }
    return 0;
}
