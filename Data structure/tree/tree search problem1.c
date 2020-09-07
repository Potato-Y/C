//입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
	}
}

TreeNode* search(TreeNode* node, int key) {  //순환적인 탐색 함수
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key) return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) current = current->left;
	return current;
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d\n", root->key);
		inorder(root->right);
	}
}

int main(void) {
	printf("다른 문자를 입력하면 입력이 완료됩니다.\n");

	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	int num=0;
	
	for (int i = 0; i < 10001; i++){
		scanf_s("%d", &num);
		if (0 < num && num < 1000000) {
			root = insert_node(root, num);
		}
		else break;
		
	}
	

	
	printf("\n\n");
	postorder(root);
	return 0;
}
