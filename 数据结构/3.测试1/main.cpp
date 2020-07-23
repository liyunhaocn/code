#include <iostream>
#include <windows.h>
#include"Queue.h"
#include"Stack.h"
using namespace std;
/*
  �������ı����ʼǷǵݹ�ʵ�� ��
  ��ǰ���������ǰ�ڵ㲻��ʱ����ջ�����ʵ�ǰ�ڵ㣬��ǰ�ڵ�ָ�����ӡ�
             ��ǰ�ڵ�Ϊ��ʱ��������ǰջ���ڵ�����ӱ�����ɣ���ջ����ǰ�ڵ�ָ��ջ���ڵ���ֺ��ӡ�
  �������������ǰ�ڵ㲻��ʱ����ջ����ǰ�ڵ�ָ�����ӡ�
             ��ǰ�ڵ�Ϊ��ʱ��������ǰջ���ڵ�����ӱ�����ɣ���ջ�����ʵ�ǰջ���ڵ㣬��ǰ�ڵ�ָ��ջ���ڵ���ֺ��ӡ�
  �ں����������ǰ�ڵ㲻��ʱ����ջ����ǰ�ڵ�ָ�����ӡ�
             ��ǰ�ڵ�Ϊ��ʱ���õ�ǰ�ڵ�ָ��ջ�ڵ�ĳ���ڵ���Һ��ӣ���ĳ���ڵ�Ҫ�������Һ��ӣ����Ҹ��Һ���û�б����ʹ���
             ��ʱ��ĳ���ڵ��ٴ�ѹ��ջ�У���ǰ�ڵ�ָ��ĳ���ڵ���Һ��ӡ�


*/
template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode
{
   friend class BinaryTree<T>;
  private:
      T element; //���ݳ�Ա
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
     BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current)const;//����current�ڵ�����ֵ�
     BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current)const;//����current�ڵ�����ֵ�
     void breadthFirstOrder();//������ȱ�����rootΪ���ڵ������
     void preOrderTree();
     void preOrder(BinaryTreeNode<T> *root);        //���������rootΪ���ڵ������,�ݹ�ʵ��
     void preOrder();        //���������rootΪ���ڵ���������ǵݹ�ʵ��
     void inOrderTree();
     void inOrder(BinaryTreeNode<T> *root);         //���������rootΪ���ڵ������,�ݹ�ʵ��
     void inOrder();         //���������rootΪ���ڵ������,�ǵݹ�ʵ��
     void postOrderTree();
     void postOrder(BinaryTreeNode<T> *root);       //���������rootΪ���ڵ������,�ݹ�ʵ��
     void postOrder();       //���������rootΪ���ڵ������,�ǵݹ�ʵ��
     void levelOrder(BinaryTreeNode<T> *root);      //����α�����rootΪ���ڵ������
     void deleteBinaryTree(BinaryTreeNode<T> *root);//ɾ����rootΪ���ڵ������
     void createTree();//���Ƶ���
     void createByXian_Zhong(T *xian,int s1,int e1,T *zhong,int s2,int e2);//���������ݹ�ʵ��
     BinaryTreeNode<T>* createTreeByXian_Zhong(T *xian,int s1,int e1,T *zhong,int s2,int e2);//���������
     void createByHou_Zhong(T *hou,int s1,int e1,T *zhong,int s2,int e2);//���������ݹ�ʵ��
     BinaryTreeNode<T>* createTreeByHou_Zhong(T *hou,int s1,int e1,T *zhong,int s2,int e2);//���������
     int oneChildNodeCounter();////ͳ�ƶ�Ϊһ�Ľڵ����,�ݹ����
     int oneChildNodeCounter(BinaryTreeNode<T> *rt);  //ͳ�ƶ�Ϊһ�Ľڵ����
     int twoChildNodeCounter();////ͳ�ƶ�Ϊ���Ľڵ����,�ݹ����
     int twoChildNodeCounter(BinaryTreeNode<T> *rt);  //ͳ�ƶ�Ϊ���Ľڵ����
     int noneChildNodeCounter();//ͳ�ƶ�Ϊ��Ľڵ����,�ݹ����
     int noneChildNodeCounter(BinaryTreeNode<T> *rt);  //ͳ�ƶ�Ϊ��Ľڵ����
     int heightCounter();////ͳ�Ƹ߶�,�ݹ����
     int heightCounter(BinaryTreeNode<T> *rt);  //ͳ�Ƹ߶�
     T GetMaxmember();  //�������Ԫ��
     T GetMaxmember(BinaryTreeNode<T> * rt);
     void changeChild();//�������ӣ��ݹ����
     void changeChild(BinaryTreeNode<T> * rt);
     void deleteLeave();//�������ӣ��ݹ����
     void deleteLeave(BinaryTreeNode<T> * rt);
     bool isCompleteTree();//�Ƿ�Ϊ��ȫ���������ݹ����
     bool isCompleteTree(BinaryTreeNode<T> * rt);
     void CountLine(BinaryTreeNode<T>* str,int* ptr,int i);//��һ�п��
     int FindMaxLine();//�õ����Ŀ��
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
BinaryTreeNode<T> * BinaryTree<T>::getParent(BinaryTreeNode<T> *current)const//����current�ڵ�ĸ��ڵ�
{
    ;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> *current)const//����current�ڵ�����ֵ�
{
    ;
}
template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRightSibling(BinaryTreeNode<T> *current)const//����current�ڵ�����ֵ�
{

}
template<class T>
void BinaryTree<T>::breadthFirstOrder()//������ȱ�����rootΪ���ڵ������
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

//���������rootΪ���ڵ������,�ݹ�ʵ��

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


//���������rootΪ���ڵ������,�ǵݹ�ʵ��

template<class T>
void BinaryTree<T>::preOrder()
{
    //���ϵĴ���
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
    //��ʦ����

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
//���������rootΪ���ڵ���������ݹ�ʵ��
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

//���������rootΪ���ڵ���������ǵݹ�ʵ��

template<class T>
void BinaryTree<T>::inOrder()
{
   //���ϵĴ���
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
    //��ʦ����
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


//���������rootΪ���ڵ���������ݹ�ʵ��
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


//���������rootΪ���ڵ���������ǵݹ�ʵ��
template<class T>
void BinaryTree<T>::postOrder()
{
    //���ϵı�������
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
    //��ʦ���ı�������
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
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root)      //����α�����rootΪ���ڵ������
{
    ;
}
template<class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root)//ɾ����rootΪ���ڵ������
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
void BinaryTree<T>::createByXian_Zhong(T *xian,int s1,int e1,T *zhong,int s2,int e2)
{

    cout<<"����&�����������"<<endl;
    root=createTreeByXian_Zhong(xian, s1,e1,zhong,s2,e2);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createTreeByXian_Zhong(T *xian,int s1,int e1,T *zhong,int s2,int e2)
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
    //cout<<"������ "<<L<<endl;
    //cout<<"������"<<R<<endl;
    if(L>0)
    {
        rt->leftChild=createTreeByXian_Zhong(xian,s1+1,s1+L,zhong,s2,i-1);
    }
    if(R>0)
    {
        rt->rightChild=createTreeByXian_Zhong(xian,s1+L+1,e1,zhong,i+1,e2);
    }
    //cout<<"��ǰ���ؽڵ�"<<" "<<rt->element<<endl;
    return rt;
}

template<class T>
void BinaryTree<T>::createByHou_Zhong(T *hou,int s1,int e1,T *zhong,int s2,int e2)
{

    cout<<"����&�����������"<<endl;
    root=createTreeByHou_Zhong(hou,s1,e1,zhong,s2,e2);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::createTreeByHou_Zhong(T *hou,int s1,int e1,T *zhong,int s2,int e2)
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
    //cout<<"������ "<<L<<endl;
    //cout<<"������"<<R<<endl;
    if(L>0)
    {
        rt->leftChild=createTreeByHou_Zhong(hou,s1,s1+L-1,zhong,s2,i-1);
    }
    if(R>0)
    {
        rt->rightChild=createTreeByHou_Zhong(hou,s1+L,e1-1,zhong,i+1,e2);
    }
    //cout<<"��ǰ���ؽڵ�"<<" "<<rt->element<<endl;
    return rt;
}

template<class T>
int BinaryTree<T>::oneChildNodeCounter()//ͳ�ƶ�Ϊһ�Ľڵ����,�ݹ����
{
    return oneChildNodeCounter(root);
}
template<class T>
int BinaryTree<T>::oneChildNodeCounter(BinaryTreeNode<T> *rt)  //ͳ�ƶ�Ϊһ�Ľڵ����
{
    if(!rt)    //���ڵ�Ϊ��
        return 0;
    else if (rt->leftChild == NULL && rt->rightChild==NULL)//ֻ�и��ڵ�
        return 0;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
        return 1+oneChildNodeCounter(rt->leftChild);
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
        return 1 + oneChildNodeCounter(rt->rightChild);
    else if (rt->leftChild != NULL && rt->rightChild != NULL)//���Һ��Ӷ���
        return  oneChildNodeCounter(rt->leftChild) + oneChildNodeCounter(rt->rightChild);
}

template<class T>
int BinaryTree<T>::twoChildNodeCounter()//ͳ�ƶ�Ϊһ�Ľڵ����,�ݹ����
{
    return twoChildNodeCounter(root);
}
template<class T>
int BinaryTree<T>::twoChildNodeCounter(BinaryTreeNode<T> *rt)  //ͳ�ƶ�Ϊ���Ľڵ����
{
    if(!rt)    //���ڵ�Ϊ��
        return 0;
    else if (rt->leftChild == NULL && rt->rightChild==NULL)//ֻ�и��ڵ�
        return 0;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
        return twoChildNodeCounter(rt->leftChild);
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
        return twoChildNodeCounter(rt->rightChild);
    else if (rt->leftChild != NULL && rt->rightChild!= NULL)//���Һ��Ӷ���
        return 1+twoChildNodeCounter(rt->leftChild) + twoChildNodeCounter(rt->rightChild);
}

template<class T>
int BinaryTree<T>::noneChildNodeCounter()//ͳ�ƶ�Ϊ��Ľڵ����,�ݹ����
{
    return noneChildNodeCounter(root);
}
template<class T>
int BinaryTree<T>::noneChildNodeCounter(BinaryTreeNode<T> *rt)  //ͳ�ƶ�Ϊһ�Ľڵ����
{
    if(!rt)    //���ڵ�Ϊ��
        return 0;
    else if (rt->leftChild == NULL && rt->rightChild==NULL)//ֻ�и��ڵ�
        return 1;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
        return noneChildNodeCounter(rt->leftChild);
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
        return noneChildNodeCounter(rt->rightChild);
    else if (rt->leftChild != NULL && rt->rightChild != NULL)//���Һ��Ӷ���
        return  noneChildNodeCounter(rt->leftChild) + noneChildNodeCounter(rt->rightChild);
}

template<class T>
int BinaryTree<T>::heightCounter()//ͳ�Ƹ߶�,�ݹ����
{
    return heightCounter(root);
}
template<class T>
int BinaryTree<T>::heightCounter(BinaryTreeNode<T> *rt)  //ͳ�Ƹ߶�
{
    if(!rt)    //���ڵ�Ϊ��
        return 0;
    else if (rt->leftChild == NULL && rt->rightChild==NULL)//ֻ�и��ڵ�
        return 1;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
        return 1+heightCounter(rt->leftChild);
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
        return 1+heightCounter(rt->rightChild);
    else if (rt->leftChild != NULL && rt->rightChild != NULL)//���Һ��Ӷ���
    {
        return 1+(heightCounter(rt->leftChild)>=heightCounter(rt->rightChild)?heightCounter(rt->leftChild):heightCounter(rt->rightChild));
    }

}


template<class T>
void BinaryTree<T>::CountLine(BinaryTreeNode<T>* rt,int* ptr,int i)
{
        //ptr�Ǽ�¼ÿ��Ľڵ��������飬i��ָ����ĳһ��
	if (rt != NULL)
	{
		//ÿ�εݹ鶼���ò�Ľڵ����ӵ���Ӧ��������ȥ
		ptr[i]++;
		CountLine(rt->leftChild, ptr, i + 1);
		CountLine(rt->rightChild, ptr, i + 1);
	}
}
template<class T>
int BinaryTree<T>::FindMaxLine()
{
	//������Ӧ���������洢ÿ��Ľڵ���
	int height = heightCounter();
	int* str = new int[height];
	for (int i = 0; i < height; i++)
		str[i] = 0;
	//��ýڵ���
	CountLine(root, str, 0);
	int max1 = 0;
	//��������д���������ֵ
	for (int i = 0; i < height; i++)
	{
		if (max1 < str[i])
			max1 = str[i];
	}
	return max1;
}

template<class T>
T BinaryTree<T>::GetMaxmember()
{
    return GetMaxmember(root);
}

template<class T>
T BinaryTree<T>::GetMaxmember(BinaryTreeNode<T> * rt)
{
    if (rt->leftChild == NULL && rt->rightChild==NULL)//ֻ�и��ڵ�
        return rt->element;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
        return (rt->element>GetMaxmember(rt->leftChild)?rt->element:GetMaxmember(rt->leftChild));
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
        return (rt->element>GetMaxmember(rt->rightChild)?rt->element:GetMaxmember(rt->rightChild));
    else if (rt->leftChild != NULL && rt->rightChild != NULL)//���Һ��Ӷ���
    {
        T max;
        max=(GetMaxmember(rt->leftChild)>GetMaxmember(rt->rightChild)?GetMaxmember(rt->leftChild):GetMaxmember(rt->rightChild));
        return  (rt->element>max?rt->element:max);
    }
}

template<class T>
void BinaryTree<T>::changeChild()
{
    changeChild(root);
}

template<class T>
void BinaryTree<T>::changeChild(BinaryTreeNode<T> * rt)
{
    if (rt->leftChild == NULL && rt->rightChild==NULL)
         return;
    else if (rt->leftChild != NULL  &&  rt->rightChild == NULL)//������û���Һ���
    {
        changeChild(rt->leftChild);
        rt->rightChild=rt->leftChild;
        rt->leftChild=0;
    }
    else if (rt->leftChild == NULL && rt->rightChild != NULL)//���Һ���û������
    {
        changeChild(rt->rightChild);
        rt->leftChild=rt->rightChild;
        rt->rightChild=0;
    }
    else if (rt->leftChild != NULL && rt->rightChild != NULL)//���Һ��Ӷ���
    {
       changeChild(rt->leftChild);
       changeChild(rt->rightChild);
       BinaryTreeNode<T> * temp;
       temp=rt->leftChild;
       rt->leftChild=rt->rightChild;
       rt->rightChild=temp;
    }
}

template<class T>
void BinaryTree<T>::deleteLeave()
{
    deleteLeave(root);
}

template<class T>
void BinaryTree<T>::deleteLeave(BinaryTreeNode<T> * rt)
{
    //if(rt==NULL)return;
   // if((!rt->leftChild) && (!root->rightChild)) return;
    if(rt->leftChild)
    {
        if (rt->leftChild->leftChild || rt->leftChild->rightChild)
        {
            deleteLeave(rt->leftChild);
        }
        else
        {
          delete rt->leftChild;
          rt->leftChild=0;
        }
    }
    if(rt->rightChild)
    {
        if (rt->rightChild->leftChild || rt->rightChild->rightChild)
        {
            deleteLeave(rt->rightChild);
        }
        else
        {
           delete rt->rightChild;
           rt->rightChild=0;
        }

    }
}

template<class T>
bool BinaryTree<T>::isCompleteTree()
{
    Queue<BinaryTreeNode<T> *> q;
	BinaryTreeNode<T> * ptr;
	// ���й�����ȱ�������α�����������NULL�ڵ�Ҳ�������
	q.EnQueue(root);
	q.DeQueue(ptr);
	while (ptr!= NULL)
	{
	    q.EnQueue(ptr->leftChild);
	    q.EnQueue(ptr->rightChild);
	    q.DeQueue(ptr);
	}
	// �ж��Ƿ���δ�����ʵ��Ľڵ�
	while (!q.IsEmpty())
	{
		q.DeQueue(ptr);
		// ��δ���ʵ��ĵķ�NULL�ڵ㣬�������ڿն���Ϊ����ȫ������
		if (NULL != ptr)
		{
		    cout<<"����������ȫ������"<<endl;
			return false;
		}
	}
     cout<<"��������ȫ������"<<endl;
	return true;
}
int main()
{
    BinaryTree<int> a;
    //a.createTree();
    int xian[7]= {1,2,4,5,3,6,7};
    int zhong[7]={4,2,5,1,6,3,7};
    int hou[7]={4,5,2,6,7,3,1};
    //a.createByXian_Zhong(xian,0,6,zhong,0,6);
    a.createByHou_Zhong(hou,0,6,zhong,0,6);
    a.breadthFirstOrder();
    cout<<"Ҷ�ӽڵ����"<<endl;
    cout<< a.noneChildNodeCounter()<<endl;



    system("pause");
    return 0;
}
