//8:43 100pts
#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y);
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e9+5;
int n,m;
string s[3005],ss[3005],fir,sec;
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        if(i==1)fir=s[1];
        if(i==2) {
            if(s[i]<fir)fir=s[i],sec=s[1];
            else sec=s[2];
        }
        sort(s[i].begin(),s[i].end());
        ss[i]=s[i];
        reverse(s[i].begin(),s[i].end());
        if(s[i]<fir) {
            sec=fir;
            fir=s[i];
        } else if(s[i]<sec) {
            sec=s[i];
        }
    }
    //cout<<fir<<endl<<sec<<endl;
    if(n==1) {
        printf("1");
        return 0;
    }
    //sort(ss+1,ss+n+1);
    for(int i=1;i<=n;i++) {
        string str=s[i];
        s[i]=ss[i];
        //cout<<s[i]<<endl;
        if(str==fir) {
            if(s[i]>sec)printf("0");
            else printf("1");
        } else {
            if(s[i]>fir)printf("0");
            else printf("1");
        }
    }
    return 0;
}
