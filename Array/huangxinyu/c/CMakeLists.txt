cmake_minimum_required(VERSION 3.16)
project(c)

set(CMAKE_CXX_STANDARD 14)

#add_executable(leetcode towSum.c upstairs.c main.cpp alo.h strStr.c mergeSortedArray.c getIntersectionNode.c reverseList.c mergeSortedLink.c removeNthFromEnd.cpp oddEventList.cpp Solution.cpp StackByQueue.cpp StackByQueue.h MyQueue.cpp MaxQueue.cpp ArrayNesting.cpp)
add_executable(arrayNesting ArrayNesting.cpp FindNumbers.cpp Matrix.cpp PageReplace.cpp PageReplace.h)
#add_executable(findNumber FindNumbers.cpp)
add_executable(numOfSubarrays numOfSubarrays.cpp)
add_executable(maxProfit3 maxProfit3.cpp)
add_executable(reverseList reverseList.c)
add_executable(matrix Matrix.cpp)
add_executable(detectCycle detectCycle.cpp)
add_executable(PageReplace PageReplace.h PageReplace.cpp)