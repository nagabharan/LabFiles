.model small
.data
        array dw 0010h,0020h,0030h,0040h
        len dw ($-array)/2
        key dw 0011h
        msg1 db "Element found",10,13,"$"
        msg2 db "Element not found",10,13,"$"
.code
        mov ax,@data
        mov ds,ax
        mov cx,key
        mov bx,01h
        mov dx,len

   back:cmp bx,dx
        ja fail
        mov ax,bx
        add ax,dx
        shr al,01h
        mov si,ax
        dec si
        add si,si
        cmp cx,array[si]
        jae bigger
        dec ax
        mov dx,ax
        jmp back
    bigger:je success
        inc ax
        mov bx,ax
        jmp back
   success:lea dx,msg1
        jmp print
   fail:lea dx,msg2
   print:mov ah,09h
        int 21h
        mov ah,4ch
        int 21h
   end

        
