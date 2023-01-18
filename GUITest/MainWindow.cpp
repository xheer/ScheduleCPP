#include "MainWindow.h"

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
//test
MainWindow::~MainWindow()
{

}
