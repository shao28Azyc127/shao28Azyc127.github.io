#include<bits/stdc++.h>
using namespace std;
struct code{
    int a,b,c,d,e;
}s[15];
int n;
bool check(int a,int b,int c,int d,int e,int i){
    if(a==s[i].a && b==s[i].b && c==s[i].c && d==s[i].d && e==s[i].e) return false;
    if(a==s[i].a && b==s[i].b && c==s[i].c && d==s[i].d) return true;
    if(a==s[i].a && b==s[i].b && c==s[i].c && e==s[i].e) return true;
    if(a==s[i].a && b==s[i].b && d==s[i].d && e==s[i].e) return true;
    if(a==s[i].a && c==s[i].c && d==s[i].d && e==s[i].e) return true;
    if(b==s[i].b && c==s[i].c && d==s[i].d && e==s[i].e) return true;

    if(a==s[i].a   && b==s[i].b   && c==s[i].c   && (d-s[i].d)  == (e-s[i].e) ) return true;
    if(a==s[i].a   && b==s[i].b   && (c-s[i].c)  == (d-s[i].d)  && e==s[i].e  ) return true;
    if(a==s[i].a   && (b-s[i].b)  == (c-s[i].c)  && d==s[i].d   && e==s[i].e  ) return true;
    if((a-s[i].a)  == (b-s[i].b)  && c==s[i].c   && d==s[i].d   && e==s[i].e  ) return true;

    if(a==s[i].a      && b==s[i].b      && c==s[i].c      && (d-s[i].d)     == (e-s[i].e)+10 ) return true;
    if(a==s[i].a      && b==s[i].b      && (c-s[i].c)     == (d-s[i].d)+10  && e==s[i].e     ) return true;
    if(a==s[i].a      && (b-s[i].b)     == (c-s[i].c)+10  && d==s[i].d      && e==s[i].e     ) return true;
    if((a-s[i].a)     == (b-s[i].b)+10  && c==s[i].c      && d==s[i].d      && e==s[i].e     ) return true;

    if(a==s[i].a      && b==s[i].b      && c==s[i].c      && (d-s[i].d)+10  == (e-s[i].e)    ) return true;
    if(a==s[i].a      && b==s[i].b      && (c-s[i].c)+10  == (d-s[i].d)     && e==s[i].e     ) return true;
    if(a==s[i].a      && (b-s[i].b)+10  == (c-s[i].c)     && d==s[i].d      && e==s[i].e     ) return true;
    if((a-s[i].a)+10  == (b-s[i].b)     && c==s[i].c      && d==s[i].d      && e==s[i].e     ) return true;

    return false;
}
int sum=0;
bool flag=true;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d %d",&s[i].a,&s[i].b,&s[i].c,&s[i].d,&s[i].e);
    }
    for(int a=0;a<=9;a++){
        for(int b=0;b<=9;b++){
            for(int c=0;c<=9;c++){
                for(int d=0;d<=9;d++){
                    for(int e=0;e<=9;e++){
                        for(int i=1;i<=n;i++){
                            if(!check(a,b,c,d,e,i)){
                                flag=false;
                                break;
                            }
                        }
                        if(flag) sum++;
                        //if(flag){
                        //     cout << a << b << c << d << e << " ";
                        //}
                        flag=true;
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}
