loc_503100:
mov al,gInBeginScene
loc_503105:
sub esp,1Ch
loc_503108:
test al,al
loc_50310A:
jnz loc_503119
loc_50310C:
push offset aDrawingOutside
loc_503111:
call print_if_false
loc_503116:
add esp,4
loc_503119:
mov eax,gLowGraphics
loc_50311E:
push ebx
loc_50311F:
push esi
loc_503120:
mov esi,[esp+24h+arg_0]
loc_503124:
test eax,eax
loc_503126:
push edi
loc_503127:
jz loc_503230
loc_50312D:
mov edi,dword_6B7A8C
loc_503133:
cmp edi,1
loc_503136:
jz loc_503230
loc_50313C:
fld ,dword ptr [esi+2Ch]
loc_50313F:
fsub ,dword ptr [esi+10h]
loc_503142:
mov edx,[esi+0Ch]
loc_503145:
lea eax,[edx-1]
loc_503148:
fstp ,[esp+28h+var_1C]
loc_50314C:
fld ,dword ptr [esi+30h]
loc_50314F:
fsub ,dword ptr [esi+14h]
loc_503152:
lea ecx,ds:0[eax*8]
loc_503159:
sub ecx,eax
loc_50315B:
cmp eax,2
loc_50315E:
fstp ,[esp+28h+var_14]
loc_503162:
fld ,dword ptr [esi+ecx*4+10h]
loc_503166:
fsub ,dword ptr [esi+10h]
loc_503169:
lea ecx,[esi+ecx*4+10h]
loc_50316D:
fstp ,[esp+28h+var_18]
loc_503171:
fld ,dword ptr [ecx+4]
loc_503174:
fsub ,dword ptr [esi+14h]
loc_503177:
fstp ,[esp+28h+arg_0]
loc_50317B:
jle loc_5031A5
loc_50317D:
fld ,dword ptr [esi+2Ch]
loc_503180:
fsub ,dword ptr [esi+48h]
loc_503183:
fstp ,[esp+28h+var_4]
loc_503187:
fld ,dword ptr [esi+30h]
loc_50318A:
fsub ,dword ptr [esi+4Ch]
loc_50318D:
fstp ,[esp+28h+var_C]
loc_503191:
fld ,dword ptr [esi+64h]
loc_503194:
fsub ,dword ptr [esi+48h]
loc_503197:
fstp ,[esp+28h+var_10]
loc_50319B:
fld ,dword ptr [esi+68h]
loc_50319E:
fsub ,dword ptr [esi+4Ch]
loc_5031A1:
fstp ,[esp+28h+var_8]
loc_5031A5:
fld ,[esp+28h+arg_0]
loc_5031A9:
fmul ,[esp+28h+var_1C]
loc_5031AD:
fld ,dword ptr [esp+10h]
loc_5031B1:
fmul ,[esp+28h+var_14]
loc_5031B5:
cmp edi,3
loc_5031B8:
fsubp st(1),st
loc_5031BA:
fstp ,[esp+28h+arg_0]
loc_5031BE:
fld ,[esp+28h+arg_0]
loc_5031C2:
fcomp ,ds:flt_53B280
loc_5031C8:
fnstsw ax
loc_5031CA:
jnz loc_5031D5
loc_5031CC:
test ah,1
loc_5031CF:
jnz loc_5031DE
loc_5031D1:
mov cl,1
loc_5031D3:
jmp loc_5031E0
loc_5031D5:
test ah,41h
loc_5031D8:
jz loc_5031DE
loc_5031DA:
mov cl,1
loc_5031DC:
jmp loc_5031E0
loc_5031DE:
xor cl,cl
loc_5031E0:
cmp edx,3
loc_5031E3:
jle loc_503228
loc_5031E5:
fld ,[esp+28h+var_10]
loc_5031E9:
fmul ,[esp+28h+var_C]
loc_5031ED:
fld ,[esp+28h+var_8]
loc_5031F1:
fmul ,[esp+28h+var_4]
loc_5031F5:
cmp edi,3
loc_5031F8:
fsubp st(1),st
loc_5031FA:
fstp ,[esp+28h+arg_0]
loc_5031FE:
fld ,[esp+28h+arg_0]
loc_503202:
fcomp ,ds:flt_53B280
loc_503208:
fnstsw ax
loc_50320A:
jnz loc_503215
loc_50320C:
test ah,1
loc_50320F:
jnz loc_50321E
loc_503211:
mov al,1
loc_503213:
jmp loc_503220
loc_503215:
test ah,41h
loc_503218:
jz loc_50321E
loc_50321A:
mov al,1
loc_50321C:
jmp loc_503220
loc_50321E:
xor al,al
loc_503220:
xor al,cl
loc_503222:
jnz loc_5033D6
loc_503228:
test cl,cl
loc_50322A:
jz loc_5033D6
loc_503230:
mov edi,[esp+28h+arg_4]
loc_503234:
test edi,edi
loc_503236:
jl loc_503266
loc_503238:
cmp edi,1000h
loc_50323E:
push offset aInvalidForcedS
loc_503243:
setle dl
loc_503246:
push edx
loc_503247:
call print_if_false
loc_50324C:
mov eax,gSceneBuffer[edi*4]
loc_503253:
add esp,8
loc_503256:
mov [esi],eax
loc_503258:
mov gSceneBuffer[edi*4],esi
loc_50325F:
pop edi
loc_503260:
pop esi
loc_503261:
pop ebx
loc_503262:
add esp,1Ch
loc_503265:
retn 
loc_503266:
mov al,gDxPolyRelated
loc_50326B:
test al,al
loc_50326D:
jz loc_503390
loc_503273:
cmp word ptr [esi+8],0
loc_503278:
jnz loc_503390
loc_50327E:
mov ebx,[esi+4]
loc_503281:
mov eax,gDDSurface7
loc_503286:
cmp ebx,eax
loc_503288:
jz loc_5032C9
loc_50328A:
mov eax,g_D3DDevice7
loc_50328F:
push ebx
loc_503290:
push 0
loc_503292:
push eax
loc_503293:
mov ecx,[eax]
loc_503295:
call dword ptr [ecx+8Ch]
loc_50329B:
mov edi,eax
loc_50329D:
test edi,edi
loc_50329F:
jz loc_5032C3
loc_5032A1:
push 3EEh
loc_5032A6:
push offset aCBackupSpideyp_1
loc_5032AB:
push edi
loc_5032AC:
call displayD3DError
loc_5032B1:
add esp,0Ch
loc_5032B4:
test edi,edi
loc_5032B6:
jge loc_5032C3
loc_5032B8:
call ?DXINIT_ShutDown@@YAXXZ
loc_5032BD:
push edi
loc_5032BE:
call _exit
loc_5032C3:
mov gDDSurface7,ebx
loc_5032C9:
xor edx,edx
loc_5032CB:
mov dx,[esi+8]
loc_5032CF:
push edx
loc_5032D0:
call ?DXPOLY_SetBlendMode@@YAXI@Z
loc_5032D5:
mov ax,[esi+0Ah]
loc_5032D9:
add esp,4
loc_5032DC:
not ax
loc_5032DF:
and eax,0FFFFh
loc_5032E4:
mov edi,eax
loc_5032E6:
and eax,4
loc_5032E9:
or al,2
loc_5032EB:
and edi,2
loc_5032EE:
shr eax,1
loc_5032F0:
mov ebx,eax
loc_5032F2:
mov eax,gAddressU
loc_5032F7:
or edi,1
loc_5032FA:
cmp edi,eax
loc_5032FC:
jz loc_503317
loc_5032FE:
mov eax,g_D3DDevice7
loc_503303:
push edi
loc_503304:
push 0Dh
loc_503306:
push 0
loc_503308:
mov ecx,[eax]
loc_50330A:
push eax
loc_50330B:
call dword ptr [ecx+94h]
loc_503311:
mov gAddressU,edi
loc_503317:
cmp ebx,gAddressV
loc_50331D:
jz loc_503338
loc_50331F:
mov eax,g_D3DDevice7
loc_503324:
push ebx
loc_503325:
push 0Eh
loc_503327:
push 0
loc_503329:
mov edx,[eax]
loc_50332B:
push eax
loc_50332C:
call dword ptr [edx+94h]
loc_503332:
mov gAddressV,ebx
loc_503338:
mov al,[esi+0Ah]
loc_50333B:
mov cl,gTexAlpha
loc_503341:
shr al,3
loc_503344:
and al,1
loc_503346:
cmp al,cl
loc_503348:
jz loc_50336D
loc_50334A:
mov ecx,g_D3DDevice7
loc_503350:
xor ebx,ebx
loc_503352:
test al,al
loc_503354:
setnz bl
loc_503357:
add ebx,3
loc_50335A:
mov gTexAlpha,al
loc_50335F:
mov edx,[ecx]
loc_503361:
push ebx
loc_503362:
push 4
loc_503364:
push 0
loc_503366:
push ecx
loc_503367:
call dword ptr [edx+94h]
loc_50336D:
mov edx,[esi+0Ch]
loc_503370:
mov eax,g_D3DDevice7
loc_503375:
push 0
loc_503377:
add esi,10h
loc_50337A:
mov ecx,[eax]
loc_50337C:
push edx
loc_50337D:
push esi
loc_50337E:
push 144h
loc_503383:
push 6
loc_503385:
push eax
loc_503386:
call [ecx+arg_60]
loc_503389:
pop edi
loc_50338A:
pop esi
loc_50338B:
pop ebx
loc_50338C:
add esp,1Ch
loc_50338F:
retn 
loc_503390:
fld ,gFlHudOffset
loc_503396:
fmul ,dword ptr [esp+38h]
loc_50339A:
fmul ,ds:flt_53C828
loc_5033A0:
call __ftol
loc_5033A5:
mov ecx,eax
loc_5033A7:
mov eax,gHudOffset
loc_5033AC:
sub eax,ecx
loc_5033AE:
mov ecx,[esp+28h+arg_8]
loc_5033B2:
add eax,ecx
loc_5033B4:
jns loc_5033BA
loc_5033B6:
xor eax,eax
loc_5033B8:
jmp loc_5033C6
loc_5033BA:
cmp eax,1000h
loc_5033BF:
jle loc_5033C6
loc_5033C1:
mov eax,1000h
loc_5033C6:
mov edx,gSceneBuffer[eax*4]
loc_5033CD:
mov [esi],edx
loc_5033CF:
mov gSceneBuffer[eax*4],esi
loc_5033D6:
pop edi
loc_5033D7:
pop esi
loc_5033D8:
pop ebx
loc_5033D9:
add esp,1Ch
loc_5033DC:
retn 
