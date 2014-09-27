.model small
.code
        mov al,030h
        loop1: mov dl,al
               mov ah,02h
               int 21h
               push ax
               mov bl,030h
        loop2: mov dl,bl
               mov ah,02h
               int 21h
               inc bl
               call delay
               mov ah,03h
               int 10h
               mov dl,01h
               mov ah,02h
               int 10h
               cmp bl,039h
               jle loop2
               mov dl,00h
               mov ah,02h
               int 10h
               pop ax
               inc al
               cmp al,039h
               jle loop1
               mov ah,4ch
               int 21h
               delay proc
               push cx
               push bx
               mov cx,0FFfFh
     loop3:     mov bx,0fffh
     loop4:    dec bx
               jnz loop4
               loop loop3
               pop bx
              pop cx
               ret
               delay endp
               end




