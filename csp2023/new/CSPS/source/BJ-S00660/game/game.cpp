//���汣�ӣ�����
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<char>q;
LL n;
string s;
LL cnt;
//���߰���Ķ���
int main(){
    //��ֵ�С����2���⿴���ݴ�Լ50��
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s; // ���������ͻأ
    //ͨ�����ַ���ÿһ���ַ����ν���ջ����ջ���ˣ�
    //��Ϊ������ȫ�������ִ���ͬʱcnt++
    //������ջ˳�򣬴ӵ�i��Ԫ�ؿ�ʼ��������ջ
    //int T = 0;
    for(LL T = 0; T < n-1; T++)
    {
        //if((n-T) % 2 != 0) continue; 
        // ��֦������ʧ��
        q.push(s[T]);
        for(LL i = T+1; i < s.size(); i++)
        {
            //�жϼ�����ջԪ���ܲ����붥��Ԫ������
            if(q.empty()) 
            {
                //cnt++;
                q.push(s[i]);
                continue;
            }
            if(s[i] == q.top())
            {
                q.pop();
                //��ջ��Ԫ��pop��ȥ
                if(q.empty())
                {
                    //�ж��Ƿ�empty,��ʵ�ڵ�20���ж�Ҳ����
                    cnt++;
                }
            }
            else q.push(s[i]);
        }
        while(!q.empty())
        {
            q.pop();
            //�����п����Ԫ�س�ȥ���ʼ��������˰���-_-|��
        }
    }
    cout << cnt << endl;//������
    return 0;//��ϰ��
}