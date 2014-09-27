.model small
.data
   str db " MADAMa $"
   len equ 5
   revstr db 10 dup(?)
   msg1 db 10,13,"PALLINDROME $"
   msg2 DB 10,13,"not PALLINDROME $"
.code
   mov ax,@data
   mov ds,ax
   mov es,ax
   lea si,str
   lea di,revstr
   add di,len
   dec di
   mov cl,len
again: mov al,[si]
   mov [di],al
   dec di
   inc si
   dec cl
   jnz again
   cld
   mov ch,0h
   mov cl,len
   lea si, str
   lea di,revstr
   repe cmpsb
   je palin
   lea dx,msg2
   mov ah,09h
   int 21h
exit: mov ah,4ch
     int 21h
palin: lea dx,msg1
      mov ah,09h
      int 21h
      jmp exit
      end
