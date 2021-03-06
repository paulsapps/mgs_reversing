#include "linker.h"
#include "data.h"
#include "menuMan.h"
#include "dgd.h"

void MENU_Text_Init_80038b98(void);
void mts_doNothing_8008BB98(void);

extern int gActiveBuffer_800AB920;
extern MenuGlue gMenuPrimBuffer_8009E2D0;
extern struct_dg gOts_800B1800[3];
extern int dword_800AB68C;

/*
void menu_reset_ot_80038A88(void)
{
    MenuGlue* pGlue = &gMenuPrimBuffer_8009E2D0;
    MenuPrimBuffer* pPrimBuf = &pGlue->mPrimBuf;
    if (pPrimBuf->mOtEnd < pPrimBuf->mFreeLocation)
    {
        mts_doNothing_8008BB98();
    }

    pPrimBuf->mOtEnd =  pGlue->mPrimPtrs[gActiveBuffer_800AB920] + 0x2000;
    pPrimBuf->mOt = gOts_800B1800[2].mOrderingTables[gActiveBuffer_800AB920];
    dword_800AB68C = pPrimBuf->mFreeLocation - pGlue->mPrimPtrs[1 - gActiveBuffer_800AB920];
    pPrimBuf->mFreeLocation = pGlue->mPrimPtrs[gActiveBuffer_800AB920];
    MENU_Text_Init_80038b98();
}
*/

void MENU_Text_XY_Flags_80038B34(int xpos, int ypos, int flags)
{
	TextConfig *pTextConfig = &gMenuTextConfig_8009E2E4;

	pTextConfig->xpos = xpos;
	pTextConfig->ypos = ypos;
	pTextConfig->flags = flags;
}

void MENU_Color_80038B4C(int r, int g, int b)
{
	unsigned int newColour;
	unsigned int unknown;
	TextConfig *pTextConfig = &gMenuTextConfig_8009E2E4;

	if ((pTextConfig->flags & TextConfig_Flags_eSemiTransparent_20) != 0)
	{
		newColour = r | g << 8 | b << 0x10;
		unknown = 0x66000000;
	}
	else
	{
		newColour = r | g << 8 | b << 0x10;
		unknown = 0x64000000;
	}

	pTextConfig->colour = newColour | unknown;
}

void MENU_Text_Init_80038b98(void)
{
	TextConfig *pTextConfig = &gMenuTextConfig_8009E2E4;
	pTextConfig->colour = 0x64808080;
	pTextConfig->flags = 0;
}
