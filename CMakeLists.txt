cmake_minimum_required(VERSION 3.12)
project(demo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(demo2 test.c header/random_data.h util/random_data.c header/linked_list.h util/linked_list.c header/heap.h util/heap.c
        header/sort.h sort/bubble_sort.c sort/bucket_sort.c sort/counting_sort.c sort/heap_sort.c sort/insertion_sort.c sort/merge_sort.c sort/quick_sort.c sort/selection_sort.c sort/shell_sort.c util/binaryTree.c header/binaryTree.h util/queue.c header/queue.h)
#add_executable(demo2 commonAlgorithms/convenientBinaryTree.c util/queue.c util/binaryTree.c)#层序便利二叉树