#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;

void Input_Packet(PACKET* p)
{
	scanf("%d %d",&p->packet_no,&p->prior_level); // packet_no, prior_level �Է�
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer(PACKET* p)
{
	PACKET *pac;
	PACKET *cur;

	pac = (PACKET*)malloc(sizeof(PACKET));
	*pac = *p;
	
	cur = &buffer;
	while (cur->next != (PACKET*)0)
	{
		if (cur->next->prior_level > pac->prior_level) break;
		else cur = cur->next;
	}

	pac->next = cur->next;
	cur->next = pac;

	return SUCCESS;
}

int Get_Packet_from_Buffer(PACKET* p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	*p = *buffer.next;
	free(buffer.next);

	buffer.next = p->next;
	
	return SUCCESS;
}

int main(void)
{
	int i,N;
	PACKET packet;

	scanf("%d", &N);	// ��Ŷ�� �� �Է�
	
	packet.next = NULL;
	// ��Ŷ�� ����
	for (i = 0; i < N; i++)
	{
		Input_Packet(&packet);
		Put_Packet_to_Buffer(&packet);
	}
	
	// ��Ŷ ó������ ���
	while (Get_Packet_from_Buffer(&packet) == SUCCESS)
	{
		printf("%d ", packet.packet_no);
	}

	return 0;
}
