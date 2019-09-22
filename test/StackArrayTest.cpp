#define BOOST_TEST_MODULE StackArrayTest

#include "StackArray.hpp"

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


BOOST_AUTO_TEST_SUITE_END()