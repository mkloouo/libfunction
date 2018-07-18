set(PROJECT_HEADERS "${PROJECT_HEADERS}
testfunction.h
" PARENT_SCOPE)

file(GLOB TESTFUNCTION_SRCS *.cc)

add_executable(testfunction ${TEST_MAIN_FILE} ${TESTFUNCTION_SRCS} ${PROJECT_HEADERS})
add_test(testfunction testfunction)

target_link_libraries(testfunction
	libfunction
	libgtest
	libgmock
)
