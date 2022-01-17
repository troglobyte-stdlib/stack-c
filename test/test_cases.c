//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "miok/stack.h"
#include <unity.h>

//
// test var mainly used for the cases in whitch this
// package source code is being ran with.
//
StackOf *stack;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    stack = miok_stack_create();
} // end of function setUp

void tearDown(void)
{
    miok_stack_erase(&stack);
} // end of function tearDown


//
// list of all the test cases for this project
//
static void test_miok_stack_push(void)
{
    TEST_ASSERT_NOT_NULL(stack);
    miok_stack_push(stack, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", miok_stack_peek(stack));

    miok_stack_push(stack, "2077");
    miok_stack_push(stack, "2010");
    TEST_ASSERT_EQUAL_STRING("2010", miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_push_with_nullptr(void)
{
    miok_stack_push(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));

    miok_stack_push(NULL, "2077");
    miok_stack_push(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_pop(void)
{
    TEST_ASSERT_NOT_NULL(stack);
    miok_stack_push(stack, "red chicken");
    miok_stack_push(stack, "blue chicken");
    miok_stack_push(stack, "black chicken");
    miok_stack_push(stack, "green chicken");
    miok_stack_push(stack, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("yellow chicken", miok_stack_peek(stack));
    miok_stack_pop(stack);
    TEST_ASSERT_EQUAL_STRING("green chicken", miok_stack_peek(stack));
    miok_stack_pop(stack);
    TEST_ASSERT_EQUAL_STRING("black chicken", miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_pop_with_nullptr(void)
{
    miok_stack_push(NULL, "red chicken");
    miok_stack_push(NULL, "blue chicken");
    miok_stack_push(NULL, "black chicken");

    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));
    miok_stack_pop(stack);
    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_its_empty(void)
{
    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_TRUE(miok_stack_its_empty(stack));
    miok_stack_push(stack, "red chicken");
    TEST_ASSERT_FALSE(miok_stack_its_empty(stack));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_its_empty_with_nullptr(void)
{
    miok_stack_push(NULL, "red chicken");
    TEST_ASSERT_TRUE(miok_stack_its_empty(stack));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_not_empty(void)
{
    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_FALSE(miok_stack_not_empty(stack));
    miok_stack_push(stack, "red chicken");
    TEST_ASSERT_TRUE(miok_stack_not_empty(stack));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_stack_peek(stack));
} // end of test case

static void test_miok_stack_not_empty_with_nullptr(void)
{
    miok_stack_push(NULL, "red chicken");
    TEST_ASSERT_FALSE(miok_stack_not_empty(stack));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_stack_peek(stack));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_miok_stack_push);
    RUN_TEST(test_miok_stack_pop);
    RUN_TEST(test_miok_stack_its_empty);
    RUN_TEST(test_miok_stack_not_empty);
    RUN_TEST(test_miok_stack_push_with_nullptr);
    RUN_TEST(test_miok_stack_pop_with_nullptr);
    RUN_TEST(test_miok_stack_its_empty_with_nullptr);
    RUN_TEST(test_miok_stack_not_empty_with_nullptr);

    return UNITY_END();
} // end of function main
