/*
 * vim 설정
 * vim:ts=4:shiftwidth=4:sts=4:et:cindent:fileencoding=utf-8:
 */

#include <tutil.hpp>

#include <chrono>
#include <thread>
#include <string>

static auto fillVector(const size_t aSize)
{
    tutil::Timer sTimer(tutil::makeString("fillVector(aSize=%ld)", aSize));

    std::vector<std::string> sResult;
    for (size_t i = 0;i < aSize; ++i)
    {
        sResult.push_back(std::to_string(i)); 
    }
    return sResult;
}

static auto readVec1(const std::vector<std::string> &aVec)
{
    tutil::Timer sTimer("readVec1(..) : 첨자 버전");

    std::string sResult;
    for (size_t i = 0; i < aVec.size(); ++i)
    {
        sResult += aVec[i];
    }
    return sResult;
}

static auto readVec2(const std::vector<std::string> &aVec)
{
    tutil::Timer sTimer("readVec2(..) : Iterator 버전");

    std::string sResult;
    for (auto sIter = aVec.cbegin(); sIter != aVec.cend(); ++sIter)
    {
        sResult += *sIter;
    }
    return sResult;
}

static auto readVec3(const std::vector<std::string> &aVec)
{
    tutil::Timer sTimer("readVec3(..) : at(..) 버전");

    std::string sResult;
    for (size_t i = 0; i < aVec.size(); ++i)
    {
        sResult += aVec.at(i);
    }
    return sResult;
}

void test_vector()
{
    constexpr const auto INPUT_SIZE = 10000000;

    auto sVec = fillVector(INPUT_SIZE);

    std::cout << "========== Vector 순회 ==========" << std::endl;
    (void)readVec1(sVec); // 첨자 버전
    (void)readVec2(sVec); // Iter 버전
    (void)readVec3(sVec); // at 버전
}
