#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Mat.h"

void readMat(Mat* matPtr, int count){		//�� List
	int j = 0;
	
	for (j = 0; j < count; j++){
		if (strstr(matPtr[j].name , "#deleted")==0){
			printf("\n�� �̸�: %s\n", matPtr[j].name);
			printf("\n�� ��ġ: %s\n", matPtr[j].location);
			printf("\n�� ��ǥ �޴�: %s\n", matPtr[j].representMenu);
			printf("\n�� ����: %d\n", matPtr[j].price);
			printf("\n\n---------------------------------------------------------------------------\n");

		}
	}
}

void updateMat(Mat* matPtr, int hang, char search[10]){

	int updateChoice = 1;
	int hangcount = 0;
	int k, l=0;

	if (hang > 1){
		printf("\n�˻������ �������Դϴ�. �� ��° ������ �������ּ���: ");
		scanf("%d", &updateChoice);
		while (updateChoice < 0 || updateChoice > hang){
			printf("\n�˻� ��� �߿� ���° ������ �������ּ���: ");
			scanf("%d", &updateChoice);
		}
	}

	
	for (k = 0; l<updateChoice; k++){
		if (strstr(matPtr[k].name, search) != 0 ||	//���� �̸�, ���, �޴��� �˻�����
			strstr(matPtr[k].location, search) != 0 ||
			strstr(matPtr[k].representMenu, search) != 0){
			l++;
		}
	}
		
	k--;

	printf("\n�� �̸�: %s\n", matPtr[k].name);
	printf("������ �� �̸�: ");
	scanf("%s", matPtr[k].name);

	printf("\n�� ��ġ: %s\n", matPtr[k].location);
	printf("������ �� ��ġ: ");
	scanf("%s", matPtr[k].location);

	printf("\n�� ��ǥ �޴�: %s\n", matPtr[k].representMenu);
	printf("������ �� ��ǥ �޴�: ");
	scanf("%s", matPtr[k].representMenu);

	printf("\n�� ����: %d\n", matPtr[k].price);
	printf("������ �� ����: ");
	scanf("%d", &(matPtr[k].price));
	printf("\n\n---------------------------------------------------------------------------\n");

}

void deleteMat(Mat* matPtr, int hang, char search[10]){

	int updateChoice = 1;
	int hangcount = 0;
	int k, l = 0;

	if (hang > 1){
		printf("\n�˻������ �������Դϴ�. �� ��° ������ �������ּ���: ");
		scanf("%d", &updateChoice);
		while (updateChoice < 0 || updateChoice > hang){
			printf("\n�˻� ��� �߿� ���° ������ �������ּ���: ");
			scanf("%d", &updateChoice);
		}
	}

	
	for (k = 0; l<updateChoice; k++){
		if (strstr(matPtr[k].name, search) != 0 ||	//���� �̸�, ���, �޴��� �˻�����
			strstr(matPtr[k].location, search) != 0 ||
			strstr(matPtr[k].representMenu, search) != 0){
			l++;
		}
	}

	k--;

	strcpy(matPtr[k].name , "#deleted");
	strcpy(matPtr[k].location , "#deleted");
	strcpy(matPtr[k].representMenu , "#deleted");
	strcpy(&matPtr[k].price , "#deleted");
	
	
	printf("\n\n---------------------------------------------------------------------------\n");


}


void searchMat(Mat* matPtr, int count, int* changeContents){
	int j;
	char search[10];
	int whatToDo = 0;
	int hang = 0;

	printf("\n\n\n                  � ���� ã���ó���?");
	gets_s(search, sizeof(search));

	for (j = 0; j < count; j++){

		if (strstr(matPtr[j].name, search) != 0 ||	//���� �̸�, ���, �޴��� �˻�����
			strstr(matPtr[j].location, search) != 0 ||
			strstr(matPtr[j].representMenu, search) != 0){

			printf("\n�� �̸�: %s\n", matPtr[j].name);
			printf("\n�� ��ġ: %s\n", matPtr[j].location);
			printf("\n�� ��ǥ �޴�: %s\n", matPtr[j].representMenu);
			printf("\n�� ����: %d\n", matPtr[j].price);
			printf("\n---------------------------------------------------------------------------\n\n");
			hang++;
		}
	}
	while (whatToDo != 1){
		printf("|     1.������      |      2.�� ����      |      3.�� ����      |\n\n");
		scanf("%d", &whatToDo);
		switch (whatToDo){
		case 1:
			printf("���� ȭ������ ���ư��ϴ�.\n");
			break;
		case 2:
			printf("\n�˻��� ���� �����մϴ�.\n");
			updateMat(matPtr, hang, search);
			(*changeContents)++;
			break;
		case 3:
			printf("\n�˻��� ���� �����մϴ�.\n");
			deleteMat(matPtr, hang, search);
			(*changeContents)++;
			break;
		}

	}
}
	void writeMat(Mat* matPtr, int* pcount, int* changeContents){		//�� �߰�
		int j;

		printf("\n\n\n                           ���� �߰��մϴ�...!              \n");

		for (j = 0; j < *pcount; j++){
			if (strstr(matPtr[j].name, "#deleted") != 0){
				break;
			}
		}

		printf("\n\n\n�� �̸�: ");
		gets_s(matPtr[j].name, sizeof(matPtr[j].name));
		fflush(stdin);

		printf("\n�� ��ġ: ");
		gets_s(matPtr[j].location, sizeof(matPtr[j].location));
		fflush(stdin);

		printf("\n�� ��ǥ �޴�: ");
		gets_s(matPtr[j].representMenu, sizeof(matPtr[j].representMenu));
		fflush(stdin);

		printf("\n�� ����: ");
		scanf_s("%d", &(matPtr[j].price));
		fflush(stdin);

		printf("\n\n�Է��Ͻ� ���� ��ϵǾ����ϴ�!\n\n");

		if (*pcount <= j){
			*pcount = j + 1;
		}
		(*changeContents)++;
	}




