#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <deque>

using namespace std;

const int size = 10;

struct Node 
{
	int data;
	Node *next;
};

struct Link
{
	string headName;
	Node *head;
	int count;
};

struct Graph
{
	Link link[size];
	int vecnum;
	int arcnum;
};

int locatVex(Graph &G, string str)
{
	for (int i = 0; i < size; i++)
	{
		if (G.link[i].headName == str)
			return i;
	}

	cout << "wront input" << endl;
	return -1;
}

void constructGraph(Graph &G)
{
	cout << "input head name " << endl;
	string name;
	int i = 0;
	while (name != "end")
	{
		cin >> name;
		G.link[i].head = NULL;
		G.link[i].count = 0;
		G.link[i++].headName = name;
	}

	cout << "input vexnum: " << endl;
	cin >> G.vecnum;
	cout << "input arcnum: " << endl;
	cin >> G.arcnum;

	string leftNode, rightNode;
	while (leftNode != "end" || rightNode != "end")
	{
		cout << "input leftNode & rightNode: " << endl;
		cin >> leftNode >> rightNode;

		int i = locatVex(G, leftNode);
		int j = locatVex(G, rightNode);

		Node *node = new Node;
		node->data = j;
		node->next = NULL;

		node->next = G.link[i].head;
		G.link[i].head = node;
	}
}

void toposort(Graph &G)
{
	deque<int> ideque;
	int countSum = 0;

	for (int i = 0; i < G.vecnum; i++)
	{
		for (Node *p = G.link[i].head; p; p = p->next)
		{
			int pos = p->data;
			G.link[pos].count++;
		}
	}

	for (int i = 0; i < G.vecnum; i++)
	{
		if (G.link[i].count == 0)
			ideque.push_back(i);
	}

	while (!ideque.empty())
	{
		int i = ideque.front();
		ideque.pop_front();
		cout << G.link[i].headName << " ";
		++countSum;

		for (Node *p = G.link[i].head; p; p = p->next)
		{
			int k = p->data;
			if (!(--G.link[k].count))
				ideque.push_front(k);
		}
	}
}

int main()
{
	Graph G;
	constructGraph(G);
	toposort(G);

	return 0;
}
