.model small
.data
arr db 50 dup(?)
.code
extrn readkey:far
extrn echo:far
start:
mov ax,@data
mov ds,ax
mov si,offset arr
mov di,offset arr
mov cx,00h
next:
call readkey
inc cx
cmp al,0dh
jnz next
mov dl,10
mov ah,02h
int 21h
mov dl,0dh
mov ah,02h
int 21h
next1:
mov dl,[di]
inc di
call echo
loop next1
mov ah,4ch
int 21h
end start

