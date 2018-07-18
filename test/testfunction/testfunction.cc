#include "testfunction.h"

using SimpleFunction = void(void);
using SimpleIntFunction = int(void);

namespace {
	void foo(void);
	int bar(void);
}

TEST(MyFunction, Constructor_WithoutArguments_Works) {
	function<SimpleFunction> f;
}

TEST(MyFunction, BraceOperator_WithoutArguments_Works) {
	function<SimpleFunction> f;
	f();
}

TEST(MyFunction, Constructor_PassingFunctionFittingFunction_Works) {
	function<SimpleFunction> f(foo);
}