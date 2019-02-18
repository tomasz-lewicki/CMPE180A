# Lab 3 Linked List

## Objectives:
1. Get yourself familiar with the forward linked list creation and operations.
2. Manipulate pointers
3. Create linked node by is-a or has-a

## Overview
- [x] A stock in a portfolio contains a stock symbol (e.g. AAPL), a cost (i.e. purchase price), and the number of shares.
- [x] Write the stock class.
- [x] program that creates a forward linked list of at least 20 elements, where each element holds a stock.
    + [x] The stock symbol is a string which you can generate randomly or just do A1, A2, etc.
    + [x] The cost and number of shares are randomly generated between 0 and 99.
    + [x] Print the list.  As you may eventually find out that __"reading a stock file" into the linked list is actually easier__ than artificially generate one.  You can choose that option instead.

- [x] Write the function "returnMiddleList" to find the middle element of the linked list in one pass.
    + [x] Print the element and the position of this element (starting at zero) in relation to the head (where the head = 0, the element pointed to by the head = 1, the element pointed to by the previous one = 2, etc).
    
- [ ] Split the list in half at the middle element to create two entirely separate* linked lists of near equal size (+/- 1) and print the two lists.  In other words, write the "split in half" function.

## Discussions
1. Can you try both is-a and has-a implementation for node?  What do you like or don't like?
2. If you add a length field, finding middle is fairly easy to do.  What if you do not have length?
3. Do you do "add" to list when you create a new stock?
4. What if the stock portfolio is on a disk file?

## Notes:
How to convert int to string so that we can concatenate A1, A2?

Try the simple test with stringstream:
```C++
stringstream s;
s << 123;
cout << s.str() << endl;
```
