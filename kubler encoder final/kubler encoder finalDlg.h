
// kubler encoder finalDlg.h : 头文件
//

#pragma once
#include "mscomm1.h"
#include "tchart1.h"
#include "afxwin.h"

// CkublerencoderfinalDlg 对话框
class CkublerencoderfinalDlg : public CDialogEx
{
// 构造
public:
	CkublerencoderfinalDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_KUBLERENCODERFINAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float m_Angle1;
	float m_Angle2;
	CMscomm1 m_Mscomm1;
	CMscomm1 m_Mscomm2;
	afx_msg void OnBnClickedButton1();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	void OnCommMscomm2();
//	CEdit m_REC;
	CString m_REC;
};
