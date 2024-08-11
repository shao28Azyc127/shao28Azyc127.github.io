#include <iostream>
#include <queue>
#define ll long long

using namespace std;

const int N = 1e5+5;
const ll minn = 1;

int n;
ll a[N],b[N],c[N];
ll t[N];    //time to grow up -- special condition A    ;   how tall it has grown up -- special condition B
queue<int> q;
queue<int> q2;
bool flaga = true, flagb = true, flagc = true,flagd = true; //special conditions

int h[N],tot = 0;
struct edge{
    int v,next;
}e[2*N];
void addedge(int u,int v){
    e[++tot].v = v;
    e[tot].next = h[u];
    h[u] = tot;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        if(c[i] != 0) flaga = false;
    }
    for(int i = 1;i < n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        addedge(u,v);
        addedge(v,u);
        if(u != i || v != i+1) flagb = false;
        //cout << flagb << endl;
    }
    if(flaga){  //It's Okay ^.^
        //the advantage of this condition it that the days to grow up in need can directly be found
        ll ans = n;
        for(int i = 1;i <= n;i++){
            t[i] = b[i]<=1 ? a[i] : (a[i]%b[i]==0 ? a[i]/b[i] : a[i]/b[i]+1);
            ans = max(ans,t[i]);
        }
        printf("%lld\n",ans);
        return 0;
    }
    else if(flagb){ //o.O? there is no example for me to test it! but I'll have a try
        //the advantage of this condition is that it doesn't have to choose the next one to plant
        //Okay, I created an example and it suggests that it's Okay
        //hope it's Okay.
        ll ans = 1;
        int island = 1;   //this island
        t[1] = max(b[1]+c[1],minn);    //add its height
        if(t[1] < a[1]) q.push(1);      //push it into the queue
        while(1){
            ans++;
            island = e[h[island]].v;    //jump into the next island
            q.push(island);
            while(!q.empty()){  //count its height and compare its height with the need
                int u = q.front();
                q.pop();
                t[u] += max(b[u]+ans*c[u], minn);
                if(t[u] < a[u]) q2.push(u); //store them briefly
            }
            while(!q2.empty()){ //put them back to q
                int u = q2.front();
                q2.pop();
                q.push(u);
            }
            if(q.empty()){
                printf("%d\n",ans);
                return 0;
            }
        }
    }
    return 0;
}
