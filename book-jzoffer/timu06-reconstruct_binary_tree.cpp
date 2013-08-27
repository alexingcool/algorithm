#include <iostream>

using namespace std;

struct BinaryTreeNode {
	BinaryTreeNode(int i = 0, BinaryTreeNode *l = NULL, BinaryTreeNode *r = NULL) 
		: m_value(i), m_left(l), m_right(r) {}
	int m_value;
	BinaryTreeNode *m_left;
	BinaryTreeNode *m_right;
};

int pre_order[] = {1, 2, 4, 7, 3, 5, 6, 8};
int in_order[] = {4, 7, 2, 1, 5, 3, 8, 6};
const int pre_order_len = sizeof pre_order / sizeof *pre_order;
const int in_order_len = sizeof in_order / sizeof *in_order;

BinaryTreeNode* ConstructTree(int *pre_order, int *in_order, int len) {
	if (pre_order == NULL || in_order == NULL || len <= 0) {
		return NULL;
	}
	int index = 0;
	while (index < len && pre_order[0] != in_order[index]) {
		index++;
	}
	if (index == len) {
		cerr << "error" << endl;
		return NULL;
	}
	BinaryTreeNode *node = new BinaryTreeNode(pre_order[0]);
	node->m_left = ConstructTree(pre_order + 1, in_order, index);
	node->m_right = ConstructTree(pre_order + index + 1, in_order + index + 1, len - index - 1);
	return node;
}

void PreOrder(BinaryTreeNode *root) {
	if (root != NULL) {
		cout << root->m_value << " ";
		PreOrder(root->m_left);
		PreOrder(root->m_right);
	}
}

int main() {
	BinaryTreeNode *root = ConstructTree(pre_order, in_order, pre_order_len);
	PreOrder(root);
}
