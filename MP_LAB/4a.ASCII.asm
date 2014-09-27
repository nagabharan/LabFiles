.model small
.data
        msg db "enter a key",10,13,"$"
.code
        mov ax,@data
        mov ds,ax
        mov ah,00h
        mov al,03h
        int 10h
        mov dx,offset msg
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        mov bl,al
        mov ah,02
        mov bh,00h
        mov dh,12
        mov dl,40
        int 10h
        mov al,bl
        and al,0f0h
        mov cl,04h
        shr al,cl
        call display
        mov al,bl
        and al,0fh
        call display
        mov ah,4ch
        int 21h
display proc
        cmp al,0ah
        jb skip
        add al,7h
skip:
        add al,30h
        mov dl,al
        mov ah,02h
        int 21h
        ret
        display endp
end



