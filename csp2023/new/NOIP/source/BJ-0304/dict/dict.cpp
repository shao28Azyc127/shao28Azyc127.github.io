#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
string s[3010],smax[3010];

bool check(int x){
    for(int i=1;i<=n;i++){
        if(i!=x){
            if(s[x].compare(s[i])>=0){
                return false;
            }
        }
    }
    return true;
}
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(check(i)==true){
                printf("1");
            }else{
                printf("0");
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        char tmp[3010];
        for(int j=0;j<m;j++){
            tmp[j]=s[i][j];
        }
        sort(tmp,tmp+m,cmp);
        s[i]=tmp;
        smax[i]=tmp;
    }
    for(int i=1;i<=n;i++){
        char tmp[3010];
        for(int j=0;j<m;j++){
            tmp[j]=s[i][j];
        }
        sort(tmp,tmp+m);
        s[i]=tmp;
        if(i-1!=0){
            s[i-1]=smax[i-1];
        }
        if(check(i)==true){
            printf("1");
        }else{
            printf("0");
        }
    }

    return 0;
}
