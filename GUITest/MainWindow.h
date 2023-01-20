#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class MainWindow: public wxFrame
{
public:
	MainWindow(wxWindow* parent,
        wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE,
        const wxString& name = wxASCII_STR(wxFrameNameStr));
	~MainWindow();

    //For each button create a new event handler
    void onNew(wxCommandEvent& event); //this needs to be above the declaration
    void onTest(wxCommandEvent& event);
    void onQuit(wxCommandEvent& event);
    void onClose(wxCloseEvent& event);

    DECLARE_EVENT_TABLE()
};

