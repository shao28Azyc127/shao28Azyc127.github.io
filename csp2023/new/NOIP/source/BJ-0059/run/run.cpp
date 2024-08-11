/*
退役了（悲
C 只会暴力 n^2m 的 25 分
D 只会暴力 m^2 的 44 分
不挂分的话加起来勉强超过 250……
1= 可能有点悬了（难过
不管了先写。能拿多少是多少吧。
我超！！！精细算了一下能拿的部分分好像有 76pts，再加上 C 的 25pts 真的可以到 301pts>300，赢！！！
我还有 2.5h，加油！！！
好吧还是吐槽一下，cxy 你怎么只会两道啊，逊色。
直观感觉这题应该是四边形不等式优化 dp，但是我没学。遗憾离场。

开心一点 cxy，至少你还认识过她，她还愿意和你成为朋友，这就已经足够了好吧，别想太多！！！
而且你考完了就能去和 caca 贴贴，想想你认识了一位未来 BJ E 队队长，这难道不是很棒吗！！！
至于 NOIp……考的不好就不好啦，反正首先你 BJOI2024 还可以翻盘，其次就算明年没进省队你仍然还有三年啊！！！

你要学会自信！！！
就比如说你虽然考的很烂，但你比其他人都可爱！！！（确信
以及就算你发现你最后什么都成为不了，考虑到专业对口，你还可以去哥谭当小丑！！！
凭借你出色的乐子属性以及什么也成功不了的 debuff，你一定会成为最好的小丑的！！！（确信
或者根据你妹妹对你的评价，你还可以去动物园成为大猴子！！！
反正这张图上，没有哪个点出度是为 0 的。只要你愿意，总还是能找到一条出路的。
不要太悲观啦 cxy

你看甚至还有那么多人看国足呢，你又怕什么呀。前几天逆转泰国，大家不都笑的挺开心的吗，成为不了最好的，将就着活着也不是不行啦

好耶，刚才去写了 C，发现我其实有 35pts，现在还剩 1.5h，cxy 你要加油啊！！！只用把目前写的调出来你就已经 303pts 了！！！再写个 B 性质就 311 了！！！

qnmd为什么就是过不了样例 2 啊。

好好好删了离散化是有 36 分的，目前总分是 271，已经比刚开题时的预期高了，加油！！！

孩子你离散化写错了…… lowerbound 那里长度就已经是 t 了……现在应该是 303pts 了，比初一时高了 3pts了，很有水平，加油！

出了点锅导致样例 4 没过……还有 0.5h，你能调出来的啊 cxy！！！

好好好数组开小了+没有初始化，你真的是天才啊 cxy
没事了，现在已经有 303pts 了，你已经很棒了！剩下 0.5h 争取把性质 B 写了！

好吧。分算错了。其实是 299pts。但是还剩 0.5h！看起来 B 只需要单调队列优化就行了！加油，你可以写出来的！

过性质 B 了！！！现在是 307pts！！！比上两次高了 7pts！！！赢！！！
*/
#include<stdio.h>
#include<algorithm>
typedef long long ll;
struct{
	ll l,r,w;
}a[100001];
ll p[200001],f[200001],g[200001],w[200001];
inline ll max(ll a,ll b){return a>b?a:b;}
void work(){
	int m,k;ll n,d;
	scanf("%lld%d%d%lld",&n,&m,&k,&d);
	for(int i=1;i<=m;++i)scanf("%lld%lld%lld",&a[i].r,&a[i].l,&a[i].w),a[i].l=a[i].r-a[i].l,p[(i-1)*2+1]=a[i].l,p[(i-1)*2+2]=a[i].r;
	std::sort(p,p+2*m+1);int t=std::unique(p,p+2*m+1)-p-1;
	for(int i=1;i<=m;++i)a[i].l=std::lower_bound(p,p+t+1,a[i].l)-p,a[i].r=std::lower_bound(p,p+t+1,a[i].r)-p;
	std::sort(a+1,a+m+1,[](const auto&u,const auto&v){return u.r<v.r;});
	for(int i=0;i<=t;++i)w[i]=0;
	for(int i=1,lst=1;i<=t;++i){
		g[i]=max(g[i-1],f[i-1]);
		for(;lst<=m&&a[lst].r<=i;++lst)w[a[lst].l]+=a[lst].w;
		ll s=0;f[i]=0;
		for(int j=i-1;j>=0&&p[j]+k>=p[i];--j)
			s+=w[j],f[i]=max(f[i],s-(p[i]-p[j])*d+g[j]);
	}
	printf("%lld\n",max(f[t],g[t]));
}
int q[100001];ll s[100001];
ll calc(int i,int j,ll d){
	return g[j]+(s[i]-s[j])-(a[i].r-a[j+1].l)*d;
}
void workb(){
	int m,k;ll n,d;
	scanf("%lld%d%d%lld",&n,&m,&k,&d);
	for(int i=1;i<=m;++i)scanf("%lld%lld%lld",&a[i].r,&a[i].l,&a[i].w),a[i].l=a[i].r-a[i].l,s[i]=s[i-1]+a[i].w;
	int l=0,r=0;q[r++]=0;
	for(int i=1;i<=m;++i){
		for(;l<r&&a[q[l]].l+k<a[i].r;++l);
		f[i]=l<r?calc(i,q[l],d):0,g[i]=max(g[i-1],f[i]);
		for(;l<r&&calc(i,q[r-1],d)<calc(i,i,d);--r);
		q[r++]=i;
	}
	printf("%lld\n",max(f[m],g[m]));
}
int main(){
	freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c<=16){
		for(;t--;work());
	}else{
		for(;t--;workb());
	}
	return 0;
}