//Max Starceski
//ECE231L Final Project

#ifndef _TREE_H
#define _TREE_H

template <typename T = int>
class Node {
	private:
		T* data;
		Node* left;
		Node* right;
	public:
		Node() {data = NULL; left = NULL; right = NULL;}
		Node(T *n_v, Node *l, Node *r) {data = n_v; left = l; right = r;}
		int getValue() {return value;}
		Node * getLeft() {return left;}
		Node * getRight() {return right;}
		
		void setLeft(Node *l) {left = l;}
		void setRight(Node *r) {right = r;}

}; 


template <typename T = int>
class Tree{
	private:
		Node *root;
		Node *find(T &x, BinaryNode *t);
		void insert(T &x, BinaryNode *t);
										
	public:
		Tree() {root = NULL;}
		Node *find(T &x) {return find(x, root);}
		void insert(int &x) {insert(x, root);}



};


template <typename T = int>
void Tree::insert(T &x, Node *t) {
	if(root == NULL){
		root = new Node(x, NULL, NULL);
	} else {
		if (x < t->getValue()) {
			if (t->getLeft() == NULL)
				t->setLeft(new Node(x, NULL, NULL));
			else
				insert(x, t->getLeft());
		}
		else if (x >= t->getValue()) {
			if (t->getRight() == NULL)
				t->setRight(new Node(x, NULL, NULL));
			else
				insert(x, t->getRight());
		}
	}


}

#endif
