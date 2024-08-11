# include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,d,e;
}m[20];
map <string,bool> p;
map <string,int> t;
int n;
long long ans = 0;
string js(node t){
    string s;
    s = "00000";
    s[0] = char(t.a+'0');
    s[1] = char(t.b+'0');
    s[2] = char(t.c+'0');
    s[3] = char(t.d+'0');
    s[4] = char(t.e+'0');
    return s;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d %d",&m[i].a,&m[i].b,&m[i].c,&m[i].d,&m[i].e);
        p[js(m[i])] = 2;
        t[js(m[i])] = -9999;
    }
    for(int i=0;i<n;i++){
        //单圈情况遍历
        for(int j=0;j<=9;j++){
            node d = m[i];
            d.a = j;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        for(int j=0;j<=9;j++){
            node d = m[i];
            d.b = j;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        for(int j=0;j<=9;j++){
            node d = m[i];
            d.c = j;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        for(int j=0;j<=9;j++){
            node d = m[i];
            d.d = j;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        for(int j=0;j<=9;j++){
            node d = m[i];
            d.e = j;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        //2环情况遍历
        node d = m[i];
        for(int j=0;j<9;j++){
            d.a++;
            d.b++;
            d.a = d.a%10;
            d.b = d.b%10;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        d = m[i];
        for(int j=0;j<9;j++){
            d.b++;
            d.c++;
            d.c = d.c%10;
            d.b = d.b%10;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        d = m[i];
        for(int j=0;j<9;j++){
            d.c++;
            d.d++;
            d.c = d.c%10;
            d.d = d.d%10;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
        d = m[i];
        for(int j=0;j<9;j++){
            d.e++;
            d.d++;
            d.d = d.d%10;
            d.e = d.e%10;
            if(p[js(d)]!=1&&p[js(d)]!=2){
                ans++;
                p[js(d)] = 1;
                t[js(d)] = 1;
            }
            else t[js(d)] = t[js(d)] + 1;
        }
    }
    ans = 0;
    node dd;
    for(int i1=0;i1<=9;i1++){
        dd.a = i1;
        for(int i2=0;i2<=9;i2++){
            dd.b = i2;
            for(int i3=0;i3<=9;i3++){
                dd.c = i3;
                for(int i4=0;i4<=9;i4++){
                    dd.d = i4;
                    for(int i5=0;i5<=9;i5++){
                        dd.e = i5;
                        if(t[js(dd)]==n) ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
