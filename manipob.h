#pragma once

#ifndef MANIPOB_H
#define MANIPOB_H

#include "export.h"
#include "ob.h"
#include "m3dcolij.h"

class CManipOb : public CBody
{
	public:
		EXPORT void CalculateThrowPositionArray(CVector*, int);
		EXPORT void ThrowPos(CVector *, int);
		EXPORT void Throw(CVector *);
		EXPORT void GetAttachPoint(CVector *);
		EXPORT u8 TugImpulse(CVector *,CVector *);

		EXPORT void Chunk(SLineInfo*, CVector*);
		EXPORT void TurnOffShadow(void);
		EXPORT void SendPulse(void);
		EXPORT void Pickup(void);
		EXPORT void Drop(CVector*);

		EXPORT CManipOb(i16*, i32);
		EXPORT virtual ~CManipOb(void);

		EXPORT virtual void Smash(void);

		PADDING(4);

		i32 mNumVectors;
		CVector *pVectors;
		i32 field_100;

		i16 field_104;
		PADDING(2);

		i16 field_108;

		i32 field_10C;

		CVector field_110;

		CItem *field_11C;
		u32 field_120;

		u8 field_124;

		PADDING(0x128-0x124-1);
};

class CManipObChunk : public CBody
{
	public:
		EXPORT CManipObChunk(u32,CVector *,CVector *);
		EXPORT ~CManipObChunk(void) OVERRIDE;

		EXPORT void AI(void) OVERRIDE;
		EXPORT void CManipObChunk::DoPhysics(void);

		PADDING(8);

		i32 field_FC;

};

void validate_CManipOb(void);
void validate_CManipObChunk(void);
#endif
