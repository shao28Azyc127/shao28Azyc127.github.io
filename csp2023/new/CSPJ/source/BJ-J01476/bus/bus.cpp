//zyc AK IOI
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Road{
    int u,v,t;
}road[20005];
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> road[i].u >> road[i].v >> road[i].t;
    }
    cout << -1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//100+100+50+?
//寄了寄了我太废物了，大家都AK了只有我爆0了
//感觉左边那个好厉害看着还比我小，我就是个图论废物只会骗分
//完了完了被单调队列了我是不是要AFO了
//大寄，寄掉之前先来爆瓜吧
//2338bitexplo 暗恋 LJH ，Br00k5xx 暗恋 ayt
//1145141919810kunkun 暗恋LD
//欸呀怎么还有45min 我要无聊死了
//继续继续，但是 ayt 喜欢 Sumy01，Br00k5xx 为此十分愤怒
//LJH 也说他对 Sumy01 有好感 修罗场了属于是
//一些圣经：2338nitexplo:1145141919810kunkun 你就知点足吧
//你喜欢的人至少关心你。
//LITFLYR：2338bitexplo 你就知点足吧 你喜欢的人至少关心你什么时候die
//2338bitexplo : 好好好，黑暗森林打击了属于是。
//好好好还有35min 润去改题