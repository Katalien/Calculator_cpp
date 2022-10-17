cmake_minimum_required(VERSION 3.8)

project(Calculator)

set(SOURCES
        Calc/main.cpp
        Calc/Calculator.cpp
		Calc/PluginLoader.cpp
        Calc/ExprHandler.cpp
        Calc/Operators.cpp
)

set(HEADERS
        Calc/Calculator.hpp
		Calc/PluginLoader.hpp
        Calc/ExprHandler.hpp
        Calc/Operators.hpp
        Calc/Symbol.hpp
)

add_executable(Calc ${SOURCES} ${HEADERS})

set_property(TARGET Calc PROPERTY CXX_STANDARD 20)