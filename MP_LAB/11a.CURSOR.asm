disp macro msg
lea dx,msg
mov ah,09h
int 21h
endm
.model small
.data
m1 db 10,13,"enter row value(00-24)$"
m2 db 10,13,"enter column value(00-79)$"
m3 db 10,13,"press any key$"
row db ?
col db ?
.code
mov ax,@data
mov ds,ax
disp m1
call read
mov row,al
disp m2
call read
mov col,al
disp m3
mov ah,08h
int 21h
mov ah,00h
mov al,03h
int 10h
mov dh,row
mov dl,col
mov ah,02h
int 10h
mov ah,08h
int 21h
mov ah,4ch
int 21h
read proc
mov ah,01h
int 21h
and al,0fh
mov bl,al
mov ah,01h
int 21h
and al,0fh
mov ah,bl
aad
ret
read endp
end
