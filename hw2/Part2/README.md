# Building Data Structures - Stack
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Lifo_stack.png/350px-Lifo_stack.png" alt="Stack picture">

A 'stack' data structure is analogous to how you might wash dishes at a restaurant. A dirty dish is placed near the sink, and you pick it up to begin washing it. As customers bring in more dirty dishes, they are stacked on top of each other. With this ordering, the newest dirty-dish is placed on the top. This makes a stack a  'last-in first-out' (LIFO) data structure. Thus stacks have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a stack using a linked list in the **mystack.h** file.

## Part 1 - Stack implementation as a linked list.

Our stack has two fundamental operations that it can perform:

1. push - Add elements to the top of the stack.
2. pop  - Remove elements from the top of the stack.

You will notice, both of these operations happen at *the top of the stack*. Sometimes, we also refer to these operations as 'enqueue' or 'dequeue' so we have a consistent langauge for our data structures.

Our stack that we are implementing can expand dynamically, thus a linked list is a good foundational data struturre to use in our implementation.

Our stack can push elements onto it, until `MAX_DEPTH` is reached. MAX_DEPTH is defined as 32 for our implementation. For our implementation, we are artificially setting this limit. Remember however, we only have a finite amount of memory on our systems, so if we had very large stacks, we could get a [stack overflow](https://en.wikipedia.org/wiki/Stack_overflow).

For more information on the stack, can be seen here: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

Your task will be to implement the functions in the mystack.h to have a working implementation of stack.

### Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working stack implementation. A sample unit tests is given:

```cpp
void unitTest1(){
	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to add %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
}
```

You must write unit tests to test your implementation in the `main.c` file provided. Some example tests we might come up with include:

* Fill a stack, empty the stack, and fill the stack again.
* Create an empty stack and pop an item to add something to it.
* etc.

## Part 2 - What is a file that ends in .h.

A file that ends in .h is known as a header file. A header file typically is a file that contains an 'interface' for a set of functions to perform some task. The actual implementation (i.e. the loops, if-statements, arrays, and tools that do work) are found in a .c file. 

For this assignment, our 'stack' library is quite small, so we will implement the entire functionality into a header file. There are some pros and cons to this approach. One particular 'pro' is it makes your code very easy to test.

* More information on header files
	* https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

## Part 3 - Why is a stack a useful data structure?

We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?

# TODO: Put your answer here

Stacks are a last in first out structure. Stacks do not need to have a bounded capacity and so may contain a lot of data. They have a few methods like pop, push, and peek, all O(1), which are very fast. If you had an array with n elements and wanted to remove the newest highest index element you'd have to search through the entire list to reach the last element. This is more taxing than using pop of course. Apparently stacks are used for undo operation in some word processors which makes sense — everything typed is stored and each last thing typed can be popped off the stack in O(1) without iterating through a list of all the typed words! Stacks are also used for back/forward on browsers and are also commonly used when traversing nodes of a tree.


	However, utilizing a stack is not a good idea if you want to remove the first added elements near index 0. Contrarily, if the numbers were instead in a stack, you can remove the “top” number in a single step. A stack may also not be a good option if you want to iterate through and alter data. Stacks are not particularly flexible. Searching for and deleting specific items from a stack would have a O(n) complexity, so may not be better than an array if you are just trying to search and delete specific items.



# Rubric

- 40% Correct Stack implementation
  - All functions should be implemented. Do not rename the functions, but you may add any 'helper' functions if you deem necessary.
    - (e.g. You might have a 'stack_print' to help you debug)
  - There should be no memory leaks
  - There should be no bugs in your functions 
  - Your implementation will be graded by our set of unit tests, and we will check your code 'style' as well.
- 10% Correct writeup on the importance of stacks.
  - I expect this to be in the range of 2-3 paragraphs (Can include complexity, example usage, pros/cons, etc).

# Resources to help

- This is a nice interactive tutorial for learning C
  - http://www.learn-c.org/
- Stack Data Type High level description
  - https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
  
# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * stack_peek - Returns the top value of the stack (without removing it)
  * stack_equals - Checks if two stacks are equal
  
  
* Information on pros/cons of our header only design
	* https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient
* Some examples (Revisit this again in a few weeks)
	* https://github.com/nothings/single_file_libs  
  
# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based stack here!
  - Use them as a *rough* outline for the genearl concept. Do make sure to follow the specifications above.

