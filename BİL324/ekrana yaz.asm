

    ;EKRANA YAZ

.STACK 64
.DATA
DATA_ASC DB 'SUDE','$'   ; String sonu karakteri

.CODE
MAIN PROC FAR
    MOV AX, @DATA       ; Veri segmentini ayarla
    MOV DS, AX          ; DS'ye yUkle

    MOV AX, 0600H       ; EkranÝ temizle
    MOV BH, 07
    MOV CX, 0000
    MOV DX, 184FH
    INT 10H

    MOV AH, 09          ; String yazdIrma
    MOV DX, OFFSET DATA_ASC
    INT 21H

    MOV AH, 4CH         ; Programý sonlandýr
    INT 21H
MAIN ENDP
END MAIN
