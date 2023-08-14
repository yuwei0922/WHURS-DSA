#include <iostream>
using namespace std;

//Reverse a Linked List using Recursion

//�ṹ�嶨��
struct tag_Stu
{
	int nAge;
	struct tag_Stu* next;
};
typedef struct tag_Stu Stu;

//��������
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

//�������
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

//��ת����
Stu* reverse(Stu* pH)
{
	if (pH->next == NULL)
	{
		Stu* pH2 = new Stu();
		pH2->next = pH;
		return pH2;
	}
	Stu* newH = reverse(pH->next);//һֱѭ��������ĩβ
	pH->next->next = pH;//��תÿ���ڵ��ָ��
	pH->next = NULL;

	return newH;
}

int main()
{
	cout << "��������" << endl;
	Stu* pH = CreateLinker();
	OutPut(pH);
	cout << endl;

	pH = reverse(pH->next);
	cout << "����ת�����" << endl;
	OutPut(pH);
	cout << endl;
	delete pH;
	pH = NULL;
	return 0;
}