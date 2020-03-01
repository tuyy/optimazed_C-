## 문자열 최적화
* C++98과 C++11 이후 표준을 준수하는 컴파일러에서 std::string의 구현은 서로 다를 수 있다. 즉, 기존에 작동하던 코드가 새 표준에서는 작동하지 않을 수도 있다.
* 문자열에는 구현과 관계없이 비용이 높은 함수가 있다.  이 함수들은 메모리를 동적으로 할당하고 표현식에서 값처럼 작동하며 내부에서 복사를 많이한다.

### 문자열은 메모리를 동적으로 할당합니다
* std::string은 문자열이 길어지면 내부 버퍼를 새 문자열의 길이보다 더 큰 공간을 할당한다. (2의 배수)

#### 문자열은 값입니다
* 문자열은 값으로 동작한다.
```C++
std::string s1, s2;
s1 = "hot";
s2 = s1;
s1[0] = 'n';

auto s1 = s1 + s2 + s1 + s2; // 임시 문자열이 생성되고 소멸되는 안티패턴;
```

#### 문자열은 복사를 많이 합니다
* C++11 이후 우측값 참조와 이동 문법으로 인해 복사 비용이 많이 낮아졌다.

#### 문자열 최적화 첫번째 시도, 두번째 시도
* include/test_string.hpp 
```
========== String 최적화 연습 첫 번째==========
ELAPSED:14.548 NAME:removeCharA01(std::string s) : FIRST
ELAPSED:0.040 NAME:removeCharA02(std::string s) : sResult += s[i] 버전
ELAPSED:0.040 NAME:removeCharA03(std::string s) : reserve 버전
ELAPSED:0.044 NAME:removeCharA04(const std::string &s) : 인수 ref 버전
ELAPSED:0.040 NAME:removeCharA05(const std::string &s) : 인수 ref + iter 버전
ELAPSED:0.040 NAME:removeCharA06(const std::string &s) : 인수 ref + iter + out arg 버전
ELAPSED:0.002 NAME:removeCharA07(char *aDest, const char *aSrc, const size_t aSize) : cstyle 버전
========== String 최적화 연습 두 번째==========
ELAPSED:0.683 NAME:removeCharA08(std::string s) : 알고리즘 개선 버전
ELAPSED:0.685 NAME:removeCharA09(std::string s) : 알고리즘 개선 버전2 reserve
ELAPSED:0.013 NAME:removeCharA10(std::string s) : 알고리즘 개선 버전3 reserve + append
ELAPSED:0.525 NAME:removeCharA11(std::string s) : 알고리즘 개선 버전4 erase
```

#### std::stringstream을 사용해 값 의미를 피하세요
```C++
std::stringstream s;
for (int32_t i = 0; i < 10; ++i)
{
    s.clear();
    s << "The square of " << i << " is " << i * i << std::endl;
    log(s.str());
}
```

#### std::string_view
* C++17 부터 지원하는 std::string_view는 std::string의 문제를 해결한다. 부분 문자열을 구하거나 자르기 멤버 함수는 동일한 작동을 하는 std::string의 멤버 함수보다 효율적이다.

### 문자열 변환 연산 제거하기

#### C 문자열에서 std::string으로 변환
* C-string to std::string의 암시적 변환을 주의하자.

#### 문자 인코딩 사이의 변환
* 변환 연산을 제거하는 가장 좋은 방법은 하나의 형식을 선택해 모든 문자열을 선택한 형식으로 저장하는 것이다.
