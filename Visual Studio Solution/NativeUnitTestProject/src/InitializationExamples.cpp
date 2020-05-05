#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InitializationExamples
{
    TEST_MODULE_INITIALIZE(ModuleInit)
    {
        Logger::WriteMessage("Test module initialization");
    }

    TEST_MODULE_CLEANUP(ModuleCleanup)
    {
        Logger::WriteMessage("Test module cleanup");
    }

    TEST_CLASS(InitializationExamples)
    {
        TEST_CLASS_INITIALIZE(ClassInit)
        {
            Logger::WriteMessage("Test class initialization (class 1)");
        }

        TEST_CLASS_CLEANUP(ClassCleanup)
        {
            Logger::WriteMessage("Test class cleanup (class 1)");
        }
        
        TEST_METHOD_INITIALIZE(MethodInit)
        {
            Logger::WriteMessage("Test method initialization (class 1)");
        }

        TEST_METHOD_CLEANUP(MethodCleanup)
        {
            Logger::WriteMessage("Test method cleanup (class 1)");
        }

        

    public:
        TEST_METHOD(MethodName1)
        {
            Logger::WriteMessage("Running test method 1");
        }

        TEST_METHOD(MethodName2)
        {
            Logger::WriteMessage("Running test method 2");
        }
    };

    TEST_CLASS(InitializationExamples2)
    {
        TEST_CLASS_INITIALIZE(ClassInit)
        {
            Logger::WriteMessage("Test class initialization (class 2)");
        }

        TEST_CLASS_CLEANUP(ClassCleanup)
        {
            Logger::WriteMessage("Test class cleanup (class 2)");
        }

        TEST_METHOD_INITIALIZE(MethodInit)
        {
            Logger::WriteMessage("Test method initialization (class 2)");
        }

        TEST_METHOD_CLEANUP(MethodCleanup)
        {
            Logger::WriteMessage("Test method cleanup (class 2)");
        }



    public:
        TEST_METHOD(MethodName1)
        {
            Logger::WriteMessage("Running test method 1");
        }

        TEST_METHOD(MethodName2)
        {
            Logger::WriteMessage("Running test method 2");
        }
    };
}