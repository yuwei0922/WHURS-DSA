#include <iostream>
using namespace std;

//Reverse a Linked List using Recursion

//结构体定义
struct tag_Stu
{
	int nAge;
	struct tag_Stu* next;
};
typedef struct tag_Stu Stu;

//创建链表
Stu* CreateLinker()
{
	Stu* pH = new Stu();
	Stu* pRetH = pH;
	for (int i = 0; i < 10; i++)
	{
		Stu* pT = new Stu();
		pT->nAge = 10 - i;
		pT->next = NULL;
		pH->next = pT;
		pH = pH->next;
	}
	return pRetH;
}

//输出链表
void OutPut(Stu* pH)
{
	if (pH == NULL)
		return;
	pH = pH->next;
	while (pH != NULL)
	{
		cout << pH->nAge << " ";
		pH = pH->next;
	}
}

//翻转链表
Stu* reverse(Stu* pH)
{
	if (pH->next == NULL)
	{
		Stu* pH2 = new Stu();
		pH2->next = pH;
		return pH2;
	}
	Stu* newH = reverse(pH->next);//一直循环到链表末尾
	pH->next->next = pH;//反转每个节点的指向
	pH->next = NULL;

	return newH;
}

int main()
{
	cout << "创建链表：" << endl;
	Stu* pH = CreateLinker();
	OutPut(pH);
	cout << endl;

	pH = reverse(pH->next);
	cout << "链表翻转结果：" << endl;
	OutPut(pH);
	cout << endl;
	delete pH;
	pH = NULL;
	return 0;
}