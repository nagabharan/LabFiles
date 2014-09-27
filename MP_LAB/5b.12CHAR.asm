.model small
.data
        msg db 0C0h,0F9h,0A4h,0B0h,99h,92h,82h,0F8h,80h,98h,88h,83h,0C6h
        len dw ($-msg)
.code
        mov ax,@data
        mov ds,ax
        mov al,80h
        mov dx,9803h
        out dx,al
        mov bx,03h

   AGAIN:
        mov cx,len
        lea si,msg

   AGAIN1:
        mov al,[si]
        call DISPLAY
        call DELAY
        inc si
        loop AGAIN1
        dec bx
        jnz EXIT

   DISPLAY PROC
        push cx
        mov cx,08

   AGAIN2:
        mov dx,9801h
        rol al,01
        out dx,al
        push ax
        mov dx,9802h
        mov al,0ffh
        out dx,al
        mov al,00h
        out dx,al
        pop ax
        loop AGAIN2
        pop cx
        ret
   DISPLAY ENDP

   EXIT:
        mov ah,4ch
        int 21h

   DELAY PROC
        push cx
        push bx
        mov cx,0ffffh
   LOOP2:
        mov bx,0ffffh
   LOOP1:
        dec bx
        jnz LOOP1
        loop LOOP2
        pop bx
        pop cx
        ret
   DELAY ENDP

END
