/*
Brain gonna explode.
11:00

Fu Su Ren Bu Zai (written by dongqiudi)

Zhe yi lu shang jin jin tui tui,
shi nian kan ke guo he xie wu yan
man man yue guo shu dao tian xian
ting feng qi ai tan.
xin xian kai tong bai xing xiao yan
sheng shi zai yan qian
fu xing ke jiao ao,
gao su li shi jian,
feng chui qi le cong qian:
cong qian jing hu chong gao chu,
yi ran ru gu,
zao zhuang yuan qu zhong dao beng bu,
ben wu tian cheng, ming ling ti su,
chong kai mi wu......
ru jin chu shi ren jian ku,
jiang biao jiang su,
qian xing wu wang yuan di ta bu,
gao tie zhi ming hao jiao you shei ren du?
wo ceng bei shang jing nan,
dong dao hu hang,
xi yue miao dong,
nan xia wu guang,
quan li qian xing,
er san nian guo,
jiang su nan tao.
bu wei bai nian ji jiang biao he fang?
xi cheng si shi hui fu wu wang,
jing nan yi qu san bai wu miao mang.
ren sheng ru xi jiang na sui yue wang.

Zhe yi lu shang jin jin tui tui,
shi nian kan ke guo he xie wu yan
man man yue guo shu dao tian xian
ting feng qi ai tan.
xin xian kai tong bai xing xiao yan
fei long zai yan qian
fu xing ke jiao ao,
gao su li shi jian,
feng chui qi le cong qian:
cong qian chu jian zhe jiang shan,
wan ban ai lian,
ri fu yi ri ti su shi yan,
ye meng xiang yi ri zhi zhong zou bian zhe shi jian,
ru jin dan jian xi yang can,
yi mu xi jian,
shen hou bai li lu jing zai qian,
ming xing sui gai, xin reng yuan fu dang nian.
Chang ke neng shang gao han ru hei long jiang,
hu han rong shang ban wu chang jiang.
fu xing yun ying er san nian guo,
fu biao wu wang.
bai nian guo hou man su que wu fang,
xi ri hui huang jin ri wei sang,
xu zhou yi ye jian da su huo you wang.

Qi yue sheng xia jing nan zhan wai xie yang,
liu shi wang fan ti su xian shang.
jiang shan ru hua, wang ri you zai, bu jian ren kuang.
mu se zhe bu zhu ni hui gui de bu fa,
wan jiu jiang su si hui de hua,
hua zhong de ni,
dian gong huo hua kuang......
wo ceng bei shang jing nan,
dong dao hu hang,
xi yue miao dong,
nan xia wu guang,
quan li qian xing,
er san nian guo,
jiang su nan tao.
liu nian hou zai lai fu su he fang?
fu su sui you, fu biao wu wang.
jing nan yi qu dong ji chang lai wang.
ren sheng ru xi jiang na sui yue wang!

Zhi wo men shi er fu de de 350 km/h.
*/
#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, a[500010], b[500010], x[500010], y[500010];
int mikan()
{
    if (a[1] == b[1]) return 0;
    bool f1 = (a[1] > b[1]);
    bool f2 = (a[n] > b[m]);
    int mina = 2e9, minb = 2e9, maxa = 0, maxb = 0;
    for (int i = 1; i <= n; i++) mina = min(mina, a[i]);
    for (int i = 1; i <= m; i++) minb = min(minb, b[i]);
    if (f1 + f2 == 1) return 0;
    if (f1 == 1 && mina < minb) return 0;
    if (f1 == 0 && mina > minb) return 0;
    if (f1 == 1 && maxb > maxa) return 0;
    if (f1 == 0 && maxa > maxb) return 0;
    return 1;
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], x[i] = a[i];
    for (int i = 1; i <= m; i++) cin >> b[i], y[i] = b[i];
    cout << mikan();
    for (int i = 1, ka, kb, j, v; i <= q; i++)
    {
        for (int j = 1; j <= n; j++) a[i] = x[i];
        for (int j = 1; j <= m; j++) b[i] = y[i];
        cin >> ka >> kb;
        while (ka--)
        {
            cin >> j >> v;
            a[j] = v;
        }
        while (kb--)
        {
            cin >> j >> v;
            b[j] = v;
        }
        cout << mikan();
    }
    return 0;
}
