/***************************************************************
 * Name:      RTC4RlaysFBMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alfonso Abelenda Escudero (alfonso@abelenda.es)
 * Created:   2018-06-07
 * Copyright: Alfonso Abelenda Escudero (https://chafalladas.com)
 * License:
 **************************************************************/

#ifndef RTC4RLAYSFBMAIN_H
#define RTC4RLAYSFBMAIN_H

#include "RTC4RlaysFBApp.h"

#include "GUIDialog.h"

class RTC4RlaysFBDialog: public GUIDialog
{
    public:
        RTC4RlaysFBDialog(wxDialog *dlg);
        ~RTC4RlaysFBDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void onInitFBMain(wxInitDialogEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
		virtual void onHalfSec( wxTimerEvent& event );
		virtual void OnToogleCon( wxCommandEvent& event );
		virtual void onBtnSync( wxCommandEvent& event );
		virtual void onAceptRTC( wxCommandEvent& event );
		virtual void commandTimerAct( wxTimerEvent& event );
		virtual void GetAlarms( wxCommandEvent& event );
		virtual void rescanPorts( wxCommandEvent& event );
		virtual void btnSetAlarms( wxCommandEvent& event );
		virtual void helWanted( wxCommandEvent& event );
		virtual void checkVerb( wxCommandEvent& event );
		virtual void checkSleep( wxCommandEvent& event );

};
#endif // RTC4RLAYSFBMAIN_H
