#pragma once

// #include "aod.h" // project header files

#include <iostream> // std header files

#include <Windows.h> // system header files

#define MY_MACRO(...)                                                                              \
    do                                                                                             \
    {                                                                                              \
        __VA_ARGS__                                                                                \
    } while (0)

#define MY_PI 3.14159

namespace aod {

    extern int gGlobalVarible;

    void ThisIsAFunction()
    {
        // only used to exemplify the style rules
        // --> never write logic in a header file unless you are using templates

        static bool sVisited = false;

        bool isValid = true;
        auto ThisIsAnotherFunction = [&]() { ; };
    }

    class ExampleBaseClass
    {
    public:
        virtual ~ExampleBaseClass() = default;
        virtual void FunctionA() = 0;
        virtual void FunctionB() const = 0;
    };

    class ExampleClass : public ExampleBaseClass
    {
    public:
        virtual void FunctionA() override;
        virtual void FunctionB() const override;

        int GetA() const;

        void DoSomething();

    public:
        int _VarA;

    private:
        void DoOtherThings();

    private:
        int _VarB;
    };

    enum class Color
    {
        RED,
        GREEN,
        BLUE
    };

} // namespace aod
