.model small
.data
        msg1 db "press any key to return to dos",13,10,"$"
.code
        mov ax,@data
        mov ds,ax
        lea dx,msg1
        mov ah,09h
        int 21h
        mov al,82h
        mov dx,9803h
        out dx,al
        mov dx,9801h
        in al,dx
        cmp al,01h
        je down
        mov al,00h
     up:mov dx,9800h
        out dx,al
        call delay
        inc al
        cmp al,0ah
        jne up
        jmp quit
    down:mov al,09h
   again:mov dx,9800h
         out dx,al
         call delay
         dec al
         cmp al,0ffh
         jne again
    quit:mov ah,4ch
        int 21h
   delay proc
        push cx
        push bx
        mov cx,05fffh
   loop2:mov bx,0ffffh
   loop1:dec bx
        jnz loop1
        loop loop2
        pop bx
        pop cx
        ret
        delay endp
        end

