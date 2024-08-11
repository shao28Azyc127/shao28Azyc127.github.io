#include <bits/stdc++.h>
using namespace std;
char a[9][6];
int x[9][6],b[82][6],c[82][6],d[82][6],e[82][6],f[82][6],g[82][6],h[82][6],k[82][6];
int n,nmb=0,l[82],m[82],o[82],p[82],q[82],r[82],s[82],t[82];
int a1[82],z1,a2[82],z2,a3[82],z3,a4[82],z4,a5[82],z5,a6[82],z6;
int one(){
    cout<<81;
}
int two(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  nmb++;
            }
    }
}
int three(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
    }
    z1=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<81;j++){
                if(a1[i]==o[j])  nmb++;
            }
    }
}
int fore(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                e[v][i+1]+=j;
                if(e[v][i+1]>9) e[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
            p[i]=10000*e[i][0]+1000*e[i][1]+100*e[i][2]+10*e[i][3]+e[i][4];
    }
    z1=0;
    z2=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(p[i]==o[j])  a2[z2]=o[j],z2++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<z2;j++){
                if(a1[i]==a2[j])  nmb++;
            }
    }

}
int fife(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                e[v][i+1]+=j;
                if(e[v][i+1]>9) e[v][i+1]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                f[v][i+1]+=j;
                if(f[v][i+1]>9) f[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
            p[i]=10000*e[i][0]+1000*e[i][1]+100*e[i][2]+10*e[i][3]+e[i][4];
            q[i]=10000*f[i][0]+1000*f[i][1]+100*f[i][2]+10*f[i][3]+f[i][4];
    }
    z1=0;
    z2=0;
    z3=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(p[i]==o[j])  a2[z2]=o[j],z2++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<z2;j++){
                if(a1[i]==a2[j])  a3[z3]=a2[j],z3++;
            }
    }
    for(int i=0;i<z3;i++){
            for(int j=0;j<82;j++){
                if(a3[i]==q[j])  nmb++;
            }
    }


}
int six(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                e[v][i+1]+=j;
                if(e[v][i+1]>9) e[v][i+1]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                f[v][i+1]+=j;
                if(f[v][i+1]>9) f[v][i+1]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                g[v][i+1]+=j;
                if(g[v][i+1]>9) g[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
            p[i]=10000*e[i][0]+1000*e[i][1]+100*e[i][2]+10*e[i][3]+e[i][4];
            q[i]=10000*f[i][0]+1000*f[i][1]+100*f[i][2]+10*f[i][3]+f[i][4];
            r[i]=10000*g[i][0]+1000*g[i][1]+100*g[i][2]+10*g[i][3]+g[i][4];
    }
    z1=0;
    z2=0;
    z3=0;
    z4=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(p[i]==o[j])  a2[z2]=o[j],z2++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<z2;j++){
                if(a1[i]==a2[j])  a3[z3]=a2[j],z3++;
            }
    }
    for(int i=0;i<82;i++){
            for(int j=0;j<82;j++){
                if(r[i]==q[j])  a4[z4]=q[j],z4++;
            }
    }
    for(int i=0;i<z3;i++){
            for(int j=0;j<z4;j++){
                if(a3[i]==a4[j])  nmb++;
            }
    }



}
int seven(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                h[v][i]+=j;
                if(h[v][i]>9) h[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                e[v][i+1]+=j;
                if(e[v][i+1]>9) e[v][i+1]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                f[v][i+1]+=j;
                if(f[v][i+1]>9) f[v][i+1]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                g[v][i+1]+=j;
                if(g[v][i+1]>9) g[v][i+1]-=10;
                h[v][i]+=j;
                if(h[v][i]>9) h[v][i]-=10;
                h[v][i+1]+=j;
                if(h[v][i+1]>9) h[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
            p[i]=10000*e[i][0]+1000*e[i][1]+100*e[i][2]+10*e[i][3]+e[i][4];
            q[i]=10000*f[i][0]+1000*f[i][1]+100*f[i][2]+10*f[i][3]+f[i][4];
            r[i]=10000*g[i][0]+1000*g[i][1]+100*g[i][2]+10*g[i][3]+g[i][4];
            s[i]=10000*h[i][0]+1000*h[i][1]+100*h[i][2]+10*h[i][3]+h[i][4];

    }
    z1=0;
    z2=0;
    z3=0;
    z4=0;
    z5=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(p[i]==o[j])  a2[z2]=o[j],z2++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<z2;j++){
                if(a1[i]==a2[j])  a3[z3]=a2[j],z3++;
            }
    }
    for(int i=0;i<82;i++){
            for(int j=0;j<82;j++){
                if(r[i]==q[j])  a4[z4]=q[j],z4++;
            }
    }
    for(int i=0;i<z3;i++){
            for(int j=0;j<z4;j++){
                if(a3[i]==a4[j])  a5[z5]=a4[z4],z5++;
            }
    }
    for(int i=0;i<z5;i++){
            for(int j=0;j<82;j++){
                if(a5[i]==s[j])  nmb++;
            }
    }



}
int eight(){
    int v=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                h[v][i]+=j;
                if(h[v][i]>9) h[v][i]-=10;
                k[v][i]+=j;
                if(k[v][i]>9) k[v][i]-=10;
                v++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<10;j++){
                b[v][i]+=j;
                if(b[v][i]>9) b[v][i]-=10;
                b[v][i+1]+=j;
                if(b[v][i+1]>9) b[v][i+1]-=10;
                c[v][i]+=j;
                if(c[v][i]>9) c[v][i]-=10;
                c[v][i+1]+=j;
                if(c[v][i+1]>9) c[v][i+1]-=10;
                d[v][i]+=j;
                if(d[v][i]>9) d[v][i]-=10;
                d[v][i+1]+=j;
                if(d[v][i+1]>9) d[v][i+1]-=10;
                e[v][i]+=j;
                if(e[v][i]>9) e[v][i]-=10;
                e[v][i+1]+=j;
                if(e[v][i+1]>9) e[v][i+1]-=10;
                f[v][i]+=j;
                if(f[v][i]>9) f[v][i]-=10;
                f[v][i+1]+=j;
                if(f[v][i+1]>9) f[v][i+1]-=10;
                g[v][i]+=j;
                if(g[v][i]>9) g[v][i]-=10;
                g[v][i+1]+=j;
                if(g[v][i+1]>9) g[v][i+1]-=10;
                h[v][i]+=j;
                if(h[v][i]>9) h[v][i]-=10;
                h[v][i+1]+=j;
                if(h[v][i+1]>9) h[v][i+1]-=10;
                k[v][i]+=j;
                if(k[v][i]>9) k[v][i]-=10;
                k[v][i+1]+=j;
                if(k[v][i+1]>9) k[v][i+1]-=10;
                v++;
        }
    }
    for(int i=0;i<81;i++){
            l[i]=10000*b[i][0]+1000*b[i][1]+100*b[i][2]+10*b[i][3]+b[i][4];
            m[i]=10000*c[i][0]+1000*c[i][1]+100*c[i][2]+10*c[i][3]+c[i][4];
            o[i]=10000*d[i][0]+1000*d[i][1]+100*d[i][2]+10*d[i][3]+d[i][4];
            p[i]=10000*e[i][0]+1000*e[i][1]+100*e[i][2]+10*e[i][3]+e[i][4];
            q[i]=10000*f[i][0]+1000*f[i][1]+100*f[i][2]+10*f[i][3]+f[i][4];
            r[i]=10000*g[i][0]+1000*g[i][1]+100*g[i][2]+10*g[i][3]+g[i][4];
            s[i]=10000*h[i][0]+1000*h[i][1]+100*h[i][2]+10*h[i][3]+h[i][4];
            t[i]=10000*k[i][0]+1000*k[i][1]+100*k[i][2]+10*k[i][3]+k[i][4];

    }
    z1=0;
    z2=0;
    z3=0;
    z4=0;
    z5=0;
    z6=0;
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(l[i]==m[j])  a1[z1]=m[j],z1++;
            }
    }
    for(int i=0;i<81;i++){
            for(int j=0;j<81;j++){
                if(p[i]==o[j])  a2[z2]=o[j],z2++;
            }
    }
    for(int i=0;i<z1;i++){
            for(int j=0;j<z2;j++){
                if(a1[i]==a2[j])  a3[z3]=a2[j],z3++;
            }
    }
    for(int i=0;i<82;i++){
            for(int j=0;j<82;j++){
                if(r[i]==q[j])  a4[z4]=q[j],z4++;
            }
    }
    for(int i=0;i<z3;i++){
            for(int j=0;j<z4;j++){
                if(a3[i]==a4[j])  a5[z5]=a4[z4],z5++;
            }
    }
    for(int i=0;i<z5;i++){
            for(int j=0;j<82;j++){
                if(a5[i]==s[j])  a6[z6]=s[j],z6++;
            }
    }
    for(int i=0;i<z6;i++){
            for(int j=0;j<82;j++){
                if(a6[i]==t[j])  nmb++;
            }
    }



}
int main(){
    //freopen("lock2.in","r",stdin);
    //freopen("lock2.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>x[i][j];
        }
    }
    for(int v=0;v<81;v++){
            for(int j=0;j<=5;j++){
                b[v][j]=x[0][j];
                c[v][j]=x[1][j];
                d[v][j]=x[2][j];
                e[v][j]=x[3][j];
                f[v][j]=x[4][j];
                g[v][j]=x[5][j];
                h[v][j]=x[6][j];
                k[v][j]=x[7][j];
            }
    }

    if(n==1) one();
    else if (n==2) two();
    else if(n==3) three();
    else if(n==4) fore();
    else if(n==5) fife();
    else if(n==6) six();
    else if(n==7) seven();
    else if(n==8) eight();
    cout<<nmb;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
