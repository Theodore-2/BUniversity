         ;EXAMPLE 4_1

;SET CURSOR TO SPECÝFÝC LOCATION

MOV AH,02 ;cursor pozisyon degistirme modu
MOV BH,00 ;0. sayfa
MOV DH,15 ;0FH
MOV DL,25 ;19H
INT 10H     



;GET CURSOR CURRENT POSITION

MOV AH,03 ;3. fonksiyon
MOV BH,00 ;sayfa 0
INT 10H 