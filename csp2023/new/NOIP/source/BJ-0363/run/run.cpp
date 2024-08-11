#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,T=0.94*CLOCKS_PER_SEC;
struct cli{int x,y,v;};
cli init;
int c,t,n,m,k,d;
bitset<N> vis;
long long ans;
vector<cli> memcli;
inline void file(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    //彻底无力了。甚至打字的力气都不见得有，用最后的一点时间写写想写的罢。
    //刚才看了一眼t3自己的源程序长度为1.145KB，感觉很有意思。
    //t4目前写的贪心看起来只能过第一个样例，非常没有前途。伤心。
    //好像 jincy2008 （他就在我左后没多少）一直在写代码和思考，并不像我一样一直在颓颓颓。
    // 我吃死酸辣粉 就坐在我左边的左边的左边，看样子也一直在思考。
    //至于 zhouyuhang 和 KarlPeter 他们两个并不在我视野之内。
    //我记得之前我mum说过如果NOIP只有3=就要退滚。这么看来似乎确实该退滚了。
    //t4的前两个点看起来就很能状压诶。可惜没力气写不了了，咕，伤心。
    //回想一下前面两年零两个月的OI生涯，感觉自己一直是loser阿，在每个班都会被各路神仙吊打。
    //比如在基础班被吊打。
    //然后去了提高P，时间好像很长，就，被吊打了很久。过了半年甚至开始被更加的吊打。（因为来了一些后浪）
    //再后来去P+之后被Tetris还有1307他们吊打乐。
    //暑假到了集二，被全班吊打！（
    //秋天集训的时候又在401被各种吊打。能连着两年阿克csps的神仙，初二国银的神仙，初三国金的神仙轮番吊打！！
    //到目前为止我好像也一直是垫底大师。怎么办，真是无药可救。
    //哎，不过OI还是带来了很多美好回忆的阿。
    //就像是感觉昨天在楼道里膜拜完ylq老师，又在高一食堂坐在了初三国金学长的位置，就，感觉好了很多阿。
    //昨天四个人在学校的美术馆进行了长达30min的秋游。sdsz文创好看，咕咕咕。甚至还看到了之前自己和同学的作品呢。
    //今年感觉1=线至少300+，2=线估计也得200+罢。哎，那我真的就3=退滚了。
    //t3我好像想到一种高妙策略，可是感觉不是很对而且需要巨大多的分分分。这么分治我就要似了，真写不动阿真写不动。
    //可怕！想起来自己t3有一处锅，修了。现在才能得180pts，哭哭哭。
    //呜呜呜。还是想 [数据删除] ，好珂爱阿。呜呜呜。
    //希望西西艾弗的数据水一些阿。
    //by BJ-0363,2023.11.18 12:46
}
inline bool cmp(cli a,cli b){return a.v>b.v;}
inline bool check(int p){
    int cnt=0;
    for(int i=memcli[p].x-memcli[i].y;i>=1;--i){
        if(vis[i]) ++cnt;
        else break;
    }
    if(cnt+memcli[p].y>k) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> t;
    while(t--){
        cin >> n >> m >> k >> d;
        memcli.clear(),vis.reset(),ans=0;
        while(m--){
            cin >> init.x >> init.y >> init.v;
            if(init.y>k) continue;
            if(init.v<=init.y*d) continue;
            init.v-=init.y*d;
            memcli.push_back(init);
        }
        if(!memcli.size()){cout << "0\n";continue;}
        sort(memcli.begin(),memcli.end(),cmp);
        for(int i=0;i<memcli.size();++i){
            if(check(i)){
                ans+=memcli[i].v;
                for(int j=memcli[i].x;j>memcli[i].x-memcli[i].y;--j) vis[j]=1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}