#include<bits/stdc++.h>
using namespace std;

//const int MAXNODE=2097152;
const int MAX = 2e6 + 3;
const int MAXNODE = 1 << 19;

struct NODE {
    int value;//节点对应区间的权值
    int left, right; //区间[left,right]
} node[MAXNODE];
//当区间长度为 0时，对应一个点
int father[MAX];//每个点对应的结构体数组下标


//为区间[left,right]建立一个一个以 i 为祖先的线段树
//i为数组下标，即结点序号
void BuildTree(int i, int left, int right)
{
    //写入第 i 个结点中的左区间
    node[i].left = left;

    //写入第 i 个结点中的右区间
    node[i].right = right;

    //每个区间初始化为 0
    node[i].value = 0 ;

    //当区间长度为 0 时，结束递归
    if (left == right)
    {
        father[left] = i;
        //能知道某个点对应的序号
        //为了更新时，从下往上一直到顶
        return;
    }
    //该结点往左孩子的方向继续建立线段树，
    //线段树的划分是二分思想
    //这里将区间 (left,right)一分为二

    BuildTree(i << 1, left, (right + left) / 2);

    //该结点往右孩子的方向，继续建立线段树
    BuildTree(i << 1 | 1, (right + left) / 2 + 1, right);
}

//从下往上更新，这个点本身已经在函数外更新过
void UpdateTree(int ri)
{

    //整个线段树的祖先结点对应的下标为 1
    if (ri == 1)   return; //向上已经找到了祖先

    int fi = ri / 2; //ri的父结点

    int a = node[fi << 1].value; //该父结点的两个孩子结点 （左）
    int b = node[fi << 1 | 1].value; //右

    //更新这个父结点，从两个孩子结点中挑个大的
    node[fi].value = (a > b) ? a : b;

    //递归更新，由父结点往上找
    UpdateTree(ri >> 1);
}

int Max;
// i 为区间序号
//对应的区间是最大范围的那个区间，一般初始为 1
void query(int i, int l, int r)
{
    //找到了一个完全重合的区间
    if (node[i].left == l && node[i].right == r)
    {
        Max = max(Max, node[i].value);
        return;
    }

    //get the left child of the tree node
    i = i << 1;

    if (l <= node[i].right) //左区间有涉及
    {

        if (r <= node[i].right) //全包含于左区间，则查询区间形态不变
            query(i, l, r);

        else//半包含于左区间，则查询区间拆分,左端点不变，右端点变为左孩子的右区间端点

            query(i, l, node[i].right);
    }

    //right child of the tree
    i++;

    if (r >= node[i].left) { //右区间有涉及
        if (l >= node[i].left) //全包含于右区间，则查询区间形态不变
            query(i, l, r);
        else//半包含于左区间，则查询区间拆分
            query(i, node[i].left, r);
    }
}
int main()
{
    int n, m, g;
    ios::sync_with_stdio(false);//关闭流同步
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
