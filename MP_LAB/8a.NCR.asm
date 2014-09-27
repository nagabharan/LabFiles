.model small
.data
        n dw 3h
        r dw 2h
        ncr dw 01h dup(0)
.code
        mov ax,@data
        mov ds,ax
        mov ncr,0
        mov ax,n
        mov bx,r
        call ncrproc
        mov dx,ncr
        mov ah,4ch
        int 21h
ncrproc proc
        cmp ax,bx
        je res1
        cmp bx,0
        je res1
        cmp bx,1
        je resn
        dec ax
       cmp ax,bx
        je res2
        push ax
        push bx
        call ncrproc 
        pop bx
        pop ax
        dec bx
        push ax
        push bx
        call ncrproc 
                pop bx
                pop ax
                ret
res1:   inc ncr
        ret
res2:   inc ncr
resn:   add ncr,ax
        ret
        ncrproc endp
        end
