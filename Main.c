#include "Mat.h"
#include "Util.h"

int main(void){
	FILE *matFile;							//����������
	int i = 0, count = 0;		
	int choice=0;
	int * pcount = &count;
	int changeContents=0;
	char save='x';

	matPtr = (Mat*)malloc(sizeof(Mat) * 50);	//�������� �����Ҵ�

	if (matPtr == NULL){						//����ó��
		printf("memory allocation error\n");
		exit(-1);
	}

	matFile = fopen("Mat.txt", "rt");			//�ؽ�Ʈ���� ����
	if (matFile == NULL){
		puts("�Է����� ����");
		exit(-1);
	}

	while (fscanf(matFile, "%s %s %s %d", matPtr[i].name, matPtr[i].location,
		matPtr[i].representMenu, &matPtr[i].price) != EOF){	//���� ������ �б�

		i++;
		count++;
	}


	fclose(matFile);									//���� �ݱ�

	printf("\n     �� ��������������\n     �����⦬�����⦬��\n     ���������������ئ�\n     ������������������       ���� (+)�ϴ�. <<Mat!>>\n     ��������,.��������\n     ����* ������ *�Ц�\n     ������������������\n     ������������������\n     �����ܦ�����\n");
	printf("\n");

	while (choice != 4){
		printf("|    1.����...    |     2.�� �˻�!     |     3.�� �߰�~     |    4.�� �׸�X    |\n");
		printf("\n\n                           �������ּ���: ");
		scanf_s("%d", &choice);
		fflush(stdin);

		switch (choice){
		case 1:
			readMat(matPtr, count);
			break;
		case 2:
			searchMat(matPtr, count, &changeContents);
			break;
		case 3:
			writeMat(matPtr, pcount, &changeContents);
			break;
		case 4:
			printf("\n\n");
			break;
		default:
			printf("1~6���̿��� ����~!\n");
			break;

		}
	}
	
	if (changeContents != 0){
		while (save != 'Y' && save != 'y' && save != 'N' && save != 'n'){
			printf("\n����� ������ �ֽ��ϴ�. �����Ͻðڽ��ϱ�? Y/N : ");
			scanf("%c", &save);
		}

		if (save == 'Y' || save =='y'){
			matFile = fopen("Mat.txt", "w");			//�ؽ�Ʈ���� ����
			if (matFile == NULL){
				puts("�Է����� ����");
				exit(-1);
			}
			
			for (i = 0; i < count; i++){
				fprintf(matFile, "%s %s %s %d\n", matPtr[i].name, matPtr[i].location,
					matPtr[i].representMenu, matPtr[i].price);
			}
		}
		else if (save == 'N' || save == 'n'){
			printf("\n�������� �ʰ� �����մϴ�.\n");
		}
	}
	free(matPtr);
	printf("------------------���� �����մϴ�-----------------------\n");
}

