#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Mat.h"

void readMat(Mat* matPtr, int count){		//맛 List
	int j = 0;
	
	for (j = 0; j < count; j++){
		if (strstr(matPtr[j].name , "#deleted")==0){
			printf("\n맛 이름: %s\n", matPtr[j].name);
			printf("\n맛 위치: %s\n", matPtr[j].location);
			printf("\n맛 대표 메뉴: %s\n", matPtr[j].representMenu);
			printf("\n맛 가격: %d\n", matPtr[j].price);
			printf("\n\n---------------------------------------------------------------------------\n");

		}
	}
}

void updateMat(Mat* matPtr, int hang, char search[10]){

	int updateChoice = 1;
	int hangcount = 0;
	int k, l=0;

	if (hang > 1){
		printf("\n검색결과가 여러개입니다. 몇 번째 맛인지 선택해주세요: ");
		scanf("%d", &updateChoice);
		while (updateChoice < 0 || updateChoice > hang){
			printf("\n검색 결과 중에 몇번째 맛인지 선택해주세요: ");
			scanf("%d", &updateChoice);
		}
	}

	
	for (k = 0; l<updateChoice; k++){
		if (strstr(matPtr[k].name, search) != 0 ||	//가게 이름, 장소, 메뉴로 검색가능
			strstr(matPtr[k].location, search) != 0 ||
			strstr(matPtr[k].representMenu, search) != 0){
			l++;
		}
	}
		
	k--;

	printf("\n맛 이름: %s\n", matPtr[k].name);
	printf("수정할 맛 이름: ");
	scanf("%s", matPtr[k].name);

	printf("\n맛 위치: %s\n", matPtr[k].location);
	printf("수정할 맛 위치: ");
	scanf("%s", matPtr[k].location);

	printf("\n맛 대표 메뉴: %s\n", matPtr[k].representMenu);
	printf("수정할 맛 대표 메뉴: ");
	scanf("%s", matPtr[k].representMenu);

	printf("\n맛 가격: %d\n", matPtr[k].price);
	printf("수정할 맛 가격: ");
	scanf("%d", &(matPtr[k].price));
	printf("\n\n---------------------------------------------------------------------------\n");

}

void deleteMat(Mat* matPtr, int hang, char search[10]){

	int updateChoice = 1;
	int hangcount = 0;
	int k, l = 0;

	if (hang > 1){
		printf("\n검색결과가 여러개입니다. 몇 번째 맛인지 선택해주세요: ");
		scanf("%d", &updateChoice);
		while (updateChoice < 0 || updateChoice > hang){
			printf("\n검색 결과 중에 몇번째 맛인지 선택해주세요: ");
			scanf("%d", &updateChoice);
		}
	}

	
	for (k = 0; l<updateChoice; k++){
		if (strstr(matPtr[k].name, search) != 0 ||	//가게 이름, 장소, 메뉴로 검색가능
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

	printf("\n\n\n                  어떤 맛을 찾으시나요?");
	gets_s(search, sizeof(search));

	for (j = 0; j < count; j++){

		if (strstr(matPtr[j].name, search) != 0 ||	//가게 이름, 장소, 메뉴로 검색가능
			strstr(matPtr[j].location, search) != 0 ||
			strstr(matPtr[j].representMenu, search) != 0){

			printf("\n맛 이름: %s\n", matPtr[j].name);
			printf("\n맛 위치: %s\n", matPtr[j].location);
			printf("\n맛 대표 메뉴: %s\n", matPtr[j].representMenu);
			printf("\n맛 가격: %d\n", matPtr[j].price);
			printf("\n---------------------------------------------------------------------------\n\n");
			hang++;
		}
	}
	while (whatToDo != 1){
		printf("|     1.나가기      |      2.맛 수정      |      3.맛 삭제      |\n\n");
		scanf("%d", &whatToDo);
		switch (whatToDo){
		case 1:
			printf("메인 화면으로 돌아갑니다.\n");
			break;
		case 2:
			printf("\n검색된 맛을 수정합니다.\n");
			updateMat(matPtr, hang, search);
			(*changeContents)++;
			break;
		case 3:
			printf("\n검색된 맛을 삭제합니다.\n");
			deleteMat(matPtr, hang, search);
			(*changeContents)++;
			break;
		}

	}
}
	void writeMat(Mat* matPtr, int* pcount, int* changeContents){		//맛 추가
		int j;

		printf("\n\n\n                           맛을 추가합니다...!              \n");

		for (j = 0; j < *pcount; j++){
			if (strstr(matPtr[j].name, "#deleted") != 0){
				break;
			}
		}

		printf("\n\n\n맛 이름: ");
		gets_s(matPtr[j].name, sizeof(matPtr[j].name));
		fflush(stdin);

		printf("\n맛 위치: ");
		gets_s(matPtr[j].location, sizeof(matPtr[j].location));
		fflush(stdin);

		printf("\n맛 대표 메뉴: ");
		gets_s(matPtr[j].representMenu, sizeof(matPtr[j].representMenu));
		fflush(stdin);

		printf("\n맛 가격: ");
		scanf_s("%d", &(matPtr[j].price));
		fflush(stdin);

		printf("\n\n입력하신 맛이 등록되었습니다!\n\n");

		if (*pcount <= j){
			*pcount = j + 1;
		}
		(*changeContents)++;
	}




