.model small
.data
msg1 db 10,13,"press1:create file 2:delete file "
msg2 db 10,13,"enter your choice $"
msg3 db 10,13,"error$ "
f1 db "up.txt $",0
.code
mov ax,@data
mov ds,ax
lea dx,msg1
call disp
mov ah,01h
int 21h
cmp al,'1'
je create
cmp al,'2'
je delete
error:lea dx,msg3
call disp
exit:mov ah,4ch
int 21h
create:mov cx,0
lea dx,f1
mov ah,3ch
int 21h
jc error
jmp exit
delete:lea dx,f1
mov ah,41h
int 21h
jc error
jmp exit
disp proc
mov ah,09h
int 21h
ret
disp endp
end
