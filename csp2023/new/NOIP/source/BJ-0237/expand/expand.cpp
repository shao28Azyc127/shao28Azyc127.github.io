#include<bits/stdc++.h>
#include<tr2/dynamic_bitset>
using namespace std;
#define $in 1<<20
#define getc() p1==p2&&(p1=buf)==(p2=buf+fread_unlocked(buf,1,$in,stdin))?-1:*p1++
#define putc(x) putchar_unlocked(x) 
char buf[$in],*p1(buf),*p2(buf);

template<class T>
inline void in(T& x){
    char y=getc();
    while(!isdigit(y))
    	y=getc();
    x=0;
    do x=10*x+(y^'0');
    while(isdigit(y=getc()));
}

template<class T>
inline void out(T x){
    if(x>9) out(x/10);
    putc(x%10^'0');
}

int X[Nsiz],Y[Nsiz];
int a[Nsiz],b[Nsiz];

#define Nsiz 500001
#define $N 709

#define Unit($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$20,$21,$22,$23,$24,$25,$26,$27,$28,$29,$30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$40,$41,$42,$43,$44,$45,$46,$47,$48,$49,$50,$51,$52,$53,$54,$55,$56,$57,$58,$59,$60,$61,$62,$63) \
    ($1)+(($2)<<1)+(($3)<<2)+(($4)<<3)+(($5)<<4)+(($6)<<5)+(($7)<<6)+(($8)<<7)+(($9)<<8)+(($10)<<9)+(($11)<<10)+(($12)<<11)+(($13)<<12)+(($14)<<13)+(($15)<<14)+(($16)<<15)+(($17)<<16)+(($18)<<17)+(($19)<<18)+(($20)<<19)+(($21)<<20)+(($22)<<21)+(($23)<<22)+(($24)<<23)+(($25)<<24)+(($26)<<25)+(($27)<<26)+(($28)<<27)+(($29)<<28)+(($30)<<29)+(($31)<<30)+(($32)<<31)+(($33)<<32)+(($34)<<33)+(($35)<<34)+(($36)<<35)+(($37)<<36)+(($38)<<37)+(($39)<<38)+(($40)<<39)+(($41)<<40)+(($42)<<41)+(($43)<<42)+(($44)<<43)+(($45)<<44)+(($46)<<45)+(($47)<<46)+(($48)<<47)+(($49)<<48)+(($50)<<49)+(($51)<<50)+(($52)<<51)+(($53)<<52)+(($54)<<53)+(($55)<<54)+(($56)<<55)+(($57)<<56)+(($58)<<57)+(($59)<<58)+(($60)<<59)+(($61)<<60)+(($62)<<61)+(($63)<<62)+(($64)<<63)

tr2::dynamic_bitset<> D[$N];
int C[Nsiz], T[$N];

bool play(int* a, int* b, int n, int m){
    if(a[0]<b[0]) swap(a,b);
    if(a[0]==b[0]||a[n-1]<=b[m-1])return 0;
    bcopy(b,C,4*m);
    sort(C,C+m);
    {D[0].clear();
    T[0]=C[0];
    int j=0,tmp=T[0];
    for(;j<=n-64;j+=64){
        D[0].append(Unit((a[j+0]>tmp),(a[j+1]>tmp),(a[j+2]>tmp),(a[j+3]>tmp),(a[j+4]>tmp),(a[j+5]>tmp),(a[j+6]>tmp),(a[j+7]>tmp),(a[j+8]>tmp),(a[j+9]>tmp),(a[j+10]>tmp),(a[j+11]>tmp),(a[j+12]>tmp),(a[j+13]>tmp),(a[j+14]>tmp),(a[j+15]>tmp),(a[j+16]>tmp),(a[j+17]>tmp),(a[j+18]>tmp),(a[j+19]>tmp),(a[j+20]>tmp),(a[j+21]>tmp),(a[j+22]>tmp),(a[j+23]>tmp),(a[j+24]>tmp),(a[j+25]>tmp),(a[j+26]>tmp),(a[j+27]>tmp),(a[j+28]>tmp),(a[j+29]>tmp),(a[j+30]>tmp),(a[j+31]>tmp),(a[j+32]>tmp),(a[j+33]>tmp),(a[j+34]>tmp),(a[j+35]>tmp),(a[j+36]>tmp),(a[j+37]>tmp),(a[j+38]>tmp),(a[j+39]>tmp),(a[j+40]>tmp),(a[j+41]>tmp),(a[j+42]>tmp),(a[j+43]>tmp),(a[j+44]>tmp),(a[j+45]>tmp),(a[j+46]>tmp),(a[j+47]>tmp),(a[j+48]>tmp),(a[j+49]>tmp),(a[j+50]>tmp),(a[j+51]>tmp),(a[j+52]>tmp),(a[j+53]>tmp),(a[j+54]>tmp),(a[j+55]>tmp),(a[j+56]>tmp),(a[j+57]>tmp),(a[j+58]>tmp),(a[j+59]>tmp),(a[j+60]>tmp),(a[j+61]>tmp),(a[j+62]>tmp),(a[j+63]>tmp)));
    }
    for(;j<=n-8;j+=8){
        D[0][j]=a[j]>tmp;
        D[0][j+1]=a[j+1]>tmp;
        D[0][j+2]=a[j+2]>tmp;
        D[0][j+3]=a[j+3]>tmp;
        D[0][j+4]=a[j+4]>tmp;
        D[0][j+5]=a[j+5]>tmp;
        D[0][j+6]=a[j+6]>tmp;
        D[0][j+7]=a[j+7]>tmp;
    }
    while(j<n-1) D[0][j]=a[j++]>tmp;
    }
    if(!D[0].all()) return 0;
    for(int t=1,i=sqrt(m),k=i;i<m;++t,i+=k){
    D[t].clear();
    T[t]=C[i];
    int j=0,tmp=T[t];
    for(;j<=n-64;j+=64){
        D[t].append(Unit((a[j+0]>tmp),(a[j+1]>tmp),(a[j+2]>tmp),(a[j+3]>tmp),(a[j+4]>tmp),(a[j+5]>tmp),(a[j+6]>tmp),(a[j+7]>tmp),(a[j+8]>tmp),(a[j+9]>tmp),(a[j+10]>tmp),(a[j+11]>tmp),(a[j+12]>tmp),(a[j+13]>tmp),(a[j+14]>tmp),(a[j+15]>tmp),(a[j+16]>tmp),(a[j+17]>tmp),(a[j+18]>tmp),(a[j+19]>tmp),(a[j+20]>tmp),(a[j+21]>tmp),(a[j+22]>tmp),(a[j+23]>tmp),(a[j+24]>tmp),(a[j+25]>tmp),(a[j+26]>tmp),(a[j+27]>tmp),(a[j+28]>tmp),(a[j+29]>tmp),(a[j+30]>tmp),(a[j+31]>tmp),(a[j+32]>tmp),(a[j+33]>tmp),(a[j+34]>tmp),(a[j+35]>tmp),(a[j+36]>tmp),(a[j+37]>tmp),(a[j+38]>tmp),(a[j+39]>tmp),(a[j+40]>tmp),(a[j+41]>tmp),(a[j+42]>tmp),(a[j+43]>tmp),(a[j+44]>tmp),(a[j+45]>tmp),(a[j+46]>tmp),(a[j+47]>tmp),(a[j+48]>tmp),(a[j+49]>tmp),(a[j+50]>tmp),(a[j+51]>tmp),(a[j+52]>tmp),(a[j+53]>tmp),(a[j+54]>tmp),(a[j+55]>tmp),(a[j+56]>tmp),(a[j+57]>tmp),(a[j+58]>tmp),(a[j+59]>tmp),(a[j+60]>tmp),(a[j+61]>tmp),(a[j+62]>tmp),(a[j+63]>tmp)));
    }
    for(;j<=n-8;j+=8){
        D[t][j]=a[j]>tmp;
        D[t][j+1]=a[j+1]>tmp;
        D[t][j+2]=a[j+2]>tmp;
        D[t][j+3]=a[j+3]>tmp;
        D[t][j+4]=a[j+4]>tmp;
        D[t][j+5]=a[j+5]>tmp;
        D[t][j+6]=a[j+6]>tmp;
        D[t][j+7]=a[j+7]>tmp;
    }
    while(j<n-1) D[t][j]=a[j++]>tmp;
    }

    for(int i=0;i<n;++i){
        
    }
}
int main(){
    int c,n,m,q;
    in(c);in(n);in(m);in(q);
    for(int i=0;i<n;++i)
        in(X[i]);
    for(int i=0;i<m;++i)
        in(Y[i]);
    char c=play(X,Y,n,m);
    putc(c);
    for(int i=0;i<q;++i){
    bcopy(X,a,4*n);
    bcopy(Y,b,4*m);
        int kx,ky;
        in(kx),in(ky);
    for(int _=0,p,v;_<kx;++_){
        in(p); in(v);
        a[p]=v;
    }
    for(int _=0,p,v;_<ky;++_){
        in(p); in(v);
        b[p]=v;
    }
    char c=play(a,b,n,m);
    putc(c^'0');
    }
}