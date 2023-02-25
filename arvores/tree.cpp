#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <queue>
using namespace std;

typedef struct tree {
	int data;
    struct tree *left;
	struct tree *right;
} *Tree;

// ==================================== Atividade 01
Tree createNodeTree(int x, Tree l, Tree r){
	Tree newTree =(Tree)malloc(sizeof(Tree));
	newTree->data = x;
	newTree->left = l;
	newTree->right = r;
	return newTree;
}

Tree createEmptyTree(){
    return NULL;
}

void printTreeFormated(Tree root){
    if(root != NULL){
        cout << "<" << root->data;

        printTreeFormated(root->left);
        printTreeFormated(root->right);
        cout << ">";
    }
}

void breadthFirstSearch(Tree root){
	queue<Tree> fila;
	fila.push(root);
	Tree node;

	while(!fila.empty()){
		node = fila.front();
		fila.pop();

        cout << node->data;

		if(node->left != NULL) {
		    fila.push(node->left);
		}
		
		if(node->right != NULL) {
		    fila.push(node->right);
		}   
	}
}

// ==================================== Atividade 02 - 13.02
int countNodes(Tree root){
	if(root == NULL) {
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// ==================================== Atividade 02 - 13.03
int countLeaves(Tree root) {
	if(root == NULL) {
	    return 0;
	}
	
	if(root->left == NULL && root->right == NULL) {
		return 1;
	}

	return countLeaves(root->left) + countLeaves(root->right);
}

// ==================================== Atividade 02 - 13.04
int treeHeight(Tree root){
	if(root == NULL) {
		return 0;
	}

	int left = treeHeight(root->left);
	int right = treeHeight(root->right);

	if(left > right) return left + 1;
	return right + 1;
}

// ==================================== Atividade 02 - 13.05
bool treeContains(Tree root, int item){ 
	if(root == NULL) {
		return false;
	}

	if(root->data == item){
		return true;
	}

	return treeContains(root->left, item) || treeContains(root->right, item);
}


int main(){
	Tree tree1 = createNodeTree(
				1,
				createNodeTree(
					2, 
					createNodeTree(4, NULL, NULL), 
					createNodeTree(5, NULL, NULL)
					),
				createNodeTree(
					3, 
					NULL,
					createNodeTree(6, NULL, NULL) 
					)
				);

	Tree tree2 = NULL;

    breadthFirstSearch(tree1);
    cout << endl;
	printTreeFormated(tree1);
    cout << endl;
	
	cout << countNodes(tree1) << endl;
	cout << treeHeight(tree1) << endl;
	cout << treeHeight(tree2) << endl;

	cout << treeContains(tree1, 1) << endl;
	cout << treeContains(tree1, 2) << endl;
	cout << treeContains(tree1, 3) << endl;
	cout << treeContains(tree1, 4) << endl;
	cout << treeContains(tree1, 5) << endl;
	cout << treeContains(tree1, 6) << endl;
	cout << treeContains(tree1, 7) << endl;
	cout << treeContains(tree1, 8) << endl;
}