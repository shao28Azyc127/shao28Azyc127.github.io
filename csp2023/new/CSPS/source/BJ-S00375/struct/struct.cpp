//������ģ��......

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define int long long
using namespace std;

int n;
int usedpos; //���������ֽ�
int strnum, elenum; //���ṹ��͸�Ԫ�صĸ���
int st[110], en[110]; //�洢��i����Ԫ�ص���ʼ�ͽ�����ȷλ��
string eletype[110]; //�洢��i����Ԫ������ʲô����
//-1Ϊbyte��-2Ϊshort��-4Ϊint��-8Ϊlong
int strsize[110]; //�洢��i�����ṹ���ȷ�д�С
string strname[110]; //�洢��i�����ṹ�������
string elename[110]; //�洢��i����Ԫ�ص�����
int childnum[110]; //���i���������ǽṹ�壬��ô���ж��ٸ�������

string innername[110][110]; //��i�����ṹ�����͵ĵ�j��Ԫ������
string innertype[110][110]; //��i�����ṹ�����͵ĵ�j��Ԫ������
int innerst[110][110]; //��i�����ṹ�����͵ĵ�j��Ԫ���ڸ���������
int inneren[110][110]; //��i�����ṹ�����͵ĵ�j��Ԫ���ڸ�������յ�
 
int type2size(string type)
{
    if(type=="byte") return 1;
    if(type=="short") return 2;
    if(type=="int") return 4;
    if(type=="long") return 8;

    for(int i = 1; i <= strnum; i++)
    {
        if(type == strname[i]) return strsize[i];
    }
    return -1;
}

int up24(int pos)
{
    if(pos % 4 == 0) return pos;
    return (pos / 4 + 1) * 4;
}

bool is_basic(string t)
{
    if(t=="short") return true;
    if(t=="byte") return true;
    if(t=="long") return true;
    if(t=="int") return true;
    return false;
}

int type2id(string t)
{
    for(int i = 1; i <= strnum; i++)
    {
        if(t == strname[i]) return i;
    }
    return -1;
}

void find_addr(int tar, int l, string t, string na, string bui)
{
    if(is_basic(t))
    {
        if(l + type2size(t) - 1 < tar)
        {
            printf("ERR\n");
        }
        else
        {
            cout<< bui + '.' + na <<endl;
        }
    }
    else //�����λ����Ѱ�����λ��ǡ��Ϊtar��  
    {
        int aaa = type2id(t);
        int L = 1, r = childnum[aaa], nt = tar - l;
        int key;
        bool f = false;
           while(L<r)
           {
               int m = (L+r) / 2; //�м��Ԫ��
               if(innerst[aaa][m] <= nt && inneren[aaa][m] >= nt)
               {
                   key = m;
                    f = true;
                   break;
               }
              else if(innerst[aaa][m] > nt)
               {
                   r = m-1;
               }
               else
               {
                L = m+1;
               }
          }
        if(f) L = key;
        find_addr(tar, innerst[aaa][L] + l, innertype[aaa][L], innername[aaa][L], bui + '.' + innername[aaa][L]);
    }
}

signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
    {
        int op;
        scanf("%lld",&op);
        if(op == 1) //����һ���ṹ��
        {
            strnum++;

            string sname;
            int k; //��Ա����
            cin >> sname;
            strname[strnum] = sname;
            scanf("%lld",&k);
            childnum[strnum] = k;
            int calc = 0, nowpos = 0;
            // st[strnum] = up24(usedpos+1);
            for(int j = 1; j <= k; j++) //��j����Ա
            {
                string Memname, Memtype;
                cin >> Memtype >> Memname;
                innername[strnum][j] = Memname;
                innertype[strnum][j] = Memtype;
                int csize = type2size(Memtype);
                nowpos = up24(nowpos);
                innerst[strnum][j] = nowpos;
                inneren[strnum][j] = nowpos + csize - 1;
                nowpos += csize;
            }
            // en[strnum] = nowpos - 1;
            strsize[strnum] = inneren[strnum][childnum[strnum]] + 1;
            // printf("�ɹ������ṹ�壬�������£�\n");
            // cout<<"���ƣ�"<<strname[strnum]<<"��С��"<<strsize[strnum]<<"��Ա����:"<<childnum[strnum]<<endl;
            // printf("��Ա���£�\n");
            // for(int j = 1; j <= childnum[strnum]; j++)
            // {
            //     cout<<"-���ͣ�"<<innertype[strnum][j]<<" ���ƣ�"<<innername[strnum][j]<<",";
            //     printf("�ڽṹ���е����λ��:%lld~~%lld\n",innerst[strnum][j],inneren[strnum][j]);
            // }
        }

        else if(op == 2) //����һ��Ԫ��
        {
            elenum++;

            string Elename, Eletype;
            cin >> Elename >> Eletype;
            elename[elenum] = Elename;
            st[elenum] = up24(usedpos+1); //Ԫ����ʼλ��
            en[elenum] = st[elenum] + type2size(Eletype) - 1;
            usedpos = en[elenum];
        }
        else if(op == 3) //��ѯԪ��λ��
        {

        }
        else //���ҵ�ַ��Ӧ��Ԫ��
        {
            int addr;
            scanf("%lld",&addr);
            int l = 1, r = elenum, key;
            bool  f = false;
            while(l<r)
            {
                int m = (l+r) / 2; //�м��Ԫ��
                if(st[m] <= addr && en[m] >= addr)
                {
                    key = m;
                    f = true;
                    break;
                }
                else if(st[m] > addr)
                {
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            if(f) l = key;
            // printf("���ҽ��Ϊ:%lld\n",l);
            //mΪ�±��Ӧ�ĸ�Ԫ�ص�λ��
            find_addr(addr, st[l], eletype[l], elename[l], elename[l]);
        }
    }
    return 0;
}