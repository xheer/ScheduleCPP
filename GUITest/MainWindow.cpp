#include "MainWindow.h"

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
}

void MainWindow::onNew(wxCommandEvent& event)
{
    wxMessageBox("MainWindow::onNew");
}

void MainWindow::onTest(wxCommandEvent& event)
{
    wxMessageBox("MainWindow::onTest");
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
