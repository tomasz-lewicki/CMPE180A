# Lab 2: File Import/Export and Object Array

## Overview
Redo the complex homework and perform add / delete / list / save functions.

1. Read in a file of complex numbers (sample is attached 126import.txt) and store them in an array of complex objects.  (Would you be able to do either static or dynamic array?)

2. Create a menu to allow console add / delete / list and save functions.  (You can also do load functions to make it more complete). The list and save function needs to print out the numbers in ascending order based on its value. The value of a complex number a+bi is sqrt(a*a+b*b).

3. Save function stores the results to file 126complex.txt.


## Note

1. If you can not handle a few corner cases, e.g. the last 3 complex number, remove them and focus on the main part. You will not get the full grade, but at least you need to get some code working.

2. You need to implement operator overloading to compare complex numbers as well as stream insertion / extraction operators.

3. It is highly recommended that you implement TWO classes (complex and complexDB) for this lab.  It will be a good foundation for future data structure practices. 

## Bonus Points:

Use the challenge input file 126importHard.txt to test for additional corner cases. Write your output to 126exportHard.txt in the same program