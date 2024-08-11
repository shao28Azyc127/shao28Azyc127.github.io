#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, ans = 0, ans2 = 0;
	scanf("%d", &n);
	while (n) {
		++ans;
		if (!ans2 && n % 3 == 1)
			ans2 = ans;
		//cout << n << ' ' << ans << ' ' << ans2 << "!\n";
		n -= (n - 1) / 3 + 1;
	}
	printf("%d %d\n", ans, ans2);
	return 0;
}
//喵喵喵
//我要上迷惑行为大赏！
//LUOGUID：farfar
//游记小助手：
/*
 * 进场：遇到wmt
 * 发现连着五个人都是同学，直接打ACM是吧（buff+1）
 * 学xzh摆开东西挤占旁边同学位置，然后准考证和身份证一起掉在桌子和窗台的缝里面了（如何搞崩自己的心态）（buff+1）
 * 开虚拟机，整个教室都无法启动，差评（buff+1）
 * 隔壁嗓子有点不舒服（buff+1）
 * 重启一遍VMWARE就好了
 * 电脑好卡/jk（buff+1）
 * 开题，没啥好说的，2h30min就放弃了
 * 剩下的只能整活，希望CCF能多给点分送我一个好看点的退役礼物
 * 对拍写挂了，导致拍了好久才发现一直是同一个数据（buff+1）
 * 开摆
 * 大家再见
 * */
