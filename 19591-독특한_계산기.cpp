#include<iostream>
#include<deque>
#include<map>

using namespace std;

map<char, int> enumop;
deque<long long> nums;
deque<char> ops;

void input(){
    long long a = 0;
    string input;

    cin>>input;


    bool mf = input[0] == '-';
    for(int i=0;i<input.length();++i){
        if(i == 0 && input[i] == '-'){
            continue;
        }
        else if(input[i]>='0'&&input[i]<='9'){
            if(a == 0)
                a = input[i] - '0';
            else{
                a = a*10 + (input[i] - '0');
            }
        }
        else{
            ops.push_back(input[i]);
            if(mf)
                nums.push_back(-a);
            else
                nums.push_back(a);
            mf = false;
            a = 0;
        }
    }
    if(mf)
        nums.push_back(-a);
    else
        nums.push_back(a);

    enumop['*'] = 3;
    enumop['/'] = 3;
    enumop['+'] = 5;
    enumop['-'] = 5;
}

long long calc(char op, long long num1, long long num2){
    switch (op)
    {
    case '*':
        return num1 * num2;
    
    case '/':
        return num1 / num2;

    case '+':
        return num1 + num2;

    case '-':
        return num1 - num2;
    }
    return -1;
}

void solution(){
    while(!ops.empty()){
        char lop = ops.front(), rop = ops.back();
        long long l1 = nums.front(), r2 = nums.back();
        long long l2, r1;

        nums.pop_front(); nums.pop_back();
        if(nums.empty()){
            r1 = l1;
            l2 = r2;
        }
        else{
            l2 = nums.front();
            r1 = nums.back();
        }

        if(enumop[lop] == enumop[rop]){
            long long calc1 = calc(lop, l1, l2), calc2 = calc(rop, r1, r2);

            if(calc1 >= calc2){
                nums.push_back(r2);
                ops.pop_front();
                nums.pop_front();

                nums.push_front(calc1);
            }

            else{
                nums.push_front(l1);
                ops.pop_back();
                nums.pop_back();

                nums.push_back(calc2);
            }
        }
        else if(enumop[lop] > enumop[rop]){
            nums.push_front(l1);
            ops.pop_back();
            nums.pop_back();

            nums.push_back(calc(rop, r1, r2));
        }
        else{
            nums.push_back(r2);
            ops.pop_front();
            nums.pop_front();

            nums.push_front(calc(lop, l1, l2));
        }
    }

    cout<<nums.front()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}