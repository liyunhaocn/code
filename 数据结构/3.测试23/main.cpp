#include <iostream>
#include <windows.h>
#include"Queue.h"
#include"Stack.h"
using namespace std;

template<class T>
class BinarySearchTree;

template<class T>
class BinarySearchTreeNode
{
   friend class BinarySearchTree<T>;
  private:
      T element; //数据成员
      BinarySearchTreeNode<T> *leftChild;
      BinarySearchTreeNode<T> *rightChild;
  public:
    BinarySearchTreeNode();
    BinarySearchTreeNode(const T &ele);
    BinarySearchTreeNode(const T &ele,BinarySearchTreeNode<T>*l,BinarySearchTreeNode<T>*r);
    BinarySearchTreeNode<T>* getLeftChild()const;
    BinarySearchTreeNode<T>* getRightChild()const;
    void setLeftChild(BinarySearchTreeNode<T>*l);
    void setRightChild(BinarySearchTreeNode<T>*r);
    void visit();
    T getValue() const;
    void setValue(const T & val);
    bool isLeaf()const;
};

template<class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode()
{
  element=0;
  leftChild=rightChild=0;
}
template<class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T &ele)
{
   element=ele;
   leftChild=rightChild=0;
}

template<class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T &ele,BinarySearchTreeNode<T>*l,BinarySearchTreeNode<T>*r)
{
   element=ele;
   leftChild=l;
   rightChild=r;
};

template<class T>
BinarySearchTreeNode<T>*BinarySearchTreeNode<T>::getLeftChild()const
{
    return this->leftChild;
}

template<class T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::getRightChild()const
{
    return this->rightChild;
}


template<class T>
void BinarySearchTreeNode<T>::setLeftChild(BinarySearchTreeNode<T>*l)
{
    this->leftChild=l;
}

template<class T>
void BinarySearchTreeNode<T>::setRightChild(BinarySearchTreeNode<T>*r)
{
    this->rightChild=r;
}
template<class T>
T BinarySearchTreeNode<T>::getValue() const
{
    return this->element;
}

template<class T>
void BinarySearchTreeNode<T>::setValue(const T & val)
{
    this->element=val;
}

template<class T>
bool BinarySearchTreeNode<T>::isLeaf()const
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
void BinarySearchTreeNode<T>::visit()
{
    cout<<this->element<<" ";
}


template<class T>
class BinarySearchTree
{
   private:
       BinarySearchTreeNode<T> *root;
   public:
     BinarySearchTree();
     ~BinarySearchTree();
     BinarySearchTreeNode<T> *getRoot()const;
     bool isEmpty()const;
     bool isLeaf(BinarySearchTreeNode<T> *rt);
     int getBig_k(int k);//大于K的节点个数
     bool isSearchTree();//是否为二叉搜索树
     bool Find(T value);//搜索树的查找
     bool Insert(T value);//搜索树的插入
     bool Delete(T value);//搜索树的删除
     bool comDelete(T value);//搜索树的删除

};
template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root=0;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    ;
}

template<class T>
bool BinarySearchTree<T>::isEmpty()const
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
BinarySearchTreeNode<T> *BinarySearchTree<T>::getRoot()const
{
    return root;
}

template<class T>
bool BinarySearchTree<T>::Find(T value)//搜索树的查找
{
       BinarySearchTreeNode<T> *p=root;
       while(p)
       {
           if(p->element==value)
           {

               return true;
           }
           else if(p->element>value)
           {
             p=p->leftChild;
           }
           else
           {
               p=p->rightChild;
           }
       }

}

template<class T>
bool BinarySearchTree<T>::Insert(T value)//搜索树的插入
{
    BinarySearchTreeNode<T> *p=root;
    BinarySearchTreeNode<T> *pre=0;
    if(root==0)
    {
        p=new BinarySearchTreeNode<T>;
        p->element=value;
        root=p;
        return true;
    }
    else
    {
       while(p)
       {
           if(p->element==value)
           {
               cout<<value<<" "<<"节点已经在树中"<<endl;
               return false;
           }
           else if(p->element>value)
           {
             pre=p;
             p=p->leftChild;
           }
           else
           {
               pre=p;
               p=p->rightChild;
           }
       }
       if(value>pre->element)
       {
           p=new BinarySearchTreeNode<T>;
           p->element=value;
           pre->rightChild=p;

       }
       else
       {
           p=new BinarySearchTreeNode<T>;
           p->element=value;
           pre->leftChild=p;

       }
    return true;
  }
}
template<class T>
bool BinarySearchTree<T>::Delete(T value)//搜索树的删除
{
    BinarySearchTreeNode<T> *p=root;
    BinarySearchTreeNode<T> *pre=0;
    while(p)
    {
        if(p->element==value)
        {
           break;
        }
        else if(p->element>value)
        {
            pre=p;
            p=p->leftChild;
        }
        else
        {
            pre=p;
            p=p->rightChild;
        }
    }
    if(p==NULL)
    {
        cout<<"该节点不在树中，删除失败"<<endl;
        return false;
    }
    if(isLeaf(p))
    {

       if(p==root)
       {
           root->leftChild=0;
           root->rightChild=0;
           delete root;
           root=0;
       }
       else
       {
         if(p->element>pre->element)
           pre->rightChild=0;
         else
           pre->leftChild=0;
            delete p;
       }
     }
     else if(p->leftChild && !p->rightChild)
     {
         if(p==root)
         {
             root=p->leftChild;
         }
        else if(p->element<pre->element)
          pre->leftChild=p->leftChild;
        else
          pre->rightChild=p->leftChild;
        delete p;
     }
     else if(p->rightChild && !p->leftChild)
     {
          if(p==root)
         {
             root=p->rightChild;
         }

        else if(p->element<pre->element)
          pre->leftChild=p->rightChild;
        else
          pre->rightChild=p->rightChild;
        delete p;
     }
     else
     {
         pre=p;
         BinarySearchTreeNode<T> *pp;
         p=p->leftChild;
         while(p->rightChild)
         {
             pp=p;
             p=p->rightChild;
         }
         pre->element=p->element;
          if(isLeaf(p))
          {
           if(p->element>pp->element)
            pp->rightChild=0;
          else
            pp->leftChild=0;
            delete p;
          }
         else if(p->leftChild)
         {
           if(p->element<pp->element)
            pp->leftChild=p->leftChild;
           else
           pp->rightChild=p->leftChild;
          delete p;
        }
     }
}

template<class T>
bool BinarySearchTree<T>::comDelete(T value)
{
    BinarySearchTreeNode<T> *p=root;
    BinarySearchTreeNode<T> *pre=0;
    while(p)
    {
        if(p->element==value)
        {
           break;
        }
        else if(p->element>value)
        {
            pre=p;
            p=p->leftChild;
        }
        else
        {
            pre=p;
            p=p->rightChild;
        }
    }
    if(p->leftChild && p->rightChild)
    {
        BinarySearchTreeNode<T> *pp;
            pp=p->leftChild;
          while(pp->rightChild)
            pp=pp->rightChild;

          pp->rightChild=p->rightChild;
          p->rightChild=0;
         if(p!=root)
         {
             if(p->element < pre->element)
            {
            cout<<"111"<<endl;
            pre->leftChild=p->leftChild;
           }
        else
          {
            cout<<"111"<<endl;
            pre->rightChild=p->leftChild;
          }

        }
        else
        {
            root=p->leftChild;
        }

          delete p;
    }
    else
    {
        Delete(p->element);
    }

}

template<class T>
bool BinarySearchTree<T>::isLeaf(BinarySearchTreeNode<T> *rt)
{
    if(!rt->leftChild && !rt->rightChild)
        return true;
    else
        return false;
}
template<class T>
int BinarySearchTree<T>::getBig_k(int k)//大于K
{
    int counter=0;
    Queue<BinarySearchTreeNode<T>* > que;
    BinarySearchTreeNode<T> *p=root;
    if(p)
    que.EnQueue(p);
    while(!que.IsEmpty())
    {
        que.DeQueue(p);
        if(p->element>k)counter++;
        if(p->leftChild)
            que.EnQueue(p->leftChild);
        if(p->rightChild)
            que.EnQueue(p->rightChild);
    }
    return counter;
}
template<class T>
bool BinarySearchTree<T>::isSearchTree()//是否为二叉搜索树
{
    ArrayStack< BinarySearchTreeNode<T>* > stack1;
    BinarySearchTreeNode<T>*p=root;
    T ele[20];
    int i=0;
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
        ele[i]=p->element;
        i++;
        p=p->rightChild;
       }
    }
    for(int j=0;j<i;j++)
    {
        if(ele[i]>ele[i+1])
            return false;
    }
    return true;
}
int main()
{
    BinarySearchTree<int> a;
    for(int i=0;i<10;i++)
    {
        a.Insert(i);
    }
    for(int i=-10;i<0;i++)
    {
        a.Insert(i);
    }
    cout<<"大于K的节点个数"<<endl;
    cout<<a.getBig_k(5)<<endl;
    if(a.isSearchTree())
    cout<<"是二叉搜索树"<<endl;
    else
    cout<<"不是是二叉搜索树"<<endl;

    system("pause");
    return 0;
}
