set(PROJECT_HEADERS "${PROJECT_HEADERS}
function.h
" PARENT_SCOPE)

file(GLOB LIBFUNCTION_SRCS *.cc)

add_library(libfunction SHARED ${LIBFUNCTION_SRCS} ${PROJECT_HEADERS})