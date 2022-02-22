# SpecialBool
Arduino boolean variable class that includes falling and rising edge, change of state, not, and 3 auxiliary "bools". All in the same space as a regular bool

JameSpecialBool is a class that helps keep memory usage low and has great uses built in!
arduino bools take up a whole byte even though it's states can only be 1 or 0.
JameSpecialBool uses that byte to its fullest potential by using individual bits within the byte.


bit 0: actual state of variable

bit 1: previous state of variable

bit 2: rising edge of variable

bit 3: falling edge of variable

bit 4: true when variable has changed states. (bit 2 and 3 in an OR)

bit 5-7: Auxilary bits that can be address with "instance of SpecialBool".special

