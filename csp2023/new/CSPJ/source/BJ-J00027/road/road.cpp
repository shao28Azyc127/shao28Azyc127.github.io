#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n, d;
int v[10001], a[10001];

//如果站点1的油价最低 直接在1加满到n的油

//一共有多远：
int Far(){
    int f_cnt = 0;
    for (int i = 1; i < n; i++){
        f_cnt += v[i];
    }
    return f_cnt;
}

int first_low(){
    int min = 114514, id = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] < min){
            min = a[i];
            id = i;
        }
    }
}

/*
先找 1 - n中油价最低点 标记为flag 1
再找 1 - flag 1中油价最低点 标记为flag 2
重复 直到油价最低点为1 购买1 - flag x的油
算式：
1.算出到flag X的距离：
f = v[1] + v[2] + ... + v[flag x]
2.算出到flag X的价格：
ans = f * a[k] （首次k = 1， k表示当前位置）
3.标记k = flag x
4.x-- 下一次计算flag x-1

*/

//这里找到1 - flag x中油价最低的站点 并记录 flag初始为n
//即每次找到当前段最便宜的油价
//并前往下一个油价最低点或者终点

int cnt = 0;//一共的价格
int k = 1;//当前的位置
void Low(int flag){
    //k表示当前位置
    //flag表示最便宜区间前的站点编号 初始为n
    int min = 114514, id = 0;

    //min表示最低油价
    //id表示最低油价的站点编号

    for (int i = 1; i <= flag; i++){
        if (a[i] < min){
            min = a[i];
            id = i;
        }
    }




    //更新最便宜区间前的站点编号为ID（即向左半边缩小）
    //m计算1 - ID之间的最小站点编号
    //int m = Low(id, k);
    //F计算的是1 - id之间距离
    //for (int j = m; j <= flag; j++) f += v[j];
    if (id != 1) Low(id);

    //已经保证站点1最小，开始计算1 到flag x之间的价格
    //f = v[1] + v[2] + ... + v[flag x]
    //定义下一个站点编号,flag
    //int next_flag = flag;
    //f表示1 - flag x之间的距离
    //b表示要买的油的数量
    int f = 0;
    double b = 0.0;
    for (int i = k; i < flag; i++) f += v[i];
    //cout << f << endl;

    b = (double)f / (double)d;
    b = ceil(b);
    cnt += (int)b * a[id];

    k = flag;
    return;


}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n] = 1919810;
    int l = first_low(), f = Far();
    if (l == 1){
        //路程 / 每升油走的路程 = 耗油数
        //消耗的油数 * 单价 = 总价
        cout << f / d * a[1] << endl;
        return 0;
    }

    Low(n);

    cout << cnt << endl;

    return 0;
}
