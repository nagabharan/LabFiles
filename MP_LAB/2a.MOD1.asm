.model small
.code
public readkey
readkey proc
mov ah,01h
int 21h
mov[si],al
inc si
ret
readkey endp
end
