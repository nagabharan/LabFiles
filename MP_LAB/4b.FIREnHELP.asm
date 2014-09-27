.model small
.data
        FIRST db 86h,88h,0F9H,8Eh
        SECOND db 8Ch,0Ch,86h,89h
.code
        mov ax,@data
        mov ds,ax
        mov dx,9803h
        mov al,80h
        out dx,al
        mov bh,0Ah

   AGAIN:
        lea si,FIRST
        call DISPLAY
        call DELAY
        lea si,SECOND
        call DISPLAY
        call DELAY
        dec bh
        cmp bh,00h
        je EXIT
        jmp AGAIN

   DISPLAY PROC
        mov cx,04h

   LOOP1:
        mov bl,08h
        mov al,[si]

   NEXT:
        rol al,01h
        mov dx,9801h
        out dx,al
        push ax
        mov al,0ffh
        inc dx
        out dx,al
        mov al,00h
        out dx,al
        dec bl
        pop ax
        jz NEXT
        jmp NEXT1

   NEXT1:
        inc si
        loop LOOP1
        ret
   DISPLAY ENDP

   DELAY PROC
        push cx
        push bx
        mov cx,0ffffh

   LOOP2:
        mov bx,0ffffh

   LOOP3:
        dec bx
        jnz LOOP3
        loop LOOP2
        pop bx
        pop cx
        ret
   DELAY ENDP

   EXIT:
        mov ah,4ch
        int 21h

END
