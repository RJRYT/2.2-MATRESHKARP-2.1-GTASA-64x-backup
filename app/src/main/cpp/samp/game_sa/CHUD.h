#pragma once

#include "rwcore.h"
#include "Rect.h"

struct CGtaRect
{
public:
	float x1;           // x1
	float y1;    // y1

//	float x2;        // x2
//	float y2;          // y2
};

struct CRadarBrRect
{
public:
    float x1;           // x1
    float y1;    // y1

    float x2;        // x2
    float y2;          // y2
};

struct CGtaSizePosition
{
public:
	float size1;           // size
	float size2;    // size

	float x1;           // x1
	float y1;    // y1

	float x2;        // x2
	float y2;          // y2
};

class CHUD
{
public:
    static bool m_bShow;
    static bool m_bShowDialog;
    static RwTexture* hud_radar;

public:
    static void Initialise();

    static CGtaRect radarBgPos1; // x y
    static CGtaRect radarBgPos2; // x y
    static CGtaRect radarPos; // x y
    static CRadarBrRect radar1; // x y
	static CGtaSizePosition radarBgPosSize; // size size x y

    static void Disable()      { m_bShow = false; }
    static void Enable()       { m_bShow = true; };

    static void DisableD()      { m_bShow = false; }
    static void EnableD()       { m_bShow = true; };

    static bool IsEnabled()    { return m_bShow; };
    static bool IsEnabledDialog()    { return m_bShowDialog; };

    static void EditRadar(CRect* rect);
    static void EditRadarBios(CRect* rect);
    static void Render();
};
