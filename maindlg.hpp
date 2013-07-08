/////////////////////////////////////////////////////////////////////////////
// Name:        MainDlg.h
// Purpose:     Main Application Window
// Author:      Jason Champion
// Created:     02/08/2006 11:45:51
// Copyright:   (c) 2006-2013
// Licence:     MIT License
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINDLG_H_
#define _MAINDLG_H_

#include "wx/wx.h"
#include "wx/spinctrl.h"

class wxSpinCtrl;

#define ID_MAINDIALOG 10000
#define SYMBOL_MAINDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxMAXIMIZE_BOX
#define SYMBOL_MAINDLG_TITLE _("ZC Trigram Generator")
#define SYMBOL_MAINDLG_IDNAME ID_MAINDIALOG
#define SYMBOL_MAINDLG_SIZE wxSize(440, 300)
#define SYMBOL_MAINDLG_POSITION wxDefaultPosition
#define ID_BUTTON_TRIGRAM 10001
#define ID_BUTTON_DIGRAM 10002
#define ID_TEXT_INPUT 10003
#define ID_TEXT_OUTPUT 1004
#define ID_SAMPLERATE 10009
#define ID_SAMPLES 10010
#define ID_BITDEPTH 10011
#define ID_CHANNELS 10012
#define ID_NUM_WORDS 10013
#define ID_BUTTON_ABOUT 10014

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * MainDlg class declaration
 */
class MainDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( MainDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    MainDlg( );
    ~MainDlg( );
    MainDlg( wxWindow* parent, wxWindowID id = SYMBOL_MAINDLG_IDNAME, const wxString& caption = SYMBOL_MAINDLG_TITLE, const wxPoint& pos = SYMBOL_MAINDLG_POSITION, const wxSize& size = SYMBOL_MAINDLG_SIZE, long style = SYMBOL_MAINDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MAINDLG_IDNAME, const wxString& caption = SYMBOL_MAINDLG_TITLE, const wxPoint& pos = SYMBOL_MAINDLG_POSITION, const wxSize& size = SYMBOL_MAINDLG_SIZE, long style = SYMBOL_MAINDLG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

    void OnButtonDigramClick( wxCommandEvent& event );

    void OnMouseWheel( wxMouseEvent& event );

    void OnMinfreqUpdated( wxSpinEvent& event );

    void OnMinfreqTextUpdated( wxCommandEvent& event );

    void OnMaxfreqUpdated( wxSpinEvent& event );

    void OnMaxfreqTextUpdated( wxCommandEvent& event );

	void OnQuit(wxCloseEvent &event);
	void OnButtonAboutClick( wxCommandEvent& event );

    wxBitmap GetBitmapResource( const wxString& name );

    wxIcon GetIconResource( const wxString& name );

    static bool ShowToolTips();

	int GetLetterNumber( char letter );
	char GenerateRandomLetter(bool trigram);
	// Reverse of GetLetterNumber
	char GetLetter( int number );

private:
	// 26 = SPACE
	// 27 = period
	// 28 = comma
    wxTextCtrl* _txtInput;
	wxTextCtrl* _txtOutput;
    wxButton* _btnDigram;
	wxButton* _btnTrigram;
	wxButton* _btnAbout;
    wxStaticText* _txtStatus;
	wxSpinCtrl* _spnNumWords;
	int _trigramWeights[95][95][95];
	int _totalWeight[95][95];
	char _previousLetter;
	char _previousPreviousLetter;
};

#endif
