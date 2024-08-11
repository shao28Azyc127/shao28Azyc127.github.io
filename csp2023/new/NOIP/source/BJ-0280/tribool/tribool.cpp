#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int N = 1e5+5;

int c,t;

int fa[N*2];

char value[N*2];
map<char,char> mp;

int getfa(int a){
    if(fa[a] == a) return a;
    return fa[a] = getfa(fa[a]);
}

void mer(int a,int b){
    //printf("merge %d & %d\n",a,b);
    int faa = getfa(a), fab = getfa(b);
    //printf("faa = %d, fab = %d\nfa[%d]=%d\n\n",faa,fab,faa,fab);
    if(faa != fab){
        fa[a] = fab;
        value[a] = 0;
    }
}

int n,m;
char v;
int x,y;
int ans;
int against[N*2];

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    mp['T'] = 'F';
    mp['F'] = 'T';
    mp['U'] = 'U';
    scanf("%d%d",&c,&t);
    for(int T = 1;T <= t;T++){
        memset(against,0,sizeof(against));
        memset(value,0,sizeof(value));
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n*2+3;i++) fa[i] = i;
        value[2*n+1] = 'T';
        value[2*n+2] = 'F';
        value[2*n+3] = 'U';
        for(int i = 1;i <= m;i++){
            cin >> v;
            if(v == '+'){
                scanf("%d%d",&x,&y);
                mer(x,y);
                mer(x+n,y+n);
            }
            else if(v == '-'){
                scanf("%d%d",&x,&y);
                mer(x,y+n);
                mer(x+n,y);
            }
            else{
                scanf("%d",&x);
                if(v == 'T'){
                    fa[x] = n*2+1;
                    fa[x+n] = n*2+2;
                }
                else if(v == 'F'){
                    fa[x] = n*2+2;
                    fa[x+n] = n*2+1;
                }
                else if(v == 'U'){
                    fa[x] = fa[x+n] = n*2+3;
                }
                value[x] = v;
                value[x+n] = mp.find(v)->second;
            }
        }
        for(int i = 1;i <= n;i++){
            int fai = getfa(i),fai2 = getfa(i+n);
            if(fai == fai2) against[fai]++;
            //if(value[fai] == 'U' || fai == fai2 ) ans++;
        }
        for(int i = 1;i <= n;i++){
            int fai = getfa(i),fai2 = getfa(i+n);
            /*
            if(against[fai]) printf("%d->%d %c against!\n",i,fai,value[fai]);
            else printf("%d->%d %c\n",i,fai,value[fai]);
            */
            //printf("%d->%d %c\n",i,fai,value[fai]?value[fai]:' ');
            if(value[fai] == 'U' || (against[fai] && (value[i] != 'T' && value[i] != 'F'))) ans++;
        }
        printf("%d\n",ans);
        /*
        for(int i = 1;i <= n*2;i++){
            if(i <= n) printf("%d %d %c\n",i,getfa(i),value[i]);
            else printf("-%d %d %c\n",i-n,getfa(i),value[i]);
        }
        cout << endl;
        */
    }
    return 0;
}
