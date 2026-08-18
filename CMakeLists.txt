cmake_minimum_required(VERSION 3.10)

project(ShapeProjects)

set(CMAKE_CXX_STANDARD 17)

add_executable(main 
    main.cpp
    Shape.cpp
    Square.cpp
    Rectangle.cpp
)

add_executable(testSquare 
    testSquare.cpp
    Shape.cpp
    Square.cpp
)

add_executable(testRectangle
   testRectangle.cpp
   Shape.cpp
   Rectangle.cpp
)

enable_testing()

add_test(
   NAME SquareTest
   COMMAND testSquare
)

add_test( 
   NAME RectangleTest
   COMMAND testRectangle
)
