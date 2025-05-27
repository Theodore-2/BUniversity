
        ;ekran ortasina fonksiyonla yazi yazma            
            
    .MODEL SMALL
    .STACK 64
    .DATA

MESSAGE DB 'This is a test of the display routine','$'

    .CODE
MAIN PROC FAR
    
    MOV AX,@DATA
    MOV DS,AX
    CALL CLEAR      ;fonksiyon cagirma
    CALL CURSOR
    CALL DISPLAY
    MOV AH,4CH
    INT 21H 
MAIN ENDP

;CLEAR

CLEAR PROC
    MOV AX,0600H    ;scroll up
    MOV BH,07       ;beyaz yazi siyah arka plan
    MOV CX,0000     ;sayfa sag ust
    MOV DX,184FH    ;sayfa sag alt
    INT 10H         ;BIOS INT 10H cagrisi
    RET             ;return
CLEAR ENDP


;CURSOR

CURSOR PROC
    MOV AH,02   ;imlec pozisyonlandirma modu
    MOV BH,00   ;sayfa 0
    MOV DH,12   ;row 12 (orta)
    MOV DL,39   ;column 39 (orta)
    INT 10H
    RET
CURSOR ENDP


;DISPLAY

DISPLAY PROC
    MOV AH,09               ;string out
    MOV DX,OFFSET MESSAGE   ;adres yukleme 
    INT 21H
    RET
DISPLAY ENDP

END MAIN





    