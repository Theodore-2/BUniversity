        ;4_3

;VIDEO MODE

MOV AH,00
MOV AL,03
INT 10H    
 
 
;SET CURSOR POSÝTÝON

MOV AH,02
MOV BH,00
MOV DH,12
MOV DL,39  
INT 10H


;WRTITE WITH COLOR 

MOV AH,09   ;RESERVE
MOV BH,00   ;SAYFA
MOV AL,'D'  ;D    
MOV CX,1    ;yazilacak karaktrer sayisi
MOV BL,0F0H ;blinking white on black
INT 10H