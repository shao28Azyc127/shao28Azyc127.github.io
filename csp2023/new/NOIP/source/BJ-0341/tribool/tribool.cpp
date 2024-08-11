#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct variable {
    bool isRev;
    int orig;
    char isForce;
};
struct equation {
    bool isRev;
    int targP;
    int fromP;
    char isForce;
};
int c,t,n,m,father[maxn],dist[maxn];
char isForce[maxn];
variable arr[maxn];
int getfather(int pos) {
    if(father[pos] == pos) return pos;
    int rt = father[pos];
    father[pos] = getfather(father[pos]);
    dist[pos] = (dist[pos]+dist[rt])%2;
    return father[pos];
}
char findV(int pos) {
    int fth = getfather(pos);
    int dst = dist[maxn];
    char ret = isForce[fth];
    if(ret == '.') return '.';
    if(ret == 'U') return 'U';
    if(ret == 'T' && dst == 0) return 'T';
    if(ret == 'T' && dst == 1) return 'F';
    if(ret == 'F' && dst == 0) return 'F';
    if(ret == 'F' && dst == 1) return 'T';
    return '.';
}
int main () {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++) {
            isForce[i] = '.';
            arr[i].isForce = '.';
            arr[i].isRev = false;
            arr[i].orig = i;
            father[i] = i;
            dist[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            char a;
            scanf(" %c",&a);
            if(a == 'T' || a == 'F' || a == 'U') {
                int b;
                scanf("%d",&b);
                arr[b].isForce = a;
            }
            if(a == '-' || a == '+') {
                int b,c;
                scanf("%d%d",&b,&c);
                if(arr[c].isForce != '.') {
                    if(arr[c].isForce == 'T') arr[b].isForce = 'F';
                    if(arr[c].isForce == 'F') arr[b].isForce = 'T';
                    if(arr[c].isForce == 'U') arr[b].isForce = 'U';
                }
                else {
                    arr[b] = arr[c];
                    if(a == '-') arr[b].isRev = !arr[b].isRev;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            equation tmp;
            tmp.targP = i;
            tmp.fromP = arr[i].orig;
            tmp.isRev = arr[i].isRev;
            tmp.isForce = arr[i].isForce;
            //printf("from: %d\ntarget: %d\nreversed: %d\nforced value: %c\n\n",tmp.fromP,tmp.targP,tmp.isRev,tmp.isForce);
            int fromFather = getfather(tmp.fromP);
            int targFather = getfather(tmp.targP);
            if(tmp.isForce == '.') {
                if(fromFather == targFather) {
                    if((dist[tmp.fromP]+dist[tmp.targP])%2 != tmp.isRev) {
                        isForce[fromFather] = 'U';
                    }
                }
                else {
                    char fromV = isForce[fromFather];
                    char targV = isForce[targFather];
                    int dst = (dist[tmp.fromP]+dist[tmp.targP]+tmp.isRev)%2;
                    dist[targFather] = dst;
                    father[targFather] = fromFather;
                    if(targV == 'U') {
                        isForce[fromFather] = 'U';
                    }
                    else if(targV == 'T') {
                        if(dst == 0) {
                            if(fromV == 'F') isForce[fromFather] = 'U';
                            else if(fromV == '.') isForce[fromFather] = 'T';
                        }
                        else if(dst == 1) {
                            if(fromV == 'T') isForce[fromFather] = 'U';
                            else if(fromV == '.') isForce[fromFather] = 'F';
                        }
                    }
                    else if(targV == 'F') {
                        if(dst == 0) {
                            if(fromV == 'T') isForce[fromFather] = 'U';
                            if(fromV == '.') isForce[fromFather] = 'F';
                        }
                        if(dst == 1) {
                            if(fromV == 'F') isForce[fromFather] = 'U';
                            if(fromV == '.') isForce[fromFather] = 'T';
                        }
                    }
                }
            }
            else {
                int dst = dist[tmp.targP];
                char newV = tmp.isForce;
                if(dst == 1) {
                    if(newV == 'T') newV = 'F';
                    else if(newV == 'F') newV == 'T';
                }
                if(isForce[targFather] == '.') isForce[targFather] = newV;
                else if(isForce[targFather] == 'U') isForce[fromFather] = 'U';
                else if(isForce[targFather] != newV) isForce[targFather] = 'U';
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (findV(i) == 'U');
            //printf("%c",findV(i));
        }
        //printf("\n");
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
