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

## 2023-01-21

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

### 2023-01-24

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

와 이거 정말 어렵다....... 나중에 다시 보러 와야겠다.

### 못풀어서 다시 보러 올 부분


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

