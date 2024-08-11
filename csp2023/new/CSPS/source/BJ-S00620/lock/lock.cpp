#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string a[10];
string read(){
    char c;
    string ss="";
    while(ss.size()<5){
        c=getchar();
        if(c<'0'||c>'9') continue;
        ss+=c;
    }
    return ss;
}
bool cmp(string x,string y){
    int diff=0,dpos=0;
    for(int i=0;i<5;++i){
        if(x[i]==y[i]) continue;
        if(diff==0){
            diff=abs(x[i]-y[i]);
            dpos=i;
        }
        else if(i-dpos>1) return false;
        else{
            if(x[i]>y[i]){
                int wy=x[i]-y[i];
                if((y[i-1]-'0'+wy)%10+'0'==x[i-1]) continue;
                else return false;
            }
            else{
                int wy=y[i]-x[i];
                if((x[i-1]-'0'+wy)%10+'0'==y[i-1]) continue;
                else return false;
            }
        }
    }
    return true;
}
bool cmp2(string x){
    for(int i=2;i<=n;++i){
        if(x==a[i]) return false;
        if(!cmp(x,a[i])) return false;
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    string s;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    if(n==1){
        printf("81\n");
        return 0;
    }
    string s1;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=9;++j){
            s1=a[1];
            s1[i-1]=(s1[i-1]-'0'+j)%10+'0';
            if(cmp2(s1)) ++ans;
        }
    }
    for(int i=1;i<=4;++i){
        for(int j=1;j<=9;++j){
            s1=a[1];
            s1[i-1]=(s1[i-1]-'0'+j)%10+'0';
            s1[i]=(s1[i]-'0'+j)%10+'0';
            if(cmp2(s1)) ++ans;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
