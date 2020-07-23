#include <iostream>
using namespace std;


struct AVLTreeNode{
public:
	int key;						// �ؼ���(��ֵ)
	int nHeight;					// �߶�
	AVLTreeNode *pLeftChild;		// ���ӽڵ�
	AVLTreeNode *pRightChild;		// �Һ��ӽڵ�

	AVLTreeNode( int value, AVLTreeNode *l, AVLTreeNode *r ) : key(value), nHeight(0),pLeftChild(l),pRightChild(r)
	{
	}
};

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void Preorder();		//	ǰ�����
	void Inorder();			//	�������
	void Postorder();		//	�������

	void Insert( int key );	//	����ָ��ֵ�Ľڵ�
	void Delete( int key );			//	ɾ��ָ��ֵ�Ľڵ�

	void Destroy();			//	����AVL��

	const int GetMiniNum();			//	����AVL���е���Сֵ
	const int GetMaxNum();			//	����AVL���е����ֵ
	const int GetHeight();			//	��ȡAVL���ĸ߶�

	AVLTreeNode* SearchRecurse( int key );		//	����ָ��ֵ��ʹ�õݹ���У�
	AVLTreeNode* Search( int key );			//	����ָ��ֵ��ʹ�õ��������У�
private:
	void Preorder( AVLTreeNode* pNode ) const;		//	ǰ�����
	void Inorder( AVLTreeNode* pNode ) const;		//	�������
	void Postorder( AVLTreeNode* pNode ) const;	//	�������


	AVLTreeNode* Delete( AVLTreeNode* &pNode, int key );	//	ɾ��AVL���нڵ�pDel,�����ر�ɾ���Ľڵ�

	void Destroy( AVLTreeNode* &pNode);

	AVLTreeNode* GetMiniNum( AVLTreeNode* pNode ) const;
	AVLTreeNode* GetMaxNum( AVLTreeNode* pNode ) const;
	int GetHeight( AVLTreeNode* pNode );

	AVLTreeNode* SearchRecurse( AVLTreeNode* pNode, int key ) const;
	AVLTreeNode* Search( AVLTreeNode* pNode, int key ) const;


	AVLTreeNode* LeftRotaion( AVLTreeNode* pNode );				//	������������������������ת��ĸ��ڵ�
	AVLTreeNode* RightRotation( AVLTreeNode* pNode );				//	������������������������ת��ĸ��ڵ�
	AVLTreeNode* LeftRightRotation( AVLTreeNode* pNode );			//	������������������������˫������������ת��ĸ��ڵ�
	AVLTreeNode* RightLeftRotation( AVLTreeNode* pNode );			//	������������������������˫������������ת��ĸ��ڵ�

	AVLTreeNode* Insert( AVLTreeNode* &pNode, int key );
	int max(int a, int b)
	{
		return a>b ? a : b;
	}

private:
	AVLTreeNode* pRoot;
};


AVLTree::AVLTree( ) : pRoot( NULL )
{}

AVLTree::~AVLTree( )
{
	Destroy( pRoot );
}

void AVLTree::Preorder()
{
	Preorder( pRoot );
}

void AVLTree::Preorder( AVLTreeNode* pNode ) const
{
	if ( pNode != NULL )
	{
		cout << " " << pNode->key << " " ;
		Preorder( pNode->pLeftChild );
		Preorder( pNode->pRightChild );
	}
}

void AVLTree::Inorder()
{
	Inorder( pRoot );
}

void AVLTree::Inorder( AVLTreeNode* pNode ) const
{
	if ( pNode != NULL )
	{
		Inorder( pNode->pLeftChild );
		cout << " " << pNode->key << " " ;
		Inorder( pNode->pRightChild );
	}
}

void AVLTree::Postorder()
{
	Postorder( pRoot );
}

void AVLTree::Postorder( AVLTreeNode* pNode ) const
{
	if ( pNode != NULL )
	{
		Postorder( pNode->pLeftChild );
		Postorder( pNode->pRightChild );
		cout << " " << pNode->key << " " ;
	}
}

void AVLTree::Destroy()
{
	Destroy( pRoot );
}

void AVLTree::Destroy( AVLTreeNode* &pNode)
{
	if ( pNode == NULL )
		return;

	Destroy( pNode->pLeftChild );
	Destroy( pNode->pRightChild );
	delete pNode;
	pNode = NULL;
}

void AVLTree::Insert( int key )
{

	Insert( pRoot, key );
}

AVLTreeNode* AVLTree::Insert( AVLTreeNode* &pNode, int key )
{
	if ( pNode == NULL )
		pNode = new AVLTreeNode( key, NULL, NULL );
	else if ( pNode->key > key )								//	����ֵ�ȵ�ǰ�ڵ��ֵС�����뵽��ǰ�ڵ��������
	{
		pNode->pLeftChild = Insert( pNode->pLeftChild, key );
		if ( GetHeight( pNode->pLeftChild) - GetHeight( pNode->pRightChild ) == 2 )
		{
			if ( key < pNode->pLeftChild->key )					//	���뵽�����������ӽڵ��ϣ���������
				pNode = RightRotation( pNode );
			else if ( key > pNode->pLeftChild->key )			//	���뵽�����������ӽڵ��ϣ�����������������
				pNode = LeftRightRotation( pNode );
		}
	}
	else if ( pNode->key < key )								//	����ֵ�ȵ�ǰ�ڵ��ֵ�󣬲��뵽��ǰ�ڵ��������
	{
		pNode->pRightChild = Insert( pNode->pRightChild, key );
		if ( GetHeight( pNode->pRightChild ) - GetHeight( pNode->pLeftChild ) == 2 )
		{
			if ( key > pNode->pRightChild->key )				//	���뵽���������ҽڵ��ϣ���������
				pNode = LeftRotaion( pNode );
			else if ( key < pNode->pRightChild->key )
				pNode = LeftRightRotation( pNode );
		}
	}

	pNode->nHeight = max( GetHeight( pNode->pLeftChild ), GetHeight( pNode->pRightChild ) ) + 1;
	return pNode;
}

void AVLTree::Delete( int key )
{
	pRoot = Delete( pRoot, key );
}

AVLTreeNode* AVLTree::Delete( AVLTreeNode* &pNode, int key )
{
	if ( pNode == NULL )
		return NULL;

	if ( key == pNode->key )									//	�ҵ�Ҫɾ���Ľڵ�
	{
		if ( pNode->pLeftChild != NULL && pNode->pRightChild != NULL )
		{
			//	���������������ߣ�����������ѡ��ڵ�����滻
			if ( GetHeight( pNode->pLeftChild ) > GetHeight( pNode->pRightChild ) )
			{
				//	ʹ�������������ڵ������汻ɾ�ڵ㣬��ɾ�������ڵ�
				AVLTreeNode* pNodeTemp = GetMaxNum( pNode->pLeftChild );				//	���������ڵ�
				pNode->key = pNodeTemp->key;
				pNode->pLeftChild = Delete( pNode->pLeftChild, pNodeTemp->key );		//	�ݹ��ɾ�����ڵ�
			}
			else
			{
				//	ʹ����С�ڵ������汻ɾ�ڵ㣬��ɾ������С�ڵ�
				AVLTreeNode* pNodeTemp = GetMiniNum( pNode->pRightChild );				//	����������С�ڵ�
				pNode->key = pNodeTemp->key;
				pNode->pRightChild = Delete( pNode->pRightChild, pNodeTemp->key );		//	�ݹ��ɾ����С�ڵ�
			}

		}
		else
		{
			AVLTreeNode* pNodeTemp = pNode;
			if ( pNode->pLeftChild != NULL )
				pNode = pNode->pLeftChild;

			if ( pNode->pRightChild != NULL )
				pNode = pNode->pRightChild;

			delete pNodeTemp;
			pNodeTemp = NULL;
			return pNode;

		}
	}
	else if ( key > pNode->key )							//	Ҫɾ���Ľڵ�ȵ�ǰ�����������������в���
	{
		pNode->pRightChild = Delete( pNode->pRightChild, key );
		if ( GetHeight( pNode->pLeftChild ) - GetHeight( pNode->pRightChild ) == 2 )
		{
			if ( GetHeight( pNode->pLeftChild->pRightChild ) > GetHeight( pNode->pLeftChild->pLeftChild ) )
				pNode = LeftRightRotation( pNode );
			else
				pNode = RightRotation( pNode );
		}

	}
	else													//	Ҫɾ���Ľڵ�ȵ�ǰ���С���������������в���
	{
		pNode->pLeftChild = Delete( pNode->pLeftChild, key );
		if ( GetHeight( pNode->pLeftChild->pRightChild ) > GetHeight( pNode->pLeftChild->pLeftChild ) )
			pNode = RightLeftRotation( pNode );
		else
			pNode = LeftRotaion( pNode );
	}

	return pNode;
}

const int AVLTree::GetMiniNum()
{
	AVLTreeNode* pFindNode = GetMiniNum( pRoot );
	if ( pFindNode == NULL )
		return 0;

	return pFindNode->key;
}

AVLTreeNode* AVLTree::GetMiniNum( AVLTreeNode* pNode ) const
{
	if ( pNode == NULL )
		return NULL;

	while ( pNode->pLeftChild != NULL )
		pNode = pNode->pLeftChild;

	return pNode;
}

const int AVLTree::GetMaxNum()
{
	AVLTreeNode* pFindNode = GetMaxNum( pRoot );
	if ( pFindNode == NULL )
		return 0;

	return pFindNode->key;
}

AVLTreeNode* AVLTree::GetMaxNum( AVLTreeNode* pNode ) const
{
	if ( pNode == NULL )
		return NULL;

	while ( pNode->pRightChild != NULL )
		pNode = pNode->pRightChild;

	return pNode;
}

const int AVLTree::GetHeight()
{
	return GetHeight( pRoot );
}

int AVLTree::GetHeight( AVLTreeNode* pNode )
{
	if ( pNode == NULL )
		return 0;

	return pNode->nHeight;
}

AVLTreeNode* AVLTree::SearchRecurse( int key )
{
	return SearchRecurse( pRoot, key );
}

AVLTreeNode* AVLTree::SearchRecurse( AVLTreeNode* pNode, int key ) const
{
	if ( pNode == NULL )
		return NULL;

	if ( key == pNode->key )
		return pNode;

	if ( key > pNode->key )
		return SearchRecurse( pNode->pRightChild, key);
	else
		return SearchRecurse( pNode->pLeftChild, key);
}

AVLTreeNode* AVLTree::Search( int key )
{
	return Search( pRoot, key );
}

AVLTreeNode* AVLTree::Search( AVLTreeNode* pNode, int key ) const
{
	while ( pNode != NULL )
	{
		if ( key == pNode->key )
			return pNode;
		if ( key > pNode->key )
			pNode = pNode->pRightChild;
		else
			pNode = pNode->pLeftChild;
	}
	return NULL;
}

AVLTreeNode* AVLTree::LeftRotaion( AVLTreeNode* pNode )
{
	AVLTreeNode* pRChlid = pNode->pRightChild;
	pNode->pRightChild = pRChlid->pLeftChild;
	pRChlid->pLeftChild = pNode;

	pNode->nHeight = max( GetHeight( pNode->pLeftChild ), GetHeight( pNode->pRightChild ) ) + 1 ;
	pRChlid->nHeight = max( GetHeight( pRChlid->pLeftChild ), GetHeight( pRChlid->pRightChild ) ) + 1 ;

	return pRChlid;
}

AVLTreeNode* AVLTree::RightRotation( AVLTreeNode* pNode )
{
	AVLTreeNode* pLChild = pNode->pLeftChild;
	pNode->pLeftChild = pLChild->pRightChild;
	pLChild->pRightChild = pNode;

	pNode->nHeight = max( GetHeight( pNode->pLeftChild ), GetHeight( pNode->pRightChild ) ) + 1 ;
	pLChild->nHeight = max( GetHeight( pLChild->pLeftChild ), GetHeight( pLChild->pRightChild ) ) + 1 ;
	return pLChild;
}

AVLTreeNode* AVLTree::LeftRightRotation( AVLTreeNode* pNode )
{
	pNode->pRightChild = RightRotation( pNode->pRightChild );
	return LeftRotaion( pNode );
}

AVLTreeNode* AVLTree::RightLeftRotation( AVLTreeNode* pNode )
{
	pNode->pLeftChild = LeftRotaion( pNode->pLeftChild );
	return RightRotation( pNode );
}

int main( )
{
	AVLTree* pTree = new AVLTree( );
	for ( int nIdx = 0; nIdx < 10; nIdx++ )
	{
		pTree->Insert( nIdx );
	}

	cout << " ���ĸ߶�Ϊ��" << pTree->GetHeight( ) << endl;

	cout << " ǰ�������" ;
	pTree->Preorder( );
	cout << endl;

	cout << " ���������" ;
	pTree->Inorder( );
	cout << endl;

	cout << " ���������" ;
	pTree->Postorder( );
	cout << endl;

	int nDeleteKey = 8;
	AVLTreeNode* pFindNode = pTree->SearchRecurse( nDeleteKey );
	if ( pFindNode == NULL )
		cout << " ��Ԫ��" << nDeleteKey << endl;
	else
	{
		cout << " ɾ��Ԫ��" << nDeleteKey << endl;
		pTree->Delete( nDeleteKey );
		cout << " ǰ�������" ;
		pTree->Preorder( );
	}

	cout << endl;


//	system( "pause");
	return 0;
}
