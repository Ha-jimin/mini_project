typedef struct{
    char name[20];
    char explain[100];
    char weight[10];
    int price;
    int packway;
}Product;


int addProduct(Product *p);//제품을 등록하는 함수
//제품의 이름, 제품 설명, 제품 중량, 판매가격, 배송방법 입력
int readProduct(Product p); // 하나의 제품 출력 함수
//전달받은 인자의 제품 설명을 출력한다.
int listProduct(Product *p[], int count);//전체 제품을 출력하는 함수
//변수 count에 저장되어 있는 제품의 개수만큼 리스트 출력
void buyProduct(Product *p[], int count);//소비자가 제품을 사게 하는 함수
//함수 listProduct를 통해서 소비자가 전체 나열된 제품을 보고
//마음에 드는 제품을 선택한다. 그 번호에 해당하는 제품을 선택하고 구매 여부를 결정함
void searchName(Product *p[], int count);//제품검색 함수
//이용자가 제품의 이름을 검색하고 이미 등록된 제품의 이름과 입력된 제품의 이름을 비교한다
void searchPrice(Product *p[], int count);//제품 가격 검색 함수
//이용자가 제품의 가격을 검색하고 이미 등록된 제품의 가격과 입력된 제품의 가격을 비교한다
void searchPackway(Product *p[], int count);//제품 배송방법 검색 함수
//이용자가 제품의 배송방법을 검색하고 이미 등록된 제품의 배송방법과 입력된 제품의 배송방법을 비교한다.
int loaddata(Product *p[]);//파일에 있는 데이타를 불러오는 함수
//파일을 열고 파일 안에 데이타가 있다면 데이타를 불러오기 없다면 "파일없음!" 출력
int saveData(Product *p[], int count);//파일에 데이타를 저장하는 함수
//파일을 열고 파일 안에 struct에 있는 정보 저장

