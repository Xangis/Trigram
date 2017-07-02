/////////////////////////////////////////////////////////////////////////////
// Name:        wxapp.h
// Purpose:     Header for Application Wrapper
// Author:      Jason Champion
// Created:     02/08/2006 11:42:44
// Copyright:   (c) 2006-2017
// Licence:     MIT License
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXAPP_H_
#define _WXAPP_H_

#include "wx/wx.h"
#include "maindlg.hpp"

/*!
 * wxApplication class declaration
 */
class wxApplication: public wxApp
{
    DECLARE_CLASS( wxApplication )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    wxApplication();

    /// Destructor
    ~wxApplication();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

private:
	MainDlg* _MainDlg;
};

DECLARE_APP(wxApplication)

#endif
