.model small
.data
        msg db "the no of 1's is",13,10,"$"
.code
        mov ax,@data
        mov ds,ax
        lea dx,msg
        mov ah,09h
        int 21h
        mov al,82h
        mov dx,9803h
        out dx,al
        mov dx,9801h
        in al,dx
        mov cx,08h
        mov bl,00h
AGAIN: shr al,01h
        JNC SKIP
        INC bl
SKIP: loop AGAIN
        mov cl,bl
        shr cl,01h
    jc odd_parity
        mov al,0ffh
        JMP HERE
 odd_parity:xor al,al
 HERE: mov dx,9800h
        out dx,al
        add bl,30h
        mov dl,bl
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h
        end

