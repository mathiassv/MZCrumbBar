// CrumbBarDemoDlg.h : header file
//

#pragma once
#include "BlockCrumbBar.h"
#include "afxwin.h"



// CCrumbBarDemoDlg dialog
class CCrumbBarDemoDlg : public CDialog
{
// Construction
public:
	CCrumbBarDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CRUMBBARDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();

  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
  afx_msg void OnBnClickedCancel();
  afx_msg void OnBnClickedOk();

	afx_msg HCURSOR OnQueryDragIcon();

  afx_msg void OnCrumbarItemLeftClick(NMHDR *pNotifyStruct, LRESULT* pResult);
  afx_msg void OnCrumbarItemRightClick(NMHDR *pNotifyStruct, LRESULT* pResult);
  afx_msg void OnCrumbarItemMiddleClick(NMHDR *pNotifyStruct, LRESULT* pResult);
  afx_msg void OnCrumbarItemLeftDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult);
  afx_msg void OnCrumbarItemRightDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult);
  afx_msg void OnCrumbarItemMiddleDubbleClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
  void OnItemClick(NM_CRUMBBARITEM* pnmCrumbBarItem, const CString& strMsg);
	void InitCrumbBarController();
public:
  CBlockCrumbBar m_CrumbBar;
  CStatic m_stText;
  CStatic m_stPath;

	CString m_strPath;
	CString m_strDelimiter;

	CButton m_chkGradient;
	CButton m_chkCustomDraw;

	CButton m_chkLeftMargin;
	CEdit m_editMargin;

  CButton m_chkSpacing;
  CEdit m_editSpacing;

  CButton m_chkEditOnClickL;
  CButton m_chkEditOnClickR;
  CButton m_chkEditOnClickM;
  CButton m_chkEditOnDubbleClickL;
  CButton m_chkEditOnBackgroundClk;

	afx_msg void OnBnClickedChkgradient();
	afx_msg void OnBnClickedChkadvmode();
	afx_msg void OnBnClickedChkcustmode();
	afx_msg void OnBnClickedBtnpath1();
	afx_msg void OnBnClickedBtnpath2();
	afx_msg void OnBnClickedBtnpath3();
	afx_msg void OnBnClickedChkleftmargin();

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedChkspacing();

  afx_msg void OnBnClickedChkeditonclickl();
  afx_msg void OnBnClickedChkeditonclickr();
  afx_msg void OnBnClickedChkeditonclickm();
  afx_msg void OnBnClickedChkeditonclickdbll();
  afx_msg void OnBnClickedChkeditonbk();
  
  afx_msg void OnBnClickedChkStylecallback();
  afx_msg void OnBnClickedChkNodelimiteronlast();
};
