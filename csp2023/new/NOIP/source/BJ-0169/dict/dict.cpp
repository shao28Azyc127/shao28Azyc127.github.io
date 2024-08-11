#include<bits/stdc++.h>

using namespace std;

typedef pair<string,int> PII;
const int N=3010;

int n,m;
PII v[3];
string s[N],s1[N],s2[N];

bool cmp1(char a,char b){
    return a<b;
}

bool cmp2(char a,char b){
    return a>b;
}

/*bool check(string a,string b){
    int len=a.size();
    for(int i=0;i<len;++i) if(a[i]!=b[i]) return a[i]<b[i];
    return 0;
}*/

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    v[1].first=v[2].first="#";
    for(int i=1;i<=n;++i){
        cin>>s[i];
        s1[i]=s2[i]=s[i];
        sort(s2[i].begin(),s2[i].end(),cmp2);
        //sort(s1[i].begin(),s1[i].end(),cmp1);
        s1[i]=s2[i];
        reverse(s1[i].begin(),s1[i].end());
        PII u={s2[i],i};
        if(u<v[1] || v[1].first=="#") v[2]=v[1],v[1]=u;
        else if(u<v[2] || v[2].first=="#") v[2]=u;
    }
    for(int i=1;i<=n;++i){
        int flag=1;
        if(s1[i]<v[1].first){
            flag=1;
        }
        else{
            if(v[1].second==i){
                if(n==1 || s1[i]<v[2].first) flag=1;
                else flag=0;
            }
            else{
                flag=0;
            }
        }
        printf("%d",flag);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}