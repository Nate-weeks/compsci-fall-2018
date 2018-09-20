* problem 2.11

this problem is occuring because the pointers in the last operation contain the same value in an odd array.  When inplace_swap is called on the same value, it produces 0.  A simple change to the code would be to change first <= last to first < last.

* problem 2.14

x = 0110 0110
y = 0011 1001

x&y = 0010 0000 = 0x20
x|y = 0111 1111 = 0x7F
~x = 1001 1001 ~y = 1100 0110 ~x|~y = 1101 1111 = 0xDF
x&!y = 0000 0000 = 0x00
x&&y = true = 0x01
x||y = true = 0x01
!x||!y = false = 0x00
x && ~y = true = 0x01

* problem 2.23

* problem 2.60
