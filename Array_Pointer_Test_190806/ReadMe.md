### 아이디 중복 시스템을 짜보자.

> 입력: 아이디 입력

> [조건]

1. 아이디는 `30자 이내` 로 작성해야 한다.
1. 만약 입력된 아이디가 현재 저장된 아이디라면 다시 입력 받아야 한다.
1. 아이디의 첫 문자로는 `특수문자` 가 올 수 없다.
1. 아이디는 대문자 1개 이상, 특수문자 포함 1개이상, 숫자 1개 이상으로 해야 한다.
1. 만약 위의 조건들에 만족된다면 아이디를 저장한다.
1. 아이디 저장 시 숫자, 알파벳 대문자, 알파벳 소문자 순으로 저장한다.
1. 아이디를 수정한다면 다시 수정된 저장소에 대한 정렬을 진행


> [입력 커맨드]

1. 입력
1. 아이디 명단 출력
1. 아이디 조회
1. 아이디 수정


> 주요 동작 함수

```c

/*Functions*/
void Init(ID_DB* list, int size); /* 초기화 */
int Is_Full(ID_DB* list); /* ID를 저장할 공간에 크기에 대한 검사 */
int Is_ID_Duplicated(ID_DB* list, const char* str); /* ID 중복 검사 */
int Validate_ID(const char* str, int size); /* 아이디 형식 검사(첫 글자 특수문자X, 영어 - 대문자, 소문자, 숫자 등) */
int Get_ID(char* str); /* 입력 함수 */
int Input_ID(ID_DB* list); /* 전체 입력 함수 (ID에 대한 검사 및 입력, 저장) */
int Compare_ID(const void* v1, const void* v2); /* qsort 용 비교 함수 */
void View_ID(ID_DB* list); /* 출력 함수 */

//Test the system
void Test_ID_SYS(); /* 시스템 테스트 함수 */

```

