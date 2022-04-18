#include "manager.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int addProduct(Product *p){
    printf("제품명? ");;
    scanf("%s", p->name);
    printf("제품 설명? ");
    getchar();
    fgets(p->explain, 20 , stdin);
    p->explain[strlen(p->explain)-1]='\0';
    printf("제품 중량?");
    scanf("%s", p->weight);
    printf("판매 가격? ");
    scanf("%d", &p->price);
    printf("배송 방법? ");
    scanf("%d", &p->packway);

    return 1;
    }//제품을 등록하는 함수


int readProduct(Product p){
    if(p.packway == 1)
        printf("%s /%s /%s/ %d/ 새벽배송\n", p.name, p.explain, p.weight, p.price);
    else
        printf("%s /%s /%s/ %d/ 택배배송\n", p.name, p.explain, p.weight, p.price);

    return 1;
    }// 하나의 제품 출력 함수


int listProduct(Product *p[], int count){
  
    #ifdef DEBUG
    printf("DEBUG\n");
    #endif
    printf("이름 / 설명 / 중량 / 가격 / 배송방법\n");
    printf("================================\n");
    for(int i = 0; i < count; i++){
        if(p[i] == NULL){
            continue;
        }
        printf("%2d", i+1);
        readProduct(*p[i]);
    }
    printf("\n");
    return 1;
    }//전체 제품을 출력하는 함수



int loaddata(Product *p[]){
    //int count = 0;
    #ifdef DEBUG
    printf("DEBUG\n");
    #endif
    int count = 0;
    int i = 0;
    int size;
    FILE *fp;
    fp = fopen("product.txt", "r");
    if(fp == NULL){
        printf("파일없음! \n");
        return 0;
    }else{
        for(; i < 100; i++){
        char pack[10];
        if(feof(fp))break;
	count ++;
        p[i] = (Product *)malloc(sizeof(Product));
        fscanf(fp, "%s", p[i]->name);
	fscanf(fp, "%d", &size);
	int sizes = size+1;
        fgets(p[i]->explain, sizes, fp);
	fscanf(fp, "%s", p[i]->weight);
        fscanf(fp, "%d", &p[i]->price);
        fscanf(fp, "%s", pack);
        fscanf(fp, "%d", &p[i]->packway);
        printf("%s %s %s %d %s\n", p[i]->name, p[i]->explain, p[i]->weight, p[i]->price, pack );
        
    }
    //int ret = 
    fclose(fp);
    printf("=>로딩완료!\n");
    return count;
    }
}

int saveData(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i < count; i++){
        if(p[i] == NULL)continue;
        else{
	int length = strlen(p[i]->explain);
        if(p[i]->packway == 1)
        fprintf(fp, "%s %d %s %s %d 새벽배송 %d\n", p[i]->name,length, p[i]->explain, p[i]->weight, p[i]->price, p[i]->packway);
    else
        fprintf(fp, "%s %d %s %s %d 택배배송 %d\n", p[i]->name,length, p[i]->explain, p[i]->weight, p[i]->price, p[i]->packway);
    }
    }
    fclose(fp);
    printf("=> 저장완료! \n");
    return 1;
}

void searchName(Product *p[], int count){
    int scnt = 0;
    char search[20];
    //char names[20];

    printf("제품 이름은? ");
    getchar();
    fgets(search, 20, stdin);
    search[strlen(search)-1] = '\0';
    
    printf("\n\n");
    printf("================================\n");
    for(int i = 0; i < count ; i++){
        if(p[i] == NULL)continue;
        if(strstr (p[i]->name, search)){
            printf("%2d", i+1);
            readProduct(*p[i]);
            scnt++;
        }
    }
    
    if(scnt == 0)printf("=> 제품이 없습니다!");
    printf("\n");
}

void searchPrice(Product *p[], int count){
    int scnt = 0;
    char search[20];
    //char names[20];
    int num;

    printf("제품 이름은? ");
    getchar();
    fgets(search, 20, stdin);
    search[strlen(search)-1] = '\0';
    
    printf("\n\n");
    printf("================================\n");
    for(int i = 0; i < count ; i++){
        if(p[i] == NULL)continue;
        if(strstr (p[i]->name, search)){
            num = i;
            printf("%2d", i+1);
            readProduct(*p[i]);
            scnt++;
        }
    }

    printf("제품의 가격은 %d원 입니다.\n", p[num]->price);
    
    if(scnt == 0)printf("=> 제품이 없습니다!\n");
    printf("\n");
}

void searchPackway(Product *p[], int count){
    int scnt = 0;
    char search[20];
    //char names[20];
    int num;

    printf("제품 이름은? ");
    getchar();
    fgets(search, 20, stdin);
    search[strlen(search)-1] = '\0';
    
    printf("\n\n");
    printf("================================\n");
    for(int i = 0; i < count ; i++){
        if(p[i] == NULL)continue;
        if(strstr (p[i]->name, search)){
            num = i;
            printf("%2d", i+1);
            readProduct(*p[i]);
            scnt++;
        }
    }

    if(p[num]->packway == 1){
        printf("제품의 배송방법은 새벽배송입니다.\n");
    }else{
        printf("제품의 배송방법은 택배배송입니다.\n");
    }
    
    if(scnt == 0)printf("=> 제품이 없습니다!");
    printf("\n");
}
