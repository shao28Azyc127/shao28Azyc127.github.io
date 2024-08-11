#include<bits/stdc++.h>
using namespace std;
struct w {
    int a,b,c,d,e;
}s[10][90];
int a1[10],b1[10],c1[10],d1[10],e1[10],zl[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,z,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a1[i]>>b1[i]>>c1[i]>>d1[i]>>e1[i];
    }
    if(n==1) {
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++) {
        z=1;
        for(int j=1;j<=2;j++) {
            for(int y=1;y<=9;y++) {
                if(j==1) {
                    if(a1[i]!=(a1[i]+y)%10) {
                        s[i][z].a=(a1[i]+y)%10;
                        s[i][z].b=b1[i];
                        s[i][z].c=c1[i];
                        s[i][z].d=d1[i];
                        s[i][z].e=e1[i];
                        z++;
                    }
                    if(b1[i]!=(b1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=(b1[i]+y)%10;
                        s[i][z].c=c1[i];
                        s[i][z].d=d1[i];
                        s[i][z].e=e1[i];
                        z++;
                    }

                    if(c1[i]!=(c1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=b1[i];
                        s[i][z].c=(c1[i]+y)%10;
                        s[i][z].d=d1[i];
                        s[i][z].e=e1[i];
                        z++;
                    }
                    if(d1[i]!=(d1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=b1[i];
                        s[i][z].c=c1[i];
                        s[i][z].d=(d1[i]+y)%10;
                        s[i][z].e=e1[i];
                        z++;
                    }
                    if(e1[i]!=(e1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=b1[i];
                        s[i][z].c=c1[i];
                        s[i][z].d=d1[i];
                        s[i][z].e=(e1[i]+y)%10;
                        z++;
                    }
                }
                if(j==2) {
                    if(a1[i]!=(a1[i]+y)%10&&b1[i]!=(b1[i]+y)%10) {
                        s[i][z].a=(a1[i]+y)%10;
                        s[i][z].b=(b1[i]+y)%10;
                        s[i][z].c=c1[i];
                        s[i][z].d=d1[i];
                        s[i][z].e=e1[i];
                        z++;
                    }
                    if(b1[i]!=(b1[i]+y)%10&&c1[i]!=(c1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=(b1[i]+y)%10;
                        s[i][z].c=(c1[i]+y)%10;
                        s[i][z].d=d1[i];
                        s[i][z].e=e1[i];
                        z++;
                    }

                    if(c1[i]!=(c1[i]+y)%10&&d1[i]!=(d1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=b1[i];
                        s[i][z].c=(c1[i]+y)%10;
                        s[i][z].d=(d1[i]+y)%10;
                        s[i][z].e=e1[i];
                        z++;
                    }
                    if(d1[i]!=(d1[i]+y)%10&&e1[i]!=(e1[i]+y)%10) {
                        s[i][z].a=a1[i];
                        s[i][z].b=b1[i];
                        s[i][z].c=c1[i];
                        s[i][z].d=(d1[i]+y)%10;
                        s[i][z].e=(e1[i]+y)%10;
                        z++;
                    }
                }
            }
        }
        zl[i]=z-1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=zl[i];j++) {
            for(int y=i+1;y<=n;y++) {
                if(i==y) {
                    continue;
                }
                for(int x=1;x<=zl[y];x++) {
                    for(int k=1;k<=5;k++) {
                        if(k==1) {
                            if(s[i][j].a!=s[y][x].a) {
                                goto toto;
                            }
                        }
                        if(k==2) {
                            if(s[i][j].b!=s[y][x].b) {
                                goto toto;
                            }
                        }
                        if(k==3) {
                            if(s[i][j].c!=s[y][x].c) {
                                goto toto;
                            }
                        }
                        if(k==4) {
                            if(s[i][j].d!=s[y][x].d) {
                                goto toto;
                            }
                        }
                        if(k==5){
                            if(s[i][j].e!=s[y][x].e) {
                                goto toto;
                            }
                        }
                    }
                    sum++;
                    toto: ;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
