///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDIALOG_H__
#define __GUIDIALOG_H__
#ifdef WX_GCH
#include <wx_pch.h>
#else
#include <wx/wx.h>
#endif
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/tglbtn.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/timectrl.h>
#include <wx/choice.h>
#include <wx/listbox.h>
#include <wx/calctrl.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxDialog
{
	private:

	protected:
		enum
		{
			lb_RTCTime = 1000,
			lSysTime,
			idbtnSync,
			idBtnAbout,
			idBtnQuit,
			idSerialSelect,
			lbPortSpeed,
			lbDatabits,
			lbtextDatabits,
			lbParity,
			lbStopbits,
			lbFlowcontrol,
			lbConnect,
			idAlarmDate0,
			idAlarmTime0,
			idTimerOn0,
			idTimerOff0,
			idAlarmDate1,
			idAlarmDate2,
			idAlarmDate3,
			idAlarmDate4,
			idAlarmDate5,
			idAlarmDate6,
			idAlarmDate7,
			lbSetAlarms,
			idbtnSetRTC,
			idcommandTimer
		};

		wxStaticText* m_RTCTime;
		wxStaticText* mSysTime;
		wxButton* mbtnSync;
		wxButton* BtnAbout;
		wxStaticLine* m_staticline1;
		wxButton* BtnQuit;
		wxStaticLine* m_staticline11;
		wxButton* mHelp;
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxComboBox* mSerialSelect;
		wxStaticText* m_staticText11;
		wxComboBox* mPortSpeed;
		wxStaticText* m_staticText12;
		wxComboBox* mDatabits;
		wxStaticText* textDatabits;
		wxComboBox* mParity;
		wxStaticText* m_staticText16;
		wxComboBox* mStopbits;
		wxStaticText* m_staticText17;
		wxComboBox* mFlowcontrol;
		wxStaticText* m_staticText18;
		wxCheckBox* mDTS;
		wxCheckBox* mRTS;
		wxToggleButton* mConnect;
		wxButton* mRescan;
		wxPanel* m_panel1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText171;
		wxDatePickerCtrl* mAlarmDate0;
		wxTimePickerCtrl* mAlarmTime0;
		wxCheckBox* mAlarmAct0;
		wxComboBox* mAlarmTmr0;
		wxTimePickerCtrl* mTimerOn0;
		wxTimePickerCtrl* mTimerOff0;
		wxComboBox* mTimerRep0;
		wxChoice* mTimerAct0;
		wxListBox* mDayOff0;
		wxDatePickerCtrl* mAlarmDate1;
		wxTimePickerCtrl* mAlarmTime1;
		wxCheckBox* mAlarmAct1;
		wxComboBox* mAlarmTmr1;
		wxTimePickerCtrl* mTimerOn1;
		wxTimePickerCtrl* mTimerOff1;
		wxComboBox* mTimerRep1;
		wxChoice* mTimerAct1;
		wxListBox* mDayOff1;
		wxDatePickerCtrl* mAlarmDate2;
		wxTimePickerCtrl* mAlarmTime2;
		wxCheckBox* mAlarmAct2;
		wxComboBox* mAlarmTmr2;
		wxTimePickerCtrl* mTimerOn2;
		wxTimePickerCtrl* mTimerOff2;
		wxComboBox* mTimerRep2;
		wxChoice* mTimerAct2;
		wxListBox* mDayOff2;
		wxDatePickerCtrl* mAlarmDate3;
		wxTimePickerCtrl* mAlarmTime3;
		wxCheckBox* mAlarmAct3;
		wxComboBox* mAlarmTmr3;
		wxTimePickerCtrl* mTimerOn3;
		wxTimePickerCtrl* mTimerOff3;
		wxComboBox* mTimerRep3;
		wxChoice* mTimerAct3;
		wxListBox* mDayOff3;
		wxDatePickerCtrl* mAlarmDate4;
		wxTimePickerCtrl* mAlarmTime4;
		wxCheckBox* mAlarmAct4;
		wxComboBox* mAlarmTmr4;
		wxTimePickerCtrl* mTimerOn4;
		wxTimePickerCtrl* mTimerOff4;
		wxComboBox* mTimerRep4;
		wxChoice* mTimerAct4;
		wxListBox* mDayOff4;
		wxDatePickerCtrl* mAlarmDate5;
		wxTimePickerCtrl* mAlarmTime5;
		wxCheckBox* mAlarmAct5;
		wxComboBox* mAlarmTmr5;
		wxTimePickerCtrl* mTimerOn5;
		wxTimePickerCtrl* mTimerOff5;
		wxComboBox* mTimerRep5;
		wxChoice* mTimerAct5;
		wxListBox* mDayOff5;
		wxDatePickerCtrl* mAlarmDate6;
		wxTimePickerCtrl* mAlarmTime6;
		wxCheckBox* mAlarmAct6;
		wxComboBox* mAlarmTmr6;
		wxTimePickerCtrl* mTimerOn6;
		wxTimePickerCtrl* mTimerOff6;
		wxComboBox* mTimerRep6;
		wxChoice* mTimerAct6;
		wxListBox* mDayOff6;
		wxDatePickerCtrl* mAlarmDate7;
		wxTimePickerCtrl* mAlarmTime7;
		wxCheckBox* mAlarmAct7;
		wxComboBox* mAlarmTmr7;
		wxTimePickerCtrl* mTimerOn7;
		wxTimePickerCtrl* mTimerOff7;
		wxComboBox* mTimerRep7;
		wxChoice* mTimerAct7;
		wxListBox* mDayOff7;
		wxButton* mSetAlarms;
		wxButton* mGetAlarms;
		wxPanel* m_panel3;
		wxCalendarCtrl* m_calendar1;
		wxTimePickerCtrl* m_timePicker25;
		wxButton* btnSetRTC;
		wxPanel* m_panel5;
		wxTextCtrl* m_textCtrl1;
		wxCheckBox* mSleep;
		wxCheckBox* mVerbosity;
		wxTimer m_timer1;
		wxTimer commandTimer;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onInitFBMain( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void onBtnSync( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void helWanted( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToogleCon( wxCommandEvent& event ) { event.Skip(); }
		virtual void rescanPorts( wxCommandEvent& event ) { event.Skip(); }
		virtual void btnSetAlarms( wxCommandEvent& event ) { event.Skip(); }
		virtual void GetAlarms( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAceptRTC( wxCommandEvent& event ) { event.Skip(); }
		virtual void checkSleep( wxCommandEvent& event ) { event.Skip(); }
		virtual void checkVerb( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHalfSec( wxTimerEvent& event ) { event.Skip(); }
		virtual void commandTimerAct( wxTimerEvent& event ) { event.Skip(); }


	public:

		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RTC 4 Relays config"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 822,566 ), long style = wxDEFAULT_DIALOG_STYLE|wxDIALOG_NO_PARENT|wxMINIMIZE_BOX );
		~GUIDialog();

};

#endif //__GUIDIALOG_H__
