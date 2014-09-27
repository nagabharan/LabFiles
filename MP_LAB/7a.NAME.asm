strread macro loc
mov ah,01h
int 21h
mov loc,al
endm
.model small
.data
m1 db "what is your name:?$"
a db 20 dup(?)
.code
mov ax,@data
mov ds,ax
mov si,0h
loop1:strread a[si]
inc si
cmp al,13
jnz loop1
mov a[si],"$"
mov ah,00h
mov al,03h
int 10h
mov ah,02h
mov bh,00h
mov dh,12
mov dl,40
int 10h
lea dx,m1
mov ah,09h
int 21h
mov si,0h
lea dx,a[si]
mov ah,09h
int 21h
mov ah,4ch
int 21h
end

