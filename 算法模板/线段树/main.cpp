#include<bits/stdc++.h>
using namespace std;

//const int MAXNODE=2097152;
const int MAX = 2e6 + 3;
const int MAXNODE = 1 << 19;

struct NODE {
    int value;//�ڵ��Ӧ�����Ȩֵ
    int left, right; //����[left,right]
} node[MAXNODE];
//�����䳤��Ϊ 0ʱ����Ӧһ����
int father[MAX];//ÿ�����Ӧ�Ľṹ�������±�


//Ϊ����[left,right]����һ��һ���� i Ϊ���ȵ��߶���
//iΪ�����±꣬��������
void BuildTree(int i, int left, int right)
{
    //д��� i ������е�������
    node[i].left = left;

    //д��� i ������е�������
    node[i].right = right;

    //ÿ�������ʼ��Ϊ 0
    node[i].value = 0 ;

    //�����䳤��Ϊ 0 ʱ�������ݹ�
    if (left == right)
    {
        father[left] = i;
        //��֪��ĳ�����Ӧ�����
        //Ϊ�˸���ʱ����������һֱ����
        return;
    }
    //�ý�������ӵķ�����������߶�����
    //�߶����Ļ����Ƕ���˼��
    //���ｫ���� (left,right)һ��Ϊ��

    BuildTree(i << 1, left, (right + left) / 2);

    //�ý�����Һ��ӵķ��򣬼��������߶���
    BuildTree(i << 1 | 1, (right + left) / 2 + 1, right);
}

//�������ϸ��£�����㱾���Ѿ��ں�������¹�
void UpdateTree(int ri)
{

    //�����߶��������Ƚ���Ӧ���±�Ϊ 1
    if (ri == 1)   return; //�����Ѿ��ҵ�������

    int fi = ri / 2; //ri�ĸ����

    int a = node[fi << 1].value; //�ø������������ӽ�� ����
    int b = node[fi << 1 | 1].value; //��

    //�����������㣬���������ӽ�����������
    node[fi].value = (a > b) ? a : b;

    //�ݹ���£��ɸ����������
    UpdateTree(ri >> 1);
}

int Max;
// i Ϊ�������
//��Ӧ�����������Χ���Ǹ����䣬һ���ʼΪ 1
void query(int i, int l, int r)
{
    //�ҵ���һ����ȫ�غϵ�����
    if (node[i].left == l && node[i].right == r)
    {
        Max = max(Max, node[i].value);
        return;
    }

    //get the left child of the tree node
    i = i << 1;

    if (l <= node[i].right) //���������漰
    {

        if (r <= node[i].right) //ȫ�����������䣬���ѯ������̬����
            query(i, l, r);

        else//������������䣬���ѯ������,��˵㲻�䣬�Ҷ˵��Ϊ���ӵ�������˵�

            query(i, l, node[i].right);
    }

    //right child of the tree
    i++;

    if (r >= node[i].left) { //���������漰
        if (l >= node[i].left) //ȫ�����������䣬���ѯ������̬����
            query(i, l, r);
        else//������������䣬���ѯ������
            query(i, node[i].left, r);
    }
}
int main()
{
    int n, m, g;
    ios::sync_with_stdio(false);//�ر���ͬ��
    while (cin >> n >> m) {
        BuildTree(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            cin >> g;
            node[father[i]].value = g;
            UpdateTree(father[i]);
        }
        string op;
        int a, b;
        while (m--) {
            cin >> op >> a >> b;
            if (op[0] == 'Q') {
                Max = 0;
                query(1, a, b);
                cout << Max << endl;
            } else {
                node[father[a]].value = b;
                UpdateTree(father[a]);
            }
        }
    }
    return 0;
}
