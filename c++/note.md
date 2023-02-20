c++ 관련 필기사항 정리 문서
========================================

[블로그 링크](https://modoocode.com/135)

## 2023-01-18

1. 왜 c++을 배우냐 부분 읽음
2. 1-1 진행함

------------------------------

## 2023-01-19

## 1-2

>iostream  == c언어에서 stdio.h 같은 존재

>std = 이름공간이라는 것(namespace)
	객체가 어디 소속인지 지정해줌

`std::cout` 에서 std가 없으면 cout를 찾을 수 없음.

```c++
// header1.h 의 내용
namespace header1 {
int foo();
void bar();
}

// header2.h 의 내용
namespace header2 {
int foo();
void bar();
}
```
> 이름공간을 정의하는 방법이다.

header1안에서 foo를 부른다면 그 안의 foo를 부르는 셈,
밖에서 부르려면 `header1::foo`가 필요.

하지만 만일 위 같은 `foo` 을 여러번 반복적으로 호출하게 되는 경우 앞에 매번 `header1::` 을 붙이기가 상당히 귀찮을 것입니다.

>그래서 아래와 같이 '나는 앞으로 `header1` 이란 이름 공간에 들어있는 `foo` 만 쓸거다!' 라고 선언할 수 있습니다.

```c++
#include "header1.h"
#include "header2.h"

using header1::foo;
int main() {
  foo();  // header1 에 있는 함수를 호출
}
////////////////////////////////////////////////////
#include "header1.h"
#include "header2.h"
// header1에 있는 공간만 사용 원할시,
using namespace header1;
int main() {
  foo();  // header1 에 있는 함수를 호출
  bar();  // header1 에 있는 함수를 호출
}
// 로 가능. 그렇다고 header2를 못 부르는 건 아니고, 명시적으로 적어주면 가능.

```

std는 iostream 안에 정의된 이름공간임.
이 경우에는, 특별히 std 생략하고 cout, endl만 적어도 가능.

**참고!** 
권장하는 방식은 `using namespace std;` 같은 것은 사용하지 않고, `std::` 를 직접 앞에 붙여서 [std](https://modoocode.com/std) 의 이름공간의 함수이다 라고 명시해주는 것이 좋습니다. 또한, 여러분이 작성하는 코드는 여러분 만의 이름 공간에 넣어서 혹시 모를 이름 충돌로 부터 보호하는 것이 중요합니다.

>cout == 표준 출력 (c언어의 stdout라네요)

>endl == 출력하겠다는 함수(대충 엔터출력정도로 지금은 생각)

잠깐 짚고 넘어가자면, C++ 에서는 재미있게도 이름 공간에 굳이 이름을 설정하지 않아도 됩니다.

이 경우 해당 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있게 됩니다. 이 경우 마치 `static` 키워드를 사용한 것과 같은 효과를 냅니다.

```c++
#include <iostream>

namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일합니다.
int only_in_this_file = 0;
}  // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}

```

--------------------------------

## 1-3

[구글픽 변수 이름 깔삼하게 짓는 팁](https://google.github.io/styleguide/cppguide.html#Variable_Names)

변수 만드는 법, 포인터 등 대부분의 문법은 c++과 c언어가 동일하다.

for문, while문, if-else문, break, switch도 동일하다.

> std::cin == 입력받기
> `std::cin >> user_input;`

**c++에서는 c언어의 scanf처럼 &연산자를 사용치 않음!**

---------------------------------------------------

## 2

참조자(레퍼런스)라는 c++만의 새로운 개념!

```c++

#include <iostream>

// 이 change_val이 참조자 개념!
int change_val(int *p) {
  *p = 3;

  return 0;
}
int main() {
  int number = 5;

  std::cout << number << std::endl;
  change_val(&number);
  std::cout << number << std::endl;
}
```

```c++
 int a = 3;
  int& another_a = a;
// 이런 거
```

>**레퍼런스 만드는 법 == 자료형 뒤에 & 붙이기, 혹은 위처럼 함수 비슷한거 만들기**

심지어 `int*` 와 같은 포인터 타입의 참조자를 만드려면 `int*&` 로 쓰면 됩니다.

위와 같이 선언함으로써 우리는 `another_a` 는 `a` 의 참조자다! 라고 공표하게 되었습니다. 이 말은 즉슨 `another_a` 는 `a` 의 또다른 이름 이라고 컴파일러에게 알려주는 것입니다. 따라서 `another_a` 에 어떠한 작업을 수행하든 이는 사실상 `a` 에 그 작업을 하는 것과 마찬가지 입니다.

어떻게 보면 참조자와 포인터는 상당히 유사한 개념입니다. 포인터 역시 다른 어떤 변수의 주소값을 보관함으로써 해당 변수에 간접적으로 연산을 수행할 수 있기 때문이죠. 하지만 레퍼런스와 포인터는 몇 가지 중요한 차이점이 있습니다.

#### 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 합니다.

`int& another_a;` 는 불가능!
**또, const같은 존재이기에 다른 놈의 별명으로 바꾸는 것도 불가능!** 
another_ a == a랑 같은 존재가 되버린 것임!

#### 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.

만일 내가 컴파일러라면 `another_a` 위해서 메모리 상에 공간을 할당할 필요가 있을까요? 아니죠! 왜냐하면 `another_a` 가 쓰이는 자리는 모두 `a` 로 바꿔치기 하면 되니까요. 따라서 이 경우 레퍼런스는 메모리 상에 존재하지 않게 됩니다. 물론 그렇다고 해서 항상 존재하지 않은 것은 아닙니다. 아래 예제를 보실까요.

```c++
#include <iostream>

int change_val(int &p) { // 이때는 int &p가 되는 이유는, change_val이 호출될 때, int &p = number가 되는 셈이여서 가능.
  p = 3;

  return 0;
}
int main() {
  int number = 5;

  std::cout << number << std::endl;
  change_val(number);
  std::cout << number << std::endl;
}
```

이때는 아마 p가 메모리 상에 존재하게 된다는 의미 같다. 

*맞나? 사실 잘 모르겠다.*

다중 레퍼런스도 가능한데, x가 y의 별명이고, z가 y의 별명이라는 것이 아니라, x의 별명이 y,z 동일하다고 되는 느낌이다.

```c++
  int x;
  int& y = x;
  int& z = y;
```

>좋은 질문 입니다. 하지만 참조자의 참조자 라는 말의 의미를 생각해보면 사실 말이 안된다는 것을 알 수 있습니다. 굳이 별명의 별명을 만들 필요는 없으니까요! 실제로 C++ 문법 상 참조자의 참조자를 만드는 것은 금지되어 있습니다.

상수 레퍼런스는 불가능.
`int &ref = 4;` 같은 녀석. `ref = 5` 같은 미친 버그를 잡기 위해서 그럼.

다만, 앞에 const를 붙여 버그를 확실히 막아둔 경우 가능.

#### 2023-01-21

#### 레퍼런스 배열은 만들 수 없다.
`int a, b; int & arr[2] = {a, b};` 는 불가능한 코드.

그런데 주소값이 존재한다라는 의미는 해당 원소가 메모리 상에서 존재한다 라는 의미와 같습니다. 하지만 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서 공간을 차지 하지 않습니다. 따라서 이러한 모순 때문에 레퍼런스들의 배열을 정의하는 것은 언어 차원에서 금지가 되어 있는 것입니다.

#### 다만, 배열들의 레퍼런스는 가능하다.

```c++
#include <iostream>

int main() {
  int arr[3] = {1, 2, 3};
  int(&ref)[3] = arr;

  ref[0] = 2;
  ref[1] = 3;
  ref[2] = 1;

  std::cout << arr[0] << arr[1] << arr[2] << std::endl;
  return 0;
}
```

따라서 `ref[0]` 부터 `ref[2]` 가 각각 `arr[0]` 부터 `arr[2]` 의 레퍼런스가 됩니다. 포인터와는 다르게 배열의 레퍼런스의 경우 참조하기 위해선 
**반드시 배열의 크기를 명시해야 합니다.**

따라서 `int (&ref)[3]` 이라면 반드시 크기가 3 인 `int` 배열의 별명이 되어야 하고 `int (&ref)[5]` 라면 크기가 5 인 `int` 배열의 별명이 되어야 합니다.

레퍼런스 리턴하는 함수도 만드는 것 가능.
다만, 레퍼런스의 본래 변수가 없어지지 않는 것(지역 변수가 아닌 것)이여야 함.

```c++
int& function() {
  int a = 2;
  return a;
}

int main() {
  int b = function();
  b = 3;
  return 0;
}
```
> 이 경우, 오류 발생. 컴파일 에러는 아니라 돌아갈수도 있지만, 위험한 작업

다만,
```c++
int& function(int& a) {
  a = 5;
  return a;
}

int main() {
  int b = 2;
  int c = function(b);
  return 0;
}
```
> 는 가능. 외부 변수의 레퍼런스를 리턴한 건데, return이 일어나는 시점에 a는 b를 참조하고 있고, function이 리턴한 참조자도 여전히 b를 참조할테니. `int c = function(b);` 라는 줄은, `int c = b`가 된 셈.


### 레퍼런스를 사용하는 이유!

그렇다면 이렇게 참조자를 리턴하는 경우의 **장점**이 무엇일까요? C 언어에서 엄청나게 큰 구조체가 있을 때 해당 구조체 변수를 그냥 리턴하면 전체 복사가 발생해야 해서 시간이 오래걸리지만, 해당 구조체를 가리키는 포인터를 리턴한다면 그냥 포인터 주소 한 번 복사로 매우 빠르게 끝납니다.

마찬가지로 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관 없이 딱 한 번의 주소값 복사로 전달이 끝나게 됩니다. 따라서 매우 효율적이죠!

위의 반대의 경우로, 참조자가 아닌 값을 리턴하는 함수를 참조자로 받는것도 같음.
```c++
int function() {
  int a = 5;
  return a;
}

int main() {
  int& c = function();
  return 0;
}
```
> 코드 실행시 오류 발생. 

다만, c++에는 **매우 중요한** 예외 규칙이 있다.

```c++
#include <iostream>

int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();
  std::cout << "c : " << c << std::endl;
  return 0;
}
```
> 의 경우에는 정상작동 한다.

원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상입니다. 따라서 기존에 `int&` 로 받았을 때에는 컴파일 자체가 안되었습니다. 하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장됩니다. 그리고 그 연장되는 기간은 레퍼런스가 사라질 때 까지 입니다.

> 즉, 원래는 그자리에서 사라졌어야 할 함수의 리턴값이 레퍼런스가 없어질때까지 유지된다는 소리.

### 배운 내용 정리

|  Paragraph   | 함수에서 값 리턴 (`int f()`)   | 함수에서 참조자 리턴 (`int& f()`)      |
| ---        |    ---   |          --- |
| 값 타입으로 받음(`int a = f()`) | 값 복사됨       |        값 복사됨. 다만 지역 변수의 레퍼런스를 리턴하지 않도록 주의     |
| 참조자 타입으로 받음 (`int& a = f()`)| 컴파일 오류 | 가능. 다만 마찬가지로 지역 변수의 레퍼런스를 리턴하지 않도록 주의   |
| 상수 참조자 타입으로 받음 (`const int& a = f()`)|가능|가능. 다만 마찬가지로 지역 변수의 레퍼런스를 리턴하지 않도록 주의      |


[블로그 링크, 레퍼런스를 사용하는 이유와 레퍼런스가 메모리를 먹는 타이밍 관련 글](https://lecor.tistory.com/39#:~:text=%EC%9D%B4%EC%99%80%20%EA%B0%99%EC%9D%80%20%EC%B0%B8%EC%A1%B0%EC%9E%90%20%EB%A6%AC%ED%84%B4,%EC%9D%98%20%EC%9E%A5%EC%A0%90%EA%B3%BC%20%EB%8F%99%EC%9D%BC%ED%95%98%EB%8B%A4.)

레퍼런스는 더 찾아봐야 할 듯!

---------------------------------------------

## 3단원

### 2023-01-22

>new == c언어의 malloc 같은 존재

>delete == c언어의 free 같은 존재


```c++
/* new 와 delete 의 사용 */
#include <iostream>

int main() {
  int* p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;
  return 0;
}
```

> new로 당연하지만, 배열 할당도 가능. `int *list = new int[arr_size]` 이런 식으로. 해지할땐 `delete[] list` 로 한다. new-delete 짝, new[ ] - delele[ ]짝 인 셈이다.

c++에서는 c처럼 맨 위가 아닌 중간에서도 변수선언이 되고, {} 안에서 선언한 건 그 안의 지역변수고, 중괄호 나가면 소멸된다.

c언어 방식의 struct 로 프로그램 만들던걸 이야기해주며, 객체지향을 위한 빌드업 세우고 마침.

-------------------------------------------------------------

## 4-1단원

기계어, 어셈블리어, 2세대언어, 3세대(절차지향), 이후 객체지향 소개해줌.

### 2023-01-23

객체

다시 말해서 `Animal` 자체가 `Play` 를 하는 것이지, `Play` 가 `Animal` 을 해주는 것이 아닙니다. 만일 `Animal` 자체가 `Play` 를 한다 라는 개념을 생각하게 된다면, 다음과 같이 생각할 수 있을 것입니다.

```c++
Animal animal;

// 여러가지 초기화 (생략)

animal.play();   // 즉 내가 (animal 이) Play 를 한다!
animal.sleep();  // 내가 sleep 을 한다!

```

이렇게 하면 `play` 함수에 `animal` 을 인자로 주지 않아도 됩니다. 왜냐하면 내가 `play` 하는 것이기 때문에 내 정보는 이미 `play` 함수가 다 알고 있기 때문입니다. `play` 함수는 나의 상태들, 예를 들어서 체력이나, 배고픔 정도나 피곤한 정도 등을 모두 알 수 있기 때문에 나에 대한 적절한 처리를 할 수 있게 되는 것입니다. 

즉, `animal` 은 **자신의 상태를 알려주는 변수(variable)** 과, **자신이 하는 행동들 (play, sleep 등등) 을 수행하는 함수(method) 들로 이루어졌다**고 볼 수 있습니다.

>객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리 이다.

이 때 객체가 현실 세계에서의 존재하는 것들을 나타내기 위해서는 **추상화(abstraction) 라는 과정이 필요**합니다. 컴퓨터 상에서 현실 세계를 100% 나타낼 수 없는 것이기 때문에, 적절하게 컴퓨터에서 처리할 수 있도록 바꾸는 것인데, 예를 들어서 핸드폰의 경우 '전화를 한다', '문자를 보낸다' 와 같은 것들은 '핸드폰이 하는 것' 이므로 함수로 추상화시킬 수 있고,핸드폰의 상태를 나타내는 것들, 예를 들어서 자기 자신의 전화 번호나 배터리 잔량 같은 것은변수로 추상화시킬 수 있습니다.

![이미지](https://modoocode.com/img/2012E33F4F4CCAF12C29D8.gif)

이와 같이 어떠한 객체는 자기 만의 정보를 나타내는 변수들과, 이를 가지고 어떠한 작업을 하는 함수들로 둘러싸고 있다고 보시면 됩니다. 

**참고로, 이러한 객체의 변수나 함수들을 보통 인스턴스 변수(instance variable) 와 인스턴스 메소드(instance method) 라고 부르게 되는데, 그냥 알고 계시는 변수와 함수와 동일한 것으로 생각하시면 됩니다.** 

누군가 인스턴스 메소드라고 하면 "아 그냥 객체에 정의되어 있는 함수구나" 라고 생각하시면 됩니다.

**그림을 메소드가 변수들을 감싸고 있는 것 처럼 그리는 이유는 진짜로 변수들이 외부로 부터 '보호' 되고 있기 때문입니다.**

다시 말해, 외부에서 어떠한 객체의 인스턴스 변수의 값을 바꾸지 못하고오직 객체의 인스턴스 함수를 통해서만 가능하다는 것이지요.

이와 같이 외부에서 직접 인스턴스 변수의 값을 바꿀 수 없고 항상 인스턴스 메소드를 통해서 간접적으로 조절하는 것을 **캡슐화(Encapsulation)** 라고 부릅니다.

일단 여기서는 캡슐화의 장점에 대해서는 나중에 설명하겠지만 간단하게 말하자면, "객체가 내부적으로 어떻게 작동하는지 몰라도 사용할 줄 알게 된다" 라고 볼 수 있습니다.

> 클래스
> 자 그러면 객체는 C++ 상에서 어떻게 만들어낼까요. 이를 위해 C++ 에서 객체를 만들 수 있는 장치를 준비하였습니다. 쉽게 말하면 객체의 '설계도' 라고 볼 수 있지요. 바로 클래스(class) 입니다.

위와 같이 안의 내용은 차있지 않고 빈 껍질로만 생각할 수 있습니다. 그리고 우리는 이 객체의 설계도를 통해서 실제 객체를 만들게 되지요. 

**C++ 에서 이와 같이 클래스를 이용해서 만들어진 객체를 인스턴스(instance) 라고 부릅니다.**

```c++
#include <iostream>

class Animal {
 private:
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}
```


`food, weight` 라는 변수가 있고, `set_animal, increase_food, view_stat` 이라는 함수들이 있는데, `Animal` 클래스 상에서 이들을 지칭할 때 

**각각 멤버 변수(member variable) 과 멤버 함수(member function) 라고 부릅니다.**

즉, 인스턴스로 생성된 객체에서는 인스턴스 변수, 인스턴스 함수, 그리고 그냥 클래스 상에서는 멤버 변수, 멤버 함수 라고 부르는 것입니다. 멤버 변수와 멤버 함수는 실재 하는 것이 아니지요. 인스턴스가 만들어져야 비로소 세상에 나타나는 것입니다.

먼저 멤버 변수들을 정의한 부분을 봅시다. 처음 보는 키워드가 있지요? 이러한 키워드를 '접근 지시자' 라고 하는데,외부에서 이러한 멤버들에 접근을 할 수 있냐 없냐를 지시해주는 것입니다. `private` 키워드의 경우, 아래에 쓰여진 것들은 모두 객체 내에서 보호되고 있다 라는 의미이지요. 즉, 앞서 객체 그림을 떠올리면 멤버 변수들이 안에서 보호 받고 있던 것 기억하시죠? `private` 되고 있는 모든 것들은 자기 객체 안에서만 접근할 수 있을 뿐 객체 외부에서는 접근할 수 없게 됩니다

> 즉, `private`는 외부에서 접근 불가능하고, 자기 객체 안에서만 접근 가능함. 말하자면, 내부의 멤버 함수를 통한 접근은 되나, 대놓고 `animal.food = 3` 이런거 안된다.


> `public` 이라는 것은 말 그대로 공개된 것으로 외부에서 마음껏 이용할 수 있게 됩니다. 그래서 `main` 함수에서도 이들을 마음대로 접근 가능.


아무것도 명시하지 않고 바로 class 아래 적으면, 자동으로 `private`로 인식.

------------------------------------------------

## 4-2

##### 2023-01-24

#### 함수의 오버로딩, 생성자, 디폴트 생성자

##### 오버로딩

음.. 그렇다면 함수의 오버로딩이라는 것은 '함수에 과부하를 주는 것' 인가 라는 생각도 드실 텐데요, 사실 맞는 말씀입니다. 사실 C 언어 에서는 하나의 이름을 가지는 함수는 딱 1 개만 존재할 수 밖에 없기에 과부하라는 말 자체가 성립이 안됬지요.

`printf` 는 C 라이브러리에 단 한 개 존재하고, `scanf` 도 C 라이브러리에 단 1 개 만 존재합니다. 

>하지만 C++ 에서는 같은 이름을 가진 함수가 여러개 존재해도 됩니다. 즉, 함수의 이름에 과부하 가 걸려도 상관이 없다는 것이지요!

```c++
/* 함수의 오버로딩 */
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}
```

>C++ 에서는 함수의 이름이 같더라도 인자가 다르면 다른 함수 라고 판단하기 때문에 오류가 발생하지 않는 것입니다.


만약, 위에서 char x를 인자로 받는 정의가 삭제되어도 동작한다.
아래 내용을 참고.

`int` 타입의 인자나 `double` 타입의 인자를 하나 받는 함수 하나 밖에 없습니다. 하지만 `main` 에서 각기 다른 타입의 인자들 (`int`, `char`, `double`) 로 `print` 함수를 호출하게 됩니다. 물론 `a` 나 `c` 의 경우 각자 자기를 인자로 하는 정확한 함수들이 있어서 성공적으로 호출 될 수 있겠지만,`char` 의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 '자신과 최대로 근접한 함수'를 찾게 됩니다.

C++ 컴파일러에서 함수를 오버로딩하는 과정은 다음과 같습니다.

###### 1 단계

자신과 타입이 정확히 일치하는 함수를 찾는다.

###### 2 단계

정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.

-   `Char, unsigned char, short` 는 `int` 로 변환된다.
    
-   `Unsigned short` 는 `int` 의 크기에 따라 `int` 혹은 `unsigned int` 로 변환된다.
    
-   `Float` 은 `double` 로 변환된다.
    
-   `Enum` 은 `int` 로 변환된다.
    

###### 3 단계

위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.

-   임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 `float -> int)`
    
-   `Enum` 도 임의의 숫자 타입으로 변환된다 (예를 들어 `Enum -> double)`
    
-   `0` 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
    
-   포인터는 `void` 포인터로 변환된다.
    

###### 4 단계

유저 정의된 타입 변환으로 일치하는 것을 찾는다 (이 부분에 대해선 나중에 설명!) ([출처](http://www.learncpp.com/cpp-tutorial/76-function-overloading/))

만약에 컴파일러가 위 과정을 통하더라도 
**일치하는 함수를 찾을 수 없거나** 
**같은 단계에서 두 개 이상이 일치하는 경우**
에 모호하다 (ambiguous) 라고 판단해서 오류를 발생하게 됩니다.




```c++
include<iostream>

    class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();
};

void Date::SetDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29;  // 윤년
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) {
  while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) {
  AddYear((inc + month_ - 1) / 12);
  month_ = month_ + inc % 12;
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() {
  Date day;
  day.SetDate(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

  day.AddDay(2000);
  day.ShowDate();

  day.SetDate(2012, 1, 31);  // 윤년
  day.AddDay(29);
  day.ShowDate();

  day.SetDate(2012, 8, 4);
  day.AddDay(2500);
  day.ShowDate();
  return 0;
}
```

코드 예제.
> 해당 코드에서, Data::를 명시한 이유는, 해당 함수들이 Data의 멤버 메소드임을 표기해준 것임. 표기하지 않을 시, 별개의 새로운 함수를 정의하게 됨.

대부분의 클래스는 깔끔함을 위해 위처럼 따로 표기함.(후에 배울 템플릿 클래스라는 것만 예외로 같이 쓴다고 함)



#### 생성자 빌드업

그럼 이제 `main` 함수를 살펴 봅시다. 위 처럼 `day` 인스턴스를 생성해서 `SetDate` 로 초기화 한 다음에 `ShowDate` 로 내용을 한 번 보여주고, 또 `AddDay` 을 해서 30일을 증가 시킨뒤 다시 새로운 날짜를 출력하도록 하였습니다. 여기서 가장 중요한 부분은 무엇일까요? 당연하게도, 처음의 `SetDate` 부분 입니다. 만일 `SetDate` 를 하지 않았더라면 초기화 되지 않은 값들에 덧셈 과 출력 명령이 내려져서

![](https://modoocode.com/img/1479614F4F4F099D33A88E.webp)

위 처럼 이상한 쓰레기 값이 출력되게 되거든요. 그런데 문제는 이렇게 `SetDate` 함수를 사람들이 꼭 뒤에 써주지 않는 다는 말입니다. 

물론 훌륭한 프로그래머들은 생성 후 초기화 를 항상 숙지하고 있겠지만 간혹 실수로 생성한 객체를 초기화 하는 과정을 빠트린다면 끔찍한 일이 벌어지게 됩니다.

다행이도 C++ 에서는 이를 언어 차원에서 도와주는 장치가 있는데 바로 **생성자(constructor)** 입니다.

#### 생성자

```c++
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) { // 해당 부분이 생성자
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

// 생략

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day(2011, 3, 1);
  day.ShowDate();

  day.AddYear(10);
  day.ShowDate();

  return 0;
}
```

	생성자의 구조
```c++
// 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다!
/* 클래스 이름 */ (/* 인자 */) {}
```

```c++
Date day(2011, 3, 1);         // 암시적 방법 (implicit)
Date day = Date(2012, 3, 1);  // 명시적 방법 (explicit)
```
> 마치 함수를 호출하듯이 사용하는 것이 암시적 방법, 명시적으로 생성자를 호출한다는 것을 보여주는 것이 명시적 방법 인데 많은 경우 암시적 방법으로 축약해서 쓸 수 있으므로 이를 선호하는 편입니다.




##### 디폴트 생성자

생성자를 클래스에 정의하지 않아도, 기본적으로 쓰레기값이 들어가게 자동으로 디폴트 생성자가 호출됨. 컴파일러가 자동으로 값을 넣어주는거지.

그리고 우리가 수동으로 
```c++
  Date() {
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
```

와 같은 방식으로 디폴트 생성자를 정의할 수도 있음.

```c++
Date day = Date(); // 명시적 방법
Date day2; // 암시적 방법
```

> 주의!!! 디폴트 생성자에서 암시적 방법을 사용할 때, `Date day3()`와 같이 적지 않도록 주의할 것. 이는 리턴값이 Date인 day3함수를 정의하는 식이 된 것임.


	절대로 인자가 없는 생성자를 호출하기 위해서 `A a()` 처럼 하면 안됩니다. 
	해당 문장은 `A` 를 리턴하는 함수 `a` 를 정의한 문장 입니다. 반드시 그
	냥 `A a` 와 같이 써야 합니다.

참고.

##### 명시적으로 디폴트 생성자 사용하기

C++ 11 이전에는 디폴트 생성자를 사용하고 싶을 경우 그냥 생성자를 정의하지 않는 방법 밖에 없었습니다. 하지만 이 때문에 그 코드를 읽는 사용자 입장에서 개발자가 깜빡 잊고 생성자를 정의를 안한 것인지, 아니면 정말 디폴트 생성자를 사용하고파서 이런 것인지 알길이 없겠죠.

다행이도 C++ 11 부터 명시적으로 디폴트 생성자를 사용하도록 명시할 수 있습니다.

```c++
class Test {
 public:
  Test() = default;  // 디폴트 생성자를 정의해라
};
```
> 바로 위처럼 생성자의 선언 바로 뒤에 `= default` 를 붙여준다면, [Test](https://modoocode.com/test) 의 디폴트 생성자를 정의하라고 컴파일러에게 명시적으로 알려줄 수 있습니다.

##### 생성자 오버로딩

앞서 함수의 오버로딩에 대해 잠깐 짚고 넘어갔는데, 생성자 역시 함수 이기 때문에 마찬가지로 함수의 오버로딩이 적용될 수 있습니다. 쉽게 말해 해당 클래스의 객체를 여러가지 방식으로 생성할 수 있게 되겠지요.

```c++
class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "인자 3 개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day = Date();
  Date day2(2012, 10, 31);

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

연습문제 푸는 중. 생각보다 어렵다. 중복이 일어나지 않을까 한참 고민했는데, 일어나지 않을 것 같다. 수학적 통찰력이 나는 좀 부족하다..

### 2023-01-25

연습문제 푸는 중..

와 이거 정말 어렵다....... 나중에 다시 보러 와야겠다. #재확인


----------------------------------------------------------


## 4-3

#### 복사 생성자, 소멸자

스타크래프트 만들기..?

```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}
Marine::Marine(int x, int y) {
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3);
  marines[1] = new Marine(3, 5);

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

```



예전에, `new` 와 `delete` 에 대해서 배울 때 [malloc](https://modoocode.com/243) 과의 차이점에 대해서 잠깐 언급 했던 것이 기억 나나요? 그 때는 아직 내용을 다 배우지 못해서, `new` 와 [malloc](https://modoocode.com/243) 모두 동적으로 할당하지만 '무언가' 다르다고 했었는데, 위 코드에서 여러분들은 아마 눈치 채셨을 것이라 생각됩니다. 바로 `new` 의 경우 객체를 동적으로 생성하면서와 동시에 자동으로 생성자도 호출해준다는 점입니다.

```c++
marines[0] = new Marine(2, 3);
marines[1] = new Marine(3, 5);
```

위와 같이 `Marine(2,3)` 과 `Marine(3,5)` 라는 생성자를 자동으로 호출해주지요. 이것이 바로 C++ 에 맞는 새로운 동적 할당이라고 볼 수 있습니다.

```c++
marines[0]->show_status();
marines[1]->show_status();
```

물론 `Marine` 들의 포인터를 가리키는 배열이기 때문에 메소드를 호출할 때 . 이 아니라 `->` 를 사용해줘야 되겠지요. 마지막으로, 동적으로 할당한 메모리는 언제나 해제해 주어야 된다는 원칙에 따라

```c++
delete marines[0];
delete marines[1];
```

를 해주어야 하겠지요.

#### 소멸자

```c++
Marine::Marine(int x, int y, const char* marine_name) {
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
```


우리는 분명히 위 코드에서 `name` 에 우리가 생성하는 마린의 이름을 넣어줄 때, `name` 을 동적으로 생성해서 문자열을 복사하였는데요, 그럼, 이렇게 동적으로 할당된 `char` 배열에 대한 `delete` 는 언제 이루어지는 것인가요?

안타깝게도, 우리가 명확히 `delete` 를 지정하지 않는 한 자동으로 `delete` 가 되는 경우는 없습니다. 다시 말해서 우리가 동적으로 할당했던 저 `name` 은 영원히 메모리 공간 속에서 둥둥 떠다닌다는 말이지요. 사실 몇 바이트 정도 밖에 되지 않을 것이지만 위와 같은 `name` 들이 쌓이고 쌓이게 되면 메모리 누수 (Memory Leak) 이라는 문제점이 발생하게 됩니다 (가끔 몇몇 프로그램들이 비정상적으로 많은 메모리를 점유하는 것 보이시지 않나요?)

>그렇다면, 만일 `main` 함수 끝에서 `Marine` 이 `delete` 될 때, 즉 우리가 생성했던 객체가 소멸 될 때 자동으로 호출되는 함수 - 마치 객체가 생성될 때 자동으로 호출 되었던 생성자 처럼 소멸 될 때 자동으로 호출되는 함수가 있다면 얼마나 좋을까요? 놀랍게도 이미 C++ 에서는 이 기능을 지원하고 있습니다. 바로 소멸자(Destructor) 이죠.

>생성자가 클래스 이름과 똑같이 생겼다면 소멸자는 그 앞에 `~` 만 붙여주시면 됩니다. `~(클래스 이름)`


위와 같이 생겼지요. 생성자와 한 가지 다른 점은, 소멸자는 인자를 아무것도 가지지 않는다는 것입니다. 생각해보세요. 소멸하는 객체에 인자를 넘겨서 무엇을 하겠습니까? 다시 말해, 소멸자는 오버로딩도 되지 않습니다.

```c++
Marine::~Marine() {
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if (name != NULL) {
    delete[] name;
  }
```

참고로 우리가 따로 생성자를 정의하지 않더라도 디폴트 생성자가 있었던 것 처럼, 소멸자도 디폴트 소멸자(Default Destructor)가 있습니다. 물론, 디폴트 소멸자 내부에선 아무런 작업도 수행하지 않습니다. 만일 소멸자가 필요 없는 클래스라면 굳이 소멸자를 따로 써줄 필요는 없습니다.

#### 복사 생성자

``` c++
#include <string.h>
#include <iostream>

class Photon_Cannon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;

 public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(const Photon_Cannon& pc); // 이것!

  void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "생성자 호출 !" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}
void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}
int main() {
  Photon_Cannon pc1(3, 3);
  Photon_Cannon pc2(pc1);
  Photon_Cannon pc3 = pc2;

  pc1.show_status();
  pc2.show_status();
}
```

> 복사 생성자의 표준 : `T(const T& a);`

위와 같이 복사 생성자 내부에서 `pc` 의 인스턴스 변수들에 접근해서 객체의 `shield, coord_x, coord_y` 등을 초기화 할 수 는 있지만

 `pc` 의 값 자체는 변경할 수 없다는 이야기 입니다. (왜냐하면 `const` 레퍼런스로 인자를 받았기 때문이죠! 아직도 이해가 안되시면 이전에 [포인터에서 const 의](https://modoocode.com/24) [용법](https://modoocode.com/24)을 떠올려보시기 바랍니다. 정확히 하는 동작이 동일합니다.)

한 가지 중요한 점은 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 꼭 `const` 를 붙여주시기 바랍니다. 위와 같이 복사 생성자의 경우도, 인자로 받은 `pc` 의 값을 변경할 일이 없기 때문에 아예 처음부터 `const` 인자로 받았지요. 이렇게 된다면 후에 발생 할 수 있는 실수들을 효과적으로 막을 수 있습니다. (예를 들어 `pc.coord_x = coord_x` 로 쓴다던지)

>인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 앞에 `const` 를 붙여 주는 것이 바람직합니다.

>`pc3 = pc2` 를 했다면 이는 평범한 대입 연산 이겠지만, 생성 시에 대입하는 연산, 즉 위에 같이 `Photon_Cannon pc3 = pc2;` 한다면, 복사 생성자가 호출되게 되는 것입니다. 이런식으로 `Photon_Cannon pc3 = pc2;` 를 해석함으로써 사용자가 상당히 직관적이고 깔끔한 프로그래밍을 할 수 있습니다.

`Photon_Cannon pc3 = pc2;` 와 

```c++
Photon_Cannon pc3;
pc3 = pc2;
```

는 엄연히 다른 문장입니다. 왜냐하면 위의 것은 말 그대로 복사 생성자가 1 번 호출되는 것이고, 아래 것은 그냥 생성자가 1 번 호출되고, `pc3 = pc2;` 라는 명령이 실행되는 것이지요. 다시 한 번 강조하지만, 복사 생성자는 오직 '생성' 시에 호출된다는 것을 명심하시면 됩니다.

그런데, 사실 디폴트 생성자와 디폴트 소멸자 처럼, C++ 컴파일러는 이미 디폴트 복사 생성자(Default copy constructor) 를 지원해 주고 있습니다. 위 코드에서 복사 생성자를 한 번 지워보시고 실행해보면, 이전과 정확히 동일한 결과가 나타남을 알 수 있습니다. 디폴트 복사 생성자의 경우 기존의 디폴트 생성자와 소멸자가 하는 일이 아무 것도 없었던 것과는 달리 실제로 '복사' 를 해줍니다.

> 디폴트 복사 생성자가 있으며, 그는 디폴트 생성자와 달리 복사를 해주는 역할을 지님.

#### 디폴트 복사 생성자의 한계

클래스가 만약 힙에 메모리가 할당되는 자료를 지닐 때, 복사 과정 후 사용까지는 문제가 없지만, 소멸자를 통해 해당 메모리를 중복초기화 함으로서, 오류가 일어날 수 있음.

그렇기 때문에, 해당 상황에서는 수동으로 복사 생성자를 이용하여 별개의 메모리를 할당시켜주어야 함.


>혹시 이 강좌만 보고 뒤의 강좌를 안보시는 분들을 위해 노파심에 이야기 하지만, C++ 에서 문자열을 다룰 때 C 언어 처럼 널 종료 `char` 배열로 다루는 것을 매우 매우 매우 비추합니다. C++ 표준 라이브러리에서 [std::string](https://modoocode.com/237) 이라는 훌륭한 문자열 클래스를 제공하니까, 뒤의 강좌들도 꼭 읽어서 사용법을 숙지하시기 바랍니다.

라는 참고사항이 있었다. 나는 계속 공부할 것이니, 우선 넘어감

### 2023-01-27 

4-3 연습문제는 풀었지만, C6386 주의가 나옴. 자세히 알아볼 필요 있음. #재확인 #5 이슈

-------------------------------------------------------------

### 2023-01-28

## 4-4

#### 생성자 초기화 리스트, 클래스의 const, static 변수, 레퍼런스 타입을 리턴하는 함수, this 포인터, const 멤버 함수 등

#### 생성자 초기화 리스트
```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {} // 생성자 초기화 리스트!

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();
}
```

>생성자 대신, 해당 부분처럼 생성자 초기화 리스트로 적을 수 있다.

멤버 초기화 리스트의 일반적인 꼴은 아래와 같습니다.

```c++
(생성자 이름) : var1(arg1), var2(arg2) {}
```

여기서 `var` 들은 클래스의 멤버 변수들을 지칭하고, `arg` 는 그 멤버 변수들을 무엇으로 초기화 할 지 지칭하는 역할을 합니다.

>한 가지 흥미로운 점은 `var1` 과 `arg1` 의 이름이 같아도 되는데, 실제로 아래의 예제는

```c++
Marine::Marine(int coord_x, int coord_y)
    : coord_x(coord_x), coord_y(coord_y), hp(50), damage(5), is_dead(false) {}
```

정상적으로 작동합니다. 왜냐하면 `coord_x ( coord_x )` 에서 바깥쪽의 `coord_x` 는 무조건 멤버 변수를 지칭하게 되는데, 이 경우 `coord_x` 를 지칭하는 것이고, 괄호 안의 `coord_x` 는 원칙상 `Marine` 이 인자로 받은 `coord_x` 를 우선적으로 지칭하는 것이기 때문입니다.

따라서 실제로, 인자로 받은 `coord_x` 가 클래스의 멤버 변수 `coord_x` 를 초기화 하게 됩니다. 아래는 당연한 얘기 겠지만
```c++
Marine::Marine(int coord_x, int coord_y) {
  coord_x = coord_x;
  coord_y = coord_y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
```

컴파일러가 두 `coord_x` 모두 인자로 받은 `coord_x` 로 구분해서 오류가 나겠지요.

> 초기화 리스트의 장점: 생성과 초기화를 동시에 진행할 수 있게 된다!

초기화 리스트는 `int a=3;` 같은거고, 그냥 생성자는 `int a; a=3;` 같은거다.

딱 보아도 후자가 조금 더 하는 작업이 많게 됩니다. 따라서 초기화 리스트를 사용하는 것이조금 더 효율적인 작업이라는 사실을 알 수 있지요. 그 뿐만 아니라, 우리 경험상 반드시 '생성과 동시에 초기화 되어야 하는 것들' 이 몇 가지 있었습니다. 대표적으로 레퍼런스와 상수가 있지요.

앞서 배운 바에 따르면 상수와 레퍼런스들은 모두 생성과 동시에 초기화가 되어야 합니다.

>모두 컴파일 오류가 나겠지요. 따라서 만약에 클래스 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 !!!초기화 리스트!!!를 사용해서 초기화 시켜주어야만 합니다. 

```c++
Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {}
```
>위처럼, 상수를 초기화하는것도, 처음 초기화할때 유동적으로 입력받아서 할 수 있다.

#### 생성된 총 `Marine` 수 세기 (static 변수)

 C++ 에서는 위와 같은 문제를 간단하게 해결 할 수 있는 기능을 제공하고 있습니다. 마치 전역 변수 같지만 클래스 하나에만 종속되는 변수인 것인데요, 바로 `static` 멤버 변수입니다.

>어떤 클래스의 `static` 멤버 변수의 경우, 멤버 변수들 처럼, 객체가 소멸될 때 소멸되는 것이 아닌, 프로그램이 종료될 때 소멸되는 것입니다.
>
>또한, 이 `static` 멤버 변수의 경우, 클래스의 모든 객체들이 '공유' 하는 변수로써 각 객체 별로 따로 존재하는 멤버 변수들과는 달리 모든 객체들이 '하나의' `static` 멤버 변수를 사용하게 됩니다. 그럼 바로 아래의 예제를 살펴 보도록 합시다.

해당 변수를 활용하여, 생성자에서는 ++, 소멸자에서는 --하는식으로 작동시키면, marine의 수를 셀 수 있다.

```c++
class Marine {
  static int total_marine_num = 0;
```

와 같이 초기화 해도 되지 않냐고 묻는 경우가 있는데, 멤버 변수들을 위와 같이 초기화 시키지 못하는 것처럼 `static` 변수 역시 클래스 내부에서 위와 같이 초기화 하는 것은 불가능 합니다. 위와 같은 꼴이 되는유일한 경우는 `const static` 변수일 때만 가능한데, 실제로
```c++
class Marine {
  const static int x = 0;
```
으로 쓸 수 있습니다.


#### static 함수

그런데 클래스 안에 `static` 변수 만 만들 수 있는 것이 아닙니다. 놀랍게도 클래스 안에는 `static` 함수도 정의할 수 있는데, `static` 변수가 어떠한 객체에 종속되는 것이 아니라, 그냥 클래스 자체에 딱 1 개 존재하는 것인 것 처럼, `static` 함수 역시 어떤 특정 객체에 종속되는 것이 아니라 클래스 전체에 딱 1 개 존재하는 함수입니다.

즉, `static` 이 아닌 멤버 함수들의 경우 객체를 만들어야지만 각 멤버 함수들을 호출할 수 있지만 `static` 함수의 경우, 객체가 없어도 그냥 클래스 자체에서 호출할 수 있게 됩니다. 그럼, 아래 예제를 살펴볼까요.

```c++
// static 함수
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4);
  Marine::show_total_marine();
}
int main() {
  Marine marine1(2, 3, 5);
  Marine::show_total_marine();

  Marine marine2(3, 5, 10);
  Marine::show_total_marine();

  create_marine();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

`static` 함수는 앞에서 이야기 한 것과 같이, 어떤 객체에 종속되는 것이 아니라 클래스에 종속되는 것으로, 따라서 이를 호출하는 방법도 `(객체).(멤버 함수)` 가 아니라, `(클래스)::(static 함수)` 형식으로 호출하게 됩니다. 왜냐하면 어떠한 객체도 이 함수를 소유하고 있지 않기 때문이죠. 그러하기에, `static` 함수 내에서는 클래스의 `static` 변수 만을 이용할 수 밖에 없습니다.

#### this 포인터

this는 객체 자신을 가르키는 포인터 역할을 함. 모든 멤버 함수 내(static 함수 제외)에 자동으로 정의되어 있는 키워드임.


#### 레퍼런스 리턴 함수

```c++
// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}

  int& access_x() { return x; }
  int get_x() { return x; }
  void show_x() { std::cout << x << std::endl; }
};

int main() {
  A a(5);
  a.show_x();

  int& c = a.access_x(); // 참조자 됨
  c = 4; // a.x = 4가 된 셈임.
  a.show_x();

  int d = a.access_x(); // 단순 복사(x의 임시 별명을 복사)
  d = 3; // 단순히 d = 3임. 
  a.show_x();

  // 아래는 오류
  // int& e = a.get_x();
  // e = 2; // 함수가 끝나면 사라지는 임시 변수 x를 참조자에 대입하려고 하니까 오류 발생.
  // a.show_x();

  int f = a.get_x(); // 단순 복사(x로부터 복사)
  f = 1;
  a.show_x();
}
```

오류가 나는 이유.
그 이유는 레퍼런스가 아닌 타입을 리턴하는 경우는 '값' 의 복사가 이루어지기 때문에 임시 객체가 생성되는데, 임시객체의 레퍼런스를 가질 수 없기 때문입니다. (임시객체는 문장이 끝나게 되면 소멸됩니다) 이 과정을 그림으로 그려보면 아래와 같습니다.

![이미지](https://modoocode.com/img/272F193851A18E5A29B569.webp)

`get_x` 의 리턴으로 인해 임시로 '복사생성' 된 `int` 는 `a.get_x()` 부분을 대체하며 위 그림의 경우

```c++
int &e = x';
```
과 같이 되는데, x' 은 문장이 끝날 때 자동으로 소멸되는 임시 객체 이기 때문에 레퍼런스를 만들 수 없습니다. 설사 레퍼런스를 만들었다고 해도 '이미 존재하지 않는 것에 대한 별명' 이 되므로 이 레퍼런스에 접근하는 것은 오류이겠지요.

아무튼 이러한 이유로 `int` 를 리턴하는 `a.get_x` 에 대해서는 레퍼런스를 만들 수 없습니다. (정확한 설명을 하자면 `int&` 는 좌측값에 대한 레퍼런스 이고, `a.get_x()` 는 우측값 이기 때문에 레퍼런스를 만들 수 없습니다. 좌측값, 우측값 내용은 나중에 더 자세히 다루겠지만 [궁금하신 분들은 이 글을 읽어보세요](https://modoocode.com/189)`!)` #재확인 

그럼 이제 다시 예전의 `Marine` 예제로 돌아가보도록 합시다.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}
```

위 경우 `be_attacked` 함수는 `Marine&` 타입을 리턴하게 되는데, 위 경우, `*this` 를 리턴하게 됩니다. 앞에서도 말했지만 `this` 가 지금 이 함수를 호출한 객체를 가리키는 것은 기억 하시죠? 그렇기 때문에 `*this` 는 그 객체 자신을 의미하게 됩니다. 따라서,

```c++
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
```

문장의 경우, 먼저 `marine2.be_attacked(marine1.attack())` 이 먼저 실행되고 리턴되는 것이 다시 `marine2` 이므로 그 다음에 또 한 번`marine2.be_attacked(marine1.attack`()) 가 실행된다고 생각할 수 있습니다.

간단하죠? 만일, `be_attacked` 함수의 리턴 타입이 `Marine&` 이 아니라 그냥 `Marine` 이라고 해봅시다. 즉, 만일 `be_attacked` 함수가 아래와 같이 바뀌었다고 가정한다면

```c++
MarineMarine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}
```

다시 같은 문장을 실행해보면 `marine2` 는 실제로 두 번 공격이 아닌 1 번 공격으로 감소한 `HP` 만을 보입니다. (즉 40 이 아닌 45 로 나옴) 이는 앞에서도 설명했듯이 리턴타입이 `Marine` 이므로, 임시 객체 `Marine` 을 생성해서, `*this` 의 내용으로 복사가 되고 (즉, `Marine` 의 복사 생성자 호출) 이 임시 객체에 대한 `be_attacked` 함수가 호출되게 되는 것입니다.

따라서 결국 두 번째 `be_attacked` 는 `marine2` 가 아닌 엉뚱한 임시 객체에 대해 호출되는 것이므로 결국 `marine2` 는 `marine1` 의 공격을 1 번만 받게 됩니다.

>참고. 만약 Marine& be_attacked 형식을 사용하지 않으면, 위처럼 연속으로 함수를 사용하는것 자체가 불가능함.


#### const 함수

`(기존의 함수의 정의) const;` 와 같은 방식으로 정의한다.

예 : 
```c++
int Marine::attack() const { return default_damage; }
```

그렇게 하였으면 위 `attack` 함수는 '상수 멤버 함수' 로 정의된 것입니다. 우리는 상수 함수로 이 함수를 정의함으로써, 이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 다른 프로그래머에게 명시 시킬 수 있습니다. 

>당연하게도, 상수 함수 내에서는 객체들의 '읽기' 만이 수행되며, 상수 함수 내에서 호출 할 수 있는 함수로는 다른 상수 함수 밖에 없습니다.

사실 많은 경우 클래스를 설계할 때, 멤버 변수들은 모두 `private` 에 넣고, 이 변수들의 값에 접근하는 방법으로 `get_x` 함수 처럼 함수를 `public` 에 넣어 이 함수를 이용해값을 리턴받는 형식을 많이 사용합니다. 이렇게 하면 멤버 변수들을 `private` 에 넣음으로써 함부로 변수에 접근하는 것을 막고, 또 그 값은 자유롭게 구할 수 있게 됩니다.

#### 생각해보기 문제

```c++
#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

 public:
  B(int c) : a(c) {}
  B(const B& b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main() {
  B b(10);

  std::cout << "---------" << std::endl;
  A a1 = b.get_A();
}
```
> 해당 코드에서 "복사 생성"은 몇번 출력되는가?

(난이도 : 上 -사실 이 글을 잘 읽었더라면 틀리게 답하는 것이 맞습니다. 컴파일러는 불필요한 복사를 막기 위해 _copy elision_ 이라는 기술을 사용하고 있는데, 이에 관해서는 추후에 이야기 하도록 하겠습니다. 정 궁금하신 분들은 [http://en.wikipedia.org/wiki/Copy_elision](http://en.wikipedia.org/wiki/Copy_elision) 를 읽어보시기 바랍니다.)

정답 : 3번. A temp(a)에서 한번, return temp에서 한번, A a1 = b.get_A()에서 복사 생성자로 바로 들어가면서 한번.

나는 return temp는 놓쳤었다. 임시 객체에 대한 내용 숙지할 것!

-------------------------------------------------------------

## 4-5

문자열 클래스 만들기 실습!

##### 2023-01-29

실습 도중, `_crtlsvalidheappointer(block)`  오류가 발생했었음. 하지만, 해결함. 이유는 정확히 아직 모르겠지만, 함수 인자를 받을 때, `const String other_string`으로 받은 것이 문제같음. `const String& other_string`으로 받자, 문제가 해결됨. #해결 

다만, 전자로 적으면, 함수가 끝날 때, other_string이 삭제될 때, 소멸자가 작동하는데, b가 초기화됨. 복사된게 초기화되는게 아니고, 왜 원래 것에 영향을 주지? #재확인 


기존 [C 언어에서는 문자열을 나타내기 위해 널 종료 문자열(Null-terstd::minating string)](https://modoocode.com/29)이라는 개념을 도입해서 문자열 끝에 `NULL` 문자를 붙여 문자열을 나타내는 방식을 사용하였습니다.

하지만 C 언어 문자열을 사용하는데에는 번거로움이 많았는데, 예를 들어서 만들어진 문자열의 크기를 바꾼다던지, 문자열 뒤에 다른 문자열을 붙인다던지 등의 작업들은 상당히 프로그래머 입장에서는 귀찮을 수 밖에 없습니다. 이와 같은 작업들을 문자열 클래스를 따로 만들어서 클래스 차원에서 지원해주면 상당히 편할 텐데 말이지요. 그래서 우리는 직접 문자열 클래스를 만들고자 합니다.

사실 C++ 에서는 표준 라이브러리로 [string](https://modoocode.com/237) 클래스를 지원하고 있습니다. (실제로 [string](https://modoocode.com/233) 헤더파일을 `include` 하면 사용할 수 있습니다.)

>노파심에 이야기 하지만 C++ 에서는 정말 왠만하면 `char` 배열을 사용하는 것보다 [string](https://modoocode.com/237) 을 사용해서 문자열을 다루는 것을 권정합니다. 뒤에 강좌에서 [string](https://modoocode.com/237) 클래스를 어떻게 사용하는지 자세히 다룹니다.

하지만 이 막강한 [string](https://modoocode.com/237) 클래스를 사용하기 이전에 우리는 직접 `MyString` 이라는 우리 만의 문자열 클래스를 만들고자 합니다.

[블로그 링크, 나와는 좀 다르게 만드니 참고할 것,](https://modoocode.com/198)

```c++
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);

  MyString& erase(int loc, int num);

  int find(int find_from, const MyString& str) const;
  int find(int find_from, const char* str) const;
  int find(int find_from, char c) const;

  int compare(const MyString& str) const;
};

MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}
MyString::MyString(const char* str) {
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}
void MyString::println() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
  // loc 의 앞 부터 시작해서 num 문자를 지운다.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
  // 생각하면 됩니다.

  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}
int MyString::find(int find_from, const MyString& str) const {
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i <= string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
  MyString temp(str);
  return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
  MyString temp(c);
  return find(find_from, temp);
}
int MyString::compare(const MyString& str) const {
  // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
  // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
  // 이 같다는 의미, -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.

  for (int i = 0; i < std::min(string_length, str.string_length); i++) {
    if (string_content[i] > str.string_content[i])
      return 1;

    else if (string_content[i] < str.string_content[i])
      return -1;
  }

  // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
  // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

  if (string_length == str.string_length) return 0;

  // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
  else if (string_length > str.string_length)
    return 1;

  return -1;
}
int main() {
  MyString str1("abcdef");
  MyString str2("abcde");

  std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
```

이것으로, 여태까지 배운 C++ 에 대한 내용을 종합해서 훌륭한 `MyString` 클래스를 만들었다고 볼 수 있습니다. 우리의 `MyString` 클래스는 다음과 같은 인터페이스를 제공합니다.

-   문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
    
-   문자열의 길이를 리턴하는 함수(length)
    
-   문자열 대입 함수(assign)
    
-   문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
    
-   특정 위치의 문자를 리턴하는 함수(at)
    
-   특정 위치에 특정 문자열을 삽입하는 함수(insert)
    
-   특정 위치의 특정 개수의 문자를 지우는 함수(erase)
    
-   특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
    
-   두 문자열을 사전식 비교하는 함수(compare)
    

이 정도면 괜찮은 문자열 클래스라고 볼 수 있지 않나요 ㅎㅎ. 이번 강좌를 통해서 현재 까지 배운 C++ 클래스에 좀더 친숙해 질 수 있는 좋은 경험이 되었으면 합니다. 자, 그럼 이것으로 이번 강좌를 마치도록 하겠습니다.

#### 문제

여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 [find](https://modoocode.com/261) 함수를 만들어보세요. 어떤 알고리즘의 경우 미리 계산된 테이블이 필요할 텐데, 이러한 정보들 역시 `class` 변수로 처리하셔도 됩니다. (난이도 : 上) #재확인 

-------------------------------------------------------------

### 2023-02-05

## 4-6

##### explicit, mutable에 대해 배울 예정

#### explicit

`DoSomethingWithString("abc")`

일단 `DoSomethingWithString` 함수를 살펴보면 인자로 `MyString` 을 받고 있습니다. 하지만 "`abc`" 는 `MyString` 타입이 아니지요. 그런데 C++ 컴파일러는 꽤나 똑똑해서 "`abc`" 를 어떻게 하면 `MyString` 으로 바꿀 수 있는지 생각해봅니다. 그리고 다행이도 `MyString` 의 생성자들 중에서는

```c++
// 문자열로 부터 생성
MyString(const char* str);
```

위와 같이 `const char*` 로 부터 생성하는 것이 있었습니다. 따라서, `DoSomethingWithString("abc")` 는 알아서

`DoSomethingWithString(MyString("abc"))`

로 변환되서 컴파일 됩니다. 위와 같은 변환을 암시적 변환(implicit conversion) 이라고 부릅니다. 하지만 암시적 변환이 언제나 사용자에게 편리한 것은 아닙니다. 때로는 예상치 못한 경우에 암시적 변환이 일어날 수 도 있습니다.

```c++
DoSomethingWithString(3)
// 해당 함수 호출은

// capacity 만큼 미리 할당함.
MyString(int capacity);
//와 연결될 것이고, 의도치 않은 암시적 변환이 일어날 것.

DoSomethingWithString(MyString(3))
//로 컴파일 될것.
//mystring 생성자에, explicit을 사용하면, 이를 막을 수 있음.
```

컴파일러에서 해당 `MyString` 생성자를 `explicit` 으로 선언한다면 이 생성자를 이용한 암시적 변환을 수행하지 못하게 막을 수 있습니다. 실제 컴파일 오류 메세지를 보아도, `int` 에서 `MyString` 으로 변환할 수 없다고 나옵니다.

`explicit` 은 또한 해당 생성자가 복사 생성자의 형태로도 호출되는 것을 막게 됩니다.

#### mutable

다음으로 살펴볼 키워드로 `mutable` 이 있습니다. 혹시 이전에 배우신 `const` 멤버 함수 기억 하시나요? `const` 함수 내부에서는 멤버 변수들의 값을 바꾸는 것이 불가능 합니다. 하지만, 만약에 멤버 변수를 `mutable` 로 선언하였다면 const 함수에서도 이들 값을 바꿀 수 있습니다.


 >그래서 mutable 이 왜 필요한데?

먼저 멤버 함수를 왜 `const` 로 선언하는지 부터 생각해봅시다. 클래스의 멤버 함수들은 이 객체는 이러이러한 일을 할 수 있습니다 라는 의미를 나타내고 있습니다.

그리고 멤버 함수를 `const` 로 선언하는 의미는 이 함수는 객체의 내부 상태에 영향을 주지 않습니다 를 표현하는 방법 입니다. 대표적인 예로 읽기 작업을 수행하는 함수들을 들 수 있습니다.

대부분의 경우 의미상 상수 작업을 하는 경우, 실제로도 상수 작업을 하게 됩니다. 하지만, 실제로 꼭 그렇지만은 않습니다. 예를 들어서 아래와 같은 서버 프로그램을 만든다고 해봅시다.

```c++
class Server {
  // .... (생략) ....

  // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
  User GetUserInfo(const int user_id) const {
    // 1. 데이터베이스에 user_id 를 검색
    Data user_data = Database.find(user_id);

    // 2. 리턴된 정보로 User 객체 생성
    return User(user_data);
  }
};
```

이 서버에는 `GetUserInfo` 라는 함수가 있는데 입력 받은 `user_id` 로 데이터베이스에서 해댱 유저를 조회해서 그 유저의 정보를 리턴하는 함수 입니다. 당연히도 데이터베이스를 업데이트 하지도 않고, 무언가 수정하는 작업도 당연히 없기 때문에 `const` 함수로 선언되어 있습니다.

그런데 대개 데이터베이스에 요청한 후 받아오는 작업은 꽤나 오래 걸립니다. 그래서 보통 서버들의 경우 메모리에 캐쉬(cache)를 만들어서 자주 요청되는 데이터를 굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 합니다.

물론 캐쉬는 데이터베이스만큼 크지 않기 때문에 일부 유저들 정보 밖에 포함하지 않습니다. 따라서 캐쉬에 해당 유저가 없다면 (이를 캐쉬 미스-cache miss 라고 합니다), 데이터베이스에 직접 요청해야겠지요. 대신 데이터베이스에서 유저 정보를 받으면 캐쉬에 저장해놓아서 다음에 요청할 때는 빠르게 받을 수 있게 됩니다.

보통 한 번 요청된 정보는 계속해서 요청될 확률이 높기때문에 캐쉬에 넣게 됩니다. 물론 캐쉬 크기는 한정적이니까 이전에 오래된 캐쉬부터 지우게됩니다.

이를 구현한다면 아래와 같겠지요.

```c++
class Server {
  // .... (생략) ....

  Cache cache; // 캐쉬!

  // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
  User GetUserInfo(const int user_id) const {
    // 1. 캐쉬에서 user_id 를 검색
    Data user_data = cache.find(user_id);

    // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
    if (!user_data) {
      user_data = Database.find(user_id);

      // 그 후 캐쉬에 user_data 등록
      cache.update(user_id, user_data); // <-- 불가능
    }

    // 3. 리턴된 정보로 User 객체 생성
    return User(user_data);
  }
};
```


그런데 문제는 `GetUserInfo` 가 `const` 함수라는 점입니다. 따라서

> const 함수의 특징.
> 요약하자면 const가 뒤에 붙은 함수에는 2가지 기능이 존재한다.
> -   객체 내부 변수 변경 불가.
> -   const 함수만 호출 가능.

`cache.update(user_id, user_data);  // <-- 불가능`

위 처럼 캐쉬를 업데이트 하는 작업을 수행할 수 없습니다. 왜냐하면 캐쉬를 업데이트 한다는 것은 케쉬 내부의 정보를 바꿔야 된다는 뜻이기 때문이죠. 따라서 저 `update` 함수는 `const` 함수가 아닐 것입니다.

그렇다고 해서 `GetUserInfo` 에서 `const` 를 떼기도 좀 뭐한것이, 이 함수를 사용하는 사용자의 입장에선 당연히 `const` 로 정의되어야 하는 함수 이기 때문이지요. 따라서 이 경우, `Cache` 를 `mutable` 로 선언해버리면 됩니다.

`mutable Cache cache;  // 캐쉬!`

위 처럼 말이지요. 이렇듯, `mutable` 키워드는 `const` 함수 안에서 해당 멤버 변수에 `const` 가 아닌 작업을 할 수 있게 만들어줍니다.

-------------------------------------------------------------

### 2023-02-07

## 5-1

##### 산술 연산자, 비교 연산자, 대입 연산자 오버로딩

안녕하세요 여러분! 지난 강좌에서 만들었던 `MyString` 을 손 좀 봐주었나요? 아마도 `MyString` 을 이용하여 여러가지 작업을 하면서 다음과 같은 생각을 하셨을 수도 있었을 것입니다.

-   `if(str1.compare(str2) == 0)` 하지 말고 `if(str1 == str2)` 하면 어떨까?
    
-   `str1.insert(str1.length(), str2)` 하지 말고 `str1 = str1 + str2;` 하면 어떨까?
    
-   `str1[10] = 'c';` 와 같은 것도 할 수 있을까?
    

물론 C 언어에서는 이러한 것을 상상조차 할 수 없었습니다. `+, -, ==, []` 와 같은 기본 연산자들은 모두 C 언어에 기본적으로 정의되어 있는 데이터 타입(`int, float` 등)에만 사용 가능한 것들 이였기 때문이죠. 이들을 구조체 변수에 사용한다는 것은 불가능하였습니다.

하지만 놀랍게도 C++ 에서는 사용자 정의 연산자를 사용할 수 있습니다. 어떠한 연산자들이 가능하나면, `::` (범위 지정), `.` (멤버 지정), `.*` (멤버 포인터로 멤버 지정) 을 제외한 여러분이 상상하는 모든 연산자를 사용할 수 있다는 것입니다. 대표적으로

-   `+, -, *` 와 같은 산술 연산자
    
-   `+=, -=` 와 같은 축약형 연산자
    
-   `>=, ==` 와 같은 비교 연산자
    
-   `&&`, `||` 와 같은 논리 연산자
    
-   `->` 나 `*` 와 같은 멤버 선택 연산자 (여기서 `*` 는 역참조 연산자 입니다. 포인터에서 `*p` 할 때 처럼)
    
-   `++, --` 증감 연산자
    
-   `[]` (배열 연산자) 와 심지어 `()` 까지 (함수 호출 연산자)
    

까지 모두 여러분이 직접 만들 수 있습니다.

이 때 이러한 기본 연산자들을 직접 사용자가 정의하는 것을 연산자를 오버로딩(overloading) 한다고 부릅니다. 이전에 같은 이름의 함수를 인자만 다르게 사용하는 것을 '함수를 오버로딩 했다' 라고 불렀던 것 처럼, 기본 연산자를 여러분이 설계한 클래스에 맞게 직접 사용하는 것을 '연산자를 오버로딩 했다' 라고 부릅니다.

> 작성 방법은 다음과 같다.
> `(리턴 타입) operator(연산자) (연산자가 받는 인자)`

이제, 우리가 `str1 == str2` 라는 명령을 한다면 이는 `str1.operator==(str2)` 로 내부적으로 변환되서 처리됩니다.

```c++
bool MyString::operator==(MyString& str) {
  return !compare(str);  // str 과 같으면 compare 에서 0 을 리턴한다.
}
// 이처럼 적을 수 있음.
```


복소수 클래스를 예시로 만드는데, 그는 [블로그](https://modoocode.com/202) 직접 참고

#에러해결 `"const char *" 형식의 값을 "char" 형식의 엔터티에 할당할 수 없습니다.` [에러해결 관련 링크](https://rewritestar.tistory.com/20)

>중간 부분에 나오는 말
>한 가지 재미있는 사실은 굳이 `operator=` 를 만들지 않더라도, 위 소스를 컴파일 하면 잘 작동한다는 점입니다. 이는 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator)를 지원하고 있기 때문인데, 이전에 [복사 생성자를 다룰 때 디폴트 복사 생성자](https://modoocode.com/188)가 있었던 것과 일맥상통합니다.

>디폴트 복사 생성자와 마찬가지로 디폴트 대입 연산자 역시 얕은 복사를 수행합니다. 따라서, 깊은 복사가 필요한 클래스의 경우 (예를 들어, 클래스 내부적으로 동적으로 할당되는 메모리를 관리하는 포인터가 있다던지) 대입 연산자 함수를 꼭 만들어주어야 할 필요가 있습니다.

여기까지 읽고 갔으면 에러 고치는데 덜 고생했을 텐데..



참고로, 연산자 오버로딩을 사용하게 된다면 `a+= b` 와 `a = a +` b; 가같다고 보장되지 않는다는 점을 명심해야 합니다. 컴파일러는 `operator+` 와 `operator=` 를 정의해놓았다고 해서 `a+=b` 를 자동으로 `a = a +` b; 로 바꾸어 주지 않습니다. 반드시 `operator+=` 를 따로 만들어야지 `+=` 를 사용할 수 있게 됩니다. 이와 같은 사실은 `++` 을 `+= 1` 로 바꾸어 주지 않는다던지, `--` 를 `-= 1` 로 바꾸어 주지 않는 다는 사실과 일맥상통합니다. 즉, 연산자 오버로딩을 하게 된다면 여러분이 생각하는 모든 연산자들에 대해 개별적인 정의가 필요합니다.

`a = a + "-1.1 + i3.923";`

와 같은 문장을 사용하였을 때, 앞에서 이야기 해왔듯이 컴파일러가 위 문장을

`a = a.operator+("-1.1 + i3.923");`

로 바꿔줍니다. 하지만, 우리에게는 `operator+(const char *str)` 이 없고, `operator+(const Complex& c)` 밖에 없기 때문에 직접적으로 오버로딩 되지는 않습니다. 그렇지만, 컴파일러는 매우 똑똑하기 때문에 그 다음 순위로 오버로딩 될 수 있는 함수들이 있는지 없는 지 확인해봅니다. 그런데 놀랍게도, 우리에게는 `const char *` 에서 `Complex` 를 생성할 수 있는 생성자

`Complex(const char* str);`

가 있기 때문에 컴파일러는 문자열 리터럴로 부터 `const Complex` 타입의 객체를 새롭게 생성할 수 있게 된다는 것입니다. 즉, 위 문장은 은 다음과 같이 변환됩니다.

`a = a.operator+(Complex("-1.1 + i3.923"));`

그럼 이제 `const Complex` 에 인자로 전달할 수 있게 되어서 제대로 프로그램이 작동을 하게 되지요. 여기서 한 가지 짚고 넘어가야 할 점은, 만일 우리가 `operator+` 함수의 인자가 `const Complex& c` 가 아니라 그냥 `Complex& c` 로 받도록 하였다면 위와 같은 변환은 이루어지지 않습니다. 왜냐하면 `-1.1 + i3.923` 자체가 문자열 리터럴 이므로, 이를 바탕으로 생성된 객체 역시 상수 여야 하기 때문입니다. 따라서여러 모로 함수 인자의 값을 변형하지 않는다고 확신이 들면 무조건 `const` 인자로 받도록 하는 것이 좋습니다.

> 이전에 explicit, mutable할때 이야기했던 부분을 이용한 것 같다.


##### 복습 시 꼭 블로그 내용 확인!

연습문제 : mystring 클래스 더 완벽하게 만들어보기 (연산자 오버로딩 포함)
#재확인 짚고 넘어가야할 문제.

-------------------------------------------------------------

## 5-2

이번 강좌에서는

-   멤버 함수가 아닌 연산자 함수 오버로딩
    
-   입출력 연산자 오버로딩 (정확히 보면 `<<, >>` 연산자)
    
-   첨자 연산자 `[]` 오버로딩
    
-   타입 변환 연산자 오버로딩
    
-   증감 연산자 `++, --` 오버로딩
    

에 대해 다룹니다.

#### friend 키워드

>`friend` 키워드는 클래스 내부에서 다른 클래스나 함수들을 friend 로 정의할 수 있는데, `friend` 로 정의된 클래스나 함수들은 원래 클래스의 `private` 로 정의된 변수나 함수들에 접근할 수 있습니다.

정말 친한 친구 사이라 보면 됩니다.

한 가지 재미있는 점은 이 친구 관계가 **짝사랑** 과 같다는 점입니다. 즉 위 경우 `B` 는 `A` 의 모든 `private` 들을 볼 수 있지만, `B` 안에서 `A` 를 `friend` 로 지정하지 않는 이상, `A` 는 `B` 의 `private` 개체들에 접근할 수 없습니다.

```c++
class A {
 private:
  void private_func() {}
  int private_num;

  // B 는 A 의 친구!
  friend class B;

  // func 은 A 의 친구!
  friend void func();
};

class B {
 public:
  void b() {
    A a;

    // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
  // 가능하다.
  a.private_func();
  a.private_num = 2;
}

int main() {}
```

#### 이항 연산자

##### 2023-02-20

>통상적으로 자기 자신을 리턴하지 않는 이항 연산자들, 예를 들어 위와 같은 `+`, `-`, `*`, `/` 들은 모두 외부 함수로 선언하는 것이 원칙 입니다. 반대로 자기 자신을 리턴하는 이항 연산자들, 예를 들어 `+=`, `-=` 같은 애들은 모두 멤버 함수로 선언하는 것이 원칙 입니다.

> 자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의합시다!


> << 연산자

```c++
std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}
```

하지만 위 `operator<<` 의 경우 한 가지 문제가 있는데 바로 이 `operator<<` 에서 `c.real` 과 `c.img` 에 접근할 수 없다는 점입니다. 왜냐하면 `real` 과 `img` 모두 `Complex` 클래스의 `private` 멤버 변수들이기 때문이죠.

따라서 이를 해결하기 위해 세 가지 방법을 고려할 수 있습니다.

1.  그냥 `real` 과 `img` 를 `public` 으로 바꾼다.
    
2.  `Complex` 에 `print(std::ostream& os)` 와 같은 멤버 함수를 추가한 뒤, 이를 `operator<<` 에서 호출한다.
    
3.  위 `operator<<` 를 `friend` 로 지정한다.
    

첫 번째 방법은 그닥 권장되지 않는 방법입니다. 구현 디테일은 최대한 숨기는 것이 좋습니다. 두 번째 방법은 나름 괜찮은 방법이기는 합니다. 하지만 `friend` 를 활용해보자는 입장에서 세 번째 방법을 사용해보도록 하겠습니다.

```c++
friend ostream& operator<<(ostream& os, const Complex& c);
```
위와 같이 `friend` 선언을 해주시면 됩니다. 비슷한 방법으로 `Complex` 객체 `c` 에 대해 `cin >> c;` 와 같은 작업을 할 수 있습니다. 다만, 이번에는 [cin](https://modoocode.com/280) 은 [istream](https://modoocode.com/146) 객체이고, `opreator>>` 를 오버로딩 해야 된다는 점이 다를 뿐이지요.



>[] 연산자

```c++
char& MyString::operator[](const int index) { return string_content[index]; }
```

> 타입 변환 연산자도 있음. (Wrapper 클래스)

오퍼레이터의 역할이 동일할 때는, 일일이 하나씩 써주는 것이 아니라,
`operator int() { return data; }` 으로 int의 모든 오퍼레이터를 모두 가져올 수 있음.
data는 class 내부의 int 변수

자세한 내용은 5-2 내부 참고

전위, 후위 연산자도 공부함.

전위 연산자는 
```c++
operator++();
operator--();
```
로 적고,

후위 연산자는
```c++
operator++(int x);
operator--(int x);
```
로 구현함. 실제로 인자로 들어가는 값은 없고, 단순히 구분을 위한 명시 용도임.

```c++
operator++(int);
operator--(int);
```
로 적어도 무방함.

참고로, 구현할땐 a++와, ++a의 반영시점을 고려해서,
```c++
A& operator++() {
  // A ++ 을 수행한다.
  return *this;
}

A operator++(int) {
  A temp(A);
  // A++ 을 수행한다.
  return temp;
}

```
로 차이가 있게 적을 수 있겠음.

따라서 후위 증감 연산의 경우 추가적으로 복사 생성자를 호출하기 때문에 전위 증감 연산보다 더 느립니다.

연산자 오버로딩에 대해 다루면서 몇 가지 중요한 포인트 들만 따로 정리해보자면;

-   두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩 하는 것이 좋습니다. (예를 들어 `Complex` 의 `operator+(const Complex&, const Complex&) const` 와 같이 말입니다.)
    
-   두 개의 객체 사이의 이항 연산자 이지만 한 객체만 값이 바뀐다던지 등의 동등하지 않는 이항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다. (예를 들어서 `operator+=` 는 이항 연산자 이지만 `operator+=(const Complex&)` 가 낫다)
    
-   단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다 (예를 들어 `operator++` 의 경우 멤버 함수로 오버로딩 합니다)
    
-   일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 합니다 (강좌 앞 부분 참고)
    

자, 이것으로 가장 많이 사용되는 연산자 함수들에 대해 알아보았습니다. 이제 슬슬 C++ 언어의 강력함이 느껴지시나요? 다음 강좌에서는 여태까지 배운 내용들을 총 망라하는 조그마한 프로젝트를 해볼려고 합니다. 그 프로젝트는 아래 '생각해보기'에 나와 있는데요, 다음 강좌를 보기 전 까지 아래 문제를 한 번 해결해 보시기 (해결은 못해도 최소한 노력은 하시기) 바랍니다.

>`N` 차원 배열을 제공하는 클래스를 만들어보세요. 이는 여러분이 여태까지 배운 내용을 시험할 것입니다. 참고로, 원소에 접근하기 위해서는 `a[1][2][3]` 과 같은 방법으로 접근하겠지요. 다만 `N` 차원 배열이기 때문에 (N은 객체 생성시에 사용자가 입력합니다) 2 차원 배열은 `a[1][2], 3` 차원 배열은 `a[1][2][3]` 과 같은 방식으로 접근할 것입니다. (난이도 : 最上) #재확인 , !!5-3은 스킵함!!

>영어를 잘하시는 분들은 연산자 오버로딩에 관해 정리해 놓은 [다음 글](http://stackoverflow.com/questions/4421706/operator-overloading)을 읽어보시기를 추천합니다. 참고로 이 글에서 다루지만 본 강좌에서는 다루지 않는 일부 내용들은 아직 배운 내용이 아니라 생략한 것이므로 너무 걱정하지 마시고 복습하는 느낌으로 천천히 읽어보시면 좋습니다. (난이도 : 中)

------------------------------------------------

### 6-1

