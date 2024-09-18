Names: Mia Patrikios and Wyatt Knepp
GitHub Link: https://github.com/mpatrikios/proj2-wyatt-mia


Discuss the relative performance of each sorting method and try to explain the differences.


Merge sort was the fastest sorting method with quick sort being the slowest. Merge sort performs in O(n log n) becuase it divides and conquers the list. 
Quick sort's time complexity depends on the pivot choice. In the best case, quick sort will perform at the same speed as merge sort. 
However, our quick sort might have been slightly slower than merge because of the pivot point we chose. STL was the second fastest, and also performs in O(n log n) time. 
The pro to STL and Qsort is they are C standard library functions, so they are optimized. Qsort is a version of quick sort, so the times for these sorting algorithms were very close. 


What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?


The main difference between theoretical complexity and actual performace is the implementation of the algorithms. While merge and quick sort should both theoretically 
perform in O(n log n) time, our actual implementation showed a large difference in the time between merge and quick for big sets of data. 


In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.


In my opinion, merge sort is the best option for sorting. Not only was it the fastest, but it is consistent since we are not choosing a pivot point. 
While it is slightly more involved to implement than the function provided by the C library, it is much faster. As data sets get larger, this could be the difference
between a couple of minutes and hours. 


In addition to the questions, please provide a brief summary of each individual group members contributions to the project.


Mia worked on the list, quick, and stl. Wyatt worked on merge, qsort, and performed the time testing. We met a couple of times outside of class to discuss the psuedocode
for the implementation of each sorting algorithm and the break up of tasks. We also worked together to create an SSH key for out GitHub and make sure we were both confident
in merge, pushing, and pulling to and from Git. 

