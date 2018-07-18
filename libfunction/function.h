#ifndef __LIBFUNCTION_FUNCTION_H__
#define __LIBFUNCTION_FUNCTION_H__

namespace my {
	template <typename T>
	class function;

	template <typename ReturnType, typename ... Args>
	class function<ReturnType(Args...)> {
		public:
		function() {}

		template <typename Function>
		function(Function f) {}

		ReturnType operator()(Args ... args) {}

	};
}

#endif // __LIBFUNCTION_FUNCTION_H__
