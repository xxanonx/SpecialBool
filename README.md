# SpecialBool
Arduino boolean variable class that includes falling and rising edge, change of state, not, and 3 auxiliary "bools". All in the same space as a regular bool

SpecialBool is a class that helps keep memory usage low and has great uses built in!
arduino bools take up a whole byte even though it's states can only be 1 or 0.
SpecialBool uses that byte to its fullest potential by using individual bits within the byte.


bit a: actual state of variable

bit b: previous state of variable

bit c: rising edge of variable

bit d: falling edge of variable

bit e: true when variable has changed states. (bit 2 and 3 in an OR)

bit f-g: Auxilary bits that can be address with "instance of SpecialBool".special

You can also use the sbool struct if you want to customize the purpose of each bit
