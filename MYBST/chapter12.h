#ifndef CHAPTER12_H
#define CHAPTER12_H
#include<iostream>
#include<vector>
#include<exception>
using namespace std;
//binary search tree node
//������������ʹ�õĽڵ���
class bstree;
class node{
public:
	node(int k,node* p=NULL,node* l=NULL,node* r=NULL):
		key(k),
		parent(p),
		left(l),
		right(r){}
	//����Ϊ��Ԫ�࣬bstree����ʹ��node��private��Ա
	friend class bstree;
private:
	//��ֵ
	int key;
	//���ڵ�
	node* parent;
	//�����
	node* left;
	//�Ҷ���
	node* right;
};
//binary search tree
//������������
class bstree{
public:
	//������������Ĭ�Ϲ��캯��
	bstree():
		root(NULL){}
	//��������
	~bstree(){clear(root);}
	//�������������õ�clear����
	void clear(node* x);
	//���캯������vector<int>�������������
	bstree(const std::vector<int>& a);
	//����������Ӹ�root��ʼ
	void inorder_tree_walk()const;
	//�����������x��ʼ
	void inorder_tree_walk(node* x) const;
	//��xΪ��������������key�Ľڵ㣬
	node* search_tree(node* x,int key) const;
	//��rootΪ������key�Ľڵ㣬
	node* search_tree(int key)const;
	//��xΪ���������е�������key�Ľڵ㣬
	node* iterative_search_tree(node* x,int key) const;
	//��rootΪ����������key�Ľڵ㣬
	node* iterative_search_tree(int key) const;
	//��xΪ�����������������key�Ľڵ㣬
	node* tree_maximum(node* x) const;
	//��rootΪ���������������key�Ľڵ㣬
	node* tree_maximum()const;
	//��xΪ����������������Сkey�Ľڵ㣬
	node* tree_minimum(node* x) const;
	//��rootΪ��������������Сkey�Ľڵ㣬
	node* tree_minimum()const;
	//���x�ĺ��
	node* tree_successor(node* x)const;
	//���x��ǰ��
	node* tree_predecessor(node* x)const;
	//�����в���ڵ�z
	void tree_insert(node* z);
	//����uΪ���ڵ�������任Ϊ��vΪ���ڵ������
	void transplant(node* u,node* v );
	//ɾ���ڵ�z
	void tree_delete(node* z);
private:
	//���ڵ�root
	node* root;
};
bstree::bstree(const std::vector<int>& a)
{
	root=NULL;
	for(int i=0;i<a.size();i++)
	{
		node* p=new node(a[i]);
		if(p==NULL)
		{
			//runtime_error("bad allocate !");
			//exit(0);
		}
		tree_insert(new node(a[i]));
	}
	root->parent=NULL;
}
void bstree::clear(node* x)
{
	while(x!=NULL)
	{
		clear(x->left);
		clear(x->right);
		//�ͷ��ڴ�
		node* tmp=x;
		x=NULL;
		delete tmp;
	}
}
void bstree::inorder_tree_walk(node* x) const
{
	if(x!=NULL)
	{
		inorder_tree_walk(x->left);
		std::cout<<x->key<<" ";
		inorder_tree_walk(x->right);
	}

}
void bstree::inorder_tree_walk()const
{
	inorder_tree_walk(root);
	std::cout<<std::endl;
}
node* bstree::search_tree(node* x,int k)const
{
	if(x==NULL||x->key==k)
		return x;
	if(k<x->key)
		return search_tree(x->left,k);
	else
		return search_tree(x->right,k);
}
node* bstree::search_tree(int key)const
{
	node* p=search_tree(root,key);
	if(p!=NULL)
		std::cout<<"find key "<<p->key<<std::endl;
	else
		std::cout<<"no find key "<<key<<std::endl;
	return p;
}
node* bstree::iterative_search_tree(node* x,int k) const
{
	while(x!=NULL&&k!=x->key)
		if(k<x->key)
			x=x->left;
		else
			x=x->right;
	return x;
}
node* bstree::iterative_search_tree(int key) const
{
	node* p=iterative_search_tree(root,key);
	if(p!=NULL)
		std::cout<<"find key "<<p->key<<std::endl;
	else
		std::cout<<"no find key "<<key<<std::endl;
	return p;
}
node* bstree::tree_maximum(node* x)const
{
	while(x->right!=NULL)
		x=x->right;
	return x;
}
node* bstree::tree_maximum()const
{
	node* p=tree_maximum(root);
	std::cout<<"tree maximum:"<<p->key<<std::endl;
	return p;
}
node* bstree::tree_minimum(node* x) const
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}
node* bstree::tree_minimum()const
{
	node* p=tree_minimum(root);
	std::cout<<"tree minimum:"<<p->key<<std::endl;
	return p;
}
node* bstree::tree_successor(node* x) const
{
	if(x->right!=NULL)
		return tree_minimum(x->right);
	node* y=x->parent;
	while(y!=NULL&&x==y->right)
	{
		x=y;
		y=y->parent;
	}
	//std::cout<<"tree successor:"<<y->key<<std::endl;
	return y;
}
node* bstree::tree_predecessor(node* x)const
{
	if(x->left!=NULL)
		return tree_maximum(x->left);
	node* y=x->parent;
	while(y!=NULL&&x==y->left)
	{
		x=y;
		y=y->parent;
	}
	//std::cout<<"tree predecessor:"<<y->key<<std::endl;
	return y;
}

void bstree::tree_insert(node* z)
{
	node* y=NULL;
	node* x=root;
	while(x!=NULL)
	{
		y=x;
		if(x->key>=z->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		root=z;
	else if(z->key<y->key)
		y->left=z;
	else
		y->right=z;

}
void bstree::transplant(node* u ,node* v )
{
	if(u->parent==NULL)
		root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else
		u->parent->right=v;
	if(v!=NULL)
		v->parent=u->parent;
}
void bstree::tree_delete(node* z)
{
	if(z->left==NULL)
		transplant(z,z->right);
	else if(z->right==NULL)
		transplant(z,z->left);
	else
	{
		node* y=tree_minimum(z->right);
		if(y->parent!=z)
		{
			transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	node* tmp=z;
	z=NULL;
	delete tmp;
}

#endif
