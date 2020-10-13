#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;

void reverse(node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	node* prev = NULL;
	node* pcur = head->next;
	node* next;
	while (pcur != NULL)
	{
		if (pcur->next == NULL)
		{
			pcur->next = prev;
			break;
		}

		next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}

	head->next = pcur;
	node* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main
{


	system("pause");
	return 0;
}