c++ 관련 필기사항 정리 문서
========================================

[블로그 링크](https://modoocode.com/135)

## 2023-01-18

1. 왜 c++을 배우냐 부분 읽음
2. 1-1 진행함

------------------------------

## 2023-01-19

### 1-2

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

### 1-3

[구글픽 변수 이름 깔삼하게 짓는 팁](https://google.github.io/styleguide/cppguide.html#Variable_Names)

변수 만드는 법, 포인터 등 대부분의 문법은 c++과 c언어가 동일하다.

for문, while문, if-else문, break, switch도 동일하다.

> std::cin == 입력받기
> `std::cin >> user_input;`

**c++에서는 c언어의 scanf처럼 &연산자를 사용치 않음!**

---------------------------------------------------

### 2

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

~~레퍼런스의 배열과 배열의 레퍼런스 직전까지 공부함~~