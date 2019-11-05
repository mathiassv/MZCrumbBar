// CrumbBarDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include <MZCrumbBar.h>
#include "CrumbBarDemo.h"
#include "CrumbBarDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCrumbBarDemoDlg dialog
CCrumbBarDemoDlg::CCrumbBarDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCrumbBarDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCrumbBarDemoDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_CRUMBBAR, m_CrumbBar);
  DDX_Control(pDX, IDC_TEXT, m_stText);
  DDX_Control(pDX, IDC_CRUMBPATH, m_stPath);
  DDX_Control(pDX, IDC_CHKGRADIENT, m_chkGradient);
  DDX_Control(pDX, IDC_CHKCUSTMODE, m_chkCustomDraw);
  DDX_Control(pDX, IDC_CHKLEFTMARGIN, m_chkLeftMargin);
  DDX_Control(pDX, IDC_EDITMARGIN, m_editMargin);

  DDX_Control(pDX, IDC_CHKSPACING, m_chkSpacing);
  DDX_Control(pDX, IDC_EDITSPACING, m_editSpacing);
  DDX_Control(pDX, IDC_CHKEDITONBK, m_chkEditOnBackgroundClk);
  DDX_Control(pDX, IDC_CHKEDITONCLICKL, m_chkEditOnClickL);
  DDX_Control(pDX, IDC_CHKEDITONCLICKR, m_chkEditOnClickR);
  DDX_Control(pDX, IDC_CHKEDITONCLICKM, m_chkEditOnClickM);
  DDX_Control(pDX, IDC_CHKEDITONCLICKDBLL, m_chkEditOnDubbleClickL);
}

BEGIN_MESSAGE_MAP(CCrumbBarDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDCANCEL, &CCrumbBarDemoDlg::OnBnClickedCancel)
  ON_BN_CLICKED(IDOK, &CCrumbBarDemoDlg::OnBnClickedOk)
  ON_NOTIFY(NMCB_LBCLICK	  , IDC_CRUMBBAR, OnCrumbarItemLeftClick )
  ON_NOTIFY(NMCB_RBCLICK	  , IDC_CRUMBBAR, OnCrumbarItemRightClick )
  ON_NOTIFY(NMCB_MBCLICK	  , IDC_CRUMBBAR, OnCrumbarItemMiddleClick )
  ON_NOTIFY(NMCB_LBDBLCLICK	, IDC_CRUMBBAR, OnCrumbarItemLeftDubbleClick )
  ON_NOTIFY(NMCB_RBDBLCLICK	, IDC_CRUMBBAR, OnCrumbarItemRightDubbleClick )
  ON_NOTIFY(NMCB_MBDBLCLICK	, IDC_CRUMBBAR, OnCrumbarItemMiddleDubbleClick )
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CHKGRADIENT, &CCrumbBarDemoDlg::OnBnClickedChkgradient)
	ON_BN_CLICKED(IDC_CHKADVMODE, &CCrumbBarDemoDlg::OnBnClickedChkadvmode)
	ON_BN_CLICKED(IDC_CHKCUSTMODE, &CCrumbBarDemoDlg::OnBnClickedChkcustmode)
	ON_BN_CLICKED(IDC_BTNPATH1, &CCrumbBarDemoDlg::OnBnClickedBtnpath1)
	ON_BN_CLICKED(IDC_BTNPATH2, &CCrumbBarDemoDlg::OnBnClickedBtnpath2)
	ON_BN_CLICKED(IDC_BTNPATH3, &CCrumbBarDemoDlg::OnBnClickedBtnpath3)
	ON_BN_CLICKED(IDC_CHKLEFTMARGIN, &CCrumbBarDemoDlg::OnBnClickedChkleftmargin)
	ON_BN_CLICKED(IDC_RADIO1, &CCrumbBarDemoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCrumbBarDemoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CCrumbBarDemoDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_CHKSPACING, &CCrumbBarDemoDlg::OnBnClickedChkspacing)
  ON_BN_CLICKED(IDC_CHKEDITONCLICKL, &CCrumbBarDemoDlg::OnBnClickedChkeditonclickl)
  ON_BN_CLICKED(IDC_CHKEDITONCLICKR, &CCrumbBarDemoDlg::OnBnClickedChkeditonclickr)
  ON_BN_CLICKED(IDC_CHKEDITONCLICKM, &CCrumbBarDemoDlg::OnBnClickedChkeditonclickm)
  ON_BN_CLICKED(IDC_CHKEDITONCLICKDBLL, &CCrumbBarDemoDlg::OnBnClickedChkeditonclickdbll)
  ON_BN_CLICKED(IDC_CHKEDITONBK, &CCrumbBarDemoDlg::OnBnClickedChkeditonbk)
  ON_BN_CLICKED(IDC_CHK_NODELIMITERONLAST, &CCrumbBarDemoDlg::OnBnClickedChkNodelimiteronlast)
END_MESSAGE_MAP()


// CCrumbBarDemoDlg message handlers

BOOL CCrumbBarDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_chkGradient.SetCheck(BST_CHECKED);
	m_chkLeftMargin.SetCheck(BST_CHECKED);
	m_editMargin.SetWindowText(_T("10"));
  m_editSpacing.SetWindowText(_T("10"));

  m_stText.SetWindowText(_T(""));
	m_stPath.SetWindowText(_T(""));
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

 	m_strPath = _T("C:\\Windows\\System32\\");
 	m_strDelimiter = _T("\\");
	InitCrumbBarController();

 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCrumbBarDemoDlg::InitCrumbBarController()
{
	m_CrumbBar.ColorDefault(GetSysColor(COLOR_WINDOWTEXT));
	m_CrumbBar.ColorHot(GetSysColor(COLOR_HOTLIGHT));

	if(m_chkGradient.GetCheck() == BST_CHECKED)
		m_CrumbBar.BackgroundColor(RGB(163,180,253) , RGB(110,120,190), true);
	else
		m_CrumbBar.BackgroundColor(GetSysColor(COLOR_WINDOW));

	if(m_chkLeftMargin.GetCheck() == BST_CHECKED)
	{
		CString text;
		m_editMargin.GetWindowText(text);
		int nMargin = _ttoi(text);
		m_CrumbBar.Margin(nMargin);
	}
	else
		m_CrumbBar.Margin(0);

	if(m_chkSpacing.GetCheck() == BST_CHECKED)
	{
		CString text;
		m_editSpacing.GetWindowText(text);
		int nSpacing = _ttoi(text);
		m_CrumbBar.ItemSpacing(nSpacing);
	}
	else
		m_CrumbBar.ItemSpacing(0);

	int nDelMode = DM_RIGHT;
	if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck() == BST_CHECKED)
	{
		nDelMode = DM_LEFT;
	}
	else if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_CHECKED)
	{
		nDelMode = DM_RIGHT;
	}
	else if(((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck() == BST_CHECKED)
	{
		nDelMode = DM_STRIP;
	}
	m_CrumbBar.DelimiterMode(nDelMode);
	m_CrumbBar.Delimiter(m_strDelimiter);

  DWORD dwStyle = 0;

  if(((CButton*)GetDlgItem(IDC_CHK_NODELIMITERONLAST))->GetCheck() == BST_CHECKED)
  {
    dwStyle = CRU_LASTITEMNODELIMITER;
  }

  if(m_chkEditOnClickL.GetCheck() == BST_CHECKED)
    dwStyle |= CRU_EDITONCLK_L;

  if(m_chkEditOnClickR.GetCheck() == BST_CHECKED)
    dwStyle |= CRU_EDITONCLK_R;

  if(m_chkEditOnClickM.GetCheck() == BST_CHECKED)
    dwStyle |= CRU_EDITONCLK_M;

  if(m_chkEditOnDubbleClickL.GetCheck() == BST_CHECKED)
    dwStyle |= CRU_EDITONDBL_L;

  if(m_chkEditOnBackgroundClk.GetCheck() == BST_CHECKED)
    dwStyle |= CRU_EDITOUTSIDE;
  
  m_CrumbBar.Style(dwStyle);

  if(m_chkCustomDraw.GetCheck() == BST_CHECKED)
    m_CrumbBar.CustomDraw(true);
  else
    m_CrumbBar.CustomDraw(false);

	m_CrumbBar.Path(m_strPath);
	MZCrumbBar::CrumbBarItem PreItem(_T(""), _T("..\\"));
	m_CrumbBar.PreItem(PreItem);
	m_CrumbBar.BuildCrumbbar();
}

void CCrumbBarDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCrumbBarDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCrumbBarDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCrumbBarDemoDlg::OnBnClickedCancel()
{
  // TODO: Add your control notification handler code here
  OnCancel();
}

void CCrumbBarDemoDlg::OnBnClickedOk()
{
  // TODO: Add your control notification handler code here
  OnOK();
}

void CCrumbBarDemoDlg::OnItemClick(NM_CRUMBBARITEM* pnmCrumbBarItem, const CString& strMsg)
{
  MZCrumbBar::CrumbBarItem* pCrumbBarItem = pnmCrumbBarItem->pCrumbBarItem;
  CString msg;
  if(pCrumbBarItem)
  {
    msg.Format(strMsg, pCrumbBarItem->Name);
    m_stText.SetWindowText(msg);  
    msg.Format(_T("Crumb path selected : %s"), pnmCrumbBarItem->strCrumbPath);
    m_stPath.SetWindowText(msg);
  }
  else
  {
    m_stText.SetWindowText(_T("Clicked outside of crumb item"));
    m_stPath.SetWindowText(_T(""));
  }
}

void CCrumbBarDemoDlg::OnCrumbarItemLeftClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was clicked with Left mouse button"));
  *pResult = 0;
}

void CCrumbBarDemoDlg::OnCrumbarItemRightClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was clicked with Right mouse button"));
  *pResult = 0;
}

void CCrumbBarDemoDlg::OnCrumbarItemMiddleClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was clicked with Middle mouse button"));
  *pResult = 0;
}

void CCrumbBarDemoDlg::OnCrumbarItemLeftDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was double clicked with Left mouse button"));
  *pResult = 0;
}

void CCrumbBarDemoDlg::OnCrumbarItemRightDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was double clicked with Right mouse button"));
  *pResult = 0;
}

void CCrumbBarDemoDlg::OnCrumbarItemMiddleDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult)
{
  NM_CRUMBBARITEM* pnmCrumbBarItem = (NM_CRUMBBARITEM*)pNotifyStruct;
  OnItemClick(pnmCrumbBarItem, _T("Crumbar Item : '%s' was double clicked with Middle mouse button"));
  *pResult = 0;
}



void CCrumbBarDemoDlg::OnBnClickedChkgradient()
{
	InitCrumbBarController();
}


void CCrumbBarDemoDlg::OnBnClickedChkadvmode()
{
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkcustmode()
{
		InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkleftmargin()
{
		InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedBtnpath1()
{
	m_strPath = _T("C:\\Windows\\System32\\");	
	m_strDelimiter  = _T("\\");
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedBtnpath2()
{
	m_strPath = _T("C:\\Windows\\System32\\Temp1\\Temp2\\Temp3\\Temp4\\Temp5\\Temp6\\Temp7\\Temp8\\Temp9\\Temp10\\");
	m_strDelimiter  = _T("\\");
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedBtnpath3()
{
	m_strPath = _T("Creature*Animal*Dog*Lassie");
	m_strDelimiter  = _T("*");
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkspacing()
{
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedRadio1()
{
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedRadio2()
{
	InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedRadio3()
{
	InitCrumbBarController();
}

//////////////////////////////////////////////////////////////////////////


void CCrumbBarDemoDlg::OnBnClickedChkeditonclickl()
{
  InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkeditonclickr()
{
  InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkeditonclickm()
{
  InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkeditonclickdbll()
{
  InitCrumbBarController();
}

void CCrumbBarDemoDlg::OnBnClickedChkeditonbk()
{
  InitCrumbBarController();
}
void CCrumbBarDemoDlg::OnBnClickedChkNodelimiteronlast()
{
  InitCrumbBarController();
}

