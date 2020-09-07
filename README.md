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
</pre>
