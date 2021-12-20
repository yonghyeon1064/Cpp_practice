/*
virtual function

-개념
기본 class(상속받지 않은 class) 내에서 선언된 후 파생 class에 의해 재정의 되는 멤버 function
Compile때가 아닌 Runtime 중에 함수를 결정 -> 주로 Runtime중에 function의 다형성(polymorphism)을 구현하는데 사용

-특징
1. class의 public 구역에만 선언한다.
2. virtual function은 static일 수 없으며 다른 class의 friend가 될 수도 없다.
3. virtual function은 실행시간 다형성을 얻기위해 기본 class의 포인터 또는 참조를 통해 access해야 한다.
4. virtual function의 프로토타입(반환형과 매개변수)은 기본 class와 파생 class에서 동일하다.
5. class는 virtual 소멸자를 가질 수 있지만 virtual 생성자를 가질 수는 없다.

-출처
https://yeolco.tistory.com/125
*/

#include <iostream>
 
using namespace std;
 
class parent {
public :
    void print1() { //일반 function
        cout << "parent print1" << "\n";
    }
    virtual void print2() { //virtual function
        cout << "parent print2" << "\n";
    }
    virtual void print3() { //virtual function, 파생 클래스에서 argument를 다르게 선언
        cout << "parent print3" << "\n";
    }
};
 
class child : public parent {
public :
    void print2() {
        cout << "child print2" << "\n";
    }
    void print3(int x) {
        cout << "child print3" << "\n";
    }
};
 
int main() {
    parent* p;
    child c;
    p = &c; //p class의 껍데기를 가지고 있지만 c의 객체
 
    p->print1(); //컴파일 시간에 어떤 함수인지 결정되기 때문에 parent의 함수
    p->print2(); //virtual 함수라 runtime에 어떤 함수인지 결정됨. parent class지만 객체가 child class의 객체이기 때문에 child의 함수 호출
    p->print3(); //매개변수가 다르기에 부모 class 함수 호출

    /*
    -실행결과

    parent print1

    child print2

    parent print3
    */
 
    return 0;
}
