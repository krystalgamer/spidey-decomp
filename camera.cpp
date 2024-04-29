#include "camera.h"
#include "validate.h"



// Not matching, not important
void CCamera::SetFixedFocusMode(CVector *a2, unsigned __int16 a3, unsigned __int16 a4){

	this->mMode = 6;
	this->field_2AC = 1;
	this->field_2E8 = *a2;
	this->field_2E4 = (0xFFFF & a3) / 3;
	this->field_2BC = a4;
}

int CCamera::SetMode(ECameraMode mode){

	int oldMode = this->mMode;
	this->mMode = mode;
	if (mode == ECam_mode_0x10 || mode == ECam_mode_0x11){
		*gCameraRelated = 0;
	}

	return oldMode;
}

void CCamera::SetCollisionRayLR(int a2){
	this->field_264 = a2;
}

void CCamera::SetCollisionRayBack(int a2){
	this->field_268 = a2;
}

void CCamera::SetCollisionAngLR(__int16 a2){
	this->field_26C = a2;
}

void CCamera::SetCollisionAngBack(__int16 a2){
	this->field_26E = a2;
}

void CCamera::SetZoom(int a2, unsigned __int16 a3){

	this->field_174 = a3;
	if (this->field_174)
	{
		this->field_178 = (a2 - this->mZoom) / (0xFFFF & a3);
		this->field_17C = a2;
	}
	else
	{
		this->mZoom = a2;
	}
}

int CCamera::GetZoom(void) const{
	return this->mZoom;
}

void validate_CCamera(void){
	VALIDATE_SIZE(CCamera, 0x2F4);


	VALIDATE(CCamera, field_F8, 0xF8);
	VALIDATE(CCamera, field_F9, 0xF9);
	VALIDATE(CCamera, field_FC, 0xFC);
	VALIDATE(CCamera, field_100, 0x100);
	VALIDATE(CCamera, field_104, 0x104);
	VALIDATE(CCamera, field_108, 0x108);
	VALIDATE(CCamera, field_10C, 0x10C);
	VALIDATE(CCamera, field_110, 0x110);
	VALIDATE(CCamera, field_114, 0x114);
	VALIDATE(CCamera, field_118, 0x118);
	VALIDATE(CCamera, field_11C, 0x11C);
	VALIDATE(CCamera, field_120, 0x120);
	VALIDATE(CCamera, field_124, 0x124);
	VALIDATE(CCamera, field_128, 0x128);
	VALIDATE(CCamera, field_12C, 0x12C);
	VALIDATE(CCamera, field_130, 0x130);
	VALIDATE(CCamera, field_134, 0x134);
	VALIDATE(CCamera, field_138, 0x138);
	VALIDATE(CCamera, field_13C, 0x13C);
	VALIDATE(CCamera, field_140, 0x140);
	VALIDATE(CCamera, field_144, 0x144);
	VALIDATE(CCamera, field_148, 0x148);
	VALIDATE(CCamera, field_14C, 0x14C);
	VALIDATE(CCamera, field_150, 0x150);
	VALIDATE(CCamera, field_154, 0x154);
	VALIDATE(CCamera, field_158, 0x158);
	VALIDATE(CCamera, field_15C, 0x15C);
	VALIDATE(CCamera, field_160, 0x160);
	VALIDATE(CCamera, field_164, 0x164);
	VALIDATE(CCamera, field_168, 0x168);
	VALIDATE(CCamera, field_16C, 0x16C);
	VALIDATE(CCamera, mZoom, 0x170);

	VALIDATE(CCamera, field_174, 0x174);
	VALIDATE(CCamera, field_178, 0x178);
	VALIDATE(CCamera, field_17C, 0x17C);


	VALIDATE(CCamera, field_1A8, 0x1A8);
	VALIDATE(CCamera, field_1AC, 0x1AC);
	VALIDATE(CCamera, field_1B0, 0x1B0);
	VALIDATE(CCamera, field_1B4, 0x1B4);
	VALIDATE(CCamera, field_1B8, 0x1B8);
	VALIDATE(CCamera, field_1BC, 0x1BC);
	VALIDATE(CCamera, field_1C0, 0x1C0);
	VALIDATE(CCamera, field_1C8, 0x1C8);
	VALIDATE(CCamera, field_1CC, 0x1CC);
	VALIDATE(CCamera, field_1CE, 0x1CE);
	VALIDATE(CCamera, field_1D8, 0x1D8);
	VALIDATE(CCamera, field_1DC, 0x1DC);
	VALIDATE(CCamera, field_1E0, 0x1E0);
	VALIDATE(CCamera, field_1E4, 0x1E4);
	VALIDATE(CCamera, field_1E8, 0x1E8);
	VALIDATE(CCamera, field_1EC, 0x1EC);
	VALIDATE(CCamera, field_1F0, 0x1F0);
	VALIDATE(CCamera, field_1F4, 0x1F4);
	VALIDATE(CCamera, field_1F8, 0x1F8);
	VALIDATE(CCamera, field_1FC, 0x1FC);
	VALIDATE(CCamera, field_200, 0x200);
	VALIDATE(CCamera, field_204, 0x204);
	VALIDATE(CCamera, field_208, 0x208);
	VALIDATE(CCamera, field_20C, 0x20C);
	VALIDATE(CCamera, field_210, 0x210);
	VALIDATE(CCamera, field_214, 0x214);
	VALIDATE(CCamera, field_218, 0x218);
	VALIDATE(CCamera, field_21C, 0x21C);
	VALIDATE(CCamera, field_220, 0x220);
	VALIDATE(CCamera, field_224, 0x224);
	VALIDATE(CCamera, field_228, 0x228);
	VALIDATE(CCamera, field_22C, 0x22C);
	VALIDATE(CCamera, field_230, 0x230);
	VALIDATE(CCamera, field_234, 0x234);
	VALIDATE(CCamera, field_238, 0x238);
	VALIDATE(CCamera, field_23C, 0x23C);
	VALIDATE(CCamera, field_240, 0x240);
	VALIDATE(CCamera, field_244, 0x244);
	VALIDATE(CCamera, field_248, 0x248);
	VALIDATE(CCamera, field_24C, 0x24C);

	VALIDATE(CCamera, field_258, 0x258);
	VALIDATE(CCamera, field_25C, 0x25C);
	VALIDATE(CCamera, field_260, 0x260);
	VALIDATE(CCamera, field_264, 0x264);
	VALIDATE(CCamera, field_268, 0x268);
	VALIDATE(CCamera, field_26C, 0x26C);
	VALIDATE(CCamera, field_26E, 0x26E);
	VALIDATE(CCamera, field_274, 0x274);
	VALIDATE(CCamera, field_276, 0x276);
	VALIDATE(CCamera, field_277, 0x277);
	VALIDATE(CCamera, field_278, 0x278);
	VALIDATE(CCamera, field_27A, 0x27A);
	VALIDATE(CCamera, field_27C, 0x27C);
	VALIDATE(CCamera, field_27E, 0x27E);
	VALIDATE(CCamera, field_284, 0x284);
	VALIDATE(CCamera, field_288, 0x288);
	VALIDATE(CCamera, field_28C, 0x28C);
	VALIDATE(CCamera, field_290, 0x290);
	VALIDATE(CCamera, field_294, 0x294);
	VALIDATE(CCamera, field_298, 0x298);
	VALIDATE(CCamera, field_29C, 0x29C);

	VALIDATE(CCamera, mMode, 0x2A0);
	VALIDATE(CCamera, field_2A4, 0x2A4);

	VALIDATE(CCamera, field_2A8, 0x2A8);
	VALIDATE(CCamera, field_2AC, 0x2AC);

	VALIDATE(CCamera, field_2B0, 0x2B0);
	VALIDATE(CCamera, field_2B4, 0x2B4);
	VALIDATE(CCamera, field_2B8, 0x2B8);

	VALIDATE(CCamera, field_2BC, 0x2BC);
	VALIDATE(CCamera, field_2C0, 0x2C0);


	VALIDATE(CCamera, field_2C4, 0x2C4);
	VALIDATE(CCamera, field_2C8, 0x2C8);
	VALIDATE(CCamera, field_2CC, 0x2CC);
	VALIDATE(CCamera, field_2D0, 0x2D0);
	VALIDATE(CCamera, field_2D4, 0x2D4);

	VALIDATE(CCamera, field_2E4, 0x2E4);

	VALIDATE(CCamera, field_2E8, 0x2E8);

}
