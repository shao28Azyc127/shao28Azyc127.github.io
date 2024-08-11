#include <bits/stdc++.h>
using namespace std;
int n,x[10][10];
long long ans;
bool qwq(int a1,int b1,int a2,int b2){
    for(int i=0;i<=20;i++){
        a1++;
        a2++;
        if(a1>9)
            a1-=10;
        if(a2>9)
            a2-=10;
        if(a1==b1&&a2==b2){
            return 0;
        }
    }
    return 1;
}
bool check1(int a,int b,int c,int d,int e){
    for(int i=1;i<=n;i++){
        int tmp[6]{0,0,0,0,0},tot=0;
        if(x[i][1]!=a)
            tmp[1]++,tot++;
        if(x[i][2]!=b)
            tmp[2]++,tot++;
        if(x[i][3]!=c)
            tmp[3]++,tot++;
        if(x[i][4]!=d)
            tmp[4]++,tot++;
        if(x[i][5]!=e)
            tmp[5]++,tot++;
        //cout<<tmp[1]<<" "<<tmp[2]<<" "<<tmp[3]<<" "<<tmp[4]<<" "<<tmp[5]<<endl;
        if(tot>2)
            return 0;
        if(tmp[1]&&tmp[3])
            return 0;//cout<<1;
        if(tmp[1]&&tmp[4])
            return 0;//cout<<1;
        if(tmp[1]&&tmp[5])
            return 0;//cout<<1;
        if(tmp[2]&&tmp[4])
            return 0;//cout<<1;
        if(tmp[2]&&tmp[5])
            return 0;//cout<<1;
        if(tmp[3]&&tmp[5])
            return 0;//cout<<1;
        if(tot==1)
            continue;
        if(tot==0)
            return 0;

        if(tmp[1]&&tmp[2]&&qwq(x[i][1],a,x[i][2],b))
            return 0;
        if(tmp[2]&&tmp[3]&&qwq(x[i][2],b,x[i][3],c))
            return 0;
        if(tmp[3]&&tmp[4]&&qwq(x[i][3],c,x[i][4],d))
            return 0;
        if(tmp[4]&&tmp[5]&&qwq(x[i][4],d,x[i][5],e))
            return 0;
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
   freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>x[i][j];
    for(int a=0;a<=9;a++)
        for(int b=0;b<=9;b++)
            for(int c=0;c<=9;c++)
                for(int d=0;d<=9;d++)
                    for(int e=0;e<=9;e++){
                        if(check1(a,b,c,d,e))
                             ans++;
                    }

    cout<<ans<<endl;
    return 0;
}
