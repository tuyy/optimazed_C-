/*
 * vim 설정
 * vim:ts=4:shiftwidth=4:sts=4:et:cindent:fileencoding=utf-8:
 */

#include <tutil.hpp>

#include <random>
#include <string>
#include <sstream>

static std::string removeCharA11(std::string s)
{
    tutil::Timer sTimer("removeCharA11(std::string s) : 알고리즘 개선 버전4 erase");

    for (size_t i = 0; i < s.size();)
    {
        if (s[i] == 'A')
        {
            s.erase(i, 1);
        }
        else
        {
            ++i;
        }
    }
    return s;
}

static std::string removeCharA10(std::string s)
{
    tutil::Timer sTimer("removeCharA10(std::string s) : 알고리즘 개선 버전3 reserve + append");

    std::string sResult;
    sResult.reserve(s.size());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1)
    {
        for (i = b; i < e; ++i)
        {
            if (s[i] == 'A')
            {
                break;
            }
        }
        sResult.append(s, b, i - b);
    }
    return sResult;
}

static std::string removeCharA09(std::string s)
{
    tutil::Timer sTimer("removeCharA09(std::string s) : 알고리즘 개선 버전2 reserve");

    std::string sResult;
    sResult.reserve(s.size());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1)
    {
        for (i = b; i < e; ++i)
        {
            if (s[i] == 'A')
            {
                break;
            }
        }
        sResult = sResult + s.substr(b, i-b);
    }
    return sResult;
}

static std::string removeCharA08(std::string s)
{
    tutil::Timer sTimer("removeCharA08(std::string s) : 알고리즘 개선 버전");

    std::string sResult;
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1)
    {
        for (i = b; i < e; ++i)
        {
            if (s[i] == 'A')
            {
                break;
            }
        }
        sResult = sResult + s.substr(b, i-b);
    }
    return sResult;
}

static void removeCharA07(char *aDest, const char *aSrc, const size_t aSize)
{
    tutil::Timer sTimer("removeCharA07(char *aDest, const char *aSrc, const size_t aSize) : cstyle 버전");

    for (size_t i = 0; i < aSize; ++i)
    {
        if (aSrc[i] != 'A')
        {
            *aDest++ = aSrc[i]; 
        }
    }
    *aDest = 0;
}

static void removeCharA06(const std::string &s, std::string *aResult)
{
    tutil::Timer sTimer("removeCharA06(const std::string &s) : 인수 ref + iter + out arg 버전");

    aResult->clear();
    aResult->reserve(s.length());
    for (auto sIter = s.cbegin(); sIter != s.cend(); ++sIter)
    {
        if (*sIter != 'A')
        {
            *aResult += *sIter; 
        }
    }
}

static std::string removeCharA05(const std::string &s)
{
    tutil::Timer sTimer("removeCharA05(const std::string &s) : 인수 ref + iter 버전");

    std::string sResult;
    sResult.reserve(s.length());
    for (auto sIter = s.cbegin(); sIter != s.cend(); ++sIter)
    {
        if (*sIter != 'A')
        {
            sResult += *sIter; 
        }
    }
    return sResult;
}

// const std::string& 버전이 더 오래걸린다;
// 그 이유는 s의 포인터 역참조를 해야하기 때문이다.
static std::string removeCharA04(const std::string &s)
{
    tutil::Timer sTimer("removeCharA04(const std::string &s) : 인수 ref 버전");

    std::string sResult;
    sResult.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'A')
        {
            sResult += s[i]; 
        }
    }
    return sResult;
}

static std::string removeCharA03(std::string s)
{
    tutil::Timer sTimer("removeCharA03(std::string s) : reserve 버전");

    std::string sResult;
    sResult.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'A')
        {
            sResult += s[i]; 
        }
    }
    return sResult;
}

static std::string removeCharA02(std::string s)
{
    tutil::Timer sTimer("removeCharA02(std::string s) : sResult += s[i] 버전");

    std::string sResult;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'A')
        {
            sResult += s[i]; 
        }
    }
    return sResult;
}

static std::string removeCharA01(std::string s)
{
    tutil::Timer sTimer("removeCharA01(std::string s) : FIRST");

    std::string sResult;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'A')
        {
            sResult = sResult + s[i]; 
        }
    }
    return sResult;
}

static std::string makeInputString(const size_t aSize)
{
    std::string sResult;
    std::random_device sRd;
    std::mt19937 sGen(sRd());
    std::uniform_int_distribution<int> sDis(65, 90);

    for (size_t i = 0; i < aSize; ++i)
    {
        // 'A' ~ 'Z'
        sResult += (char)sDis(sGen);
    }
    return sResult;
}

std::string makeStringWithInt01(const size_t aSize)
{
    tutil::Timer sTimer("makeStringWithInt01(const size_t aSize) : string");

    std::string sResult;
    sResult.reserve(aSize);

    for (size_t i = 0; i < aSize; ++i)
    {
        sResult += std::to_string(i);
    }
    return sResult;
}

std::string makeStringWithInt02(const size_t aSize)
{
    tutil::Timer sTimer("makeStringWithInt02(const size_t aSize) : stringstream");

    std::stringstream s;
    for (size_t i = 0; i < aSize; ++i)
    {
        s << i;
    }
    return std::string(s.str());
}

void test_string()
{
    constexpr const auto INPUT_SIZE = 1000000;

    auto sStr = makeInputString(INPUT_SIZE);

    std::cout << "========== String 최적화 연습 첫 번째==========" << std::endl;
    (void)removeCharA01(sStr);
    (void)removeCharA02(sStr);
    (void)removeCharA03(sStr);
    (void)removeCharA04(sStr);
    (void)removeCharA05(sStr);
    std::string sInput;
    (void)removeCharA06(sStr, &sInput);
    char sDest[INPUT_SIZE];
    (void)removeCharA07(sDest, sStr.c_str(), INPUT_SIZE);

    std::cout << "========== String 최적화 연습 두 번째==========" << std::endl;
    // 더 좋은 알고리즘을 사용하라
    (void)removeCharA08(sStr);
    (void)removeCharA09(sStr);
    (void)removeCharA10(sStr);
    (void)removeCharA11(sStr);

    std::cout << "========== string과 stringstream==========" << std::endl;
    makeStringWithInt01(INPUT_SIZE);
    makeStringWithInt02(INPUT_SIZE);
}
