#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string s[3007],a[3007];
int buc[1007];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=26;j++) buc[j]=0;
        for(int j=0;j<m;j++){
            buc[s[i][j]-'a']++;
        }
        s[i]="";
        for(int j=26;j>=0;j--){
            for(int k=1;k<=buc[j];k++) s[i]+=(j+'a');
        }
    }
    for(int i=1;i<=n;i++){
        a[i]="";
        for(int j=m-1;j>=0;j--) a[i]+=s[i][j];
    }
    string maxx,la;
    int idm=-1;
    if(s[1]>s[2]) maxx=s[2],la=s[1],idm=2;
    else maxx=s[1],la=s[2],idm=1;
    for(int i=3;i<=n;i++){
        if(s[i]<maxx){
            la=maxx;
            maxx=s[i];
            idm=i;
        }else if(s[i]<la){
            la=s[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=idm){
            if(a[i]<maxx) printf("1");
            else printf("0");
        }else{
            if(a[i]<la) printf("1");
            else printf("0");
        }
    }
    return 0;
}