 
 
    ;VERTICAL
 
 ;clear
 
MOV AX,0600H    ;scroll up
MOV BH,07       ;beyaz metin siyah arka plan
MOV CX,0000     ;row column 00,00
MOV DX,18F4H    ;sag alt kose
INT 10H


;VIDEO MODE 

MOV AH,00
MOV AL,13H
INT 10H


;WRITE PIXEL

MOV CX,100  ;COLUMN
MOV DX,50   ;ROW

BACK:   MOV AH,0CH  ;MOD
        MOV AL,0BH  ;RENK
        INT 10H
        INC DX
        CMP DX,100
        JNZ BACK