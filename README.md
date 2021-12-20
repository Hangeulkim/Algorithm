# Algorithm
<pre>
2020
6/22
acm craft- 위상 정렬의 한 파트 공부
무한_수열 - dp의 살짝 응용
키로거 - 자료구조 list사용 erase와 insert는 n^2이다.
dp는 동일한 문제를 한 번만 풀도록 하는 알고리즘 이다.

6/23
내리막길-dp dfs 살짝 응용
점프 - dp dfs 기초
차이를 최소로 - binary search 응용

6/24
테트로미노 - 브루트 포스 dfs로도 할 수 있으나 문제 분류에 맞춰서 풀음 나중에 dfs로 한번 해볼것
일곱 난쟁이 - dfs로 해결함
LCS - 단순 dp 응용
LCS2 - 배열에 저장하여 길이를 찾는 것 까진 쉬웠으나 문자열을 찾는 것에 조금 고생
gcd합 - 브루트 포스

6/25
단순 next_permutation과  prev_permutation을 응용한 브루트 포스 문제들

6/26
암호_만들기, 연산자_끼워넣기_2 - permutation으로 해결하려다가 시간이 좀 오래 걸렸다. 브루트 포스의 경우는 dfs로 하는 연습을 해야겠다.
집합 - map으로 하려다 배열로 더 간단하게 할 수 있을거 같아 배열로 했다.
퇴사 - 단순 브루트 포스 문제였다.

6/27
브루트 포스 N과M 문제
생각보다 다양한 탐색 방법이 있다는 걸 느겼다.

6/28
연결_요소의_개수 -  단순 dfs인데 강한 연결 요소를 너무 복잡하게 생각하다 보니 오래 걸림.
ABCDE, 이모티콘, 섬의_개수, 숨바꼭질_3 - 단순 탐색 문제 이지만 조건을 중간중간 잘못 넣어서 시간이 좀 걸림
이분_그래프 - 그래프를 양분화에 대한 걸 생각해보게됨

6/29
알고스팟, 탈출 - bfs 살짝 응용
123_더하기_5, 카드_구매하기_2, 스티커 - 기본 적인 2차원, 1차원 dp

6/30
부분_수열 문제들, 연속합2 - dp의 이전항과 관련한 기본적인 활용

7/1
제곱수의_합, 합분해 - 2차원 dp 살짝 응용 이었으나 3중 포문을 만드는 것 때문에 오래걸림.
수_이어_쓰기, 리모컨 - 브루트 포스 응용 단순 브루트 포스 이지만 아이디어를 찾고 이해하는데 오래 걸림

7/2
맞춰봐, 단어_수학, 알파벳 - 아직 단순 구현 쪽의 숙련도가 많이 부족하여 브루트 포스 문제를 해결하는데 상당한 시간이 걸린다.

7/3
수들의_합_2 - 단순 투포인터 알고리즘 문제

7/4
가르침, 종이_조각 - 브루트포스 구현 문제, 가르침의 경우 단순 dfs로 할 수 있어 금방 생각 났지만 종이 조각의 경우 가로 세로 구분과 그 길이를 정하는 것 때문에 상당한 시간이 걸렸다. 단순 구현 문제를 연습을 더 해야 할 것 같다.

7/5
부분합 - 단순 투포인터 문제
부분수열의_합_2 - 시간 초과를 의식해야 하는 브루트포스 dfs응용 문제 처음엔 맵을 사용하여 시간이 너무 오래걸려 더 좋은 코드를 찾으니 배열을 사용하는 방법이 있었다.
구슬_탈출_2 - 단순 bfs를 이용한 브루트 포스 였지만 10이상이라는 말에 낚여 cnt를 cnt>10조건으로 탈출하게 한 것이 문제였다. 10이상이면 10일때 탈출을 못한순간 한번더 움직여야 하므로 =이 들어가 탈출하게 해야하는걸 늦게 발견했다.

7/6
숨바꼭질_4 - 추적하는 bfs 이전에 이런 비슷한 문제를 풀어 본적이 있어 그것에 대한 복습이 되었다.

7/7
2048_easy - 단순히 이동시키며 합을 구하는 dfs 브루트 포스 문제 현재 위치의 visit의 체크 조건을 빼먹는 바람에 오래걸림
두_배열의_합 - 계산했을때 long long가 나올수 있다는 점을 간과하고 캐스팅을 해주지 않아 거기에서 막혔었음
합이_0인_네_정수 - map을 사용 하였으나 시간초과가 나와 vector에 값을 넣고 정렬한 뒤 찾는 방식을 사용함

7/8
물통 - c에 0 이 있는 경우를 빼고 생각해서 중간에 찾느라 오래 걸렸다...

7/9
DSLR-메모리나 시간 초과 때문에 고민 을 좀 했다.  스트링 방식이 아닌 2비트 데이터로 비트마스킹 방식으로 하여 dslr을 구분하면 아마 조금 더 빠르지 않을까 생각해보고 구현하려 했지만 비트마스킹을 하다 오류가 나서 결국 잡지 못했다... 비트마스킹 관련 문제도 풀어 볼 것.

7/10
숨바꼭질_2 - visit배열을 새로운 방식으로 사용한 bfs문제
퍼즐 - bfs

7/11
점프_게임 - 2차원 방문 배열 bfs

7/12
탈옥 - 다차원 dp를 처음 접했을때 처럼 이런 방식의 bfs 탐색문제는 처음 접해서 더욱 어려웠던 것 같다. 기본 메커니즘은 사실 bfs와 다를바가 없지만 여러 좌표에서 bfs를 동시방문하는 방식은 처음 보게되어 굉장히 오래 걸린 것 같다.

7/13
열쇠 - 어제 푼 탈옥의 방식을 살짝 응용 한 문제 잘 기억해 둘 것

7/14
이동하기, 123_더하기_4 - 단순 2차원 dp 와 수학

7/15
로봇_청소기 - robot[0]에 무조건 적으로 로봇 청소기 위치가 안들어 가는 부분과 시작정이 로봇 청소기 위치가 되어야 한다는 걸 간과하여 오래 걸린 문제.  문제를 더 제대로 읽어 볼 것

7/16
레이저_통신 - 단순 2차원 bfs이나 세로 가로를 구분하여 이동한다는 점이 특이함

7/17
0과1 - 나머지에 대한 bfs라 떠올리기 쉽지 않았던 문제...

7/18
펠린드롬? - 예전에 한번 풀었었던 비슷한 문제의 테크닉을 응용하여 2차원 dp 에서의 이전 항 과의 비교만을 통해 연산 횟수를 줄였다.

7/19
동전2 - 단순 dp 문제

7/20
크리보드 - 1차원 dp

7/21
기타리스트 - bool을 이용한 2차원 dp

7/22
파일_합치기 - n^2의 방법이 있어서 연구해보다가 도저히 모르겠어서 보류한 문제. 나중에 다시한번 찾아 볼 것. -Kruth's optimization 알고리즘

7/23
평범한_배낭 - 예전에 알고리즘 수업때 그리디로 구현했던게 생각나 그리디로 했다가 문제 유형이 dp인걸보고 다시 구현 하였다.  메모리 초과가 날 줄 알았는데 생각보다 메모리가 상당히 큰 것 같다...

7/24
괄호 - 아무생각 없이 짯는데 알고보니 카탈란 수라는 개념이라고 한다. 이러한 유형에 대해 나중에 복습해 봐야 겠다.
1학년 - 단순 2차원 dp 이다.

7/25
D_ㄷㄷㄷㅈ - 단순 수학 계산 문제 이나  중간 연산이 값을 초과하는 것 때문에 여러번 틀림
G_루머 - bfs 탐색 문제 특별한 것을 없었던 것 같다.

7/26
주사위_굴리기 - 단순 구현 문제였으나 북쪽에서 몇칸과 같은 국어 문제로 인하여 오래 걸린 문제...

7/27
로봇_청소기, 톱니바퀴1, 2 - 단순 구현 시물레이션 문제

7/28
경사로 - 단순 구현 문제였으나 세부사항을 전부 찾는데에 오래걸림 숙련도 부족

7/29
뱀 - 단순 구현 시물레이션 문제 기본적인 뱀의 움직임은 쉽게 구현했으나 전부 움직인 이후의 카운트에서의 버그를 찾느라 오래걸림

7/30
드래곤_커브 - 무조건 우측으로만 도는줄 알았다가 이전 세대의 방향이 무조건 우측이 아닐수도 있다는 걸 알고 다시 구현하느라 시간이 걸린 문제 문제를 좀 제대로 읽을 것.

7/31
미네랄 - 공중에 떠있을때 아래 쪽의 클러스터가 떨어질 수 있다는 걸 늦게 생각해 오래걸린 문제 

8/2
링크와_스타트 - 단순 구현 브루트포스 문제

8/3
iSharp - 줄이라고 된게 예제로는 2줄짜리를 줘서 애매 했던 문제...

8/4
LCD_TEST, 연구소 - 단순 구현 문제

8/5
감시 - 단순 구현 문제였으나 cctv가 없는 경우에 대한걸 빠르게 생각하지 못함

8/6
숫자판_점프 - 단순 구현

8/7
사다리_조작 - y x구분이 문제마다 다 다르게 나와있어서 했갈렸던 문제 예제와 비교해가며 확인 할 것 

8/8
테트리스 - 단순 구현 문제

8/9
한윤정_아이스크림 - 단순 구현 문제

8/10
에너지_모으기 - 삭제했을때의 사이즈 변화를 제대로 신경 쓰지 않아서 시간이 걸림

8/11
부분수열의_합 - 단순 탐색 문제

8/12
두_동전 - 단순 구현 탐색 문제

8/13
자와_각도기 - 구현은 금방 했으나 예제를 보고 출력형식을 정해서 틀린 문제 예제가 불친절한 경우가 있으므로 문제를 제대로 확인해 볼 것

8/14
삼각형의_값 - 단순 1차원적인 탐색은 금방 하였으나 역삼각형에 대한 탐색에 막혀 답을 보고서야 알았다. 아직 탐색에 관한 개념이 완전히 잡히지 않은 것 같다.

8/15
양 - 단순 탐색 구현 문제

8/16
구슬_탈출_4 - 이전에 풀었던 구슬탈출2와 다른건 탈출시 횟수에 대한 조건 밖에 없는 것 같다.

8/17
돌_그룹 - 단순 구현 bfs 문제 -메모리 절약 때문에 살짝 막힘

8/18
퇴사_2 - 단순 1차원 dp 문제

8/19
스타트링크 - 단순 구현 bfs

8/20
말이_되고픈_원숭이 - 단순 bfs 구현 문제 경우의 수가 많아 최적화를 신경 썻는데 굳이 그렇게 하지 않았어도 통과는 됐을 것 같다.

8/21
적록색약 - 단순 구현 bfs

8/22
4연산 - 단순 visit배열을 string으로 선언하려다가 최대사이즈가 10억인걸 보고 map으로 바꿔서 구현한 단순 bfs 탐색 문제

8/23
거울_설치 - 단순 bfs 구현 이지만 거울이 있는 위치에서의 cnt갱신 때문에 문제가 생겨 구현에 시간이 걸림

8/24
알약 - dfs를 이용한 dp 문제 기억해 둘 것

8/25
과외맨 - 주어진 입력값을 그래프화 시킬 생각을 하질 못해 오래 걸린 문제 

8/26
벽_부수고_이동하기_2 - 단순 bfs 구현문제

8/27
백조의_호수 - bfs 문제 기초만 풀면서 bfs를 마스터 하였다고 생각 하였으나 유니온 파인드 응용이나 이분탐색 응용 같은 건 보이지도 않아서 단순 구현으로 풀어버렸다... 아직 공부할건 차고 넘친다

8/29
뮤탈리스크 - 삼성 코테에는 dfs나 탐색을 활용한 dp가 자주 나오는 것 같다. dp에 대한 개념을 잘 파악해야 할 것 같다.

8/30
새로운_하노이_탑 - 단순 구현 bfs문제 map에 스트링 3개를 어떤방식으로 넣을지에 대해 고민하다 struct 방식으로 할경우 따로 operator를 재정의 해줘야 하는 것을 보고 하나 로 합쳐서 비교하게 만들었다.

8/31
성곽 - 단순 구현 bfs 문제 아직도 구현은 어렵다...

9/1
견우와_직녀 - 단순 구현 bfs 다 구현 해놓고 jmp이후 절벽 체크와 오작교를 만들 수 없는 절벽들에 대한 조건 체크 에서 실수를 해서 오래 걸린 문제

9/2
출근_기록 - dp문제 라고 되어있었는데 그냥 단순 dfs로 풀어버린것 같다. 메모라이즈를 사용하여 이전에 사용했던 애들을 기록해서 dp 로 분류되는 것 같다. 생각보다 간단한 문제 였다.

9/3
acka - 단순 구현 메모이제이션 탐색 문제

9/4
플레이리스트 - 단순 수학 dp 문제

9/5
ABC - 메모이제이션 기반 문제 이제 조금씩 DFS를 활용한 메모이제이션이 보이기 시작했다.

9/7
사다리_게임 - 규칙 자체는 단순하였으나 dp에 구현이 섞여버리니 엄청 막막했다... 조금 더 분석이 필요 하다.

9/8
N_ROCK2 - dp 문제 자꾸 dp 문제를 탐색문제로 생각하고 구현에 집중하여 풀려고 하는 경향이 생긴 것 같다. 단순히 구현하려고 하기전에 식을 세우고 그림을 그려보는 연습이 필요 할 것 같다.

9/9
시험_감독 - 단순 구현 문제

9/10
무한_문자열 - 단순 구현 수학 문제 어차피 일정 부분 이후로는 겹치게 되므로 공통 길이 일때의 문자열을 확인해서 같은지 다른지 비교 시킴.

9/11
구간 합 구하기 4 - 단순 구현 부분합 문제

9/12
이항 계수 2 - 단순 모딩 연산으로 생각했다가 분모의 모드가 0이 될 수 있다는 걸 알고 파스칼을 사용 해야 한다는 걸 알았다...

9/14
A와 B - 처음엔 s부터 시작하는 dfs 메모이제이션으로 구현했으나 메모리초과로 인해 유형을 보니 구현이었다. 역으로 생각하면 쉬운 문제 였다.

9/15
AB - 이전에 푼 ABC와 동일한 문제

9/16
나머지 합 - 0일때 자기 자신이 들어오는 경우에 대해 제대로 파악하지 못해 오래걸린 문제.

9/17
책 페이지 - 단순 연산으로 구하려다가 새로운 방법이 있다는걸 보고 찾아봤다. 되게 특이하고 간단한 방식으로 구한다는 걸 보고 새로운 걸 알게 되었다.

9/18
사탕_게임 - 단순 구현 문제 자꾸 코드를 짧고 간결하게 짜려고 하다가 실수가 나와서 if문에 대한 &&조건 때문에 틀리게 된다. 세부사항을 제대로 따져보면서 해야 할 것 같다.

9/20
가장 큰 정사각형 - 단순 구현 문제 오랫만에 scanf를 썻더니 cin과 scanf를 자꾸 혼용하여 사용한다. scanf사용 에도 다시 익숙해져야 할 것 같다.

9/21
보드 완주하기 - 단순 구현 탐색 문제 들어오는 입력의 끝에 대한 정보가 없어서 그 부분에서 막혀서 여러번 틀렸다. 앞으론 cin의 반환값을 이용하자.

9/24
봄버맨 - 단순 구현 문제 일정한 패턴이 있어 단순 구현 말고 패턴으로도 풀수 있을 것 같다.

9/25
단어_뒤집기 - 단순 구현문제 cin또한 scanf와 동일하게 화이트 스페이스가 남음으로 주의!

9/27
수족관 1 - 단순 구현 문제

9/28
욕심쟁이 판다 - 단순 구현 메모이제이션 문제 cnt로 기록을 넘겼다가 +1하는 부분에서 문제가 생겨 조금 고생한 문제

10/8
단어_뒤집기_2 - 스도미노쿠의 구현의 박에 막혀서 휴식겸 간단한 구현 문제를 풀었다. 아직 복잡한 단순 구현은 어려운 것 같다.

10/9
오큰수 - 역순으로 구하는 건 금방 알았는데 그걸 현재순서에서 역으로 돌아가면서 구하는걸 생각 하는 것에 오래걸려서 막힌 문제

10/10
오등큰수 - 오큰수의 살짝 변화 버전 메커니즘상의 차이는 단순 숫자대신 그 숫자에 대한 카운트를 사용하는 것이 전부.

10/11
알파벳_개수 - 단순 구현

10/12
후위_표기식 - 스택 구현 문제 처음 코딩을 시작했을땐 정말 어려웠던 문제를 아무렇지 않게 구현하는 걸 보니 많이 발전한 것 같다.

10/13
문자열_분석 - 단순 구현 문제

10/14
네_수, ROT13, 접미사 배열, 단어 길이 재기 - 단순 구현 문제

10/15
팩토리얼, 팩토리얼 0의 개수, 조합 0의 개수 - 단순 수학 구현 문제

10/18
숨바꼭질 6 - 단순 수학 구현 문제

10/20
2진수 8진수, 8진수 2진수 - 단순 수학 구현 문제

10/28
음의 2진수 - 음수에 대한 나눗셈과 나머지 처리를 생각하게 한 문제

10/29
골드바흐 파티션 - 수학 구현 문제

11/2
스도미노쿠 - 도저히 생각이 안나 오랫만에 다시 보니 그냥 단순 구현인게 쉽게 보였다. 복잡하게 생각하기보다 단순하게 생각하는게 답이 잘 보이는 경우가 많은 것 같다.

11/6
로봇 조종하기 - 메모이제이션 탐색 문제 아이디어 자체는 금방떠올랐으나 어떤방식으로 구현할지에 대해 오래 고민한 문제... 메모이제이션에 대한 이해가 아직은 부족한 것 같다.

11/9
벽 부수고 이동하기 - 이전에 코드가 틀려 다시 풀게된 문제 8개월 전의 코드와 현재 구현하고 만드는 코드를 보니 길이나 알고리즘에 대한 이해도가 확실히 많이 발전했다는게 보여서 뿌듯했다.

11/12
과외맨 - 시작지점에 대한 값을 -1로 줘서 문제가 생겼던 bfs 탐색 문제 경로들의 블럭 값이 1보다 크기때문에 1로 바꿔줘서 해결

2021
1/3
나무 재테크 - 처음엔 우선순위 큐로 풀었다가 시간초과가 나서 고생한 문제 아마 우선순위 큐의 원소를 넣고 뺄때 발생하는 정렬때문에 시간이 오래걸리는 듯 하다.

1/8
1로 만들기 - 2와 3으로 동시에 나눠지는 경우 어떤것이 최선인지에 대한것이 빠져 있었다.
탈옥 - 밖에서 안으로 들어가는 경우 -2로 인해 sum의 값이 음수가 나올수도 있다는걸 빼먹었다.
타일 채우기 - dp 패턴 파악이 아직은 부족하다.

1/10
2x2x2 큐브 - 큐브 에서의 움직일 수 있는 가능한 경우를 전부 체크하여 만듦.

1/11
rgb거리2 - 1번과 달라진 것은 그 다음 번 껏과도 비교를 해야되서 마지막에 처음껄 어떤걸 선택했는지에 대한지에 대한 체크를 해야한다는 것이 있었다. 처음엔 pair로 이전껄 계승하는 방식으로 하려 했지만 마지막에 엄청 큰 값을 줘버리면 처음껄 계승하다 그게 최소가 아니게 되어 그걸 선택한 경우가 사라져 버린다면 알아낼 수 없다는걸 알고 처음 선택을 기준으로 전부 dp를 돌려서 비교했다.

1/13
진법 변환 1, 2 - 단순 구현 수학 문제

1/14
Base_Conversion - 단순 구현 수학 문제

1/15
차이를 최소로 - 이전의 코드는 연산 결과가 서로 연결되어 진행해야 되는데 위에 연산에서 우측으로 진행하는 과정에 이전 연산결과가 최적인것이 반영된체로 행되지 않아 문제가 생겼던것 같다.

1/17
소인수분해 - 2부터 하나씩 반복하여 나눠 나가면 어차피 2로 나뉘는 소수가 아닌 수들은 이미 2로 전부 나뉘어 사라지므로 소수를 판별할 필요가 없고 만약 N이 i+1보다 작은 수로 나뉠 경우 몫은 i보다 작을 것이므로 i*i만 체크를 하고 남은 N은 자연스럽게 소수가 된다.

1/18
나이트의 이동 - 단순 bfs 탐색 문제

1/21
Two Dots - 단순 dfs 탐색 문제 회전 방향으로 판단하여 하려 했으나 시작지점을 저장해놓고 변경하는 방식을 사용하는게 훨씬 편하고 빠르다는 걸 알게 됐다.

2/1
뱀과 사다리 게임 - 단순 bfs 탐색 문제

2/5
데스나이트 - 단순 구현 bfs탐색 문제

2/7
벽 부수고 이동하기 4 - 오랫만에 머리 아팠던 bfs 탐색 문제 0으로 이루어진 집합의 갯수와 같은 집합에 속하는지를 판단하여 1의 위치에서의 이동가능거리를 계산하여야 했다.

2/9
벽 부수고 이동하기 3 - bfs탐색 문제 낮과 밤에대한 구분을 추가한 벽 부수고 이동하기 문제 큰 차이는 없었던 것 같다.

2/10
최소_최대, 검증수, 최댓값, 나머지 - 단순 수학 구현 문제들

2/11
펠린드롭수, 분해합, 블랙잭 - 단순 수학 구현 문제

2/12
이항계수1, Hashing, 덩치 - 단순 구현 수학 문제

2/14
마인크래프트 - 단순 구현 브루트포스 문제

2/15
큐빙 - 시뮬레이션 구현 문제 단순 구현이 제일 생각 없이 코드 패턴 찾기만 하는 경우가 많아 코드 길이가 길어지는 듯 하다.

2/18
인구 이동 - 단순 구현 탐색 문제 아직은 구현쪽이 조금 부족한 느낌이다. 찾는 방식은 바로 알았는데 구현중간 중간 에러나 오타가 생겨 시간을 하루 넘겨 버렸다.

2/19
아기 상어 - bfs 탐색 구현 문제 아가 상어가 움직일 수 있는 조건, 먹이를 먹는 조건, 먹이를 먹는 위치에 대한 조건 조건에 대한 세세한 설정을 가끔 실수 하는 것만 고치면 금방 해결할 것 같다.

2/22
숨바꼭질5 - bfs 탐색 문제 홀짝으로 쪼개서 탐색한다는 부분까지는 이해를 했는데 이전에 방문했던 부분에 대한 정답체크를 하는 부분에서 시간이 조금 걸렸다.

2/25
확장 게임 - bfs 탐색 구현 문제

2/26
모양 만들기 - 단순 bfs 탐색 구현 문제

3/2
서울 지하철 2호선 - bfs 탐색 문제 순환하는 구조를 찾아 순환 구조로 부터의 거리를 찾는다.

6/21
체스판 여행1 - 중복처리를 4전부 하여 방문처리를 하는 방법은 금방 찾았지만 초기 방문에서 방문처리를 하며 sy sx 대신 0 0을 넣어 문제가 발생하였다. 오랫만에 문제를 풀어 머리가 굳은 것 같다.

6/22
움직이는 미로 탈출, 직사각형 탈출 - bfs 브루트포스 문제 다시 감을 잡고 금방 해결한 것 같다.

6/23
배열 돌리기 1 - 단순 구현 문제 R을 mod연산 하여 횟수를 줄여보려 했으나 각 그룹마다 회전하였을때 같은 위치로 오는 횟수가 달라진다는 부분을 파악하는데 시간이 걸림
양념 반 후라이드 반 - 단순 수학 구현문제

6/24
배열 돌리기3 - 단순 구현 문제 구현이 항상 제일 복잡하고 어려운 것 같다.

6/28
나3곱2 - 단순 수학 정렬 문제

6/29
십자가 찾기 - 단순 구현 탐색문제 dfs로 풀었으면 조금 더 간단하게 구현 할 수 있었을 것 같다.

6/30
겉넓이 구하기 - 단순 수학 구현 문제 

7/1
늑대와 양 - 단순 구현 탐색 문제

7/5
배열 복원하기 - 단순 구현 문제 출력을 잘못 만들었을 때 에러 찾기가 가장 힘든 것 같다.

7/6
bfs 스페셜 저지 - bfs 파악 문제 단순 가지 파악이 아닌 가지가 들어간 순서에 따라 나오는 잎의 순서가 변한다는 걸 간과하여 오래 걸린 문제

7/7
dfs 스페셜 저지 - bfs 스페셜 저지와 유사한 방식으로 해결 bfs를 dfs로 변환시켜 해결 하였다.

7/8
체스판 위의 공 - 그래프 탐색 문제 최적화에 대해 생각하는데 시간이 좀 오래 걸린 문제 한번 돌리고 난 뒤에 최적의 경로가 아닐수도 있다는 부분을 간과했다.

7/12
미로 탈출하기 - 단순 dfs 탐색 문제

7/19
배열 B 의 값 - 딥러닝을 공부하다 오랫만에 다시 풀어본 알고리즘 구현 문제 아이디어는 금방 떠올렸으나 구현은 항상 어려운 것 같다.

7/20
레벨 햄버거 - 단순 구현 수학 문제

7/22
파이프 옮기기 2- 오랫만에 dp를 풀었더니 dp에 대한 방식을 좀 잊어서 오래 걸린 문제

7/27
스타트 링크 - 재채점이 되어 틀려있길래 다시 확인한 문제 ns가 범위가 넘었을때 visit을 방문한 부분이 문제가 되었던 듯 하다.

9/29
다리 만들기 - 연구 과제만 하다가 오랫만에 푼 bfs dfs 응용 문제 bfs라고 해서 가장 빨리 만나는 경우가 최선이 아니라는 걸 알았다. 한쪽에서의 거리가 3인 경우 다른 곳에서의 거리가 1과 2가 있을때 2를 먼저 만날 수 있으므로 주의하자.

10/12
링크와 스타트 - 브루트포스 문제 축구여서 단순히 절반으로 나눈다는 생각으로 풀었다가 틀린 문제 구현자체는 간단했으나 잘못된 부분을 찾으려다 문제를 너무 어렵게 읽어 시간이 좀 걸렸다.

11/04
트리_순회 - 간만에 map을 이용한 tree를 구현하여 사용한 전위,중위,후위 탐색 문제

11/12
케빈 베이컨 - 플로이드 와샬 알고리즘 문제 전체 탐색을 친구로 들어온 사람들을 추가하며 갱신하는 bfs방식으로 최적화 하려다가 맨 처음 방문노드의 경우가 최적이 아닌경우 이전에 그 노드를 거쳐갔던 모든 경우가 바껴야 하여 플로이드 와샬로 변경하여 푼 문제

21/12/01
거짓말 - 처음으로 풀어본 union find 문제 아이디어 자체는 간단 했다. 연결된 그룹을 하나의 부모로 묶어 일치시키는게 끝이다. 이런 종류의 문제를 다시 풀어봐야 할 것 같다.

21/12/02
트리의 지름 - 트리는 모두 연결되어 있다는 걸 이용한 dfs 문제 dfs를 2번 돌리면 된다는 생각을 떠올리는 게 오래 걸렸다.

21/12/06
파티 - 단방향 도로에서의 오가는 마을중 최대 거리를 구하는 문제 목적지에서 오는 걸 구하는 건 간단 했으나 목적지로 가는 거리를 구하는게 |V||E|보다 좋은 방법이 있을 것 같아 찾아보니 역방향 처럼 보이게 만들어 X에서 가는 것처럼 바꾸는 방법이 있었다. 까먹지 말고 비슷한 유형이 나오면 이용해 먹자

21/12/07
특별한 최단 경로 - 어제 푼 다익스트라 응용 문제와 비슷한 느낌 1 v1 v2 N 이나 1 v2 v1 N의 경로를 구하기 위해 1 v1 v2에서 시작하는 최소 경로들을 구한뒤 합한 최소값을 구했다.

21/12/08
최단경로 - 단순 다익스트라 문제 단순한 응용 다익스트라는 완전히 익힌 것 같다.

21/12/10
웜홀 - 처음으로 풀어본 벨만 포드 알고리즘 문제 돌아온다는 조건이 있고 음의 가중치를 가진 길이 있을때 사용하는 알고리즘

21/12/11
최소비용 구하기 - 단순 다익스트라 문제

21/12/13
트리의 지름 - 다중 dfs, 트리 활용 문제

21/12/15
트리의 순회 - 루트를 찾고 난 이후가 막혀 오래 걸렸던 문제 

21/12/20
조합 - 큰 수 수학 구현 문제 수학 구현은 아직 더 연습이 많이 필요 할 것 같다.
</pre>
