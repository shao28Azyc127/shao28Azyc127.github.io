#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>


class Road{
public:
    unsigned int from=-1, to=-1, open=0;
};

bool operator<(Road a, Road b){
    if (a.from==b.from){
        if (a.to==b.to){
            return a.open<b.open;
        }
        else{
            return a.to<b.to;
        }
    }
    else{
        return a.from<b.from;
    }
}


class Step{
public:
    unsigned int pos=1, time=0;

    Step(){}
    Step(unsigned int p, unsigned int t){
        this->pos = p;
        this->time = t;
    }
};


//use special: a[i]=0
int main(){
    //faster input
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    //input
    unsigned int n/*point num*/=-1, m/*road num*/=-1, k/*bus sep*/=-1; std::cin >> n >> m >> k;
    std::vector<Road> roads(m);
    for (unsigned int i=0; i<roads.size(); ++i){
        std::cin >> roads[i].from >> roads[i].to >> roads[i].open;
    }
    //format
    std::vector<std::set<Road>> roadMap(n+1);
    for (unsigned int i=0; i<roads.size(); ++i){
        roadMap[roads[i].from].insert(roads[i]);
    }

    //bfs
    std::queue<Step> stems;
    stems.push(Step());
    while (!stems.empty()){
        for (
        std::set<Road>::iterator i=roadMap[stems.front().pos].begin();
        i!=roadMap[stems.front().pos].end();
        ++i){
            if (i->to==n && !((stems.front().time+1)%k)){
                std::cout << (stems.front().time+1) << "\n";
                return 0;
            }
            stems.push(Step(i->to, stems.front().time+1));
        }
        stems.pop();
    }
    std::cout << -1 << "\n";
    return 0;
}
