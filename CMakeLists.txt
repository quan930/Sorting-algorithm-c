cmake_minimum_required(VERSION 3.12)
project(demo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(demo2 test.c header/random_data.h util/random_data.c header/linked_list.h util/linked_list.c header/heap.h util/heap.c
        header/sort.h sort/bubble_sort.c sort/bucket_sort.c sort/counting_sort.c sort/heap_sort.c sort/insertion_sort.c sort/merge_sort.c sort/quick_sort.c sort/selection_sort.c sort/shell_sort.c util/binaryTree.c header/binaryTree.h util/queue.c header/queue.h header/search.h search/binarytree_search.c header/2-3tree.h util/2-3tree.c search/2_3tree_search.c "header/redBlackTree.h" util/redBlackTree.c search/red_blacktree_search.c header/coloredfont.h util/coloredfont.c header/avlTree.h util/avlTree.c search/avltree_search.c header/b_plustree.h util/b_plustree.c header/btree.h util/btree.c search/btree_search.c)