       ; Ucgen (Triangle)
 
  ; CLEAR SCREEN (Ekraný temizle)
  MOV AX,0600H        ; Video modu: temizle ve tüm ekraný siyah yap
  MOV BH,07           ; Renk (background color) = gri
  MOV CX,0000         ; Sol üst köþe (baþlangýç koordinatý)
  MOV DX,184FH        ; Sað alt köþe (bitiþ koordinatý)
  INT 10H             ; BIOS Video Interrupt - ekraný temizle
  
  ; SET VIDEO MODE (COLOR GRAPHICS) (Grafik modunu ayarla)
  MOV AH,00           ; BIOS hizmeti: video modu seç
  MOV AL,13h          ; Mod 13h: 256 renkli 320x200 grafik modu
  INT 10H             ; BIOS Video Interrupt - mod deðiþtir
  
  ; WRITE PIXEL - DRAW A COLORFUL TRIANGLE (Renkli üçgen çiz)
  
  ; Çizginin sol yukarýdan sað aþaðýya doðru ilerleyen kýsmý
  MOV CX,100          ; CX: Baþlangýç X koordinatý (100)
  MOV DX,50           ; DX: Baþlangýç Y koordinatý (50)
BACK: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,04           ; Renk: kýrmýzý
  INT 10H             ; Pikseli ekrana çiz
  INC CX              ; X koordinatýný artýr (saða hareket)
  INC DX              ; Y koordinatýný artýr (aþaðý hareket)
  CMP CX,150          ; X koordinatý 150'ye ulaþtý mý?
  JNZ BACK            ; Henüz ulaþmadýysa döngüye devam et
  
  ; Çizginin sað yukarýdan sol aþaðýya doðru ilerleyen kýsmý
BACK2: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,02           ; Renk: yeþil
  INT 10H             ; Pikseli ekrana çiz
  INC CX              ; X koordinatýný artýr (saða hareket)
  DEC DX              ; Y koordinatýný azalt (yukarý hareket)
  CMP DX,50           ; Y koordinatý 50'ye ulaþtý mý?
  JNZ BACK2           ; Henüz ulaþmadýysa döngüye devam et
  
  ; Çizginin alt kýsýmdaki yatay çizgisi
BACK3: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,03           ; Renk: mavi
  INT 10H             ; Pikseli ekrana çiz
  DEC CX              ; X koordinatýný azalt (sola hareket)
  CMP CX,100          ; X koordinatý 100'e ulaþtý mý?
  JNZ BACK3           ; Henüz ulaþmadýysa döngüye devam et
