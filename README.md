# Homework1--Reverse LinkList.cpp
## Reverse a Linked List using Recursion

### Method: 

Recursive Function Call

### Logic: 

Achieve the reversal of node pointing from the end to the beginning through recursive function calls, while adding an empty head pointer at the beginning.

### Core Code: 

Stu* reverse(Stu* pH)
{
	if (pH->next == NULL)
	{
		Stu* pH2 = new Stu();
		pH2->next = pH;
		return pH2;
	}
	Stu* newH = reverse(pH->next);//Recursively traverse the linked list until reaching the end of the list
	pH->next->next = pH;//Recursively reverse the direction of each node's pointer
	pH->next = NULL;

	return newH;
}

# Homework2--HuffmanTree.cpp
## Huffman Coding

### Method: 

Building the Tree Bottom-Up, Assigning Codes Top-Down

### Logic: 

When encoding, search for the existence of left child nodes from top to bottom. If absent, output the code. If present, assign 0 to the left child and 1 to the right child, and continue searching downward.

### Core Code: 

while (num)
	{
		if (root->leftchild->leftchild == NULL)
		{
			strcpy(s1, s);
			m = root->leftchild->data;
			c = getC(m, b, n);
			printf("%c 【%d】:%s\n", c, m, strcat(s1, "0"));
		}
		if (root->rightchild->leftchild == NULL)
		{
			strcpy(s1, s);
			m = root->rightchild->data;
			c = getC(m, b, n);
			printf("%c 【%d】:%s\n", c, m, strcat(s1, "1"));
		}
		if (root->leftchild->leftchild != NULL)
		{
			strcat(s, "0");
			root = root->leftchild;
		}
		if (root->rightchild->leftchild != NULL)
		{
			strcat(s, "1");
			root = root->rightchild;
		}
		num--;
	}

# Homework3--Kruskal.cpp
## Kruskal’s Algorithm for finding Minimum Spanning Tree

### Method:

The method involves using the sort() function to arrange all edges in ascending order based on their weights. The process utilizes the principles of the disjoint-set union (DSU) data structure. The find() function is applied to find the root nodes, followed by path compression. This helps determine if the nodes u and v belong to the same tree. If they do not, the edge (u, v) is added to the minimum spanning tree.

### Logic:

1.Arrange edges in ascending order based on their weights.

2.Iterate through each edge. Use the find() function to find the root nodes of u and v. Check if adding the edge will create a cycle in the minimum spanning tree.

3.If the root nodes of u and v are different, it indicates that adding the edge will not create a cycle. Therefore, add this edge to the minimum spanning tree.

4.Continue iterating through the remaining edges until only n-1 edges are left, forming the minimum spanning tree consisting of n nodes.

### Core Code: 

void Kruskal()
{
	sort(e + 1, e + m + 1, cmp);//Sort the edges in ascending order based on their weights.
	for (int i = 1; i <= m; i++) 
	{
		int u = find(e[i].u);
		int v = find(e[i].v);
		if (u == v)
			continue;//If two nodes belong to the same tree, the edge is skipped.
		ans += e[i].w;
		printf("%d->%d weights:%d\n", u, v, e[i].w);
		f[v] = u;//Root node of vertex `v` is `u`, then the edge (`u`, `v`) is added.
		sum++;
		if (sum == n - 1)break;//All the nodes together form a tree.
	}
}
