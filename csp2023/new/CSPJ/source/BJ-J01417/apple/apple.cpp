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
//������
//��Ҫ���Ի���Ϊ���ͣ�
//LUOGUID��farfar
//�μ�С���֣�
/*
 * ����������wmt
 * ������������˶���ͬѧ��ֱ�Ӵ�ACM�ǰɣ�buff+1��
 * ѧxzh�ڿ�������ռ�Ա�ͬѧλ�ã�Ȼ��׼��֤�����֤һ��������Ӻʹ�̨�ķ������ˣ���θ���Լ�����̬����buff+1��
 * ����������������Ҷ��޷�������������buff+1��
 * ����ɤ���е㲻�����buff+1��
 * ����һ��VMWARE�ͺ���
 * ���Ժÿ�/jk��buff+1��
 * ���⣬ûɶ��˵�ģ�2h30min�ͷ�����
 * ʣ�µ�ֻ�����ϣ��CCF�ܶ���������һ���ÿ������������
 * ����д���ˣ��������˺þòŷ���һֱ��ͬһ�����ݣ�buff+1��
 * ����
 * ����ټ�
 * */
