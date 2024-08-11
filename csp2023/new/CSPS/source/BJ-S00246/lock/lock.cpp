#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
void read(int &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void lread(long long &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void print(int number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>9){
        print(number/10);
    }
    putchar((number%10)^48);
}
int a[6],b[6];
int c[1000001];
void cpy(){
    for(int i=1;i<=5;i++)b[i]=a[i];
}
void js(){
    int s=0;
    for(int i=1;i<=5;i++){
        s*=10;
        s+=b[i];
    }
    ++c[s];
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            read(a[j]);
        }
        for(int j=1;j<=5;j++){
            for(int k=1;k<=9;k++){
                cpy();
                b[j]=(b[j]+k)%10;
                js();
            }
        }
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                cpy();
                b[j]=(b[j]+k)%10;
                b[j+1]=(b[j+1]+k)%10;
                js();
            }
        }
    }
    int ans=0;
    for(int i=0;i<=99999;i++){
        if(c[i]==n)++ans;
    }
    print(ans);
    return 0;
}
