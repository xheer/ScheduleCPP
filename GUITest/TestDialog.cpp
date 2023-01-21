#include "TestDialog.h"


BEGIN_EVENT_TABLE(TestDialog, wxDialog)
    EVT_UPDATE_UI(wxID_OK, TestDialog::onUpdateOk)
END_EVENT_TABLE()

TestDialog::TestDialog(wxWindow* parent, wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    //Create fieldA Entry fields NOTE!!! the setup for the actual entry fields are in TestDialog.h
    wxBoxSizer* fieldASizer = new wxBoxSizer(wxHORIZONTAL);

    //FieldB Labels
    wxStaticText* fieldALabel = new wxStaticText(this, wxID_ANY, _("Field A"));
    fieldALabel->SetMinSize(wxSize(50, fieldALabel->GetMinSize().y));
    fieldASizer->Add(fieldALabel);

    fieldABox = new wxTextCtrl(this, wxID_ANY);
    fieldASizer->Add(fieldABox);

    mainSizer->Add(fieldASizer, 0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT | wxBOTTOM, 5);




    //Create fieldB Entry fields NOTE!!! the setup for the actual entry fields are in TestDialog.h
    wxBoxSizer* fieldBSizer = new wxBoxSizer(wxHORIZONTAL);

    //FieldB Labels
    wxStaticText* fieldBLabel = new wxStaticText(this, wxID_ANY, _("Field B"));
    fieldBLabel->SetMinSize(wxSize(50, fieldBLabel->GetMinSize().y));
    fieldBSizer->Add(fieldBLabel);

    fieldBBox = new wxTextCtrl(this, wxID_ANY);
    fieldBSizer->Add(fieldBBox);

    mainSizer->Add(fieldBSizer,0,wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM,5);



    //This field will have a drop down with options
    //Create fieldC Entry fields NOTE!!! the setup for the actual entry fields are in TestDialog.h
 
    //FieldC Labels
    wxStaticText* fieldCLabel = new wxStaticText(this, wxID_ANY, _("Field C"));
    fieldCLabel->SetMinSize(wxSize(50, fieldBLabel->GetMinSize().y));
    fieldBSizer->Add(fieldCLabel);

    

    wxArrayString fieldCOptions;
    fieldCOptions.push_back("Option 1");
    fieldCOptions.push_back("Option 2");
    fieldCOptions.push_back("Option 3");

    fieldCChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, fieldCOptions);
    fieldBSizer->Add(fieldCChoice);

    

    wxBoxSizer* fieldCSizer = new wxBoxSizer(wxHORIZONTAL);

    wxSizer* buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer);
    SetSizer(mainSizer);
    SetMinSize(wxSize(400, 100));
    Fit();
}

void TestDialog::onUpdateOk(wxUpdateUIEvent& event) //enabling the ok button when all fields are filled in
{
    event.Enable(false);

    if (!fieldABox->GetValue().empty())
    {
        if (!fieldBBox->GetValue().empty())
        {
            int selection = fieldCChoice->GetSelection();

            if (selection != wxNOT_FOUND)
            {
                event.Enable(true);
            }
        }
    }
}

bool TestDialog::TransferDataToWindow()
{

    fieldABox->SetValue(fieldA);
    fieldBBox->SetValue(fieldB);

    int selection = fieldCChoice->FindString(fieldC);

    if (selection != wxNOT_FOUND)
    {
        fieldCChoice->SetSelection(selection);
    }
    return true;
}

bool TestDialog::TransferDataFromWindow()
{
    fieldA = fieldABox->GetValue();
    fieldB = fieldBBox->GetValue();

    int selection = fieldCChoice->GetSelection();
    if (selection != wxNOT_FOUND)
    {
        fieldC = fieldCChoice->GetString(selection);
    }
    return true;
}

TestDialog::~TestDialog()
{

}