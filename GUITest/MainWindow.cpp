#include "MainWindow.h"
#include "TestDialog.h"

BEGIN_EVENT_TABLE(MainWindow, wxFrame) //class for event window and its parent
    EVT_MENU(wxID_NEW, MainWindow::onNew) //(id that was appended, event handler)
    EVT_MENU(wxID_EXIT, MainWindow::onQuit)
    EVT_CLOSE(MainWindow::onClose)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos ,
    const wxSize& size ,
    long style,
    const wxString& name):
    wxFrame(parent,id,title,pos,size,style,name)
{
    wxMenuBar* menuBar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu();
    menuBar->Append(fileMenu, _("&File"));

    //wxWidgets default wxMenuItem example
    fileMenu->Append(wxID_NEW);

    //Custom wxMenuItem
    wxMenuItem *fileItem = fileMenu->Append(wxID_ANY, _("&Test\tCtr+T"));
    Bind(wxEVT_MENU, &MainWindow::onTest, this, fileItem->GetId());

    //Submenu
    wxMenu* subMenu = new wxMenu();
    subMenu->Append(wxID_CUT);
    subMenu->Append(wxID_PASTE);
    fileMenu->AppendSubMenu(subMenu, _("SubMenu"));

    fileMenu->AppendSeparator();

    //Create wxMenuItem
    wxMenuItem* quitItem = new wxMenuItem(fileMenu, wxID_EXIT);
    fileMenu->Append(quitItem);

    SetMenuBar(menuBar);

    //Sizers
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPanel* panel = new wxPanel(this);
    mainSizer->Add(panel, 1, wxEXPAND);


    wxBoxSizer* panelMainSizer = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(panelMainSizer);

    wxBoxSizer* firstNameSizer = new wxBoxSizer(wxHORIZONTAL);
    //firstNameBox->SetMinSize(wxSize(100, 100)) set the box to a certain size

    //Creating the First Name Label
    wxStaticText* firstNameLabel = new wxStaticText(panel, wxID_ANY, _("First Name")); //first argument could be this pointer, but switched to panel pointer
    firstNameLabel->SetMinSize(wxSize(125, firstNameLabel->GetMinSize().y)); //this is automatically sizing it
    firstNameSizer->Add(firstNameLabel);

    //Creating the First Name Box
    wxTextCtrl* firstNameBox = new wxTextCtrl(panel, wxID_ANY);
    firstNameSizer->Add(firstNameBox); //Flag options here https://docs.wxwidgets.org/3.0/classwx_sizer_flags.html

    panelMainSizer->Add(firstNameSizer, 0, wxALL, 5);

//

    wxBoxSizer* lastNameSizer = new wxBoxSizer(wxHORIZONTAL);

    //Creating the Last Name Label
    wxStaticText* lastNameLabel = new wxStaticText(panel, wxID_ANY, _("Last Name"));
    lastNameLabel->SetMinSize(wxSize(125, lastNameLabel->GetMinSize().y)); //this is automatically sizing it
    lastNameSizer->Add(lastNameLabel);

    //Creating the Last Name Box
    wxTextCtrl* lastNameBox = new wxTextCtrl(panel, wxID_ANY);
    lastNameSizer->Add(lastNameBox); //Flag options here https://docs.wxwidgets.org/3.0/classwx_sizer_flags.html

    panelMainSizer->Add(lastNameSizer, 0, wxLEFT | wxRIGHT | wxBOTTOM,5);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->AddStretchSpacer();//takes up any extra space in the sizer

    //Buttons
    wxButton* okbutton = new wxButton(panel, wxID_OK);
    buttonSizer->Add(okbutton);

    wxButton* cancelButton = new wxButton(panel, wxID_CANCEL);
    buttonSizer->Add(cancelButton);

    panelMainSizer->Add(buttonSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5); //adding button sizer to main sizer -- the wxEXPAND is causing the buttons to go to the far right

    //Testing custom new buton
    wxButton* testButton = new wxButton(panel,wxID_ANY);
    panelMainSizer->Add(testButton);

    //Changing tab order
    cancelButton->MoveBeforeInTabOrder(okbutton);

    SetSizer(mainSizer);
    
    SetMinSize(wxSize(400, 200));
    mainSizer->Fit(this); //Resizes the window so there is no empty space
}

//Event Handlers
void MainWindow::onNew(wxCommandEvent& event)
{
    wxMessageBox("MainWindow::onNew");
}

void MainWindow::onTest(wxCommandEvent& WXUNUSED(event))
{
    //wxMessageBox("MainWindow::onTest");
    TestDialog dlg(this, wxID_ANY, _("This is a Dialog"));

    if (dlg.ShowModal() == wxID_OK)
    {
        wxMessageBox(wxString::Format("FieldA = %s'\nFieldB = %s'\nFieldC = %s'\n",
            dlg.getFieldA(), dlg.getFieldB(), dlg.getFieldC()));
    }


}

void MainWindow::onQuit(wxCommandEvent& event)
{
    wxMessageBox("MainWindow::onQuit");
    bool veto = Close();
}

void MainWindow::onClose(wxCloseEvent& event)
{
    wxMessageBox("MainWindow::onClose");

    if (event.CanVeto())
    {
        int answer = wxMessageBox(_("Should we close?"), _("Confirm?"), wxYES_NO);

        if (answer != wxYES)
        {
            event.Veto();
            return;
        }
    }

    Destroy();
}


MainWindow::~MainWindow()
{

}
