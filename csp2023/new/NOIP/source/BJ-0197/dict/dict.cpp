#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[3005][3005];
string maxs[3005], mins[3005];
bool cmp1(char a, char b){
    if(a>b) return true;
    return false;
}
bool cmp2(char a, char b){
    if(a<b) return true;
    return false;
}
string make_max(char x[]){
    int len=strlen(x);
    sort(x, x+len, cmp1);
    return x;
}
string make_min(char x[]){
    int len=strlen(x);
    sort(x, x+len, cmp2);
    return x;
}
struct Node{
    string s;
    int id;
    bool flag;
}w[6005];
bool cmp3(Node a , Node b){
    if(a.s==b.s) return a.flag>b.flag;
    return a.s<b.s;
}
bool cnt[3005];
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    if(n<=15&&m<=2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxs[i]=make_max(a[i]);
            mins[i]=make_min(a[i]);
            //cout<<maxs[i]<<" "<<mins[i]<<endl;
        }
        for(int i=1;i<=n;i++){
            string x=mins[i];
            bool ans=true;
            for(int j=1;j<=n;j++){
                if(i!=j&&x>maxs[j]){
                    ans=false;
                    break;
                }
            }
            cout<<ans;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        w[i].id=i;
        w[i].s=make_max(a[i]);
        w[i].flag=true;
        w[n+i].id=i;
        w[n+i].s=make_min(a[i]);
        w[n+i].flag=false;
    }
    sort(w+1, w+2*n+1, cmp3);
    int p=0;
    for(int i=1;i<=2*n;i++){
        if(!p){
            if(!w[i].flag) cnt[w[i].id]=true;
            else{
                p=w[i].id;
            }
        }
        else{
            if(w[i].id==p){
                cnt[w[i].id]=true;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i];
    }
    return 0;
}
