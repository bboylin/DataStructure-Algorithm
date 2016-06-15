#ifndef CHAPTER12_H
#define CHAPTER12_H
#include<iostream>
#include<vector>
#include<exception>
using namespace std;
//binary search tree node
//供二叉搜索树使用的节点类
class bstree;
class node{
public:
	node(int k,node* p=NULL,node* l=NULL,node* r=NULL):
		key(k),
		parent(p),
		left(l),
		right(r){}
	//声明为友元类，bstree可以使用node的private成员
	friend class bstree;
private:
	//键值
	int key;
	//父节点
	node* parent;
	//左儿子
	node* left;
	//右儿子
	node* right;
};
//binary search tree
//二叉搜索树类
class bstree{
public:
	//二叉搜索树的默认构造函数
	bstree():
		root(NULL){}
	//析构函数
	~bstree(){clear(root);}
	//由析构函数调用的clear函数
	void clear(node* x);
	//构造函数，由vector<int>构造二叉搜索数
	bstree(const std::vector<int>& a);
	//中序遍历，从根root开始
	void inorder_tree_walk()const;
	//中序遍历，从x开始
	void inorder_tree_walk(node* x) const;
	//以x为根的子树中搜索key的节点，
	node* search_tree(node* x,int key) const;
	//以root为根搜索key的节点，
	node* search_tree(int key)const;
	//以x为根的子树中迭代搜索key的节点，
	node* iterative_search_tree(node* x,int key) const;
	//以root为根迭代搜索key的节点，
	node* iterative_search_tree(int key) const;
	//以x为根的子树中搜索最大key的节点，
	node* tree_maximum(node* x) const;
	//以root为根的树中搜索最大key的节点，
	node* tree_maximum()const;
	//以x为根的子树中搜索最小key的节点，
	node* tree_minimum(node* x) const;
	//以root为根的树中搜索最小key的节点，
	node* tree_minimum()const;
	//结点x的后继
	node* tree_successor(node* x)const;
	//结点x的前驱
	node* tree_predecessor(node* x)const;
	//在树中插入节点z
	void tree_insert(node* z);
	//将以u为根节点的子树变换为以v为根节点的子树
	void transplant(node* u,node* v );
	//删除节点z
	void tree_delete(node* z);
private:
	//根节点root
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
		//释放内存
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
