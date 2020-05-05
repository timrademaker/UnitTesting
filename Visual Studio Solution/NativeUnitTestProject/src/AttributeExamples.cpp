#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AttributeExamples
{
    BEGIN_TEST_MODULE_ATTRIBUTE()
        TEST_MODULE_ATTRIBUTE(L"ModuleAttribute", L"Value")
    END_TEST_MODULE_ATTRIBUTE()

    TEST_CLASS(AttributeExamples)
    {
        BEGIN_TEST_CLASS_ATTRIBUTE()
            TEST_CLASS_ATTRIBUTE(L"ClassAttribute", L"Value")
        END_TEST_CLASS_ATTRIBUTE()

        BEGIN_TEST_METHOD_ATTRIBUTE(MethodName1)
            TEST_PRIORITY(1)
            TEST_METHOD_ATTRIBUTE(L"AttributeName", L"AttributeValue")
        END_TEST_METHOD_ATTRIBUTE()

        TEST_METHOD(MethodName1)
        {

        }


        BEGIN_TEST_METHOD_ATTRIBUTE(IgnoredTest)
            TEST_IGNORE()
            TEST_PRIORITY(2)
            TEST_METHOD_ATTRIBUTE(L"AttributeName", L"AttributeValue")
        END_TEST_METHOD_ATTRIBUTE()

        TEST_METHOD(IgnoredTest)
        {
            Logger::WriteMessage("This test will never run!");
        }


#pragma section("testdata$zsomething", read, shared)

        static const EXPORT_METHOD ::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo* CALLING_CONVENTION __GetTestMethodInfo_SomeMethod()
        {
            __GetTestClassInfo();
            __GetTestVersion();
            //__declspec(allocate("testdata$zsomething"))
                //static const ::Microsoft::VisualStudio::CppUnitTestFramework::MethodMetadata s_Metadata = { L"TestMethodInfo", L"thisNameIsIrrelevant", reinterpret_cast<const unsigned char*>(__FUNCTION__), reinterpret_cast<const unsigned char*>(__FUNCDNAME__), __WFILE__, __LINE__ };
            ALLOCATE_TESTDATA_SECTION_METHOD
                static const ::Microsoft::VisualStudio::CppUnitTestFramework::MethodMetadata s_Metadata = { L"TestMethodInfo", L"thisMethodNameIsIrrelevant", reinterpret_cast<const unsigned char*>("AttributeExamples::AttributeExamples::__GetMethodMetadata_NotActuallyTheNameOfTheTest"), reinterpret_cast<const unsigned char*>(__FUNCDNAME__), __WFILE__, __LINE__ };

            static ::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo s_Info = { ::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo::TestMethod, NULL, &s_Metadata };
            s_Info.method.pVoidMethod = static_cast<::Microsoft::VisualStudio::CppUnitTestFramework::TestClassImpl::__voidFunc>(&ThisClass::someMethodName);
            return &s_Info;
        }

        void someMethodName()
        {
            Logger::WriteMessage("Test");
        }
    };
}
