### PATTERNS


## 1. Nearest Smaller at left / right
# approch
* 1. separetly

> left --> 
a. Take element into a stack when it's empty and search for the element to which it's NSL
b. Rather check, if the existing element can be the NSL for the current element, if yes put it and update the nsl vector of that position, rather pop it from the stack
c. push the current element to the stack for the same purpose (a) 

> right -->
a. Take element in a stack and search for the NSR / NGR iterating through the remaing part
b. When got an element > the current element in the stack, pop it out and update the NSR / NGR vector with the value
c. Then push the elemnt to the stack for the same purpose

* 2. simalteneously
Go for the right and the just before element in the stack will be the left 

# applications
a. NG in circular array
b. maximum rectangle in ahistogram
c. maximal rectangle
d. stock span





### 2. Target hitting and popping
#  applications
a. valid parenthesis
b. bracket number
c. celebrity problem
d. stock span
e. asteroid
d. beautiful array
f. adjacent duplicate removing