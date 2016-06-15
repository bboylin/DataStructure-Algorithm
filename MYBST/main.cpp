#include"chapter12.h"
int main()
{
	int array[]={15,6,18,3,7,17,20,2,4,13,9};
	std::vector<int> vec(array,
		array+sizeof(array)/sizeof(int));
	bstree bst(vec);
	bst.inorder_tree_walk();
	node* p1=bst.search_tree(6);
	node* p2=bst.iterative_search_tree(7);
	bst.tree_maximum();
	bst.tree_minimum();
	node* p3=bst.tree_successor(p1);
	node* p4=bst.tree_predecessor(p1);
	node* p5=bst.tree_successor(p2);
	node* p6=bst.tree_predecessor(p2);
	node* p_new1=new node(14);
	node* p_new2=new node(19);
	bst.tree_insert(p_new1);
	bst.tree_insert(p_new2);
	bst.tree_delete(p_new1);
	bst.tree_delete(p_new2);
	bst.tree_delete(p1);
	bst.tree_delete(p2);
	return 0;

}
