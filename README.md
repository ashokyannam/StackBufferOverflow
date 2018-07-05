# StackBufferOverflow
A simple example for Stack Buffer Overflow Demonstration

1. Compile
  gcc main.c -o stack -fno-stack-protector
  -fno-stack-protector option disables the stack protection so that stack smashing will be allowed
  
 2. Read disassembly code 
  objdump -d stack
