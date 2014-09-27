.model small
.data
table db 0h,0dh,1ah,27h,33h,3fh,4ah,55h,5eh,67h,6eh,74h,79h,7ch,7eh,7fh
size1 dw ($-table)
.code
mov ax,@data
mov ds,ax
mov dx,9803h
mov al,80h
out dx,al
again:mov cx,size1
lea si,table
mov dx,9801h
a1:mov al,[si]
        add al,7fh
        out dx,al
        inc si
        loop a1
        mov cx,size1
        dec cx
a2:dec si
        mov al,[si]
        add al,7fh
        out dx,al
        loop a2
              jmp again
        end
             
