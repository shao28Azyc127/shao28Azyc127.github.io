#include<bits/stdc++.h>
using namespace std;
int n,a[10][6],po[6],s[10];
bool check(int x,int y){
    int t=x,t1=y;
    string s1="";
    while(t!=0){
        s1=(char)(t%10+'0')+s1;
        t/=10;
    }
    string s2="";
    while(t1!=0){
        s2=(char)(t1%10+'0')+s2;
        t1/=10;
    }
    while(s1.size()!=5) s1="0"+s1;
    while(s2.size()!=5) s2="0"+s2;
    int c=0;
    string s="",w="";
    for(int i = 0;i < s1.size();i++){
        if(s1[i]!=s2[i]){
            c++;
            s=s+(char)((s1[i]-s2[i]+10)%10+'0');
        }else s=s+'0';
    }
    if(c>2) return false;
    if(c==1) return true;
    for(int i = 0;i < s.size();i++){
        if(s[i]!='0'&&s[i+1]!='0'&&s[i]==s[i+1]){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        s[i]=0;
        for(int j = 1;j <= 5;j++){
            scanf("%d",&a[i][j]);
            s[i]=s[i]*10+a[i][j];
        }
    }
    int cnt=0;
    for(int st=0;st <= 99999;st++){
        bool r=true;
        for(int i = 1;i <= n;i++){
            if(!check(s[i],st)){
                r=false;
            }
        }
        if(r==true) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
