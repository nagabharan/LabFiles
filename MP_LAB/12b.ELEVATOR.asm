.model small
.data
.stack
           ar db 04h,07h,04h,0d3h,0b6h,79h
.code
        mov ax,@data
        mov ds,ax
        mov dx,9803h
        mov al,82h
        out dx,al
        lea si,ar
        mov dx,9800h
        mov al,0f0h
        out dx,al
        mov dx,9801h
up1:    in al,dx
        or al,0f0h
        cmp al,0ffh
        je up1
        shr al,01h
        jnc down0
        shr al,01h
        jnc down1
        inc si
        shr al,01h
        jnc down1
        inc si
down1: mov cl,[si]
        mov bl,cl
        mov dx,9800h
        mov al,0f0h
up2:out dx,al
        call delay
        inc al
        loop up2
        add si,003h
        mov al,[si]
        out dx,al
        mov cl,bl
        dec cl
up3: dec al
        out dx,al
        call delay
        loop up3
        jmp stop
down0: call delay
        call delay
        mov dx,9800h
        mov al,0e0h
        out dx,al
stop:   int 3h
        delay proc
        push cx
        push bx
        mov cx,0fffh
up4: mov bx,0ffffh
up5: dec bx
        jnz up5
        loop up4
        pop bx
        pop cx
        ret
        delay endp
        end
