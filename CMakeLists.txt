cmake_minimum_required(VERSION 3.15)
project(Cpp0x11)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cpp0x11 main.cpp variadic_templates.h spaces_in_template_expression_and_nullptr.h uniform_initialization.h initializer_lists.h explicit.h rangebased_for.h default_delete_ctor.h alias_template.h decltype.h lambdas.h Rvalue_references.h)

