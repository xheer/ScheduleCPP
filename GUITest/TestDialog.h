#pragma once
#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class TestDialog :
    public wxDialog
{
public:
    TestDialog(wxWindow* parent, wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE,
        const wxString& name = wxASCII_STR(wxDialogNameStr));

    virtual ~TestDialog();

    wxString getFieldA() const { return fieldA; }
    wxString getFieldB() const { return fieldB; }
    wxString getFieldC() const { return fieldC; }
private:

    virtual bool TransferDataToWindow() override;
    virtual bool TransferDataFromWindow() override;
    void onUpdateOk(wxUpdateUIEvent& event);  //updating the window to enable a button
    wxTextCtrl* fieldABox = nullptr;
    wxTextCtrl* fieldBBox = nullptr;
    wxChoice* fieldCChoice = nullptr;
    wxString fieldA = "This is field A";
    wxString fieldB = "This is field B";
    wxString fieldC = "Option 1";

    DECLARE_EVENT_TABLE()

};

