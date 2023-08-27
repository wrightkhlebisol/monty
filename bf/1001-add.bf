, c1
>, c2
[ start loop
<+ move to c0 and add 1
>- come back to c1 and remove 1
] end loop when c2 = 0

next we need to get the values as digits
by removing 48 since we are taking inputs
via the standard input (stdin)

we are still at c1 which is presently zero that is c1 = 0
++++++ initialize c1 with 6 that is c1 = 6
[ start loop: keep checking for when c1 becomes zeo(0)
<-------- move back to c0 and remove 8
>- move back to c1 and remove 1
] keep loop by preventing it from going out of the bracket so far c1 is nonzero
<. move back to c0 which holds the value and print it to stdout
