/***************************************************************
 * Name:      RTC4RlaysFBMain.cpp
 * Purpose:   Code for Application Frame
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

#include "RTC4RlaysFBMain.h"
#include <stdlib.h>
#include <stdio.h>
#include <imported_functions.c>

#ifdef _WIN32
#include <Windows.h>
#else

#include <unistd.h>
#endif
#include "rs232.h"
#include <time.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

#include <wx/cshelp.h>


std::ostringstream oss;
int actPort=-1;
wxDateTime AL1 = wxDateTime::Now();

struct _myAlarms {
	wxDateTime almTime;
	wxDateTime almDate;
	int almAct, almTim, almRan;
	wxDateTime timOnTime;
	int timOnAct, timOnRel, timOnRep;
	wxDateTime timOffTime;
	int timOffAct, timOffRel, timOffRep;
	int weekOff;
} myAlarms[8];

//******************************************************************
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
//******************************************************************
RTC4RlaysFBDialog::RTC4RlaysFBDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

RTC4RlaysFBDialog::~RTC4RlaysFBDialog()
{
}
/** \brief const char* GetArduinoDates(char* RTCtime) Formats given csv string into a date string
 *
 * \param char* RTCtime Y;m;d;h;m;s
 * \return (const char*)RTCtime; "h:m:s d/m/y"
 */

const char* GetArduinoDates(char* RTCtime)
{
	char* command = strtok(RTCtime," ");
	const char* result[80];
	int k = 0, argument[10];
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%H:%M:%S %d/%m/%Y",timeinfo);

	while (command != NULL)
		{
		command = strtok (NULL, ";");
		argument[k] = atoi(command);
		k++;
		}
	timeinfo->tm_hour = argument[3]; timeinfo->tm_min = argument[4]; timeinfo->tm_sec = argument[5];
	timeinfo->tm_mday = argument[2]; timeinfo->tm_mon = argument[1] - 1; timeinfo->tm_year = argument[0] - 1900;
	strftime (RTCtime,80,"%H:%M:%S %d/%m/%Y",timeinfo);
return (const char*)RTCtime;
}

/** \brief const char* GetArduinoAlarms(char* RTCtime) Formats given csv string into a date object
 *
 * \param char* RTCtime Y;m;d;h;m;s
 * \return (const char*)RTCtime; "h:m:s d/m/y"
 */

int GetArduinoAlarms(char* RTCalarm)
{

wxDateTime RTCDate;
char* command = strtok(RTCalarm," "); //Divide chain in two.
char buff[100];
int i=0,j=0,k=0;
int data[9];
char key[] = "0123456789";
char * pch;

struct _buffs {
	char myBuff[100];
} buffs[8];

	while (command != NULL && i < 8)
		{
		command = strtok (NULL, "-");
		sprintf(buffs[i].myBuff,"%s", command);
/*		#ifdef DEBUG
		printf("buffs[%d].myBuff %s command %s\n", i, buffs[i].myBuff, command);
		#endif // DEBUG*/
		if ((i % 2 == 0) && (i > 0))
			{
/*			#ifdef DEBUG
			printf("odd\n");
			#endif // DEBUG*/
			pch = strpbrk (buffs[i].myBuff, key);
  			while (pch != NULL)
  				{
				data[j] = atoi(pch);
/*				#ifdef DEBUG
    			printf ("data[%d] %d \n" , j, data[j]);
				#endif // DEBUG*/
				if (data[j] == 8 || data[j] == 9)
					{pch = strpbrk (pch+1,key);}
				else
					{pch = strpbrk (pch+1,key);j++;}
  				}
			}
		i++;
		}

myAlarms[atoi(buffs[0].myBuff)].almTime.ParseFormat(buffs[1].myBuff, "%Y;%m;%d;%H;%M;%S");
myAlarms[atoi(buffs[0].myBuff)].almDate.ParseFormat(buffs[1].myBuff, "%Y;%m;%d;%H;%M;%S");
myAlarms[atoi(buffs[0].myBuff)].timOnTime.ParseFormat(buffs[3].myBuff, "%Y;%m;%d;%H;%M;%S");
myAlarms[atoi(buffs[0].myBuff)].timOffTime.ParseFormat(buffs[5].myBuff, "%Y;%m;%d;%H;%M;%S");
myAlarms[atoi(buffs[0].myBuff)].almAct = data[0];myAlarms[atoi(buffs[0].myBuff)].almTim = data[1];myAlarms[atoi(buffs[0].myBuff)].almRan = data[2];
myAlarms[atoi(buffs[0].myBuff)].timOnAct = data[3];myAlarms[atoi(buffs[0].myBuff)].timOnRel = data[4];myAlarms[atoi(buffs[0].myBuff)].timOnRep = data[5];
myAlarms[atoi(buffs[0].myBuff)].timOffAct = data[6];myAlarms[atoi(buffs[0].myBuff)].timOffRel = data[7];myAlarms[atoi(buffs[0].myBuff)].timOffRep = data[8];
myAlarms[atoi(buffs[0].myBuff)].weekOff = atoi(buffs[7].myBuff);
return atoi(buffs[0].myBuff);
}

int strcmpc(char* stringToTest, char* stringToCompare)
{
int result = strlen(stringToCompare);
/*#ifdef  DEBUG
printf("result = %d test = \"%s\" compare = \"%s\"\n",result,stringToTest,stringToCompare);
#endif // DEBUG*/
	for(int i=0;i<strlen(stringToCompare);i++)
	{
		if (stringToTest[i] == stringToCompare[i])
		{
/*			#ifdef  DEBUG
			printf("true = %d\n",result);
			#endif // DEBUG*/
			result--;
		}
/*		#ifdef  DEBUG
		else
		{

			printf("false = %d\n",result);
		}
		#endif // DEBUG*/
	}
/*#ifdef  DEBUG
printf("returning = %d\n",result);
#endif // DEBUG*/
return result;
}


/******************************************************************
******************** MAIN DIALOG **********************************
******************************************************************/
void RTC4RlaysFBDialog::OnClose(wxCloseEvent &event)
{
	comWrite(mSerialSelect->GetSelection(), "GUIMODE 0\n",9);
    comCloseAll();
    Destroy();
}

void RTC4RlaysFBDialog::OnQuit(wxCommandEvent &event)
{
	comWrite(mSerialSelect->GetSelection(), "GUIMODE 0\n",9);
    comCloseAll();
    Destroy();
}

void RTC4RlaysFBDialog::OnAbout(wxCommandEvent &event)
{
	wxString msg = "      RTC 4 Relays configurator\n                    ****** \n\©2018 Alfonso Abelenda Escudero";
    wxMessageBox(msg, _(""));
}
void RTC4RlaysFBDialog::commandTimerAct( wxTimerEvent& event )
{

}
    /**
     * \fn void RTC4RlaysFBDialog::onHalfSec( wxTimerEvent& event )
     * \brief Read COM bytes, print system and RTC time every 500ms.
     */
void RTC4RlaysFBDialog::onHalfSec( wxTimerEvent& event )
{
    time_t rawtime;
    struct tm * timeinfo;
	char buffer[100],buff[100];
    char pbuffer[4096],cbuffer[4096];
	int i = 0, j = 0, k = 0;
	int argument[10];
	int arrDoof[]={6,0,1,2,3,4,5};

	char nameCtrl[16],ctrlBuffer[16];
	wxWindow* ctrl;
	wxComboBox* ctrlCombo;
	wxDatePickerCtrl* ctrlDate;
	wxCheckBox* ctrlCheck;
	wxChoice* ctrlChoice;
	wxListBox* ctrlLBox;
	wxArrayInt index;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%H:%M:%S %d/%m/%Y",timeinfo);
    mSysTime->SetLabel(buffer);
	int rByte = comRead(actPort, pbuffer, 4096);
    if(rByte > 0)
		{
		i=0; j=0;
		while (i<=strlen(pbuffer))
			{
			if(pbuffer[i] == '\n')
				{
				cbuffer[j] = pbuffer[i];
				cbuffer[j+1] = NULL;		//Now the string ends here
				int rc = strcmpc(cbuffer, "GUIRTC"); //Check for RTC time
				if (rc != 0)
					{
					rc = strcmpc(cbuffer, "GUIALM"); //Check for alarms data
					if (rc != 0)
						{
						m_textCtrl1->AppendText(cbuffer); //We put the line just read
						}
					else
						{
						int whichRow = GetArduinoAlarms(cbuffer); //Check for alarms data

						if (myAlarms[whichRow].almTim == 88)
							{
							myAlarms[whichRow].almTim = 8;
							}
						else
							{
							if (myAlarms[whichRow].almTim == 99)
								{
								myAlarms[whichRow].almTim = 9;
								}
							}

						sprintf(nameCtrl, "mAlarmDate%d", whichRow);
						ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
						ctrlDate->SetValue(myAlarms[whichRow].almTime);

						sprintf(nameCtrl, "mAlarmTime%d", whichRow);
						ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
						ctrlDate->SetValue(myAlarms[whichRow].almTime);

						sprintf(nameCtrl, "mAlarmAct%d", whichRow);
						ctrlCheck = (wxCheckBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
						ctrlCheck->SetValue(myAlarms[whichRow].almAct);

						sprintf(nameCtrl, "mAlarmTmr%d", whichRow);
						ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
						ctrlCombo->Select(myAlarms[whichRow].almTim);


						if (myAlarms[whichRow].almTim < 8)
							{
							#ifdef DEBUG
							printf("< 8 almTim=%d Repeats=%d\n",myAlarms[whichRow].almTim,myAlarms[whichRow].timOnRep);
							#endif // DEBUG
							sprintf(nameCtrl, "mTimerOn%d", whichRow);
							ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlDate->SetValue(myAlarms[whichRow].timOnTime);

							sprintf(nameCtrl, "mTimerOff%d", whichRow);
							ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlDate->SetValue(myAlarms[whichRow].timOffTime);

							sprintf(nameCtrl, "mTimerRep%d", whichRow);
							ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlCombo->Select(myAlarms[whichRow].timOnRep);

							sprintf(nameCtrl, "mTimerAct%d", whichRow);
							ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlCombo->Select(myAlarms[whichRow].timOnRel);
							}

						else
							{
							myAlarms[whichRow].timOnTime = 0;

							sprintf(nameCtrl, "mTimerOn%d", whichRow);
							ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlDate->SetValue(myAlarms[whichRow].timOnTime);

							sprintf(nameCtrl, "mTimerOff%d", whichRow);
							ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlDate->SetValue(myAlarms[whichRow].timOnTime);

							sprintf(nameCtrl, "mTimerRep%d", whichRow);
							ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlCombo->Select(0);

							sprintf(nameCtrl, "mTimerAct%d", whichRow);
							ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
							ctrlCombo->Select(0);
							}

						sprintf(nameCtrl, "mDayOff%d", whichRow);
						ctrlLBox = (wxListBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
						ctrlLBox->DeselectAll();
						k = 0;
						for (byte mask = 128; mask; mask >>= 1)
							{
							if(mask&myAlarms[whichRow].weekOff)
								{
								ctrlLBox->Select(arrDoof[k]);
								}
							k++;
							}
						}
					}
				else
					{
    				m_RTCTime->SetLabel(GetArduinoDates(cbuffer));  //Check for RTC time
					}
				i++;
				j=0;
				}
			else
				{
				cbuffer[j] = pbuffer[i];
				i++; j++;
				}
			}
		}
}
void RTC4RlaysFBDialog::helWanted( wxCommandEvent& event )
{
#ifdef _WIN32
wxCHMHelpController* chmHelp = new wxCHMHelpController;
chmHelp->Initialize("doxygen/help/RTC4RelaysGUI.chm");
chmHelp->LoadFile("doxygen/help/RTC4RelaysGUI.chm");
chmHelp->DisplayContents();
#endif // _WIN32
}

void RTC4RlaysFBDialog::onInitFBMain(wxInitDialogEvent& event)
{
    int enumP = comEnumerate();
    char *buf = "";
	char *buff = "";
/*	#ifdef DEBUG
    printf("Got %d ports ...\n",enumP);
    #endif // DEBUG*/
    for (int i = 0; i < enumP; i++)
		{
		const char *portIName = comGetInternalName(i);
    	const char *portFName = comGetPortName(i);
/*		#ifdef DEBUG
    	printf("port %d name is %s . ",i,portIName);
    	printf("port %d friendly name is %s ...\n",i,portFName);
    	#endif // DEBUG*/
    	if (comState(i).BaudRate == 666)
    		{
			sprintf (buff,"\nError %d reading port %d, already opened by another app...\n",comState(i).BaudRate,i);
			m_textCtrl1->AppendText(buff);
			}
    	if (comState(i).BaudRate == 999)
    		{
			sprintf (buff,"\nError %d reading port %d is not an available port...\n",comState(i).BaudRate,i);
			m_textCtrl1->AppendText(buff);
			}
		mDCB mainDCB = comState(i);
/*		#ifdef DEBUG
    	printf(("\nBaudRate = %d, ByteSize = %d, Parity = %d, StopBits = %d\n fBinary = %d, fParity = %d, fErrorChar = %d\nfNull = %d, fAbortOnError = %d, EvtChar = %c\n"),
				comState(i).BaudRate,
				comState(i).ByteSize,
				comState(i).Parity,
				comState(i).StopBits,
				comState(i).fBinary,
				mainDCB.fParity,
				mainDCB.fErrorChar,
				mainDCB.fNull,
				mainDCB.fAbortOnError,
				mainDCB.EvtChar
              );
		#endif // DEBUG*/
    	mSerialSelect->Append(portFName);
		}
	mSerialSelect->Select(0);
    mConnect->SetValue(1);
}
/******************************************************************
******************** COM settings *********************************
******************************************************************/

void RTC4RlaysFBDialog::OnToogleCon( wxCommandEvent& event )
{
int speedPort[]={50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 128000, 230400};
int dataBits[]={4,5,6,7,8};
int pParity[]={2,3,0,1,4};

int mfOutX = 0; int mfInX = 0;					/**< No flow control */
int mfOutxCtsFlow = 0; int mfOutxDsrFlow = 0;

int mmfDtrControl = 0; int mmfRtsControl = 0; /**< No DTS/RTS */

char buffer [80];

	if (mConnect->GetValue() == 1)
		{
		comWrite(mSerialSelect->GetSelection(), "GUIMODE 0\n",9);
	    comCloseAll();
		oss << "\nPort " << comGetPortName(mSerialSelect->GetSelection()) << " closed...\n";
		m_textCtrl1->AppendText(oss.str());
		mConnect->SetLabel("Connect!");
		mConnect->SetToolTip("Click here to connect to the clock");
		}
	else
		{
		actPort = mSerialSelect->GetSelection();
		switch (mFlowcontrol->GetSelection())
			{
			case 0:
				{
  				 mfOutX = 1;  mfInX = 1;
				 mfOutxCtsFlow = 0;  mfOutxDsrFlow = 0;
				break;
				}
			case 1:
				{
  				 mfOutX = 0;  mfInX = 0;
				 mfOutxCtsFlow = 1;  mfOutxDsrFlow = 1;
				break;
				}
			case 2:
				{
  				 mfOutX = 0;  mfInX = 0;
				 mfOutxCtsFlow = 0;  mfOutxDsrFlow = 0;
				break;
				}
			}
		if (mDTS->GetValue() == 1)
				{
				mmfDtrControl = 1;
				}
		else
				{
				mmfDtrControl = 0;
				}
		if (mRTS->GetValue() == 1)
				{
				mmfRtsControl  = 1;
				}
		else
				{
				mmfRtsControl  = 0;
				}
	    int opnPort = comOpen(actPort, speedPort[mPortSpeed->GetSelection()], dataBits[mDatabits->GetSelection()],
							pParity[mParity->GetSelection()],mStopbits->GetSelection(),
							mfOutX, mfInX, mfOutxCtsFlow, mfOutxDsrFlow, mmfDtrControl, mmfRtsControl);
/*		#ifdef DEBUG
    	printf(("\nactPort = %d, speedPort = %d, Parity = %d, mDatabits = %d\n mStopbits = %d, mfOutX = %d, mfInX = %d, mfOutxCtsFlow = %d, mfOutxDsrFlow = %d\nmmfDtrControl = %d, mmfRtsControl = %d\n"),
				actPort,
				speedPort[mPortSpeed->GetSelection()],
				pParity[mParity->GetSelection()],
				dataBits[mDatabits->GetSelection()],
				mStopbits->GetSelection(),
				mfOutX, mfInX, mfOutxCtsFlow, mfOutxDsrFlow,
				mmfDtrControl, mmfRtsControl
              );
		#endif // DEBUG*/
		oss << "Port " << comGetPortName(mSerialSelect->GetSelection()) << " speed set to " << speedPort[mPortSpeed->GetSelection()] << " Opening...\n";
		m_textCtrl1->AppendText(oss.str());
		if (opnPort == 1)
			{
			oss << "Port connected  " << opnPort << "...\n";
			m_textCtrl1->AppendText(oss.str());
   			mConnect->SetLabel("Disconnect!");
			mConnect->SetToolTip("Click here to disconnect to the clock");
			comWrite(mSerialSelect->GetSelection(), "GUIMODE 1\n",9);
 			wxMilliSleep(1000); // x-amount of seconds
 			comWrite(mSerialSelect->GetSelection(), "DisplayAlarms\n",14);
			}
		else
			{
			if(opnPort == 6)
				{
				oss << "Couldn't connect to port " << comGetPortName(mSerialSelect->GetSelection()) << ", is being used by another progran...\n";
				}
			if(opnPort == 9)
				{
				oss << "Couldn't connect to port " << comGetPortName(mSerialSelect->GetSelection()) << ", is unavailable...\n";
				}
			if(opnPort == 0)
				{
				oss << "Couldn't connect to port " << comGetPortName(mSerialSelect->GetSelection()) << "...\n";
				}
			m_textCtrl1->AppendText(oss.str());
			mConnect->SetValue(1);
			}
		}
}
void RTC4RlaysFBDialog::rescanPorts( wxCommandEvent& event )
{
    int enumP = comEnumerate();
    char *buf = "";
/*	#ifdef DEBUG
    printf("Got %d ports ...\n",enumP);
	#endif // DEBUG*/
	mSerialSelect->Clear();
    for (int i = 0; i < enumP; i++)
		{
		const char *portIName = comGetInternalName(i);
    	const char *portFName = comGetPortName(i);
/*    	if (comState(i).BaudRate == 666)
    		{
			#ifdef DEBUG
			printf ("\nError %d reading port %d, already opened by another app...\n",comState(i).BaudRate,i);
			#endif // DEBUG
			}
    	if (comState(i).BaudRate == 999)
    		{
			#ifdef DEBUG
			printf ("\nError %d reading port %d is not an available port...\n",comState(i).BaudRate,i);
			#endif // DEBUG
			}*/
    	mSerialSelect->Append(portFName);
		}

    if(mConnect->GetValue() == 1)
		{
		mConnect->SetLabel("Connect!");
		mConnect->SetToolTip("Click here to connect to the clock");
		mConnect->SetValue(1);
		}
	else
		{
		mConnect->SetLabel("Disconnect!");
		mConnect->SetToolTip("Click here to disconnect to the clock");
		mConnect->SetValue(0);
		}
}
/******************************************************************
******************** RTC settings *********************************
******************************************************************/

void RTC4RlaysFBDialog::onBtnSync( wxCommandEvent& event )
{
	char buffer[100],buff[100];
	wxDateTime RTC = wxDateTime::Now();
	sprintf(buff,"SetTime %s\n", (const char*)RTC.Format(wxS("%Y/%m/%d %H:%M:%S")));
	comWrite(mSerialSelect->GetSelection(), buff,strlen(buff));
	m_textCtrl1->AppendText(buff);
}
void RTC4RlaysFBDialog::onAceptRTC( wxCommandEvent& event )
{
	char buffer[100],buff[100];
	wxDateTime RTCDate = m_calendar1->GetDate();
	wxDateTime RTCTime = m_timePicker25->GetValue();
	sprintf(buff,"SetTime %s %s \n", (const char*)RTCDate.Format(wxS("%Y/%m/%d")), (const char*)RTCTime.Format(wxS("%H:%M:%S")));
	comWrite(mSerialSelect->GetSelection(), buff,strlen(buff));
	m_textCtrl1->AppendText(buff);
}
/******************************************************************
******************** Alarms settings ******************************
******************************************************************/
void RTC4RlaysFBDialog::GetAlarms( wxCommandEvent& event )
{
	comWrite(mSerialSelect->GetSelection(), "GUIMODE 1\n",9);
	wxMilliSleep(1000); // x-amount of seconds
	comWrite(mSerialSelect->GetSelection(), "DisplayAlarms\n",14);
}

void RTC4RlaysFBDialog::btnSetAlarms( wxCommandEvent& event )
{
int i = 0;
char nameCtrl[16],buffer[16],strBuf[20],buff[411],cmdBuff[411];
char* finis;
int countChoices = 0;
wxWindow* ctrl;
wxComboBox* ctrlCombo;
wxDatePickerCtrl* ctrlDate;
wxTimePickerCtrl* ctrlTime;
wxCheckBox* ctrlCheck;
wxChoice* ctrlChoice;
wxListBox* ctrlListBox;
wxArrayInt index;
comWrite(mSerialSelect->GetSelection(), "GUIMODE 0\n",9);
wxMilliSleep(1000); // x-amount of seconds
for (i=0;i<8;i++)
	{
	sprintf(nameCtrl, "mAlarmDate%d", i);
	ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].almDate = ctrlDate->GetValue();

	sprintf(nameCtrl, "mAlarmTime%d", i);
	ctrlTime = (wxTimePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].almTime = ctrlTime->GetValue();
sprintf(buff, "SetData %d %s;%s",i ,(const char*)myAlarms[i].almDate.Format(wxS("%Y;%m;%d")), (const char*)myAlarms[i].almTime.Format(wxS("%H;%M;%S")));

	sprintf(nameCtrl, "mTimerOn%d", i);
	ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].timOnTime = ctrlDate->GetValue();
sprintf(buff, "%s;%s",buff, (const char*)myAlarms[i].timOnTime.Format(wxS("%H;%M;%S")));

	sprintf(nameCtrl, "mTimerOff%d", i);
	ctrlDate = (wxDatePickerCtrl*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].timOffTime = ctrlDate->GetValue();
sprintf(buff, "%s;%s",buff, (const char*)myAlarms[i].timOffTime.Format(wxS("%H;%M;%S")));

	sprintf(nameCtrl, "mAlarmAct%d", i);
	ctrlCheck = (wxCheckBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].almAct = ctrlCheck->GetValue();

sprintf(buff, "%s;%d",buff, myAlarms[i].almAct);
	sprintf(nameCtrl, "mAlarmTmr%d", i);
	ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].almTim = ctrlCombo->GetSelection();
	if (ctrlCombo->GetSelection() == 8)
		{
		myAlarms[i].almTim = 88;
		}
	else
		{
		if (ctrlCombo->GetSelection() == 9)
			{
			myAlarms[i].almTim = 99;
			}
		}

sprintf(buff, "%s;%d",buff, myAlarms[i].almTim);
	sprintf(nameCtrl, "mTimerRep%d", i);
	ctrlCombo = (wxComboBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].timOnRep  = ctrlCombo->GetSelection();

sprintf(buff, "%s;%d",buff, myAlarms[i].timOnRep);
	sprintf(nameCtrl, "mTimerAct%d", i);
	ctrlChoice = (wxChoice*)wxWindow::FindWindowByName(nameCtrl,NULL);
	myAlarms[i].timOnRel  = ctrlChoice->GetSelection();

sprintf(buff, "%s;%d",buff, myAlarms[i].timOnRel);
	sprintf(nameCtrl, "mDayOff%d", i);
	ctrlListBox = (wxListBox*)wxWindow::FindWindowByName(nameCtrl,NULL);
	countChoices = ctrlListBox->GetSelections(index);

	myAlarms[i].weekOff = 0;
	for (int j = 0; j < countChoices; j++)
		{
		if(index[j] == 6)
			{
			index[j] = 0;
			}
		else
			{
			index[j]++;
			}
		myAlarms[i].weekOff = myAlarms[i].weekOff | (128 >> index[j]);
		itoa(myAlarms[i].weekOff,buffer,2);
		}

sprintf(buff, "%s;%d\n",buff, myAlarms[i].weekOff,finis);
	m_textCtrl1->AppendText(buff);
	comWrite(mSerialSelect->GetSelection(), buff, strlen(buff));
	wxMilliSleep(1200); // x-amount of seconds
	}
comWrite(mSerialSelect->GetSelection(), "GUIMODE 1\n",9);
//SetData 7 2057;04;18;00;00;00;16;51;44;09;07;07;1;0;0;4;224
}
/******************************************************************
******************** Console settings ******************************
******************************************************************/
void RTC4RlaysFBDialog::checkVerb( wxCommandEvent& event )
{
	if(mVerbosity->GetValue() == 1)
		{comWrite(mSerialSelect->GetSelection(), "Verbosity 1\n",12);}
	else
		{comWrite(mSerialSelect->GetSelection(), "Verbosity 0\n",12);}
}
void RTC4RlaysFBDialog::checkSleep( wxCommandEvent& event )
{
	if(mSleep->GetValue() == 1)
		{comWrite(mSerialSelect->GetSelection(), "Sleep 1\n",12);}
	else
		{comWrite(mSerialSelect->GetSelection(), "Sleep 0\n",12);}
}
