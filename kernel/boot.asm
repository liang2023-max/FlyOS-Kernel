org 07c00h
mov ax,3
int 0x10
mov ax,0
mov ds,ax
mov es,ax
mov ss,ax
mov sp,0x7c00
mov ax,0xb800
mov ds,ax
mov byte [0], 'H'
call Disp
jmp $
Disp:
    mov ax,BootMsg
    mov bp,ax
    mov cx,16
    mov ax,01301h
    mov bx,000ch
    mov dl,0
    int 10h
BootMsg: db "Welcome Use FlyOS DOS"
times 510 - ($-$$)  db 0
dw 0xaa55