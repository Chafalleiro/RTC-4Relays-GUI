/***************************************************************
 * Name:      RTC4RlaysFBApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alfonso Abelenda Escudero (alfonso@abelenda.es)
 * Created:   2018-06-07
 * Copyright: Alfonso Abelenda Escudero (https://chafalladas.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "RTC4RlaysFBApp.h"
#include "RTC4RlaysFBMain.h"

IMPLEMENT_APP(RTC4RlaysFBApp);

bool RTC4RlaysFBApp::OnInit()
{

    RTC4RlaysFBDialog* dlg = new RTC4RlaysFBDialog(0L);
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
