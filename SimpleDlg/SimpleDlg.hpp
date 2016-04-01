#pragma once

#include "resource.h"
#include "inlineMap.h"

class CSimpleDlg : public CDialogEx
{
	INL_BEGIN_MESSAGE_MAP(CSimpleDlg, CDialogEx)
		ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CSimpleDlg::OnTcnSelchangeTab)
	INL_END_MESSAGE_MAP()

public:
	CSimpleDlg(CWnd* pParent = NULL) : CDialogEx(CSimpleDlg::IDD, pParent) {
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	}

	enum { IDD = IDD_SIMPLEDLG_DIALOG };

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog() {
		CDialogEx::OnInitDialog();

		SetIcon(m_hIcon, TRUE);
		SetIcon(m_hIcon, FALSE);

		// タブコントロールをなんかする
		tab.SubclassDlgItem(IDC_TAB, this);

		tab.InsertItem(0, _T("たろう"));
		tab.InsertItem(1, _T("じろう"));
		tab.InsertItem(3, _T("マイケル"));

		// タブに貼っつける奴らをなんか作ったりする
		dlg[0].Create(IDD_DIALOG1, &tab);
		dlg[1].Create(IDD_DIALOG2, &tab);
		dlg[2].Create(IDD_DIALOG3, &tab);

		// なんか場所の調整
		CRect rect;
		tab.GetWindowRect(rect);
		tab.AdjustRect(FALSE, rect);
		tab.ScreenToClient(rect);

		dlg[0].MoveWindow(rect);
		dlg[1].MoveWindow(rect);
		dlg[2].MoveWindow(rect);

		// 初回たろうを表示
		OnTcnSelchangeTab(NULL, NULL);

		return TRUE;
	}
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult) {
		auto cur = tab.GetCurSel();
		for (int i = 0; i < 3; i++) {
			dlg[i].ShowWindow(i == cur ? SW_SHOW : SW_HIDE);
		}
	}

	afx_msg HCURSOR OnQueryDragIcon() {
		return static_cast<HCURSOR>(m_hIcon);
	}

private:
	CTabCtrl tab;	// 親たぶ
	CDialog dlg[3];	// たぶの子供3枚
};

class CSimpleDlgApp : public CWinApp
{
public:
	virtual BOOL InitInstance() 
	{
		CWinApp::InitInstance();

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

		CSimpleDlg dlg;
		m_pMainWnd = &dlg;

		dlg.DoModal();

		return FALSE;
	}
} theApp;