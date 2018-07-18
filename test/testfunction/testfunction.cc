#include "testfunction.h"

using SimpleFunction = void(void);
using SimpleIntFunction = int(void);

namespace {
	void foo(void) { return; }
	int bar(void) { return 1; }
} // namespace

TEST(Constructor, WithoutArguments_Works) { my_function<SimpleFunction> mf; }

TEST(Constructor, WithOneFunctionArgument_Works) {
	my_function<SimpleFunction> mf(foo);
}

TEST(CopyConstructor, Works) {
	my_function<SimpleFunction> one;
	my_function<SimpleFunction> another(one);
}

TEST(CopyAssignment, WorksWithOtherFunctionWithTheSameTemplateParam) {
	my_function<SimpleFunction> one(foo);
	my_function<SimpleFunction> another = one;
}

TEST(CopyAssignment, WorksWithPlainFunction) {
	my_function<SimpleFunction> mf = foo;
}

TEST(CopyAssignment, WorksWithLamdaExpression) {
	my_function<SimpleFunction> mf = []() { return; };
}

TEST(CopyAssignment, WorksWithStdBind) {
	my_function<SimpleFunction> mf = std::bind(foo);
}

TEST(BraceOperator, Exists) {
	my_function<SimpleFunction> mf(foo);
	mf();
}

TEST(BraceOperator, ThrowsExceptionWhenNoFunction) {
	my_function<SimpleFunction> mf;
	try {
		mf();
		FAIL();
	} catch (no_function_exception const& ex) { SUCCEED(); } catch (...) {
		FAIL();
	}
}

TEST(BraceOperator, ExecutesLambdaWhenPassedToConstructor) {
	int expected_result = 1;

	my_function<int(void)> mf([expected_result]() { return expected_result; });
	int result = mf();
	ASSERT_EQ(result, expected_result);
}

TEST(BraceOperator, ExecutesFunctionWhenPassedToConstructor) {
	int expected_result = 1;

	my_function<int(void)> mf(bar);
	int result = mf();
	ASSERT_EQ(result, expected_result);
}

TEST(ResultType, Exists) {
	typename my_function<SimpleIntFunction>::result_type i;
}

TEST(ResultType, IsSameAsResultTypeInFunctionType) {
	auto const& typeOfInt = typeid(int);
	auto const& typeOfResultType =
		typeid(my_function<SimpleIntFunction>::result_type);

	ASSERT_EQ(typeOfInt, typeOfResultType);
}

TEST(BoolOperator, IsFalseWhenNoFunction) {
	my_function<SimpleFunction> mf;
	bool result = mf;
	ASSERT_EQ(false, result);
}

TEST(BoolOperator, IsTrueWhenFunctionExists) {
	my_function<SimpleFunction> mf(foo);
	bool result = mf;
	ASSERT_EQ(true, result);
}
