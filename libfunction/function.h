#ifndef __LIBFUNCTION_FUNCTION_H__
#define __LIBFUNCTION_FUNCTION_H__

#include <memory>

namespace my {

	using std::unique_ptr;

	class no_function_exception {};

	template <typename T>
	class function;

	template <typename ReturnType, typename... Args>
	class function<ReturnType(Args...)> {
	public:
		using result_type = ReturnType;

		function() : fh() {}

		template <typename Function>
		function(Function&& f) : fh(new function_holder_impl<Function>(f)) {}

		ReturnType operator()(Args... args) {
			if (fh) {
				return (*fh)(args...);
			} else {
				throw no_function_exception();
			}
		}

		operator bool() { return fh != nullptr; }

	private:
		class function_holder_base {
		public:
			function_holder_base() {}
			virtual ~function_holder_base() {}
			virtual ReturnType operator()(Args... args) = 0;
		};

		template <typename Function>
		class function_holder_impl : public function_holder_base {
		public:
			Function sf;

			function_holder_impl(Function f) : function_holder_base(), sf(f) {}
			ReturnType operator()(Args... args) override { return sf(args...); }
		};

		unique_ptr<function_holder_base> fh;
	};

} // namespace my

#endif // __LIBFUNCTION_FUNCTION_H__
