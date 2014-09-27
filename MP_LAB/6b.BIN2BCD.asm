.model small
.stack
.data
bin dw 14e2h
bcd db 4 dup(?)
disptable db 03h,09Fh,25h,0Dh,99h,49h,41h,1Fh,01h,09bh
.code
mov ax,@data
mov ds,ax
mov al,90h
mov dx,9803h
out dx,al
mov cx,bin
mov ax,00h
again: add al,01
      daa
      jnc noincah
      add ah,01
      mov al,ah
      daa
      mov ah,al
      mov al,00
noincah: loop again
         mov dx,ax
         mov bl,10h
         mov ah,00
         mov al,dh
         div bl
         mov bcd,al
         mov bcd+1,ah
         mov ah,00
         mov al,dl
         div bl
         mov bcd+2,al
         mov bcd+3,ah
         mov cl,0ah
repet: call bcdldisp
       call delay
       call bcdrdisp
       call delay
       loop repet
       mov ah,4ch
       int 21h
bcdldisp proc
push cx
mov si,03
nextchar: mov ah,08h
          mov al,bcd[si]
          lea bx,disptable
          xlat
nextseg: mov dx,9801h
         out dx,al
         mov ch,al
         mov al,00h
         mov dx,9802h
         out dx,al
         mov al,0ffh
         out dx,al
         dec ah
         jz overchk
         mov al,ch
         ror al,01
         jmp nextseg
overchk: dec si
        cmp si,-1
        jne nextchar
        pop cx
        ret
        bcdldisp endp
bcdrdisp proc
push cx
mov si,0
nextchar1: mov ah,08h
           mov al,bcd[si]
           lea bx,disptable
           xlat
nextseg1: mov dx,9801h
         out dx,al
         mov ch,al
         mov al,00h
         mov dx,9802h
         out dx,al
         mov al,0ffh
         out dx,al
         dec ah
         jz overchk1
         mov al,ch
         ror al,01h
         jmp nextseg1
overchk1: inc si
          cmp si,04
          jne nextchar1
          pop cx
          ret
          bcdrdisp endp
delay proc
push cx
push bx
mov cx,0ffffh
loop2: mov bx,0ffffh
loop1: dec bx
       jnz loop1
       loop loop2
       pop bx
       pop cx
       ret
       delay endp
       end
