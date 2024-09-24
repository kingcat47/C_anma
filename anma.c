//생각한 배경.
//추석에 할머니집을 오게되었음.
//안마기계가 있는데 오시는 어르신들이 다들 사용하심.
//작동 방식을 생각해보다 컴퓨터 시스템 일반 시간에 배웠던 스케쥴링 방법이 생각남.
//그중에 선점형과 비선점형이 있는데 만약 선점형이라면 이런식으로 작동하지 않을까~ 하고 생각하면서 만든문제
//실제로는 무슨 운동할때 세트도는것처럼 선택하는 거였지만 만들어봄.

//중복되는 문제를 찾아봤지만 백준에서 우선순위 스케쥴링 문제만 있고 선점형 스케쥴링 문제는 없어서 겹치는게 없다고 생각하고 제출함(2024-9-17)
//이 문제에서 확인하는 목록은
//0.우선순위에 따라 선점형으로 실행하는 작동방식을 이해했는가
//1. 숫자형,문자형 리스트
//2. 내림차순 정렬
//3. 그외 간단한 입출력과 함수 호출
//3점 정도 된다고 생각한다.

//몸 여러군데 피로도를 입력받아 가장 피로도가 높은 곳 부터 차례대로 안마를 시작하는 기계
//기계는 한번에 3군데를 안마하고 피로도 5를 줄여줌
//끝난후에는 다시 피로도가 높은순서를 배열하고 안마시작
//모든 부위의 피로도가 0이면 실행종료

// 어깨 등 팔 다리 손 발 등등

#include <stdio.h>

char *list[] = {"어깨", "등", "팔", "다리", "손", "발"};
int piro_list[6];
int count = 1;

// 함수가 서로 호출하기 때문에 서로 저 함수 없는데 왜 호출하냐고 해서 처음부분에 선언을 추가해줌줌
void jung(int size);
void anma(int size);

void jung(int size) {  // 정렬
    int temp;
    char *list_temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (piro_list[j] < piro_list[j + 1]) {  // 내림차순 정렬
                // 피로
                temp = piro_list[j];
                piro_list[j] = piro_list[j + 1];
                piro_list[j + 1] = temp;

                // 신체
                list_temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = list_temp;
            }
        }
    }
    anma(size);  // 정렬 후 안마 시작
}

void anma(int size) {  // 안마마
    int check = 0;
    printf("%d번째 안마\n", count++);
    printf("안마할 부위와 피로도:\n");

    // 3군데를 안마하고 피로도 5 감소
    for (int i = 0; i < 3 && i < size; i++) {
        piro_list[i] -= 5;
        if (piro_list[i] < 0) {
            piro_list[i] = 0;
        }
        printf("%s 피로도: %d  ", list[i], piro_list[i]);
    }
    printf("\n");

    // 피로도가 남아있는지 확인
    for (int i = 0; i < size; i++) {
        if (piro_list[i] > 0) {
            check++;
            //printf("check: %d  ",check);
        }
    }

    if (check > 0) {
        jung(size);  // 피로도가 남아있으면 다시 정렬 및 안마
    } else {
        printf("안마가 끝났습니다.\n");
    }
}

void piro(int size) {  // 피로도 입력
    printf("피로도를 입력하세요\n");
    for (int i = 0; i < size; i++) {  // 수정: i < size로 변경
        printf("%s의 피로도: ", list[i]);
        scanf("%d", &piro_list[i]);  // &를 붙여서 주소를 전달
    }
    jung(size);  // 피로도 입력 후 정렬 및 안마 시작
}

int main() {  // 메인
    int size = sizeof(list) / sizeof(list[0]);
    piro(size);  // 피로도 입력 및 안마 시작
    return 0;
}





//테스트 케이스