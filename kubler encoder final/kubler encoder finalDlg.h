
// kubler encoder finalDlg.h : ͷ�ļ�
//

#pragma once
#include "mscomm1.h"
#include "tchart1.h"
#include "afxwin.h"

// CkublerencoderfinalDlg �Ի���
class CkublerencoderfinalDlg : public CDialogEx
{
// ����
public:
	CkublerencoderfinalDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KUBLERENCODERFINAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
