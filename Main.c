#include "Mat.h"
#include "Util.h"

int main(void){
	FILE *matFile;							//파일포인터
	int i = 0, count = 0;		
	int choice=0;
	int * pcount = &count;
	int changeContents=0;
	char save='x';

	matPtr = (Mat*)malloc(sizeof(Mat) * 50);	//맛포인터 동적할당

	if (matPtr == NULL){						//예외처리
		printf("memory allocation error\n");
		exit(-1);
	}

	matFile = fopen("Mat.txt", "rt");			//텍스트파일 열기
	if (matFile == NULL){
		puts("입력파일 에러");
		exit(-1);
	}

	while (fscanf(matFile, "%s %s %s %d", matPtr[i].name, matPtr[i].location,
		matPtr[i].representMenu, &matPtr[i].price) != EOF){	//문서 끝까지 읽기

		i++;
		count++;
	}


	fclose(matFile);									//파일 닫기

	printf("\n     　 ˚　　　　　。\n     ┏━△━━━△━┓\n     ┃　　　　　　※┃\n     ┃　━　　　━　┃       맛을 (+)하다. <<Mat!>>\n     ┃　　　,.　　　┃\n     ┃☞* ┳┳┳ *☜┃\n     ┃　　┃┃┃　　┃\n     ┗━━┃┃┃━━┛\n     　　♪┗━┛\n");
	printf("\n");

	while (choice != 4){
		printf("|    1.맛들...    |     2.맛 검색!     |     3.맛 추가~     |    4.맛 그만X    |\n");
		printf("\n\n                           선택해주세요: ");
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
			printf("1~6사이에서 선택~!\n");
			break;

		}
	}
	
	if (changeContents != 0){
		while (save != 'Y' && save != 'y' && save != 'N' && save != 'n'){
			printf("\n변경된 내용이 있습니다. 저장하시겠습니까? Y/N : ");
			scanf("%c", &save);
		}

		if (save == 'Y' || save =='y'){
			matFile = fopen("Mat.txt", "w");			//텍스트파일 열기
			if (matFile == NULL){
				puts("입력파일 에러");
				exit(-1);
			}
			
			for (i = 0; i < count; i++){
				fprintf(matFile, "%s %s %s %d\n", matPtr[i].name, matPtr[i].location,
					matPtr[i].representMenu, matPtr[i].price);
			}
		}
		else if (save == 'N' || save == 'n'){
			printf("\n저장하지 않고 종료합니다.\n");
		}
	}
	free(matPtr);
	printf("------------------맛을 종료합니다-----------------------\n");
}

