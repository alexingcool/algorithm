#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    Node(int i = 0, Node *l = NULL, Node *r = NULL) : data(i), left(l), right(r) {}
	int data;
	Node *left;
	Node *right;
};

bool isSubTree2(Node *lhsTree, Node *rhsTree);
bool isSubTree3(Node *lhsTree, Node *rhsTree);

Node* constructLeftTree()
{
	Node *node9 = new Node(1);
	Node *node8 = new Node(2);
	Node* node7 = new Node(7, node8, node9);
	Node *node6 = new Node(4);
	Node *node5 = new Node(2, node6, node7);
	Node *node4 = new Node(9);
	Node *node3 = new Node(7);
	Node *node2 = new Node(8, node4, node5);
	Node *node1 = new Node(8, node2, node3);

	return node1;
}

Node *constructRightTree()
{
	Node *node4 = new Node(2);
	Node *node3 = new Node(7, node4);
	Node *node2 = new Node(4);
	Node *node1 = new Node(2, node2, node3);

	return node1;
}

//利用递归的解法
bool isSubTree(Node *lhsTree, Node *rhsTree)
{
	if (rhsTree == NULL)
		return true;
	if (lhsTree == NULL)
		return false;

	if (lhsTree->data != rhsTree->data)
		return false;

	return isSubTree(lhsTree->left, rhsTree->left) && isSubTree(lhsTree->right, rhsTree->right);
}

bool hasSubTree(Node *lhsTree, Node *rhsTree)
{
	if (lhsTree == NULL || rhsTree == NULL)
		return false;

	bool rootFlag = isSubTree(lhsTree, rhsTree);
	bool leftFlag = hasSubTree(lhsTree->left, rhsTree);
	bool rightFlag = hasSubTree(lhsTree->right, rhsTree);

	//只要其中之一是subtree即可，所以用||
	return rootFlag || leftFlag || rightFlag;
}

//利用迭代，前序遍历的解法
bool isSubTree2(Node *lhsTree, Node *rhsTree)
{
	if (lhsTree == NULL || rhsTree == NULL)
		return false;

	stack<Node*> lhsStack;
	stack<Node*> rhsStack;
	bool ret = false;
	while ((lhsTree != NULL || !lhsStack.empty()) && (rhsTree != NULL || !rhsStack.empty()))
	{
		if (lhsTree != NULL && rhsTree != NULL)
		{
			if (lhsTree->data != rhsTree->data)
				break;
			lhsStack.push(lhsTree);
			rhsStack.push(rhsTree);
			lhsTree = lhsTree->left;
			rhsTree = rhsTree->left;
		}
		else if (lhsTree != NULL && rhsTree == NULL)
		{
			ret = true;
			break;
		}
		else
		{
			lhsTree = lhsStack.top();
			rhsTree = rhsStack.top();
			lhsStack.pop();
			rhsStack.pop();
			lhsTree = lhsTree->right;
			rhsTree = rhsTree->right;
		}
	}

	if (lhsStack.empty() && rhsStack.empty())
		ret = true;

	return ret;
}

bool hasSubTree2(Node *lhsTree, Node *rhsTree)
{
	if (lhsTree == NULL || rhsTree == NULL)
		return false;

	stack<Node*> lhsStack;
	bool ret;
	while (lhsTree != NULL || !lhsStack.empty())
	{
		if (lhsTree != NULL)
		{
			ret = isSubTree2(lhsTree, rhsTree);
			if (ret == true)
				break;
			lhsStack.push(lhsTree);
			lhsTree = lhsTree->left;
		}
		else
		{
			lhsTree = lhsStack.top();
			lhsStack.pop();
			lhsTree = lhsTree->right;
		}
	}

	return ret;
}

//利用中序遍历求
bool isSubTree3(Node *lhsTree, Node *rhsTree)
{
	if (lhsTree == NULL || rhsTree == NULL)
		return false;

	stack<Node*> lhsStack;
	stack<Node*> rhsStack;
	bool ret = false;
	while ((lhsTree != NULL || !lhsStack.empty()) && (rhsTree != NULL || !rhsStack.empty()))
	{
		if (lhsTree != NULL && rhsTree != NULL)
		{
			lhsStack.push(lhsTree);
			rhsStack.push(rhsTree);
			lhsTree = lhsTree->left;
			rhsTree = rhsTree->left;
		}
		else if (lhsTree != NULL && rhsTree == NULL)
		{
			ret = true;
			break;
		}
		else
		{
			if (lhsTree->data != rhsTree->data)
				break;
			lhsTree = lhsStack.top();
			rhsTree = rhsStack.top();
			lhsStack.pop();
			rhsStack.pop();
			lhsTree = lhsTree->right;
			rhsTree = rhsTree->right;
		}
	}

	if (lhsStack.empty() && rhsStack.empty())
		ret = true;

	return ret;
}

void main()
{
	Node *lhsTree = constructLeftTree();
	Node *rhsTree = constructRightTree();
	bool ret = hasSubTree2(lhsTree, rhsTree);
	if (ret == true)
		cout << "has subtree" << endl;
	else
		cout << "has not substree" << endl;
}
