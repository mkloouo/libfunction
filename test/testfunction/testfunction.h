#ifndef __TESTFUNCTION_H__
#define __TESTFUNCTION_H__

#include <functional>
#include <gtest/gtest.h>

#include <typeinfo>

#include "function.h"

template <typename Function>
using my_function = my::function<Function>;

template <typename Function>
using std_function = std::function<Function>;

using my::no_function_exception;

#endif // __TESTFUNCTION_H__
