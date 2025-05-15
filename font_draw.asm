extern __ftol

extern ?DoAssert@@YAXEPBDZZ
extern        ?isEscapeChar@Font@@QAEHD@Z
extern ?fixedCharWidth@Font@@QAEHD@Z
extern ?handleEscapeChar@Font@@QAEXD@Z

section .data

jumptable_0043EA50 dd 0,0,0,0

section .text

global @Font_draw_asm@28

@Font_draw_asm@28:
 sub         esp,0x430
 xor         edx,edx
 push        ebx
 push        ebp
 push        esi
 mov         esi,ecx
 push        edi
 cmp         dword [esi+0x34],edx
 jne         .L0043E4DC
 cmp         dword [esi+0x30],edx
 je          .L0043EA42
.L0043E4DC:
 mov         ebx,dword [esp+0x0000044C]

 xor         ecx,ecx
 mov         dword [esp+0x10],ecx
 mov         dword [esp+0x2C],edx
 mov         al,byte [ebx]
 mov         dword [esp+0x20],edx
 test        al,al
 mov         dword [esp+0x1C],edx
 mov         dword [esp+0x28],ebx
 je          .L0043E6D6
 lea         eax,[esp+0x00000140]

 lea         edx,[esp+0x00000240]

 mov         dword [esp+0x14],eax
 lea         eax,[esp+0x40]
 lea         edi,[esp+0x00000340]

 mov         dword [esp+0x24],edx
 mov         dword [esp+0x18],eax
.L0043E528:
 movsx       edx,byte [ebx]
 cmp         edx,0x0FF
 jne         .L0043E56B
 mov         eax,dword [esp+0x1C]
 mov         ebp,dword [esp+0x18]
 inc         eax
 mov         edx,dword [esp+0x24]
 mov         dword [esp+0x1C],eax
 mov         eax,4
 add         ebp,eax
 add         edx,eax
 mov         dword [esp+0x18],ebp
 mov         ebp,dword [esp+0x14]
 add         ebp,eax
 add         edi,eax
 inc         ebx
 mov         dword [esp+0x24],edx
 mov         dword [esp+0x14],ebp
 mov         dword [esp+0x28],ebx
 jmp         .L0043E6CB
.L0043E56B:
 mov         eax,dword [esp+0x1C]
 push        0x54A4B8
 cmp         eax,0x40
 setl        al
 push        eax
 call        ?DoAssert@@YAXEPBDZZ
 mov         al,byte [ebx]
 xor         edx,edx
 movsx       ecx,al
 add         esp,8
 mov         dl,byte [ecx+esi+0x5F]
 mov         ebp,edx
 cmp         ebp,0x0FF
 jne         .L0043E5D2
 push        eax
 mov         ecx,esi
 call        ?isEscapeChar@Font@@QAEHD@Z
 test        eax,eax
 jne         .L0043E694
 mov         eax,dword [esi+0x48]
 xor         ecx,ecx
 mov         cl,byte [eax+4]
 mov         eax,ecx
 imul        eax,dword [esi+0x34]
 lea         ecx,[eax+eax*4]
 mov         eax,0x51EB851F
 shl         ecx,4
 imul        ecx
 sar         edx,5
 mov         eax,edx
 shr         eax,0x1F
 add         edx,eax
 jmp         .L0043E690
.L0043E5D2:
 mov         edx,dword [esi+0x48]
 mov         ecx,dword [esp+0x10]
 mov         dword [edi],ecx
 xor         ebx,ebx
 mov         bl,byte [edx+ebp*8+5]
 lea         eax,[edx+ebp*8]
 mov         edx,dword [esi+0x34]
 xor         ecx,ecx
 mov         cl,byte [eax+6]
 mov         eax,ebx
 sub         eax,ecx
 mov         ebx,dword [esp+0x20]
 imul        eax,edx
 cmp         eax,ebx
 jle         .L0043E5FF
 mov         dword [esp+0x20],eax
.L0043E5FF:
 imul        ecx,edx
 cmp         ecx,dword [esp+0x2C]
 jle         .L0043E60C
 mov         dword [esp+0x2C],ecx
.L0043E60C:
 mov         eax,ecx
 mov         ecx,dword [esp+0x14]
 neg         eax
 mov         dword [ecx],eax
 mov         ecx,dword [esi+0x54]
 test        ecx,ecx
 je          .L0043E638
 mov         ebx,dword [esp+0x18]
 mov         edx,dword [esp+0x10]
 mov         dword [ebx],edx
 mov         edx,dword [esp+0x24]
 mov         dword [edx],eax
 mov         edx,dword [esp+0x14]
 mov         eax,dword [ecx]
 push        edx
 push        edi
 call        dword [eax+0x14]
.L0043E638:
 mov         eax,dword [esi+0x30]
 mov         ebx,dword [esp+0x28]
 test        eax,eax
 je          .L0043E67E
 mov         al,byte [ebx]
 mov         ecx,esi
 push        eax
 call        ?fixedCharWidth@Font@@QAEHD@Z
 mov         ecx,dword [esi+0x48]
 xor         edx,edx
 shl         eax,0x0C
 mov         dl,byte [ecx+ebp*8+4]
 mov         ecx,dword [edi]
 imul        edx,dword [esi+0x34]
 sub         eax,edx
 add         ecx,eax
 mov         al,byte [ebx]
 mov         dword [edi],ecx
 push        eax
 mov         ecx,esi
 call        ?fixedCharWidth@Font@@QAEHD@Z
 mov         ecx,dword [esp+0x10]
 shl         eax,0x0C
 add         ecx,eax
 mov         dword [esp+0x10],ecx
 jmp         .L0043E694
.L0043E67E:
 mov         ecx,dword [esi+0x48]
 xor         edx,edx
 mov         dl,byte [ecx+ebp*8+4]
 mov         ecx,dword [esi+0x0C]
 add         edx,ecx
 imul        edx,dword [esi+0x34]
.L0043E690:
 add         dword [esp+0x10],edx
.L0043E694:
 mov         edx,dword [esp+0x1C]
 mov         ecx,dword [esp+0x18]
 mov         ebp,dword [esp+0x24]
 inc         edx
 mov         dword [esp+0x1C],edx
 mov         edx,dword [esp+0x14]
 mov         eax,4
 add         ecx,eax
 add         ebp,eax
 add         edx,eax
 add         edi,eax
 inc         ebx
 mov         dword [esp+0x18],ecx
 mov         ecx,dword [esp+0x10]
 mov         dword [esp+0x24],ebp
 mov         dword [esp+0x14],edx
 mov         dword [esp+0x28],ebx
.L0043E6CB:
 cmp         byte [ebx],0
 jne         .L0043E528
 xor         edx,edx
.L0043E6D6:
 mov         eax,dword [esi+4]
 sub         eax,edx
 je          .L0043E701
 dec         eax
 je          .L0043E6F1
 dec         eax
 jne         .L0043E70F
 mov         eax,dword [esp+0x00000444]

 shl         eax,0x0C
 sub         eax,ecx
 jmp         .L0043E70B
.L0043E6F1:
 mov         eax,dword [esp+0x00000444]

 shl         eax,0x0C
 sar         ecx,1
 sub         eax,ecx
 jmp         .L0043E70B
.L0043E701:
 mov         eax,dword [esp+0x00000444]

 shl         eax,0x0C
.L0043E70B:
 mov         dword [esp+0x24],eax
.L0043E70F:
 mov         eax,dword [esi+8]
 cmp         eax,3
 ja          .L0043E77B
 jmp         dword [eax*4+jumptable_0043EA50]

 mov         ebx,dword [esp+0x00000448]

 mov         eax,dword [esp+0x2C]
 shl         ebx,0x0C
 add         ebx,eax
 mov         dword [esp+0x10],ebx
 jmp         .L0043E77F
 mov         eax,dword [esp+0x20]
 mov         ecx,dword [esp+0x2C]
 mov         edx,dword [esp+0x00000448]

 lea         ebx,[eax+ecx]
 sar         ebx,1
 shl         edx,0x0C
 add         ebx,edx
 sub         ebx,eax
 mov         dword [esp+0x10],ebx
 jmp         .L0043E77F
 mov         ebx,dword [esp+0x00000448]

 shl         ebx,0x0C
 mov         dword [esp+0x10],ebx
 jmp         .L0043E77F
 mov         ebx,dword [esp+0x00000448]

 mov         eax,dword [esp+0x20]
 shl         ebx,0x0C
 sub         ebx,eax
 mov         dword [esp+0x10],ebx
 jmp         .L0043E77F
.L0043E77B:
 mov         ebx,dword [esp+0x10]
.L0043E77F:
 mov         eax,dword [esi+0x34]
 mov         ecx,dword [esi+0x24]
 imul        ecx,eax
 mov         dword [esp+0x3C],ecx
 mov         ecx,dword [esi+0x28]
 imul        ecx,eax
 mov         eax,dword [esp+0x0000044C]

 mov         dword [esp+0x38],ecx
 mov         dword [esp+0x1C],0

 mov         dword [esp+0x28],eax
 cmp         byte [eax],0
 je          .L0043EA42
 lea         ecx,[esp+0x40]
 lea         edx,[esp+0x00000240]

 mov         dword [esp+0x18],ecx
 lea         ecx,[esp+0x00000340]

 mov         dword [esp+0x20],edx
 lea         ebp,[esp+0x00000140]

 mov         dword [esp+0x14],ecx
.L0043E7D7:
 mov         dl,byte [eax]
 movsx       ecx,dl
 cmp         ecx,0x0FF
 jne         .L0043E81C
 mov         ecx,dword [esp+0x1C]
 mov         edi,dword [esp+0x14]
 inc         ecx
 mov         edx,dword [esp+0x18]
 mov         dword [esp+0x1C],ecx
 mov         ecx,4
 add         edi,ecx
 add         ebp,ecx
 mov         dword [esp+0x14],edi
 mov         edi,dword [esp+0x20]
 add         edi,ecx
 add         edx,ecx
 inc         eax
 mov         dword [esp+0x20],edi
 mov         dword [esp+0x18],edx
 mov         dword [esp+0x28],eax
 jmp         .L0043EA39
.L0043E81C:
 xor         eax,eax
 mov         al,byte [ecx+esi+0x5F]
 mov         edi,eax
 cmp         edi,0x0FF
 jne         .L0043E84F
 push        edx
 mov         ecx,esi
 call        ?isEscapeChar@Font@@QAEHD@Z
 test        eax,eax
 je          .L0043EA02
 mov         ecx,dword [esp+0x28]
 mov         dl,byte [ecx]
 mov         ecx,esi
 push        edx
 call        ?handleEscapeChar@Font@@QAEXD@Z
 jmp         .L0043EA02
.L0043E84F:
 mov         eax,dword [esi+0x48]
 mov         edx,dword [esi+0x34]
 mov         ecx,dword [eax+edi*8]
 mov         dword [ecx+0x0C],edx
 mov         eax,dword [esi+0x48]
 mov         ecx,dword [eax+edi*8]
 mov         byte [ecx+4],0
 mov         edx,dword [esi+0x48]
 mov         eax,dword [edx+edi*8]
 mov         byte [eax+6],1
 mov         ecx,dword [esi+0x48]
 mov         al,byte [esi+0x14]
 mov         edx,dword [ecx+edi*8]
 mov         byte [edx+7],al
 mov         ecx,dword [esi+0x48]
 mov         al,byte [esi+0x18]
 mov         edx,dword [ecx+edi*8]
 mov         byte [edx+8],al
 mov         ecx,dword [esi+0x48]
 mov         al,byte [esi+0x1C]
 mov         edx,dword [ecx+edi*8]
 mov         byte [edx+9],al
 mov         ecx,dword [esi+0x54]
 test        ecx,ecx
 je          .L0043E8BD
 mov         edx,dword [esi+0x48]
 mov         eax,dword [edx+edi*8]
 mov         edx,dword [ecx]
 mov         dword [esp+0x2C],eax
 add         eax,9
 push        eax
 mov         eax,dword [esp+0x30]
 add         eax,8
 push        eax
 mov         eax,dword [esp+0x34]
 add         eax,7
 push        eax
 call        dword [edx+0x18]
.L0043E8BD:
 mov         ecx,dword [esi+0x48]
 mov         eax,dword [ecx+edi*8]
 mov         ecx,dword [esp+0x00000450]

 mov         dword [esp+0x2C],eax
 mov         edx,dword [eax]
 mov         eax,dword [esp+0x00000454]

 push        eax
 mov         eax,dword [ebp]
 add         eax,ebx
 push        ecx
 sar         eax,0x0C
 mov         dword [esp+0x38],eax
 fild        dword [esp+0x38]
 fstp        qword [esp+0x38]
 fld         qword [esp+0x38]
 fsub        qword [0x0053B860]
 mov         dword [esp+0x38],edx
 call        __ftol
 mov         ecx,dword [esp+0x1C]
 push        eax
 mov         eax,dword [esp+0x3C]
 mov         edx,dword [ecx]
 mov         ecx,dword [esp+0x30]
 add         edx,ecx
 mov         ecx,dword [esp+0x38]
 sar         edx,0x0C
 dec         edx
 push        edx
 call        dword [eax+0x0C]
 mov         al,byte [esi+0x21]
 test        al,al
 je          .L0043E9CB
 mov         ecx,dword [esi+0x48]
 fld         dword [esp+0x00000454]

 mov         edx,dword [ecx+edi*8]
 fadd        dword [0x0053B27C]
 mov         byte [edx+4],1
 mov         eax,dword [esi+0x48]
 mov         ecx,dword [eax+edi*8]
 mov         byte [ecx+6],2
 mov         edx,dword [esi+0x48]
 mov         cl,byte [esi+0x2C]
 mov         eax,dword [edx+edi*8]
 mov         byte [eax+7],cl
 mov         edx,dword [esi+0x48]
 mov         cl,byte [esi+0x2C]
 mov         eax,dword [edx+edi*8]
 mov         byte [eax+8],cl
 mov         edx,dword [esi+0x48]
 mov         cl,byte [esi+0x2C]
 mov         eax,dword [edx+edi*8]
 push        ecx
 fstp        dword [esp]
 mov         byte [eax+9],cl
 mov         eax,dword [esp+0x00000454]

 mov         edx,dword [esi+0x48]
 mov         ecx,dword [ebp]
 push        eax
 mov         eax,dword [esp+0x40]
 mov         edi,dword [edx+edi*8]
 mov         edx,dword [esp+0x18]
 add         ecx,eax
 add         ecx,edx
 mov         ebx,dword [edi]
 sar         ecx,0x0C
 mov         dword [esp+0x38],ecx
 fild        dword [esp+0x38]
 fstp        qword [esp+0x38]
 fld         qword [esp+0x38]
 fsub        qword [0x0053B860]
 call        __ftol
 mov         edx,dword [esp+0x1C]
 mov         ecx,dword [esp+0x44]
 push        eax
 mov         eax,dword [edx]
 mov         edx,dword [esp+0x30]
 add         eax,ecx
 mov         ecx,edi
 add         eax,edx
 sar         eax,0x0C
 dec         eax
 push        eax
 call        dword [ebx+0x0C]
.L0043E9CB:
 mov         ecx,dword [esi+0x54]
 test        ecx,ecx
 je          .L0043E9FE
 mov         eax,dword [esp+0x1C]
 mov         ebx,dword [esp+0x10]
 push        eax
 mov         eax,dword [ebp]
 add         eax,ebx
 mov         edi,dword [esp+0x28]
 push        eax
 mov         eax,dword [esp+0x28]
 mov         edx,dword [ecx]
 mov         eax,dword [eax]
 add         eax,ebx
 push        eax
 mov         eax,dword [esp+0x24]
 mov         eax,dword [eax]
 add         eax,edi
 push        eax
 call        dword [edx+0x20]
 jmp         .L0043EA02
.L0043E9FE:
 mov         ebx,dword [esp+0x10]
.L0043EA02:
 mov         edx,dword [esp+0x1C]
 mov         ecx,dword [esp+0x14]
 mov         eax,4
 inc         edx
 add         ecx,eax
 mov         dword [esp+0x1C],edx
 mov         edx,dword [esp+0x20]
 mov         dword [esp+0x14],ecx
 mov         ecx,dword [esp+0x18]
 add         ebp,eax
 add         edx,eax
 add         ecx,eax
 mov         eax,dword [esp+0x28]
 mov         dword [esp+0x20],edx
 inc         eax
 mov         dword [esp+0x18],ecx
 mov         dword [esp+0x28],eax
.L0043EA39:
 cmp         byte [eax],0
 jne         .L0043E7D7
.L0043EA42:
 pop         edi
 pop         esi
 pop         ebp
 pop         ebx
 add         esp,0x430
 ret         0x14
