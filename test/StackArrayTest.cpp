#define BOOST_TEST_MODULE StackArrayTest

#include "StackArray.hpp"
#include "StackLL.hpp"
#include "StackADTLL.hpp"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(StackArraySuite)

BOOST_AUTO_TEST_CASE(StackArrPushTest)
{
    StackArray stackArr;
    stackArr.push(2);
    BOOST_CHECK_EQUAL(stackArr.peek(), 2);
}

BOOST_AUTO_TEST_CASE(StackArrPopTest)
{
    StackArray stackArr;
    stackArr.push(5);
    stackArr.push(10);
    BOOST_CHECK_EQUAL(stackArr.pop(), 10);
}

BOOST_AUTO_TEST_CASE(StackADTLLPopTest)
{
    StackADTLL<int> stackADTLL;
    stackADTLL.push(5);
    stackADTLL.push(10);
    BOOST_CHECK_EQUAL(stackADTLL.pop(), 10);
}


BOOST_AUTO_TEST_CASE(StackADTLLIsEmptyTest)
{
    StackADTLL<int> stackADTLL;
    BOOST_CHECK_EQUAL(stackADTLL.isEmpty(), true);
}

BOOST_AUTO_TEST_CASE(StackADTLLIsNotEmptyTest)
{
    StackADTLL<int> stackADTLL;
    stackADTLL.push(5);
    BOOST_CHECK_EQUAL(stackADTLL.isEmpty(), false);
}

BOOST_AUTO_TEST_SUITE_END()