/////////////////////////////////////////////////////////////////////////////
// Name:        MainDlg.cpp
// Purpose:     Main Application Window
// Author:      Jason Champion
// Created:     02/08/2006 11:45:51
// Copyright:   (c) 2006-2013
// Licence:     MIT License
/////////////////////////////////////////////////////////////////////////////

#include "wx/wx.h"
#include "maindlg.hpp"

IMPLEMENT_DYNAMIC_CLASS( MainDlg, wxDialog )

BEGIN_EVENT_TABLE( MainDlg, wxDialog )
    EVT_BUTTON( ID_BUTTON_DIGRAM, MainDlg::OnButtonDigramClick )
	EVT_BUTTON( ID_BUTTON_ABOUT, MainDlg::OnButtonAboutClick )
    EVT_CLOSE( MainDlg::OnQuit )
END_EVENT_TABLE()

/*!
 * MainDlg constructors
 */
MainDlg::MainDlg( )
{
}

MainDlg::~MainDlg()
{
}

MainDlg::MainDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * MainDlg creator
 */
bool MainDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    _txtInput = NULL;
	_txtOutput = NULL;
    _btnDigram = NULL;
	_btnTrigram = NULL;
    _txtStatus = NULL;
	memset( _trigramWeights, 0, sizeof(_trigramWeights ));
	memset( _totalWeight, 0, sizeof( _totalWeight ));

    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

	wxInitAllImageHandlers();
    CreateControls();
	wxIcon icon;
	if( icon.LoadFile(_T("trigram.ico"), wxBITMAP_TYPE_ICO ))
	{
		SetIcon(icon);
	}
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
    return true;
}

/*!
 * Control creation for MainDlg
 */
void MainDlg::CreateControls()
{
    MainDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 1, wxALIGN_LEFT|wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Input Text:"), wxDefaultPosition, wxSize( 72, 20 ), 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    _txtInput = new wxTextCtrl( itemDialog1, ID_TEXT_INPUT, _T(""), wxDefaultPosition, wxSize(400, 160), wxTE_MULTILINE );
    itemBoxSizer3->Add(_txtInput, 1, wxALIGN_CENTER_VERTICAL|wxTE_BESTWRAP|wxGROW|wxALL, 3);

	wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	itemBoxSizer2->Add(itemBoxSizer4, 0, wxALIGN_RIGHT, 5);

	wxStaticText* itemStaticText41 = new wxStaticText( itemDialog1, wxID_STATIC, _("# of Words:"), wxDefaultPosition, wxSize(72, 18), 0 );
	itemBoxSizer4->Add(itemStaticText41, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5 );

	_spnNumWords = new wxSpinCtrl( itemDialog1, ID_NUM_WORDS, "10", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000, 10 );
	itemBoxSizer4->Add(_spnNumWords, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

    _btnDigram = new wxButton( itemDialog1, ID_BUTTON_DIGRAM, _("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(_btnDigram, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

    _btnAbout = new wxButton( itemDialog1, ID_BUTTON_ABOUT, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(_btnAbout, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

	itemBoxSizer4->AddSpacer(5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer15, 1, wxALIGN_LEFT|wxGROW|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("Output Text:"), wxDefaultPosition, wxSize(72,20), 0 );
    itemBoxSizer15->Add(itemStaticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

	_txtOutput = new wxTextCtrl( itemDialog1, ID_TEXT_OUTPUT, _T(""), wxDefaultPosition, wxSize(400, 160), wxTE_MULTILINE );
    itemBoxSizer15->Add(_txtOutput, 1, wxALIGN_CENTER_VERTICAL|wxTE_BESTWRAP|wxGROW|wxALL, 3);
}

/*!
 * Should we show tooltips?
 */
bool MainDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */
wxBitmap MainDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
}

/*!
 * Get icon resources
 */
wxIcon MainDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PLAY
 */
void MainDlg::OnButtonDigramClick( wxCommandEvent& event )
{
	memset( _trigramWeights, 0, sizeof(_trigramWeights ));
	memset( _totalWeight, 0, sizeof( _totalWeight ));
	wxString inputText = _txtInput->GetValue();
	int numWords = _spnNumWords->GetValue();

	if( !inputText.Len() )
	{
		wxMessageBox( "Nothing to base output on." );
		return;
	}

	const char* input = inputText.mb_str();
	int length = (int)strlen( input );
	int count;
	int num = 0;

	// Set first letter to space.
	_previousPreviousLetter = 0;
	_previousLetter = GetLetterNumber(input[0]);

	// We start at one because we set the initial letter above.
	for( count = 1; count < length; count++ )
	{
		num = GetLetterNumber(input[count]);
		if( num != -1 )
		{
		   _trigramWeights[_previousPreviousLetter][_previousLetter][num]++;
		   _totalWeight[_previousPreviousLetter][_previousLetter]++;
		   _previousPreviousLetter = _previousLetter;
		   _previousLetter = num;
		}
	}

	// When generating, start with the previous letter as a space so we get realistic word beginnings.
	_previousLetter = 0;

	// TODO: Set _previousLetter to a digram generation from chart.
	_previousLetter = GetLetterNumber(input[0]);
	_previousPreviousLetter = 0;

	wxString outputText = input[0];
	outputText += GenerateRandomLetter(false);

	int words = 0;
	int letters = 0;
	while (words < numWords)
	{
		char newletter = GenerateRandomLetter(true);
		outputText += newletter;
		_previousPreviousLetter = _previousLetter;
		_previousLetter = GetLetterNumber(newletter);
		if( newletter == 32 )
		{
			words++;
		}
		letters++;
		if( letters > 12000 )
		{
			_txtOutput->SetValue("Generated output invalid.  Are you sure you have enough input text?");
			event.Skip();
			return;
		}
	}

	char outputExamine[4096];
	memset( outputExamine, 0, 4096 );
	memcpy( outputExamine, outputText.mb_str(), outputText.Len() );

	_txtOutput->SetValue(outputText);

    event.Skip();
}

/**
 @brief  EVT_QUIT handler.
*/
void MainDlg::OnQuit(wxCloseEvent &event)
{
	Destroy();
}

// Case insensitive, gets array position of a particular letter.
int MainDlg::GetLetterNumber( char letter )
{
	// Convert newlines to spaces.
	if( letter == 10 )
	{
		return 0;
	}
	if( letter < 32 || letter > 126 )
	{
		return -1;
	}
	return (letter - 32);
}

char MainDlg::GenerateRandomLetter(bool trigram)
{
	int numOptions = _totalWeight[_previousPreviousLetter][_previousLetter];

	// This should NEVER happen.
	if(numOptions == 0)
	{
		return '@';
	}

	int selection = rand() % numOptions;
	int count;
	int total = 0;

	if( trigram )
	{
		for( count = 0; count < 95; count++ )
		{
			total += _trigramWeights[_previousPreviousLetter][_previousLetter][count];
			if( selection < total )
			{
				return GetLetter(count);
			}
		}
	}
	else
	{
		for( count = 0; count < 95; count++ )
		{
			//total += _trigramWeights[_previousLetter][count][0];
			total += _trigramWeights[0][_previousLetter][count];
			if( selection < total )
			{
				return GetLetter(count);
			}
		}
	}
	// PANIC!  No match, our logic is broken.
	return '*';
}
char MainDlg::GetLetter( int number )
{
	if( number > 0 || number < 95 )
	{
		return (number + 32);
	}
	else
	{
		return 0;
	}
}

void MainDlg::OnButtonAboutClick( wxCommandEvent& event )
{
	wxMessageBox( "ZC Trigram Generator is copyright (c) 2006-2013 Jason Champion.\nhttp://www.zetacentauri.com\n\nThis application is distributed under the terms of the MIT License.", "About Trigram Generator", wxOK );
	event.Skip();
}
