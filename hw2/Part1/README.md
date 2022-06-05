# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

We have previously learned the Linked List Data Structure. Now we will introduce another data structure, known as the 'queue'.

A 'queue' data structure is analogous to waiting in line at a grocery store. The first person to the checkout counter is served, followed by the next person, and then the next until the line is empty. A queue is what is known as a 'first-in first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a queue using an array in the **myqueue.h** file. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).

## Part 1 - Queue implementation as an array (Ring Buffer).

A circular buffer has a fixed sized, or maximum number of elements that it can hold. This is advantageous if we know how many elements are typically stored in a data structure (If we do not know, then a queue with a linked list implemetation is needed). 

For more information on the Circular buffer, see here: https://en.wikipedia.org/wiki/Circular_buffer

This animation below gives an idea about how the data structure 'wraps' around. Think about what mathematical operator has a *wrap around behavior* that could be useful in your implementation when enqueuing and dequeuing items in your queue (*hint* this operator will save you from writing many if-statements in your code!).

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

Your task will be to implement the functions in the myQueue.h to have a working implementation of queue.

### Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working queue implementation. A sample unit tests is given:

```c
void unitTest1(){
	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}
```

**You must write unit tests to test your implementation.** You will loose points no the self evaluation if you do not have tests written. Some example tests you might come up with include:

* Fill a queue, empty the queue, and fill the queue again.
* Create an empty queue and attempt to add something to it.
* Make sure your queue does not overwrite any data.
* etc.

## Part 2 - What is a file that ends in .h.

A file that ends in .h is known as a header file. A header file typically is a file that contains an 'interface' for a set of functions to perform some task. The actual implementation (i.e. the loops, if-statements, arrays, and tools that do work) are found in a .c file. 

For this assignment, our 'queue' library is quite small, so we will implement the entire functionality into a header file. There are some pros and cons to this approach. One particular 'pro' is it makes your code very easy to test. Anyone that knows the names of your functions can test your code. (that is why it is important you do not change the names of any functions). 

* More information on header files
	* https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

## Part 3 - Why is a ring buffer/circular queue useful?

Do a little outside research, and edit this section of the readme answering specifically: Why is a ring buffer useful and/or when should it be used?

# TODO: Put your answer here
	Circular buffers are suited for FIFO; if you want the first item that is added to thereafter be the first item to be removed, it may be a good option. In a ring buffer, all queue operations, like enqueue and dequeue, are constant time O(1). Using a circular buffer may help conserve memory since such a buffer stores only up to a predetermined capacity and can never store past that capacity but can easily replace elements without shuffling. Elements do not need to be shuffled when one is removed (like with lists/arrays) because the head simply increases its index position. This is a lot more efficient than, for instance, using the remove function on a list in python. If you have an array with n elements and wanted to remove the oldest element (index 0) and add something to the highest index, the positional movements would be a lot more taxing (in a big list) than simply using one dequeue and one enqueue.

	Because a new item can be added where a previous is removed, an infinite number of elements can be added (so long as deletion/ head increase is used). Therefore a good implementation for the buffer would be in a program where you purposely want to overwrite old entries and repeatedly add new entires.

		The main disadvantage is one must know the size of the circular buffer before implementing it because later expanding its capacity can be costly. A linked list may be a better option for an expanding queue. However, the ring buffer can be a good option if you know the maximum size of the queue in advance.




# Rubric

- 40% Correct Queue implementation
  - All functions should be implemented. Do not rename the functions, but you may add any 'helper' functions if you deem necessary.
    - (e.g. You might have a 'queue_print' to help you debug)
  - There should be no memory leaks
  - There should be no bugs in your functions 
  - Your implementation will be graded by our set of unit tests, and we will check your code 'style' as well.
- 10% Correct writeup on the importance of queues/ring buffers as related to OS
  - I expect this to be in the range of 1-2 paragraphs (Can include complexity, example usage, pros/cons, etc).

# Resources to help

- This is a nice interactive tutorial for learning C
  - http://www.learn-c.org/
- Queue Data Type High level description
  - https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
  
# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * queue_peek - Returns the first value in the queue
  * queue_back - Returns the last value in the queue
  * queue_equals - Checks if two queues are equal
  
  
* Information on pros/cons of our header only design
	* https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient
* Some examples (Revisit this again in a few weeks)
	* https://github.com/nothings/single_file_libs  
  
# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based queue here!
  - Use them as a *rough* guide for the basic concepts. Do make sure to follow the specifications for our assignment above.

