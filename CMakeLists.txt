cmake_minimum_required(VERSION 3.25.0) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произойдёт аварийный выход.

set(PROJECT_NAME test) # задать константу с именем проекта 
project("${PROJECT_NAME}") # имя проекта 


set(CMAKE_CXX_STANDARD 17) # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("cpp/")

add_executable("${PROJECT_NAME}" Практика 2.cpp
							cpp/Multiplication.cpp
							hpp/Multiplication.hpp
							cpp/Fuctions.cpp
							hpp/Fuctions.hpp) # добавить исполняемый файл