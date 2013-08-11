#include <iostream>

using namespace std;

struct Node
{
    Node (int i = 0, Node *next = NULL) : data(i), next(next) {}
	int data;
	Node *next;
};

Node* constructLeftLink()
{
	Node dummy;
	Node *pHead = &dummy;
	for (int i = 1; i <= 19; i += 2)
	{
		Node *newNode = new Node(i);
		pHead->next = newNode;
		pHead = newNode;
	}

	return dummy.next;
}

Node* constructRightLink()
{
	Node dummy;
	Node *pHead = &dummy;
	for (int i = 2; i < 10; i += 2)
	{
		Node *newNode = new Node(i);
		pHead->next = newNode;
		pHead = newNode;
	}

	return dummy.next;
}

Node* mergeLink(Node *lhsLink, Node *rhsLink)
{
	if (lhsLink == NULL)
		return rhsLink;
	if (rhsLink == NULL)
		return lhsLink;

	Node *head;
	if (lhsLink->data < rhsLink->data)
	{
		head = lhsLink;
		head->next = mergeLink(lhsLink->next, rhsLink);
	}
	else
	{
		head = rhsLink;
		head->next = mergeLink(lhsLink, rhsLink->next);
	}

	return head;
}

void printLink(Node *head)
{
	if (head == NULL)
		return;

	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void main()
{
	Node *lhsLink = constructLeftLink();
	cout << "left link" << endl;
	printLink(lhsLink);
	Node *rhsLink = constructRightLink();
	cout << "right link" << endl;
	printLink(rhsLink);
	Node *head = mergeLink(lhsLink, rhsLink);
	printLink(head);
}
