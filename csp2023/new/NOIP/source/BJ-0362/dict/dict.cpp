#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=3e3+10;
string c[MAXN];
string s[MAXN];
int n,m;
bool cmp(char x,char y){
    return x>y;
}
int cnt[100];
int main(){
    ios::sync_with_stdio(false);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        c[i]=s[i];
    }
    for(int i=1;i<=n;i++){
        /*sort(s[i].begin(),s[i].end());
        sort(c[i].begin(),c[i].end(),cmp);*/
        memset(cnt,0,sizeof(cnt));

        for(int j=0;j<m;j++){
            char tmp=s[i][j];
            cnt[tmp-'a']++;
        }
        s[i]="";
        for(int j=0;j<='z'-'a';j++){
            while(cnt[j]--) s[i].push_back(j+'a');
        }
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<m;j++){
            char tmp=c[i][j];
            cnt[tmp-'a']++;
        }
        c[i]="";
        for(int j='z'-'a';j>=0;j--){
            while(cnt[j]--) c[i].push_back(j+'a');
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i!=j&&s[i]>c[j]){
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    return 0;
}