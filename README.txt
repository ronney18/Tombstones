Name: Ronney Sanchez
Date: 5/1/19
Assignment 4: Tombstones
Course: COMP3010 Organization of Programming Languages
Partner: David Bacon (other course section), Patrick Fuller (other course 
section)
Source: https://github.com/alan31204/tombstones/blob/master/tombstones.h

I got the assignment done finally! I am getting a warning message about an
unused variable in the test file but I think is there to do some test for
showing dangling pointers. When I ran my test file, it notified me to be aware
of segmentation falts in which it happened at the end but I don't know if it
is caused by a memory leak or for accessing memory that no longer exist.

This is my exact ouput from the console:
-----------------------------------------------------------
*ptr == 12, *bar == 12 (both should be 12)
tc->a == 14, tc->b == 3.14159 (should be 14 and 3.14159)

About to use the free() friend function - beware of SEGFAULTs...
There is a dangling pointer!
There is a dangling pointer!
free() did not cause a SEGFAULT (which is good)!

About to dereference the freed Pointer...
(this should cause an error message about dangling pointer or memory leak!)

Memory leak detected!
Segmentation fault (core dumped)
-----------------------------------------------------------------------
Based on my test output of what it showed, my program should work correctly.

I used a source to help me with this assignment after days of struggle.

https://github.com/alan31204/tombstones/blob/master/tombstones.h

I worked with David Bacon and Patrick Fuller with this assignment and they
are in the other section of the course.
