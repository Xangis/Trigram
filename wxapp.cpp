/////////////////////////////////////////////////////////////////////////////
// Name:        wxapp.cpp
// Purpose:     Application Wrapper
// Author:      Jason Champion
// Created:     02/08/2006 11:42:44
// Copyright:   (c) 2006
// Licence:     MIT License
/////////////////////////////////////////////////////////////////////////////

#include "wx/image.h"
#include "wxapp.hpp"

IMPLEMENT_APP( wxApplication )
IMPLEMENT_CLASS( wxApplication, wxApp )
BEGIN_EVENT_TABLE( wxApplication, wxApp )
END_EVENT_TABLE()

/*!
 * Constructor for wxApplication
 */
wxApplication::wxApplication()
{
}

/*!
 * Destructor for wxApplication
 */
wxApplication::~wxApplication()
{
}

/*!
 * Initialisation for wxApplication
 */
bool wxApplication::OnInit()
{
    wxInitAllImageHandlers();
	_MainDlg = new MainDlg(NULL);
	_MainDlg->Show(true);

    return true;
}

/*!
 * Cleanup for wxApplication
 */
int wxApplication::OnExit()
{
    return wxApp::OnExit();
}

