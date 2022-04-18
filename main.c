#include "manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
 Product *p[100];
 int count = 0, menu;
 int index = 0;
 count = loaddata(p);
 index = count;
 while (1){
 printf("1. 제품 목록\n");
 printf("2. 제품 등록\n");
 printf("3. 제품 검색\n");
 printf("4. 제품 가격 검색\n");
 printf("5. 배송방법 검색\n");
printf("6. 파일 저장\n");
 printf("7. 제품 수정\n");
 scanf("%d", &menu);
 if (menu == 0) break;
 if(menu == 1 || menu == 3 || menu ==4)
 if(count == 0)continue;
 if (menu == 1){
 listProduct(p, index);
 }
 else if (menu == 2){
 p[index] = (Product *)malloc(sizeof(Product));
 count += addProduct(p[index++]);
 }
 else if (menu == 3){
 searchName(p, index);
 }
 else if (menu == 4){
 searchPrice(p, index);
 }
 else if (menu == 5){
 searchPackway(p, index);
 }
 else if (menu == 6){
 saveData(p, index);
 }
 else if (menu == 7){
 int no;
 listProduct(p, index);
 printf("수정할 제품 번호? ");
 scanf("%d", &no);
 addProduct(p[no-1]);
 }
 }
 printf("종료됨!\n");
 return 0;
}
