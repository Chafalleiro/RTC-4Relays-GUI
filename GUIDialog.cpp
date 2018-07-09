///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#ifdef WX_GCH
#include <wx_pch.h>
#else
#include <wx/wx.h>
#endif

#include "GUIDialog.h"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Time Statuses") ), wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( sbSizer1->GetStaticBox(), wxID_ANY, _("RTC Time") ), wxHORIZONTAL );
	
	m_RTCTime = new wxStaticText( sbSizer2->GetStaticBox(), lb_RTCTime, _("hh:mm:ss  DD/MM/AAAA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_RTCTime->Wrap( -1 );
	m_RTCTime->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	sbSizer2->Add( m_RTCTime, 0, wxALIGN_CENTER, 5 );
	
	
	sbSizer1->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( sbSizer1->GetStaticBox(), wxID_ANY, _("System Time") ), wxHORIZONTAL );
	
	mSysTime = new wxStaticText( sbSizer3->GetStaticBox(), lSysTime, _("hh:mm:ss  DD/MM/AAAA"), wxDefaultPosition, wxDefaultSize, 0 );
	mSysTime->Wrap( -1 );
	mSysTime->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	sbSizer3->Add( mSysTime, 0, wxALL, 5 );
	
	mbtnSync = new wxButton( sbSizer3->GetStaticBox(), idbtnSync, _("Sync RTC to system"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( mbtnSync, 0, 0, 5 );
	
	
	sbSizer1->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	BtnAbout = new wxButton( this, idBtnAbout, _("&About"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnAbout, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxALL|wxEXPAND, 5 );
	
	BtnQuit = new wxButton( this, idBtnQuit, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnQuit, 0, wxALL, 5 );
	
	m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );
	
	mHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( mHelp, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxALIGN_CENTER, 1 );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Serial config") ), wxVERTICAL );
	
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 3, 6, 0, 0 );
	
	mSerialSelect = new wxComboBox( sbSizer4->GetStaticBox(), idSerialSelect, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	mSerialSelect->SetSelection( 0 );
	mSerialSelect->SetToolTip( _("Select a serial port to comunicate \nwith the device") );
	
	gSizer5->Add( mSerialSelect, 0, wxALIGN_CENTER, 5 );
	
	m_staticText11 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Select Serial Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	gSizer5->Add( m_staticText11, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	mPortSpeed = new wxComboBox( sbSizer4->GetStaticBox(), lbPortSpeed, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	mPortSpeed->Append( _("50") );
	mPortSpeed->Append( _("75") );
	mPortSpeed->Append( _("110") );
	mPortSpeed->Append( _("134") );
	mPortSpeed->Append( _("150") );
	mPortSpeed->Append( _("200") );
	mPortSpeed->Append( _("300") );
	mPortSpeed->Append( _("600") );
	mPortSpeed->Append( _("1200") );
	mPortSpeed->Append( _("1800") );
	mPortSpeed->Append( _("2400") );
	mPortSpeed->Append( _("4800") );
	mPortSpeed->Append( _("9600") );
	mPortSpeed->Append( _("19200") );
	mPortSpeed->Append( _("38400") );
	mPortSpeed->Append( _("57600") );
	mPortSpeed->Append( _("115200") );
	mPortSpeed->Append( _("128000") );
	mPortSpeed->Append( _("230400") );
	mPortSpeed->SetSelection( 16 );
	mPortSpeed->SetToolTip( _("Port speed, don't change this unless\nyou know you're doing") );
	
	gSizer5->Add( mPortSpeed, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText12 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Select Port Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	gSizer5->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	mDatabits = new wxComboBox( sbSizer4->GetStaticBox(), lbDatabits, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	mDatabits->Append( _("4") );
	mDatabits->Append( _("5") );
	mDatabits->Append( _("6") );
	mDatabits->Append( _("7") );
	mDatabits->Append( _("8") );
	mDatabits->SetSelection( 4 );
	mDatabits->SetToolTip( _("Data bit lenght, don't change this unless\nyou know you're doing") );
	
	gSizer5->Add( mDatabits, 0, wxALIGN_CENTER, 5 );
	
	textDatabits = new wxStaticText( sbSizer4->GetStaticBox(), lbtextDatabits, _("Data bits"), wxDefaultPosition, wxDefaultSize, 0 );
	textDatabits->Wrap( -1 );
	gSizer5->Add( textDatabits, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	mParity = new wxComboBox( sbSizer4->GetStaticBox(), lbParity, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	mParity->Append( _("Even") );
	mParity->Append( _("Odd") );
	mParity->Append( _("None") );
	mParity->Append( _("Mark") );
	mParity->Append( _("Space") );
	mParity->SetSelection( 2 );
	mParity->SetToolTip( _("Parity check don't change this unless\nyou know you're doing") );
	
	gSizer5->Add( mParity, 0, wxALIGN_CENTER, 5 );
	
	m_staticText16 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Parity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	gSizer5->Add( m_staticText16, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	mStopbits = new wxComboBox( sbSizer4->GetStaticBox(), lbStopbits, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	mStopbits->Append( _("1") );
	mStopbits->Append( _("1.5") );
	mStopbits->Append( _("2") );
	mStopbits->SetSelection( 0 );
	mStopbits->SetToolTip( _("Number of stop bits, don't change this unless\nyou know you're doing") );
	
	gSizer5->Add( mStopbits, 0, wxALIGN_CENTER, 5 );
	
	m_staticText17 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Stop bits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	gSizer5->Add( m_staticText17, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	mFlowcontrol = new wxComboBox( sbSizer4->GetStaticBox(), lbFlowcontrol, _("None"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	mFlowcontrol->Append( _("Xon/Xoff") );
	mFlowcontrol->Append( _("Hardware") );
	mFlowcontrol->Append( _("None") );
	mFlowcontrol->SetSelection( 2 );
	mFlowcontrol->SetToolTip( _("Port flow control, don't change this unless\nyou know you're doing") );
	
	gSizer5->Add( mFlowcontrol, 0, wxALIGN_CENTER, 5 );
	
	m_staticText18 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Flow Control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	gSizer5->Add( m_staticText18, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	mDTS = new wxCheckBox( sbSizer4->GetStaticBox(), wxID_ANY, _("DTS On"), wxDefaultPosition, wxDefaultSize, 0 );
	mDTS->SetToolTip( _("Leave unchecked or Arduino will reset") );
	
	gSizer5->Add( mDTS, 0, wxALIGN_CENTER, 5 );
	
	mRTS = new wxCheckBox( sbSizer4->GetStaticBox(), wxID_ANY, _("RTS On"), wxDefaultPosition, wxDefaultSize, 0 );
	mRTS->SetToolTip( _("Leave unchecked or Arduino will reset") );
	
	gSizer5->Add( mRTS, 0, wxALIGN_CENTER, 5 );
	
	
	sbSizer4->Add( gSizer5, 1, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	mConnect = new wxToggleButton( sbSizer4->GetStaticBox(), lbConnect, _("Connect!"), wxDefaultPosition, wxDefaultSize, 0 );
	mConnect->SetValue( true ); 
	mConnect->SetToolTip( _("Click here to connect.") );
	
	bSizer4->Add( mConnect, 0, wxALIGN_CENTER, 5 );
	
	
	bSizer4->Add( 50, 0, 1, wxEXPAND, 5 );
	
	mRescan = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Rescan ports"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( mRescan, 0, wxALIGN_CENTER, 5 );
	
	
	sbSizer4->Add( bSizer4, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	m_panel2->SetSizer( sbSizer4 );
	m_panel2->Layout();
	sbSizer4->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("Serial"), false );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 9, 9, 0, 0 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	gSizer1->Add( m_staticText2, 0, wxALIGN_CENTER, 5 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, _("Time"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALIGN_CENTER, 5 );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("Active"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALIGN_CENTER, 5 );
	
	m_staticText9 = new wxStaticText( m_panel1, wxID_ANY, _("Timer #"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer1->Add( m_staticText9, 0, wxALIGN_CENTER, 5 );
	
	m_staticText5 = new wxStaticText( m_panel1, wxID_ANY, _("On Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 0, wxALIGN_CENTER, 5 );
	
	m_staticText6 = new wxStaticText( m_panel1, wxID_ANY, _("Off Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer1->Add( m_staticText6, 0, wxALIGN_CENTER, 5 );
	
	m_staticText7 = new wxStaticText( m_panel1, wxID_ANY, _("Repeatable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gSizer1->Add( m_staticText7, 0, wxALIGN_CENTER, 5 );
	
	m_staticText8 = new wxStaticText( m_panel1, wxID_ANY, _("Action"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer1->Add( m_staticText8, 0, wxALIGN_CENTER, 5 );
	
	m_staticText171 = new wxStaticText( m_panel1, wxID_ANY, _("Week DayOff"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText171->Wrap( -1 );
	gSizer1->Add( m_staticText171, 0, wxALL, 5 );
	
	mAlarmDate0 = new wxDatePickerCtrl( m_panel1, idAlarmDate0, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate0") );
	mAlarmDate0->SetToolTip( _("Pick Alarm 0 Date") );
	
	gSizer1->Add( mAlarmDate0, 0, wxEXPAND, 5 );
	
	mAlarmTime0 = new wxTimePickerCtrl( m_panel1, idAlarmTime0, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime0") );
	mAlarmTime0->SetToolTip( _("Pick Alarm 0 Time") );
	
	gSizer1->Add( mAlarmTime0, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct0 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct0") );
	mAlarmAct0->SetToolTip( _("Activate Alarm 0") );
	
	gSizer1->Add( mAlarmAct0, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr0 = new wxComboBox( m_panel1, wxID_ANY, _("3"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr0") );
	mAlarmTmr0->Append( _("0") );
	mAlarmTmr0->Append( _("1") );
	mAlarmTmr0->Append( _("2") );
	mAlarmTmr0->Append( _("3") );
	mAlarmTmr0->Append( _("4") );
	mAlarmTmr0->Append( _("5") );
	mAlarmTmr0->Append( _("6") );
	mAlarmTmr0->Append( _("7") );
	mAlarmTmr0->Append( _("Sleep") );
	mAlarmTmr0->Append( _("Wake Up") );
	mAlarmTmr0->SetSelection( 3 );
	mAlarmTmr0->SetToolTip( _("Select Timer for Alarm 0") );
	
	gSizer1->Add( mAlarmTmr0, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn0 = new wxTimePickerCtrl( m_panel1, idTimerOn0, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn0") );
	mTimerOn0->SetToolTip( _("Pick ON duration for Timer 0") );
	
	gSizer1->Add( mTimerOn0, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff0 = new wxTimePickerCtrl( m_panel1, idTimerOff0, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff0") );
	mTimerOff0->SetToolTip( _("Pick OFF duration for Timer 0") );
	
	gSizer1->Add( mTimerOff0, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep0 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep0") );
	mTimerRep0->Append( _("Once") );
	mTimerRep0->Append( _("Ilimited") );
	mTimerRep0->Append( _("2") );
	mTimerRep0->Append( _("3") );
	mTimerRep0->Append( _("4") );
	mTimerRep0->Append( _("5") );
	mTimerRep0->Append( _("6") );
	mTimerRep0->Append( _("7") );
	mTimerRep0->Append( _("8") );
	mTimerRep0->Append( _("9") );
	mTimerRep0->Append( _("10") );
	mTimerRep0->Append( _("11") );
	mTimerRep0->Append( _("12") );
	mTimerRep0->Append( _("13") );
	mTimerRep0->Append( _("14") );
	mTimerRep0->Append( _("15") );
	mTimerRep0->Append( _("16") );
	mTimerRep0->Append( _("17") );
	mTimerRep0->Append( _("18") );
	mTimerRep0->Append( _("19") );
	mTimerRep0->Append( _("20") );
	mTimerRep0->Append( _("21") );
	mTimerRep0->Append( _("22") );
	mTimerRep0->Append( _("23") );
	mTimerRep0->Append( _("24") );
	mTimerRep0->SetSelection( 0 );
	mTimerRep0->SetToolTip( _("Pick number of repetitions for timer 0") );
	
	gSizer1->Add( mTimerRep0, 0, wxALL, 5 );
	
	wxString mTimerAct0Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct0NChoices = sizeof( mTimerAct0Choices ) / sizeof( wxString );
	mTimerAct0 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct0NChoices, mTimerAct0Choices, 0, wxDefaultValidator, wxT("mTimerAct0") );
	mTimerAct0->SetSelection( 4 );
	mTimerAct0->SetToolTip( _("Select which pin will activate Timer 0") );
	
	gSizer1->Add( mTimerAct0, 0, wxALIGN_CENTER, 5 );
	
	mDayOff0 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff0") );
	mDayOff0->Append( _("M") );
	mDayOff0->Append( _("T") );
	mDayOff0->Append( _("W") );
	mDayOff0->Append( _("t") );
	mDayOff0->Append( _("F") );
	mDayOff0->Append( _("S") );
	mDayOff0->Append( _("s") );
	mDayOff0->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff0, 0, wxALL, 5 );
	
	mAlarmDate1 = new wxDatePickerCtrl( m_panel1, idAlarmDate1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate1") );
	mAlarmDate1->SetToolTip( _("Pick Alarm 1 Date") );
	
	gSizer1->Add( mAlarmDate1, 0, wxEXPAND, 5 );
	
	mAlarmTime1 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime1") );
	mAlarmTime1->SetToolTip( _("Pick Alarm 1 Time") );
	
	gSizer1->Add( mAlarmTime1, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct1 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct1") );
	gSizer1->Add( mAlarmAct1, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr1 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr1") );
	mAlarmTmr1->Append( _("0") );
	mAlarmTmr1->Append( _("1") );
	mAlarmTmr1->Append( _("2") );
	mAlarmTmr1->Append( _("3") );
	mAlarmTmr1->Append( _("4") );
	mAlarmTmr1->Append( _("5") );
	mAlarmTmr1->Append( _("6") );
	mAlarmTmr1->Append( _("7") );
	mAlarmTmr1->Append( _("Sleep") );
	mAlarmTmr1->Append( _("Wake Up") );
	mAlarmTmr1->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr1, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn1 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn1") );
	gSizer1->Add( mTimerOn1, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff1 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff1") );
	gSizer1->Add( mTimerOff1, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep1 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep1") );
	mTimerRep1->Append( _("Once") );
	mTimerRep1->Append( _("Ilimited") );
	mTimerRep1->Append( _("2") );
	mTimerRep1->Append( _("3") );
	mTimerRep1->Append( _("4") );
	mTimerRep1->Append( _("5") );
	mTimerRep1->Append( _("6") );
	mTimerRep1->Append( _("7") );
	mTimerRep1->Append( _("8") );
	mTimerRep1->Append( _("9") );
	mTimerRep1->Append( _("10") );
	mTimerRep1->Append( _("11") );
	mTimerRep1->Append( _("12") );
	mTimerRep1->Append( _("13") );
	mTimerRep1->Append( _("14") );
	mTimerRep1->Append( _("15") );
	mTimerRep1->Append( _("16") );
	mTimerRep1->Append( _("17") );
	mTimerRep1->Append( _("18") );
	mTimerRep1->Append( _("19") );
	mTimerRep1->Append( _("20") );
	mTimerRep1->Append( _("21") );
	mTimerRep1->Append( _("22") );
	mTimerRep1->Append( _("23") );
	mTimerRep1->Append( _("3") );
	mTimerRep1->Append( _("24") );
	mTimerRep1->Append( wxEmptyString );
	mTimerRep1->SetSelection( 0 );
	gSizer1->Add( mTimerRep1, 0, wxALL, 5 );
	
	wxString mTimerAct1Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct1NChoices = sizeof( mTimerAct1Choices ) / sizeof( wxString );
	mTimerAct1 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct1NChoices, mTimerAct1Choices, 0, wxDefaultValidator, wxT("mTimerAct1") );
	mTimerAct1->SetSelection( 0 );
	gSizer1->Add( mTimerAct1, 0, wxALIGN_CENTER, 5 );
	
	mDayOff1 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff1") );
	mDayOff1->Append( _("M") );
	mDayOff1->Append( _("T") );
	mDayOff1->Append( _("W") );
	mDayOff1->Append( _("t") );
	mDayOff1->Append( _("F") );
	mDayOff1->Append( _("S") );
	mDayOff1->Append( _("s") );
	mDayOff1->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff1, 0, wxALL, 5 );
	
	mAlarmDate2 = new wxDatePickerCtrl( m_panel1, idAlarmDate2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate2") );
	mAlarmDate2->SetToolTip( _("Pick Alarm 2 Date") );
	
	gSizer1->Add( mAlarmDate2, 0, wxEXPAND, 5 );
	
	mAlarmTime2 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime2") );
	mAlarmTime2->SetToolTip( _("Pick Alarm 2 Time") );
	
	gSizer1->Add( mAlarmTime2, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct2 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct2") );
	gSizer1->Add( mAlarmAct2, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr2 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr2") );
	mAlarmTmr2->Append( _("0") );
	mAlarmTmr2->Append( _("1") );
	mAlarmTmr2->Append( _("2") );
	mAlarmTmr2->Append( _("3") );
	mAlarmTmr2->Append( _("4") );
	mAlarmTmr2->Append( _("5") );
	mAlarmTmr2->Append( _("6") );
	mAlarmTmr2->Append( _("7") );
	mAlarmTmr2->Append( _("Sleep") );
	mAlarmTmr2->Append( _("Wake Up") );
	mAlarmTmr2->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr2, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn2 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn2") );
	gSizer1->Add( mTimerOn2, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff2 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff2") );
	gSizer1->Add( mTimerOff2, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep2 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep2") );
	mTimerRep2->Append( _("Once") );
	mTimerRep2->Append( _("Ilimited") );
	mTimerRep2->Append( _("2") );
	mTimerRep2->Append( _("3") );
	mTimerRep2->Append( _("4") );
	mTimerRep2->Append( _("5") );
	mTimerRep2->Append( _("6") );
	mTimerRep2->Append( _("7") );
	mTimerRep2->Append( _("8") );
	mTimerRep2->Append( _("9") );
	mTimerRep2->Append( _("10") );
	mTimerRep2->Append( _("11") );
	mTimerRep2->Append( _("12") );
	mTimerRep2->Append( _("13") );
	mTimerRep2->Append( _("14") );
	mTimerRep2->Append( _("15") );
	mTimerRep2->Append( _("16") );
	mTimerRep2->Append( _("17") );
	mTimerRep2->Append( _("18") );
	mTimerRep2->Append( _("19") );
	mTimerRep2->Append( _("20") );
	mTimerRep2->Append( _("21") );
	mTimerRep2->Append( _("22") );
	mTimerRep2->Append( _("23") );
	mTimerRep2->Append( _("3") );
	mTimerRep2->Append( _("24") );
	mTimerRep2->Append( wxEmptyString );
	mTimerRep2->SetSelection( 0 );
	gSizer1->Add( mTimerRep2, 0, wxALL, 5 );
	
	wxString mTimerAct2Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct2NChoices = sizeof( mTimerAct2Choices ) / sizeof( wxString );
	mTimerAct2 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct2NChoices, mTimerAct2Choices, 0, wxDefaultValidator, wxT("mTimerAct2") );
	mTimerAct2->SetSelection( 0 );
	gSizer1->Add( mTimerAct2, 0, wxALIGN_CENTER, 5 );
	
	mDayOff2 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff2") );
	mDayOff2->Append( _("M") );
	mDayOff2->Append( _("T") );
	mDayOff2->Append( _("W") );
	mDayOff2->Append( _("t") );
	mDayOff2->Append( _("F") );
	mDayOff2->Append( _("S") );
	mDayOff2->Append( _("s") );
	mDayOff2->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff2, 0, wxALL, 5 );
	
	mAlarmDate3 = new wxDatePickerCtrl( m_panel1, idAlarmDate3, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate3") );
	mAlarmDate3->SetToolTip( _("Pick Alarm 3 Date") );
	
	gSizer1->Add( mAlarmDate3, 0, wxEXPAND, 5 );
	
	mAlarmTime3 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime3") );
	mAlarmTime3->SetToolTip( _("Pick Alarm 3 Time") );
	
	gSizer1->Add( mAlarmTime3, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct3 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct3") );
	gSizer1->Add( mAlarmAct3, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr3 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr3") );
	mAlarmTmr3->Append( _("0") );
	mAlarmTmr3->Append( _("1") );
	mAlarmTmr3->Append( _("2") );
	mAlarmTmr3->Append( _("3") );
	mAlarmTmr3->Append( _("4") );
	mAlarmTmr3->Append( _("5") );
	mAlarmTmr3->Append( _("6") );
	mAlarmTmr3->Append( _("7") );
	mAlarmTmr3->Append( _("Sleep") );
	mAlarmTmr3->Append( _("Wake Up") );
	mAlarmTmr3->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr3, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn3 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn3") );
	gSizer1->Add( mTimerOn3, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff3 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff3") );
	gSizer1->Add( mTimerOff3, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep3 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep3") );
	mTimerRep3->Append( _("Once") );
	mTimerRep3->Append( _("Ilimited") );
	mTimerRep3->Append( _("2") );
	mTimerRep3->Append( _("3") );
	mTimerRep3->Append( _("4") );
	mTimerRep3->Append( _("5") );
	mTimerRep3->Append( _("6") );
	mTimerRep3->Append( _("7") );
	mTimerRep3->Append( _("8") );
	mTimerRep3->Append( _("9") );
	mTimerRep3->Append( _("10") );
	mTimerRep3->Append( _("11") );
	mTimerRep3->Append( _("12") );
	mTimerRep3->Append( _("13") );
	mTimerRep3->Append( _("14") );
	mTimerRep3->Append( _("15") );
	mTimerRep3->Append( _("16") );
	mTimerRep3->Append( _("17") );
	mTimerRep3->Append( _("18") );
	mTimerRep3->Append( _("19") );
	mTimerRep3->Append( _("20") );
	mTimerRep3->Append( _("21") );
	mTimerRep3->Append( _("22") );
	mTimerRep3->Append( _("23") );
	mTimerRep3->Append( _("3") );
	mTimerRep3->Append( _("24") );
	mTimerRep3->Append( wxEmptyString );
	mTimerRep3->SetSelection( 0 );
	gSizer1->Add( mTimerRep3, 0, wxALL, 5 );
	
	wxString mTimerAct3Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct3NChoices = sizeof( mTimerAct3Choices ) / sizeof( wxString );
	mTimerAct3 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct3NChoices, mTimerAct3Choices, 0, wxDefaultValidator, wxT("mTimerAct3") );
	mTimerAct3->SetSelection( 0 );
	gSizer1->Add( mTimerAct3, 0, wxALIGN_CENTER, 5 );
	
	mDayOff3 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff3") );
	mDayOff3->Append( _("M") );
	mDayOff3->Append( _("T") );
	mDayOff3->Append( _("W") );
	mDayOff3->Append( _("t") );
	mDayOff3->Append( _("F") );
	mDayOff3->Append( _("S") );
	mDayOff3->Append( _("s") );
	mDayOff3->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff3, 0, wxALL, 5 );
	
	mAlarmDate4 = new wxDatePickerCtrl( m_panel1, idAlarmDate4, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate4") );
	mAlarmDate4->SetToolTip( _("Pick Alarm 4 Date") );
	
	gSizer1->Add( mAlarmDate4, 0, wxEXPAND, 5 );
	
	mAlarmTime4 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime4") );
	gSizer1->Add( mAlarmTime4, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct4 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct4") );
	gSizer1->Add( mAlarmAct4, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr4 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr4") );
	mAlarmTmr4->Append( _("0") );
	mAlarmTmr4->Append( _("1") );
	mAlarmTmr4->Append( _("2") );
	mAlarmTmr4->Append( _("3") );
	mAlarmTmr4->Append( _("4") );
	mAlarmTmr4->Append( _("5") );
	mAlarmTmr4->Append( _("6") );
	mAlarmTmr4->Append( _("7") );
	mAlarmTmr4->Append( _("Sleep") );
	mAlarmTmr4->Append( _("Wake Up") );
	mAlarmTmr4->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr4, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn4 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn4") );
	gSizer1->Add( mTimerOn4, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff4 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff4") );
	gSizer1->Add( mTimerOff4, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep4 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep4") );
	mTimerRep4->Append( _("Once") );
	mTimerRep4->Append( _("Ilimited") );
	mTimerRep4->Append( _("2") );
	mTimerRep4->Append( _("3") );
	mTimerRep4->Append( _("4") );
	mTimerRep4->Append( _("5") );
	mTimerRep4->Append( _("6") );
	mTimerRep4->Append( _("7") );
	mTimerRep4->Append( _("8") );
	mTimerRep4->Append( _("9") );
	mTimerRep4->Append( _("10") );
	mTimerRep4->Append( _("11") );
	mTimerRep4->Append( _("12") );
	mTimerRep4->Append( _("13") );
	mTimerRep4->Append( _("14") );
	mTimerRep4->Append( _("15") );
	mTimerRep4->Append( _("16") );
	mTimerRep4->Append( _("17") );
	mTimerRep4->Append( _("18") );
	mTimerRep4->Append( _("19") );
	mTimerRep4->Append( _("20") );
	mTimerRep4->Append( _("21") );
	mTimerRep4->Append( _("22") );
	mTimerRep4->Append( _("23") );
	mTimerRep4->Append( _("3") );
	mTimerRep4->Append( _("24") );
	mTimerRep4->Append( wxEmptyString );
	mTimerRep4->SetSelection( 0 );
	gSizer1->Add( mTimerRep4, 0, wxALL, 5 );
	
	wxString mTimerAct4Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct4NChoices = sizeof( mTimerAct4Choices ) / sizeof( wxString );
	mTimerAct4 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct4NChoices, mTimerAct4Choices, 0, wxDefaultValidator, wxT("mTimerAct4") );
	mTimerAct4->SetSelection( 0 );
	gSizer1->Add( mTimerAct4, 0, wxALIGN_CENTER, 5 );
	
	mDayOff4 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff4") );
	mDayOff4->Append( _("M") );
	mDayOff4->Append( _("T") );
	mDayOff4->Append( _("W") );
	mDayOff4->Append( _("t") );
	mDayOff4->Append( _("F") );
	mDayOff4->Append( _("S") );
	mDayOff4->Append( _("s") );
	mDayOff4->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff4, 0, wxALL, 5 );
	
	mAlarmDate5 = new wxDatePickerCtrl( m_panel1, idAlarmDate5, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate5") );
	mAlarmDate5->SetToolTip( _("Pick Alarm 5 Date") );
	
	gSizer1->Add( mAlarmDate5, 0, wxEXPAND, 5 );
	
	mAlarmTime5 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime5") );
	gSizer1->Add( mAlarmTime5, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct5 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct5") );
	gSizer1->Add( mAlarmAct5, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr5 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr5") );
	mAlarmTmr5->Append( _("0") );
	mAlarmTmr5->Append( _("1") );
	mAlarmTmr5->Append( _("2") );
	mAlarmTmr5->Append( _("3") );
	mAlarmTmr5->Append( _("4") );
	mAlarmTmr5->Append( _("5") );
	mAlarmTmr5->Append( _("6") );
	mAlarmTmr5->Append( _("7") );
	mAlarmTmr5->Append( _("Sleep") );
	mAlarmTmr5->Append( _("Wake Up") );
	mAlarmTmr5->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr5, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn5 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn5") );
	gSizer1->Add( mTimerOn5, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff5 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff5") );
	gSizer1->Add( mTimerOff5, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep5 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep5") );
	mTimerRep5->Append( _("Once") );
	mTimerRep5->Append( _("Ilimited") );
	mTimerRep5->Append( _("2") );
	mTimerRep5->Append( _("3") );
	mTimerRep5->Append( _("4") );
	mTimerRep5->Append( _("5") );
	mTimerRep5->Append( _("6") );
	mTimerRep5->Append( _("7") );
	mTimerRep5->Append( _("8") );
	mTimerRep5->Append( _("9") );
	mTimerRep5->Append( _("10") );
	mTimerRep5->Append( _("11") );
	mTimerRep5->Append( _("12") );
	mTimerRep5->Append( _("13") );
	mTimerRep5->Append( _("14") );
	mTimerRep5->Append( _("15") );
	mTimerRep5->Append( _("16") );
	mTimerRep5->Append( _("17") );
	mTimerRep5->Append( _("18") );
	mTimerRep5->Append( _("19") );
	mTimerRep5->Append( _("20") );
	mTimerRep5->Append( _("21") );
	mTimerRep5->Append( _("22") );
	mTimerRep5->Append( _("23") );
	mTimerRep5->Append( _("3") );
	mTimerRep5->Append( _("24") );
	mTimerRep5->Append( wxEmptyString );
	mTimerRep5->SetSelection( 0 );
	gSizer1->Add( mTimerRep5, 0, wxALL, 5 );
	
	wxString mTimerAct5Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct5NChoices = sizeof( mTimerAct5Choices ) / sizeof( wxString );
	mTimerAct5 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct5NChoices, mTimerAct5Choices, 0, wxDefaultValidator, wxT("mTimerAct5") );
	mTimerAct5->SetSelection( 0 );
	gSizer1->Add( mTimerAct5, 0, wxALIGN_CENTER, 5 );
	
	mDayOff5 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff5") );
	mDayOff5->Append( _("M") );
	mDayOff5->Append( _("T") );
	mDayOff5->Append( _("W") );
	mDayOff5->Append( _("t") );
	mDayOff5->Append( _("F") );
	mDayOff5->Append( _("S") );
	mDayOff5->Append( _("s") );
	mDayOff5->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff5, 0, wxALL, 5 );
	
	mAlarmDate6 = new wxDatePickerCtrl( m_panel1, idAlarmDate6, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate6") );
	mAlarmDate6->SetToolTip( _("Pick Alarm 6 Date") );
	
	gSizer1->Add( mAlarmDate6, 0, wxEXPAND, 5 );
	
	mAlarmTime6 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime6") );
	gSizer1->Add( mAlarmTime6, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct6 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct6") );
	gSizer1->Add( mAlarmAct6, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr6 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr6") );
	mAlarmTmr6->Append( _("0") );
	mAlarmTmr6->Append( _("1") );
	mAlarmTmr6->Append( _("2") );
	mAlarmTmr6->Append( _("3") );
	mAlarmTmr6->Append( _("4") );
	mAlarmTmr6->Append( _("5") );
	mAlarmTmr6->Append( _("6") );
	mAlarmTmr6->Append( _("7") );
	mAlarmTmr6->Append( _("Sleep") );
	mAlarmTmr6->Append( _("Wake Up") );
	mAlarmTmr6->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr6, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn6 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn6") );
	gSizer1->Add( mTimerOn6, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff6 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff6") );
	gSizer1->Add( mTimerOff6, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep6 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep6") );
	mTimerRep6->Append( _("Once") );
	mTimerRep6->Append( _("Ilimited") );
	mTimerRep6->Append( _("2") );
	mTimerRep6->Append( _("3") );
	mTimerRep6->Append( _("4") );
	mTimerRep6->Append( _("5") );
	mTimerRep6->Append( _("6") );
	mTimerRep6->Append( _("7") );
	mTimerRep6->Append( _("8") );
	mTimerRep6->Append( _("9") );
	mTimerRep6->Append( _("10") );
	mTimerRep6->Append( _("11") );
	mTimerRep6->Append( _("12") );
	mTimerRep6->Append( _("13") );
	mTimerRep6->Append( _("14") );
	mTimerRep6->Append( _("15") );
	mTimerRep6->Append( _("16") );
	mTimerRep6->Append( _("17") );
	mTimerRep6->Append( _("18") );
	mTimerRep6->Append( _("19") );
	mTimerRep6->Append( _("20") );
	mTimerRep6->Append( _("21") );
	mTimerRep6->Append( _("22") );
	mTimerRep6->Append( _("23") );
	mTimerRep6->Append( _("3") );
	mTimerRep6->Append( _("24") );
	mTimerRep6->Append( wxEmptyString );
	mTimerRep6->SetSelection( 0 );
	gSizer1->Add( mTimerRep6, 0, wxALL, 5 );
	
	wxString mTimerAct6Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct6NChoices = sizeof( mTimerAct6Choices ) / sizeof( wxString );
	mTimerAct6 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct6NChoices, mTimerAct6Choices, 0, wxDefaultValidator, wxT("mTimerAct6") );
	mTimerAct6->SetSelection( 0 );
	gSizer1->Add( mTimerAct6, 0, wxALIGN_CENTER, 5 );
	
	mDayOff6 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff6") );
	mDayOff6->Append( _("M") );
	mDayOff6->Append( _("T") );
	mDayOff6->Append( _("W") );
	mDayOff6->Append( _("t") );
	mDayOff6->Append( _("F") );
	mDayOff6->Append( _("S") );
	mDayOff6->Append( _("s") );
	mDayOff6->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff6, 0, wxALL, 5 );
	
	mAlarmDate7 = new wxDatePickerCtrl( m_panel1, idAlarmDate7, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN, wxDefaultValidator, wxT("mAlarmDate7") );
	mAlarmDate7->SetToolTip( _("Pick Alarm 7 Date") );
	
	gSizer1->Add( mAlarmDate7, 0, wxEXPAND, 5 );
	
	mAlarmTime7 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mAlarmTime7") );
	gSizer1->Add( mAlarmTime7, 0, wxALIGN_CENTER, 5 );
	
	mAlarmAct7 = new wxCheckBox( m_panel1, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("mAlarmAct7") );
	gSizer1->Add( mAlarmAct7, 0, wxALIGN_CENTER, 5 );
	
	mAlarmTmr7 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mAlarmTmr7") );
	mAlarmTmr7->Append( _("0") );
	mAlarmTmr7->Append( _("1") );
	mAlarmTmr7->Append( _("2") );
	mAlarmTmr7->Append( _("3") );
	mAlarmTmr7->Append( _("4") );
	mAlarmTmr7->Append( _("5") );
	mAlarmTmr7->Append( _("6") );
	mAlarmTmr7->Append( _("7") );
	mAlarmTmr7->Append( _("Sleep") );
	mAlarmTmr7->Append( _("Wake Up") );
	mAlarmTmr7->SetSelection( 0 );
	gSizer1->Add( mAlarmTmr7, 0, wxALIGN_CENTER, 5 );
	
	mTimerOn7 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOn7") );
	gSizer1->Add( mTimerOn7, 0, wxALIGN_CENTER, 5 );
	
	mTimerOff7 = new wxTimePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT, wxDefaultValidator, wxT("mTimerOff7") );
	gSizer1->Add( mTimerOff7, 0, wxALIGN_CENTER, 5 );
	
	mTimerRep7 = new wxComboBox( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0, wxDefaultValidator, wxT("mTimerRep7") );
	mTimerRep7->Append( _("Once") );
	mTimerRep7->Append( _("Ilimited") );
	mTimerRep7->Append( _("2") );
	mTimerRep7->Append( _("3") );
	mTimerRep7->Append( _("4") );
	mTimerRep7->Append( _("5") );
	mTimerRep7->Append( _("6") );
	mTimerRep7->Append( _("7") );
	mTimerRep7->Append( _("8") );
	mTimerRep7->Append( _("9") );
	mTimerRep7->Append( _("10") );
	mTimerRep7->Append( _("11") );
	mTimerRep7->Append( _("12") );
	mTimerRep7->Append( _("13") );
	mTimerRep7->Append( _("14") );
	mTimerRep7->Append( _("15") );
	mTimerRep7->Append( _("16") );
	mTimerRep7->Append( _("17") );
	mTimerRep7->Append( _("18") );
	mTimerRep7->Append( _("19") );
	mTimerRep7->Append( _("20") );
	mTimerRep7->Append( _("21") );
	mTimerRep7->Append( _("22") );
	mTimerRep7->Append( _("23") );
	mTimerRep7->Append( _("3") );
	mTimerRep7->Append( _("24") );
	mTimerRep7->Append( wxEmptyString );
	mTimerRep7->SetSelection( 0 );
	gSizer1->Add( mTimerRep7, 0, wxALL, 5 );
	
	wxString mTimerAct7Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7") };
	int mTimerAct7NChoices = sizeof( mTimerAct7Choices ) / sizeof( wxString );
	mTimerAct7 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mTimerAct7NChoices, mTimerAct7Choices, 0, wxDefaultValidator, wxT("mTimerAct7") );
	mTimerAct7->SetSelection( 0 );
	gSizer1->Add( mTimerAct7, 0, wxALIGN_CENTER, 5 );
	
	mDayOff7 = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_MULTIPLE, wxDefaultValidator, wxT("mDayOff7") );
	mDayOff7->Append( _("M") );
	mDayOff7->Append( _("T") );
	mDayOff7->Append( _("W") );
	mDayOff7->Append( _("t") );
	mDayOff7->Append( _("F") );
	mDayOff7->Append( _("S") );
	mDayOff7->Append( _("s") );
	mDayOff7->SetToolTip( _("Select days that the alarm will not be launched") );
	
	gSizer1->Add( mDayOff7, 0, wxALL, 5 );
	
	
	bSizer3->Add( gSizer1, 1, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	mSetAlarms = new wxButton( m_panel1, lbSetAlarms, _("Set Alarms"), wxDefaultPosition, wxDefaultSize, 0 );
	mSetAlarms->SetToolTip( _("Set Alarms on the clock") );
	
	bSizer7->Add( mSetAlarms, 0, wxALIGN_CENTER, 10 );
	
	
	bSizer7->Add( 50, 0, 1, wxEXPAND, 5 );
	
	mGetAlarms = new wxButton( m_panel1, wxID_ANY, _("Get Alarms"), wxDefaultPosition, wxDefaultSize, 0 );
	mGetAlarms->SetToolTip( _("Refresh the alarms from the clock") );
	
	bSizer7->Add( mGetAlarms, 0, wxALIGN_CENTER, 5 );
	
	
	bSizer3->Add( bSizer7, 1, wxALIGN_CENTER, 5 );
	
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("Alarms"), false );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_calendar1 = new wxCalendarCtrl( m_panel3, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SHOW_HOLIDAYS );
	gSizer9->Add( m_calendar1, 0, wxALIGN_CENTER, 5 );
	
	m_timePicker25 = new wxTimePickerCtrl( m_panel3, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT );
	gSizer9->Add( m_timePicker25, 0, wxALIGN_CENTER, 5 );
	
	
	bSizer9->Add( gSizer9, 1, wxALIGN_CENTER|wxFIXED_MINSIZE, 5 );
	
	btnSetRTC = new wxButton( m_panel3, idbtnSetRTC, _("Set RTC"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( btnSetRTC, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel3->SetSizer( bSizer9 );
	m_panel3->Layout();
	bSizer9->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("Set RTC"), false );
	m_panel5 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl1 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	m_textCtrl1->SetFont( wxFont( 11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("IBM Plex Mono") ) );
	m_textCtrl1->SetForegroundColour( wxColour( 128, 255, 0 ) );
	m_textCtrl1->SetBackgroundColour( wxColour( 48, 48, 48 ) );
	m_textCtrl1->SetMinSize( wxSize( 760,365 ) );
	
	bSizer6->Add( m_textCtrl1, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	mSleep = new wxCheckBox( m_panel5, wxID_ANY, _("Sleep"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( mSleep, 0, wxALL, 5 );
	
	
	bSizer8->Add( 25, 0, 1, wxEXPAND, 5 );
	
	mVerbosity = new wxCheckBox( m_panel5, wxID_ANY, _("Verbosity"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( mVerbosity, 0, wxALL, 5 );
	
	
	bSizer6->Add( bSizer8, 1, wxALIGN_CENTER, 5 );
	
	
	m_panel5->SetSizer( bSizer6 );
	m_panel5->Layout();
	bSizer6->Fit( m_panel5 );
	m_notebook1->AddPage( m_panel5, _("Console"), true );
	
	bSizer1->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_timer1.SetOwner( this, wxID_ANY );
	m_timer1.Start( 500 );
	
	commandTimer.SetOwner( this, idcommandTimer );
	commandTimer.Start( 100 );
	
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( GUIDialog::onInitFBMain ) );
	mbtnSync->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::onBtnSync ), NULL, this );
	BtnAbout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
	mHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::helWanted ), NULL, this );
	mConnect->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnToogleCon ), NULL, this );
	mRescan->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::rescanPorts ), NULL, this );
	mSetAlarms->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::btnSetAlarms ), NULL, this );
	mGetAlarms->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::GetAlarms ), NULL, this );
	btnSetRTC->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::onAceptRTC ), NULL, this );
	mSleep->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::checkSleep ), NULL, this );
	mVerbosity->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::checkVerb ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::onHalfSec ) );
	this->Connect( idcommandTimer, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::commandTimerAct ) );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( GUIDialog::onInitFBMain ) );
	mbtnSync->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::onBtnSync ), NULL, this );
	BtnAbout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
	mHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::helWanted ), NULL, this );
	mConnect->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnToogleCon ), NULL, this );
	mRescan->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::rescanPorts ), NULL, this );
	mSetAlarms->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::btnSetAlarms ), NULL, this );
	mGetAlarms->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::GetAlarms ), NULL, this );
	btnSetRTC->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::onAceptRTC ), NULL, this );
	mSleep->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::checkSleep ), NULL, this );
	mVerbosity->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::checkVerb ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::onHalfSec ) );
	this->Disconnect( idcommandTimer, wxEVT_TIMER, wxTimerEventHandler( GUIDialog::commandTimerAct ) );
	
}
