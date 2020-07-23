#include <iostream>
#include <windows.h>
#include"Queue.h"
#include"Stack.h"
using namespace std;
/*
  关于树的遍历笔记非递归实现 ：
  ①前序遍历，当前节点不空时，入栈，访问当前节点，当前节点指向左孩子。
             当前节点为空时，表明当前栈顶节点的左孩子遍历完成，弹栈，当前节点指向栈顶节点的又孩子。
  ②中序遍历，当前节点不空时，入栈，当前节点指向左孩子。
             当前节点为空时，表明当前栈顶节点的左孩子遍历完成，弹栈，访问当前栈顶节点，当前节点指向栈顶节点的又孩子。
  ②后序遍历，当前节点不空时，入栈，当前节点指向左孩子。
             当前节点为空时，让当前节点指向栈内的某个节点的右孩子，该某个节点要满足有右孩子，并且改右孩子没有被访问过。
             此时将某个节点再次压入栈中，当前节点指向某个节点的右孩子。


*/
template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode
{
   friend class BinaryTree<T>;
  private:
      T element; //数据成员
      BinaryTreeNode<T> *leftChild;
      BinaryTreeNode<T> *rightChild;
  public:
    BinaryTreeNode();
    BinaryTreeNode(const T &ele);
    BinaryTreeNode(const T &ele,BinaryTreeNode<T>*l,BinaryTreeNode<T>*r);
    BinaryTreeNode<T>* getLeftChild()const;
    BinaryTreeNode<T>* getRightChild()const;
    void setLeftChild(BinaryTreeNode<T>*l);
    void setRightChild(BinaryTreeNode<T>*r);
    void visit();
    T getValue() const;
    void setValue(const T & val);
    bool isLeaf()const;
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
  element=0;
  leftChild=rightChild=0;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele)
{
   element=ele;
   leftChild=rightChild=0;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele,BinaryTreeNode<T>*l,BinaryTreeNode<T>*r)
{
   element=ele;
   leftChild=l;
   rightChild=r;
};
template<class T>
BinaryTreeNode<T>*BinaryTreeNode<T>::getLeftChild()const
{
    return this->leftChild;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild()const
{
    return this->rightChild;
}


template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>*l)
{
    this->leftChild=l;
}

template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>*r)
{
    this->rightChild=r;
}
template<class T>
T BinaryTreeNode<T>::getValue() const
{
    return this->element;
}

template<class T>
void BinaryTreeNode<T>::setValue(const T & val)
{
    this->element=val;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf()const
{
    if(this->leftChild==0 && this->rightChild==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void BinaryTreeNode<T>::visit()
{
    cout<<this->element<<" ";
}


template<class T>
class BinaryTree
{
   private:
       BinaryTreeNode<T> *root;
   public:
     BinaryTree();
     ~BinaryTree();

     bool isEmpty()const;
     BinaryTreeNode<T> *getRoot()const;
     BinaryTreeNode<T> * getParent(BinaryTreeNode<T> *current)const;
     BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current)const;//返回current节点的左兄弟
     BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current)const;//返回current节点的右兄弟
     void breadthFirstOrder();//广度优先遍历以root为根节点的子树
     void preOrderTree();
     void preOrder(BinaryTreeNode<T> *root);        //先序遍历以root为根节点的子树,递归实现
     void preOrder();        //先序遍历以root为根节点的子树，非递归实现
     void inOrderTree();
     void inOrder(BinaryTreeNode<T> *root);         //中序遍历以root为根节点的子树,递归实现
     void inOrder();         //中序遍历以root为根节点的子树,非递归实现
     void postOrderTree();
     void postOrder(BinaryTreeNode<T> *root);       //后序遍历以root为根节点的子树,递归实现
     void postOrder();       //后序遍历以root为根节点的子树,非递归实现
     void levelOrder(BinaryTreeNode<T> *root);      //按层次遍历以root为根节点的子树
     void deleteBinaryTree(BinaryTreeNode<T> *root);//删除以root为根节点的子树
     void createTree();//定制的树
     BinaryTreeNode<T>* createByXian_Zhong();//先序和中序递归实现
     BinaryTreeNode<T>* createTreeByXian_Zhong(char *xian,int s1,int e1,char *zhong,int s2,int e2);//先序和中序
     BinaryTreeNode<T>* createByHou_Zhong();//先序和中序递归实现
     BinaryTreeNode<T>* createTreeByHou_Zhong(char *xian,int s1,int e1,char *zhong,int s2,int e2);//后序和中序

};
template<class T>
BinaryTree<T>::BinaryTree()
{
    root=0;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    ;
}

template<class T>
bool BinaryTree<T>::isEmpty()const
{
    if(root==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot()const
{
    return root;
}
template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getParent(BinaryTreeNode<T> *current)const//返回current节点的父节点
{
    ;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> *current)const//返回current节点的左兄弟
{
    ;
}
template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRightSibling(BinaryTreeNode<T> *current)const//返回current节点的右兄弟
{

}
template<class T>
void BinaryTree<T>::breadthFirstOrder()//广度优先遍历以root为根节点的子树
{
    Queue<BinaryTreeNode<T>* > que;
    BinaryTreeNode<T> *p=root;
    if(p)
    que.EnQueue(p);
    while(!que.IsEmpty())
    {
        que.DeQueue(p);
        p->visit();
        if(p->leftChild)
            que.EnQueue(p->leftChild);
        if(p->rightChild)
            que.EnQueue(p->rightChild);
    }
    cout<<endl;
}

//先序遍历以root为根节点的子树,递归实现

template<class T>
void BinaryTree<T>::preOrderTree()
{
    preOrder(root);
}
template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      rt->visit();
      preOrder(rt->leftChild);
      preOrder(rt->rightChild);
    }

}


//先序遍历以root为根节点的子树,非递归实现

template<class T>
void BinaryTree<T>::preOrder()
{
    //书上的代码
    /*
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(!stack1.isEmpty() || p)
    {
        if(p)
        {
           p->visit();
           if(p->rightChild)
           {
             stack1.Push(p->rightChild);
           }
          p=p->leftChild;
        }
        else
        {
          stack1.Pop(p);
        }
    }
    */
    //老师讲的

    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(p || !stack1.isEmpty())
    {
       if(p)
       {
         p->visit();
         stack1.Push(p);
         p=p->leftChild;
       }
       else
       {
        stack1.Pop(p);
        p=p->rightChild;
       }
    }


}
//中序遍历以root为根节点的子树，递归实现
template<class T>
void BinaryTree<T>::inOrderTree()
{
    inOrder(root);
}
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      inOrder(rt->leftChild);
      rt->visit();
      inOrder(rt->rightChild);
    }
}

//中序遍历以root为根节点的子树，非递归实现

template<class T>
void BinaryTree<T>::inOrder()
{
   //书上的代码
   /*
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(!stack1.isEmpty() || p)
    {
        if(p)
        {
           stack1.Push(p);
           p=p->leftChild;
        }
        else
        {
          stack1.Pop(p);
          p->visit();
          p=p->rightChild;
        }
    }
    */
    //老师讲的
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(p || !stack1.isEmpty())
    {
       if(p)
       {
         stack1.Push(p);
         p=p->leftChild;
       }
       else
       {
        stack1.Pop(p);
        p->visit();
        p=p->rightChild;
       }
    }

}


//后序遍历以root为根节点的子树，递归实现
template<class T>
void BinaryTree<T>::postOrderTree()
{
    postOrder(root);
}
template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      postOrder(rt->leftChild);
      postOrder(rt->rightChild);
      rt->visit();
    }
}


//后序遍历以root为根节点的子树，非递归实现
template<class T>
void BinaryTree<T>::postOrder()
{
    //书上的遍历方法
    /*
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    BinaryTreeNode<T> *pre=root;
    while(p)
    {
        for(;p->leftChild!=NULL;p=p->leftChild)
            stack1.Push(p);
        while(p!=NULL && (p->rightChild==NULL || p->rightChild==pre))
        {
            p->visit();
            pre=p;
            if(stack1.isEmpty())
                return;
            stack1.Pop(p);
        }

           stack1.Push(p);
           p=p->rightChild;
    }
    */
    //老师讲的遍历方法
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    BinaryTreeNode<T> *pre=0;
    BinaryTreeNode<T> *temp;
    while(p || !stack1.isEmpty())
    {
         if(p)
         {
          stack1.Push(p);
          p=p->leftChild;
         }
         else
         {

           while(!stack1.isEmpty())
           {
               stack1.Pop(temp);
               if(temp->rightChild && temp->rightChild!=pre)
               {
                  stack1.Push(temp);
                  p=temp->rightChild;
                  break;
               }
               else
               {
                 temp->visit();
                 pre=temp;
               }
           }

         }
   }

}
template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root)      //按层次遍历以root为根节点的子树
{
    ;
}
template<class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root)//删除以root为根节点的子树
{
    ;
}
template<class T>
void BinaryTree<T>::createTree()
{
       BinaryTreeNode<T> *p0,*p1,*p2;
       p0=new BinaryTreeNode<T>;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       root=p0;
       p0->setValue('A');
       p1->setValue('B');
       p0->setLeftChild(p1);
       p0->setRightChild(0);
       p0=p0->leftChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1->setValue('C');
       p2->setValue('D');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
       p0=p0->rightChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1->setValue('E');
       p2->setValue('F');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
       p0=p0->leftChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1=0;
       p2->setValue('G');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createByXian_Zhong()
{
    char xian[7]= {'A','B','C','D','E','G','F'};
    char zhong[7]={'C','B','E','G','D','F','A'};
    //cout<<"先序&中序构造二叉树"<<endl;
    root=createTreeByXian_Zhong(xian,0,6,zhong,0,6);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createTreeByXian_Zhong(char *xian,int s1,int e1,char *zhong,int s2,int e2)
{
    //cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<endl;
    BinaryTreeNode<T>* rt=new BinaryTreeNode<T>;
    rt->element=xian[s1];
    int i=s2;
    for(i=s2;i<=e2;i++)
    {
        if(zhong[i]==xian[s1])
            break;

    }
    //cout<<"i="<<i<<endl;
    int L=i-s2;
    int R=e2-i;
    //cout<<"左子树 "<<L<<endl;
    //cout<<"右子树"<<R<<endl;
    if(L>0)
    {
        rt->leftChild=createTreeByXian_Zhong(xian,s1+1,s1+L,zhong,s2,i-1);
    }
    if(R>0)
    {
        rt->rightChild=createTreeByXian_Zhong(xian,s1+L+1,e1,zhong,i+1,e2);
    }
    //cout<<"当前返回节点"<<" "<<rt->element<<endl;
    return rt;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createByHou_Zhong()
{
    char hou[7]={'C','G','E','F','D','B','A'};
    char zhong[7]={'C','B','E','G','D','F','A'};
    //cout<<"后序&中序构造二叉树"<<endl;
    root=createTreeByHou_Zhong(hou,0,6,zhong,0,6);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createTreeByHou_Zhong(char *hou,int s1,int e1,char *zhong,int s2,int e2)
{
    //cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<endl;
    BinaryTreeNode<T>* rt=new BinaryTreeNode<T>;
    rt->element=hou[e1];
    int i=s2;
    for(i=s2;i<=e2;i++)
    {
        if(zhong[i]==hou[e1])
            break;
    }
    //cout<<"i="<<i<<endl;
    int L=i-s2;
    int R=e2-i;
    //cout<<"左子树 "<<L<<endl;
    //cout<<"右子树"<<R<<endl;
    if(L>0)
    {
        rt->leftChild=createTreeByHou_Zhong(hou,s1,s1+L-1,zhong,s2,i-1);
    }
    if(R>0)
    {
        rt->rightChild=createTreeByHou_Zhong(hou,s1+L,e1-1,zhong,i+1,e2);
    }
    //cout<<"当前返回节点"<<" "<<rt->element<<endl;
    return rt;
}


int main()
{
    BinaryTree<char> a;
    char xian[7]= {'A','B','C','D','E','G','F'};
    char zhong[7]={'C','B','E','G','D','F','A'};
    char hou[7]={'C','G','E','F','D','B','A'};
    //cout<<"先序&中序构造二叉树"<<endl;
    //a.createByXian_Zhong();
    cout<<"后序&中序构造二叉树"<<endl;
    a.createByHou_Zhong();
    //a.createTree();
    cout<<"广度遍历二叉树，队列"<<endl;
    a.breadthFirstOrder();
    cout<<"先序遍历二叉树，递归实现"<<endl;
    a.preOrderTree();
    cout<<endl;
    cout<<"先序遍历二叉树，非递归实现"<<endl;
    a.preOrder();
    cout<<endl;
    cout<<"中序遍历二叉树，递归实现"<<endl;
    a.inOrderTree();
    cout<<endl;
    cout<<"中序遍历二叉树，非递归实现"<<endl;
    a.inOrder();
    cout<<endl;
    cout<<"后序遍历二叉树，递归实现"<<endl;
    a.postOrderTree();
    cout<<endl;
    cout<<"后序遍历二叉树，非递归实现"<<endl;
    a.postOrder();
    cout<<endl;
    system("pause");

    return 0;
}
