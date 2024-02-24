#pragma once


class CMenu  {

public:
	unsigned char unk[0x538];
	EXPORT virtual ~CMenu();


	EXPORT CMenu(int x,int y,unsigned char Justification,int HiScale,int LowScale, int LineSep);

};