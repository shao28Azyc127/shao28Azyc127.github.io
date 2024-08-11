#include <bits/stdc++.h>
using namespace std;
const int N=1000+10;
struct num{string typ,nm;int len;};
struct ad{int add;string ty;};
struct node{
    string name;
    num unt[N];
    int dem,num,total;
}a[N];
struct nd{
    string nm;
    int ty,start,num,total,add[N];
}b[N];
int t,tot,n,add;
map<string,int> findnm;
map<string,int> mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int order;
        scanf("%d",&order);
        if(order==1){
            ++tot;int k;
            cin>>a[tot].name>>k;
            findnm[a[tot].name]=tot;
            a[tot].num=k;
            for(int i=1;i<=k;i++){
                cin>>a[tot].unt[i].typ>>a[tot].unt[i].nm;
                if(a[tot].unt[i].typ=="int"){a[tot].unt[i].len=4;}
                else if(a[tot].unt[i].typ=="short"){a[tot].unt[i].len=2;}
                else if(a[tot].unt[i].typ=="long"){a[tot].unt[i].len=8;}
                else if(a[tot].unt[i].typ=="byte"){a[tot].unt[i].len=1;}
                a[tot].dem=max(a[tot].dem,a[tot].unt[i].len);
                a[tot].total=a[tot].dem+a[tot].unt[i].len;
            }
            printf("%d %d\n",a[tot].total,a[tot].dem);
        }else if(order==2){
            string ty,nm;
            cin>>ty>>nm;
            ++n;
            b[n].nm=nm;
            b[n].ty=findnm[ty];
            mp[nm]=n;
            for(;;add++){
                if(add%a[b[n].ty].dem){
                    b[n].start=add;
                    for(int i=1;i<=a[b[n].ty].num;i++){
                        while(add%a[b[n].ty].unt[i].len==0) add++;
                        b[n].add[i]=add;
                        add+=a[b[n].ty].unt[i].len;
                    }
                    break;
                }
            }
        }else if(order==3){
            string s;
            cin>>s;
            int len=s.size();
            string nm="";int cnt=0,pos;
            for(int i=0;i<len;i++){
                while(s[i]!='.') nm=nm+s[i],i++;
                if(cnt==0){
                    cnt++;
                    pos=b[mp[nm]].ty;
                }else{
                    for(int i=1;i<=a[pos].num;i++){
                        if(a[pos].unt[i].nm==nm){
                            printf("%lld\n",b[mp[nm]].add[i]);
                            break;
                        }
                    }
                }
            }
        }else if(order==4){

        }else{

        }
    }
    return 0;
}