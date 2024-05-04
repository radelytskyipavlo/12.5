#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTest
{
    TEST_CLASS(StackUnitTest)
    {
    public:



        TEST_METHOD(TestPop)
        {
            Elem* stack = nullptr;
            push(stack, "hello");
            push(stack, "world");

            Assert::AreEqual("world", pop(stack).c_str());
            Assert::AreEqual("hello", pop(stack).c_str());

            Assert::AreEqual("", pop(stack).c_str());
        }
    };

}