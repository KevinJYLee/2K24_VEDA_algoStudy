#include <iostream>

using namespace std;

class MyStack{
private:
    //new 를 활용해 공간을 동적할당 할 것
    int* data;
    
    //데이터 개수 저장합니다. 생성시 초기값 0
    int len;
    
    //top 을 가리키는 포인터를 만들까요 말까요. 아마 top 포지션은 인덱스 len 으로 접근하면 됩니다.
    
public:
    
    //최대 명령수대로 힙에 할당을 합니다.
    MyStack(int N){
        data = new int[N];
        len = 0;
    }
    
    //data 에 할당된 친구들 해제해줘야겠죠
    ~MyStack(){
        delete [] data;
    }
    
    bool empty(){
        return len == 0;
    }
    
    //오류로서든 데이터로서든, -1 이 출력될 수 있다.
    int top(){
        if(len == 0) return -1;
        return data[len - 1];
    }
    
    int pop(){
        if(len == 0) return -1;
        return data[--len];
    }
    
    void push(int num){
        data[len++] = num;
    }
    
    int getLen(){
        return len;
    }
};

//명령을 받는 절차는 main 에서 while 문으로 처리합니다.
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    MyStack S(N);
    
    int cont;
    int opr;

    for(int i = 0; i < N; i++){
        cin >> cont;
        switch (cont) {
            case 1:
                cin >> opr;
                S.push(opr);
                break;
            case 2:
                cout << S.pop() << '\n';
                break;
            case 3:
                cout << S.getLen() << '\n';
                break;
            case 4:
                cout << S.empty() << '\n';
                break;
            case 5:
                cout << S.top() << '\n';
                break;
            default:
                break;
        }
    }
    
    return 0;
}
