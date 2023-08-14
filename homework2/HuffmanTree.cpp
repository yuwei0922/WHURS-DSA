#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct Node //定义树
{ 
	int data;
	struct Node* leftchild;
	struct Node* rightchild;
}Tree;

typedef struct Data //定义字符及其对应的频率
{ 
	char c;
	int data;//频率是随机产生的
};

void Initiate(Tree** root)//初始化节点
{
	*root = (Tree*)malloc(sizeof(Tree));
	(*root)->leftchild = NULL;
	(*root)->rightchild = NULL;
}

int getMin(struct Data a[], int n)//得到a中数值最小的数
{
	int i, t;
	for (i = 1; i < n; i++)
	{
		if (a[i].data < a[0].data)
		{
			t = a[i].data;
			a[i].data = a[0].data;
			a[0].data = t;
		}
	}
	t = a[0].data;
	for (i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	return t;
}

void set(struct Data a[], struct Data b[],int n)//初始化a,且将a备份至b
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i].data = rand() % 100 + 1;
		a[i].c = i + 97;
		b[i].data = a[i].data;
		b[i].c = a[i].c;
		if (i >= 0 && a[i].data == a[i - 1].data)
			i--;
	}
}

char getC(int x, struct Data b[],int n)//得到b中数值为x的字符
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (b[i].data == x)
		{
			break;
		}
	}
	return b[i].c;
}

void prin(struct Data a[],int n)//输出初始化后的字符及对应的值
{
	int i;
	printf("字符\t出现的频率\n");
	for (i = 0; i < n; i++)
	{
		printf("%c\t  %d\n", a[i].c, a[i].data);
	}
}

int n;
void main()
{
	Tree* root = NULL, * left = NULL, * right = NULL, * p = NULL;
	int min, num, n;
	int k = 30, j, m;
	n = rand() % 10 + 2;
	struct Data a[100];
	struct Data b[100];
	int i;
	char s[100] = { '\0' }, s1[100] = { '\0' };
	char c;
	set(a, b, n);
	prin(a,n);
	Initiate(&root);
	Initiate(&left);
	Initiate(&right);
	Initiate(&p);
	//设置最底层的左节点
	min = getMin(a, n);
	left->data = min;
	left->leftchild = NULL;
	left->rightchild = NULL;
	//设置最底层的右节点
	min = getMin(a, n - 1);
	right->data = min;
	right->leftchild = NULL;
	right->rightchild = NULL;
	root->data = left->data + right->data;
	Initiate(&root->leftchild);
	Initiate(&root->rightchild);
	//将设置好的左右节点插入到root中
	root->leftchild = left;
	root->rightchild = right;
	for (i = 0; i < n - 2; i++)
	{
		min = getMin(a, n - 2 - i);
		Initiate(&left);
		Initiate(&right);
		if (min < root->data)//权值小的作为左节点
		{
			left->data = min;
			left->leftchild = NULL;
			left->rightchild = NULL;
			p->data = min + root->data;
			Initiate(&p->leftchild);
			Initiate(&p->rightchild);
			p->leftchild = left;
			p->rightchild = root;
			root = p;
		}
		else
		{
			right->data = min;
			right->leftchild = NULL;
			right->rightchild = NULL;
			p->data = min + root->data;
			Initiate(&p->leftchild);
			Initiate(&p->rightchild);
			p->leftchild = root;
			p->rightchild = right;
			root = p;
		}
		Initiate(&p);
	}
	num = n - 1;
	p = root;
	printf("哈夫曼树如下图:\n");
	while (num)
	{
		if (num == n - 1)
		{
			for (j = 0; j < k - 3; j++)
				printf(" ");
			printf("%d\n", root->data);
		}
		for (j = 0; j < k - 4; j++)
			printf(" ");
		printf("/  \\\n");
		for (j = 0; j < k - 5; j++)
			printf(" ");
		printf("%d", root->leftchild->data);
		printf("   %d\n", root->rightchild->data);
		if (root->leftchild->leftchild != NULL)
		{
			root = root->leftchild;
			k = k - 2;
		}
		else
		{
			root = root->rightchild;
			k = k + 3;
		}
		num--;
	}
	num = n - 1;
	Initiate(&root);
	root = p;
	printf("各字符对应的编码如下:\n");
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
}
