#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m;
char ch[3005][3005];
int id1,id2;
string s[3005],s1,s2,tmp;
bool cmp(char x,char y){
    return x>y;
}
bool cmp2(char x,char y){
    return x<y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1) {cout<<1<<endl; return 0;}
    for(int i=1;i<=n;i++){
            cin>>ch[i];
            sort(ch[i],ch[i]+m,cmp);
            s[i]="";
            for(int j=0;j<m;j++) s[i]+=ch[i][j];
    }
    for(int i=1;i<=n;i++){
        if(s[i]<s1||id1==0){
            s2=s1; id2=id1;
            s1=s[i]; id1=i;
        }
        else if(s[i]<s2||id2==0){
            s2=s[i]; id2=i;
        }
    }
    for(int i=1;i<=n;i++){
        sort(ch[i],ch[i]+m,cmp2);
        tmp="";
        for(int j=0;j<m;j++) tmp+=ch[i][j];
        if(id1==i) cout<<(tmp<s2);
        else cout<<(tmp<s1);
    }
    cout<<endl;
    return 0;
}
