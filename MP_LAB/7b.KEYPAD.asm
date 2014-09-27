.model small
.data
        dis db "0123456789.+-*/%ACH=WXYZ$" ,10,13
        ms db 10,13,"key pressed is:$"
        m1 db 10,13,"row no:$"
        m2  db 10,13,"col no:$"
        row db ? ,10,13,"$"
        col db ? ,10,13,"$"

.code
        mov ax,@data
        mov ds,ax
        mov al,90h
        mov dx,9803h
        out dx,al
nav:    mov dx,9802h
        mov al,01h
        out dx,al
        mov dx,9800h
        in al,dx
        cmp al,00h
        jnz fc
        mov dx,9802h
        mov al,02h
        out dx,al
        mov dx,9800h
        in al,dx
         cmp al,00h
         jnz sc
         mov al,04h
         mov dx,9802h
         out dx,al
         mov dx,9800h
         in al,dx
         cmp al,00h
         jnz tc
         jmp nav
fc:     lea si,dis
        mov row,31h
        mov cl,30h
next1: inc cl
        shr al,01h
        jc display
        inc si
        jmp next1
sc:     lea si,dis
        add si,08h
        mov row,32h
        mov cl,30h
next2:  inc cl
        shr al,01h
        inc si
        jmp next2
tc:     lea si,dis
        add si,10h
        mov row,33h
        mov cl,30h
next3: inc cl
        shr al,01h
        jc display
        inc si
        jmp next3
display:   lea dx,ms
         mov ah,09h
         int 21h
         mov dl,[si]
         mov ah,02h
         int 21h
         mov al,0DH
         mov ah,02h
         int 21h
         mov col,cl
         lea dx,m1
         mov ah,09h
         int 21h
         lea dx,m2
         mov ah,09h
         int 21h
         int 3

end

