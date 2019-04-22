# Objectives:
1. Exercise doubly-linked list 
2. insertion, deletion, and reverse

# Overview

1. Continue with the stock exercise in Lab 3.  
2. Create a portfolio class which stores stocks in doubly-linked list.
3. Portfolio class has load and store functions to keep all its stocks on files.
4. How do you prove that the portfolio is indeed linked correctly in both directions? 
```how about print and reverse print?```

5. Create your own test data such that you can demonstrate stock insertion and deletion at the beginning / middle / end of the portfolio.

# Discussions
1. How would you support "copying a portfolio"? 
2. How about merging two portfolios into one?  Such as ```port3 = port1 + port2```; 
3. If you are further ahead, try two implementations:  one with only head / tail, and another with head / tail / size.
4. If you are even more further ahead, try have the list as an ordered list.  Note that you do not really need a sorting algorithm to do so.  Instead, while you're loading from the file, insert each stock in order will do the trick.  If you're up to this stage, let me know who you are, so I can keep you challenged.