#include "bpPanel.h"
#include "rad/appdata.h"
#include <wx/aui/auibook.h>
#include "rad/auitabart.h"
#include "blueprintEditor.h"
#include <rad/bitmaps.h>

bpPanel::bpPanel(wxWindow* parent, int id) : wxPanel(parent, id)
{
    AppData()->AddHandler(this->GetEventHandler());
    wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);

    m_notebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TOP);
    m_notebook->SetArtProvider(new AuiTabArt());

    m_bpEditor = new BlueprintEditor(m_notebook);

    m_notebook->InsertPage(0, m_bpEditor, wxT("BP"), false);
    m_notebook->SetPageBitmap(0, AppBitmaps::GetBitmap(wxT("BP"), AppBitmaps::Size::Icon_Medium));


    top_sizer->Add(m_notebook, 1, wxEXPAND, 0);

    SetSizer(top_sizer);
    SetAutoLayout(true);
    // top_sizer->SetSizeHints( this );
    top_sizer->Fit(this);
    top_sizer->Layout();
}

bpPanel::~bpPanel()
{
    AppData()->RemoveHandler(this->GetEventHandler());
}