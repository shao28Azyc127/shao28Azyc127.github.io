#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
struct node{
    string s;
    int id;
};
bool cmp1(node x,node y){
    return x.s<y.s;
}

bool cmp3(char x,char y){
    return x>y;
}
node a[3005],maxx[3005],minn[3005];
void init(int x){
    a[x].id=x;
    a[x].s=minn[x].s;
    for(int i=1;i<=n;i++){
        if(i!=x){
            a[i].s=maxx[i].s;
            a[i].id=i;
        }
    }
}
void easy_s(){
    sort(a+1,a+n+1,cmp1);
}
void fx(string s,int i){
    char c[3005];//record each max
    for(int i=0;i<m;i++){
        c[i]=s[i];
    }
    sort(c,c+m,cmp3);
    s="";
    for(int i=0;i<m;i++){
        s+=c[i];
    }
    maxx[i].id=i;
    maxx[i].s=s;
}
void fn(string s,int i){
    minn[i].id=i;
    minn[i].s=maxx[i].s;
    reverse(minn[i].s.begin(),minn[i].s.end());
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n==1){
        printf("1");
        return 0;
    }
    string stmp;
    for(int i=1;i<=n;i++){
        cin>>stmp;
        fx(stmp,i);//find max
        fn(stmp,i);//find min
    }
  //  for(int i=1;i<=n;i++){
  //     cout<<maxx[i].s<<" "<<minn[i].s<<endl;
   // }
    for(int i=1;i<=n;i++){
        init(i);
        easy_s();
        if(a[1].id==i) printf("1");
        else printf("0");
    }
    return 0;
}
