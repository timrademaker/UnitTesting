#include "pch.h"
#include "CppUnitTest.h"

#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace AssertExamples
{
    TEST_CLASS(AssertExamples)
    {
    public:
        TEST_METHOD(IsNullTest)
        {
            int* nullPtr = nullptr;
            int* notNullPtr = new int;

            std::unique_ptr<int> uniqueInt = std::make_unique<int>(1);
            std::shared_ptr<int> sharedInt = nullptr;

            Assert::IsNull(nullPtr);
            Assert::IsNotNull(uniqueInt.get());
            Assert::IsNull(sharedInt.get());

            Assert::IsNotNull(notNullPtr);

            delete notNullPtr;
        }

        TEST_METHOD(AreSameTest)
        {
            int someInt = 0;
            int& someIntReference = someInt;
            int anotherInt = 0;

            Assert::AreSame(someInt, someIntReference);
            Assert::AreNotSame(someInt, anotherInt);
        }

        TEST_METHOD(AreEqualTest)
        {
            Assert::AreEqual(1.0f, 1.0f);               // Without tolerance
            Assert::AreEqual(1.0f, 1.1f, 0.2f);         // With tolerance
            Assert::AreEqual("Text", "Text");           // Compare text
            Assert::AreEqual("Text", "TEXT", true);     // Ignore case

            Assert::AreNotEqual(1.0f, 2.0f);
            Assert::AreNotEqual(1.0f, 2.0f, 0.1f);
            Assert::AreNotEqual(true, false);
            Assert::AreNotEqual("Text", "Different text");
        }

        TEST_METHOD(IsTrueTest)
        {
            Assert::IsTrue(true);
            Assert::IsTrue(1 == 1);
            
            Assert::IsFalse(false);
            Assert::IsFalse(1 == 2);
        }

        TEST_METHOD(ExceptionTest)
        {
            auto l = [](int i = 0)
            {
                if (i == 0)
                {
                    throw std::exception("Oh no, an exception!");
                }
                else if (i == 1)
                {
                    throw std::overflow_error("Overflow or something");
                }
            };

            Assert::ExpectException<std::exception>(l);
            
            auto lambdaWrapper = [=]() { l(1); };
            Assert::ExpectException<std::overflow_error>(lambdaWrapper);
        }

        TEST_METHOD(AdditionalExceptionTest)
        {
            auto l = [](int i = 0)
            {
                if (i == 0)
                {
                    throw std::exception();
                }
                else if (i == 1)
                {
                    throw std::overflow_error("Overflow or something");
                }
            };

            // Any exception
            {
                bool caughtAny = false;
                try
                {
                    l();
                }
                catch (...)
                {
                    caughtAny = true;
                }

                if (!caughtAny)
                {
                    Assert::Fail(L"No exception thrown while one was expected!");
                }
            }
        }

        TEST_METHOD(ForcedFail)
        {
            Assert::Fail(L"This test was failed for no reason!");
        }
    };
}
