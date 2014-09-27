disp MACRO msg
        lea dx,msg
        mov ah,09h
        int 21h
ENDM

.model small
.data
        m1 db 13,10, "Enter s1: $"
        m2 db 13,10, "Enter s2: $"
        m3 db 13,10, "len 1 : $"
        m4 db 13,10, "len 2 : $"
        m5 db 13,10, "Str1 = Str2$"
        m6 db 13,10, "Str1 != Str2$"
        str1 db 80,?, 80 dup (?)
        str2 db 80,?, 80 dup (?)
        l1 db ?
        l2 db ?
.code
        mov ax, @data
        mov ds, ax
        mov es, ax
        disp m1
        lea dx, str1
        call read
        disp m2
        lea dx, str2
        call read
        mov al, [str1 + 1]
        mov l1, al
        mov al, [str2 + 1]
        mov l2, al
        cmp al,l1
        JNE strnotequal
        mov ch, 0
        mov cl, l1
        lea si, str1 + 2
        lea di, str2 + 2
        cld
        REPE CMPSB
        JNE strnotequal
        disp m5
        JMP next
strnotequal : disp m6
next    :       disp m3
                mov al,l1
                call display
                disp m4
                mov al, l2
                call display
                mov ah,4ch
                int 21h
 read PROC
        mov ah,0ah
        int 21h
        ret
 read ENDP

 display PROC
        aam
        mov bx,ax
        add bx,3030h
        mov ah,02
        mov dl,bh
        int 21h
        mov dl,bl
        int 21h
        ret
 display ENDP
 end
