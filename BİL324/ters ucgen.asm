       ; Ucgen (Triangle)
 
  ; CLEAR SCREEN (Ekran� temizle)
  MOV AX,0600H        ; Video modu: temizle ve t�m ekran� siyah yap
  MOV BH,07           ; Renk (background color) = gri
  MOV CX,0000         ; Sol �st k��e (ba�lang�� koordinat�)
  MOV DX,184FH        ; Sa� alt k��e (biti� koordinat�)
  INT 10H             ; BIOS Video Interrupt - ekran� temizle
  
  ; SET VIDEO MODE (COLOR GRAPHICS) (Grafik modunu ayarla)
  MOV AH,00           ; BIOS hizmeti: video modu se�
  MOV AL,13h          ; Mod 13h: 256 renkli 320x200 grafik modu
  INT 10H             ; BIOS Video Interrupt - mod de�i�tir
  
  ; WRITE PIXEL - DRAW A COLORFUL TRIANGLE (Renkli ��gen �iz)
  
  ; �izginin sol yukar�dan sa� a�a��ya do�ru ilerleyen k�sm�
  MOV CX,100          ; CX: Ba�lang�� X koordinat� (100)
  MOV DX,50           ; DX: Ba�lang�� Y koordinat� (50)
BACK: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,04           ; Renk: k�rm�z�
  INT 10H             ; Pikseli ekrana �iz
  INC CX              ; X koordinat�n� art�r (sa�a hareket)
  INC DX              ; Y koordinat�n� art�r (a�a�� hareket)
  CMP CX,150          ; X koordinat� 150'ye ula�t� m�?
  JNZ BACK            ; Hen�z ula�mad�ysa d�ng�ye devam et
  
  ; �izginin sa� yukar�dan sol a�a��ya do�ru ilerleyen k�sm�
BACK2: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,02           ; Renk: ye�il
  INT 10H             ; Pikseli ekrana �iz
  INC CX              ; X koordinat�n� art�r (sa�a hareket)
  DEC DX              ; Y koordinat�n� azalt (yukar� hareket)
  CMP DX,50           ; Y koordinat� 50'ye ula�t� m�?
  JNZ BACK2           ; Hen�z ula�mad�ysa d�ng�ye devam et
  
  ; �izginin alt k�s�mdaki yatay �izgisi
BACK3: 
  MOV AH,0CH          ; BIOS hizmeti: piksel yaz
  MOV AL,03           ; Renk: mavi
  INT 10H             ; Pikseli ekrana �iz
  DEC CX              ; X koordinat�n� azalt (sola hareket)
  CMP CX,100          ; X koordinat� 100'e ula�t� m�?
  JNZ BACK3           ; Hen�z ula�mad�ysa d�ng�ye devam et
