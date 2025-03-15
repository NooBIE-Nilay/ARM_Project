       AREA Fibonacci, CODE, READONLY
ENTRY
         MOV r5,#10            ; Number of Fibonacci numbers to compute
         LDR R0,=0x40000000    ; Memory address for storing numbers

         MOV R1,#00
         MOV R2,#01         

         STR R1,[R0],#04
         STR R2,[R0],#04

         SUBS R5, R5, #02      ; Already stored 2 values, so decrement r5 by 2

LOOP     ADD R3,R1,R2         
         STR R3,[R0],#04     
         MOV R1,R2             
         MOV R2,R3            
         SUBS R5, R5, #01      
         BNE LOOP

STOP B STOP               
         END
