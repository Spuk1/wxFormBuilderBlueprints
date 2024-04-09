#pragma once
#include "wx/panel.h"

class BlueprintEditor;
class wxAuiNotebook;

class bpPanel : public wxPanel
{
private:
    wxAuiNotebook* m_notebook;
    BlueprintEditor* m_bpEditor;
public:
    bpPanel(wxWindow* parent, int id);
    ~bpPanel() override;

};