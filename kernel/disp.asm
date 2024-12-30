mov ax,0xb800 ;指向文本模式的显示缓冲区
mov es,ax

mov byte [es:0x00],'I'
mov byte [es:0x01],0x07
mov byte [es:0x02],'L'
mov byte [es:0x03],0x06

times 510 - ($-$$)	db 0
dw 0xaa55
;times 510 - ($-$$)	db 0
;dw 0xaa55

