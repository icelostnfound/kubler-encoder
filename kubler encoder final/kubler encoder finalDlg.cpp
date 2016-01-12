
// kubler encoder finalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "kubler encoder final.h"
#include "kubler encoder finalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CkublerencoderfinalDlg 对话框



CkublerencoderfinalDlg::CkublerencoderfinalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkublerencoderfinalDlg::IDD, pParent)
	, m_Angle1(0)
	, m_Angle2(0)
	, m_REC(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkublerencoderfinalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Angle1, m_Angle1);
	DDX_Text(pDX, IDC_EDIT_Angle2, m_Angle2);
	DDX_Control(pDX, IDC_MSCOMM1, m_Mscomm1);
	DDX_Control(pDX, IDC_MSCOMM2, m_Mscomm2);
	//  DDX_Control(pDX, IDC_EDIT3, m_REC);
	DDX_Text(pDX, IDC_EDIT3, m_REC);
}

BEGIN_MESSAGE_MAP(CkublerencoderfinalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CkublerencoderfinalDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CkublerencoderfinalDlg 消息处理程序

BOOL CkublerencoderfinalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CkublerencoderfinalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CkublerencoderfinalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CkublerencoderfinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//检测一个字符是不是十六进制字符，若是返回相应的值，否则返回0x10
char HexChar(char c)
{
	if ((c >= '0') && (c <= '9'))
		return c - 0x30;
	else if ((c >= 'A') && (c <= 'F'))
		return c - 'A' + 10;
	else if ((c >= 'a') && (c <= 'f'))
		return c - 'a' + 10;
	else return 0x10;
}
//将一个字符串作为十六进制串转化为一个字节数组，字节间可用空格分隔，返回转换后的字节数组长度，同时字节数组长度自动设置。
int Str2Hex(CString str, CByteArray &data)
{
	int t, t1;
	int rlen = 0, len = str.GetLength();
	data.SetSize(len / 2);
	for (int i = 0; i<len;)
	{
		char l, h = str[i];
		if (h == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)break;
		l = str[i];
		t = HexChar(h);
		t1 = HexChar(l);
		if ((t == 16) || (t1 == 16))
			break;
		else t = t * 16 + t1;
		i++;
		data[rlen] = (char)t;
		rlen++;
	}
	data.SetSize(rlen);
	return rlen;
}
void CkublerencoderfinalDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str,str1, n;//定义字符串 
	GetDlgItemText(IDC_BUTTON1, str);
	CWnd *h1;
	h1 = GetDlgItem(IDC_BUTTON1);//指向控件的caption 
	if (!m_Mscomm1.get_PortOpen())
	{
		//设置Mscomm1
		str1.Format(_T ("%d,n,8,1"),115200);
		m_Mscomm1.put_CommPort(2); //选择默认串口com2 
		m_Mscomm1.put_InputMode(1);   //设置输入方式为二进制方式 
		m_Mscomm1.put_Settings(str1);  //波特率为115200,无校验，8数据位，1个停止位 
		m_Mscomm1.put_InputLen(0);  //设置当前接收区数据长度为0,即：接收串口所有的数据
		m_Mscomm1.put_RThreshold(1);   //缓冲区一个字符引发事件  
		m_Mscomm1.put_RTSEnable(1);   //设置RT允许 
		m_Mscomm1.put_PortOpen(true);//打开串口 
		//设置Mscomm2
		m_Mscomm2.put_CommPort(4); //选择默认串口com4
		m_Mscomm2.put_Settings(str1);  //波特率为115200,无校验，8数据位，1个停止位 
		m_Mscomm2.put_InputLen(0);  //设置当前接收区数据长度为0,即：接收串口所有的数据
		m_Mscomm2.put_RThreshold(1);   //缓冲区一个字符引发事件  
		m_Mscomm2.put_RTSEnable(1);   //设置RT允许 
		m_Mscomm2.put_PortOpen(true);//打开串口
		if (m_Mscomm1.get_PortOpen())
		{
			str = _T("关闭串口");
			UpdateData(true);
			h1->SetWindowText(str);   //改变按钮名称为‘’关闭串口” 
		}

	}

	else
	{
		m_Mscomm1.put_PortOpen(false);
		m_Mscomm2.put_PortOpen(false);
		if (str != _T("打开串口"))
		{
			str = _T("打开串口");
			UpdateData(true);
			h1->SetWindowText(str); //改变按钮名称为打开串口 
		}
	}
	UpdateData(true);//更新控件数据 
	CByteArray data;
	//str2.Format(_T("%s"), "02");
	m_REC = _T("02");
	int len = Str2Hex(m_REC, data);//将编码器地址转换成十六进制数存入data中
	m_Mscomm1.put_Output(COleVariant(data));//发送数据给串口1
	m_Mscomm2.put_Output(COleVariant(data));//发送数据给串口2
}

BEGIN_EVENTSINK_MAP(CkublerencoderfinalDlg, CDialogEx)
	ON_EVENT(CkublerencoderfinalDlg, IDC_MSCOMM1, 1, CkublerencoderfinalDlg::OnCommMscomm1, VTS_NONE)
	ON_EVENT(CkublerencoderfinalDlg, IDC_MSCOMM2, 1, CkublerencoderfinalDlg::OnCommMscomm2, VTS_NONE)
END_EVENTSINK_MAP()


void CkublerencoderfinalDlg::OnCommMscomm1()
{
	// TODO:  在此处添加消息处理程序代码
	VARIANT variant_inp1;
	COleSafeArray safearray_inp1;
	LONG len1, k1;
	BYTE rxdata1[1024]; //设置BYTE数组 
	CString strtemp1;
	float tmp1;
	unsigned long BMQ_Val1;
	if (m_Mscomm1.get_CommEvent() == 2)     //事件值为2表示接收缓冲区内有字符
	{
		variant_inp1 = m_Mscomm1.get_Input();   //读缓冲区
		safearray_inp1 = variant_inp1;           //VARIANT型变量转换为ColeSafeArray型变量
		len1 = safearray_inp1.GetOneDimSize(); //得到有效数据长度
		for (k1 = 0; k1<len1; k1++)
			safearray_inp1.GetElement(&k1, rxdata1 + k1);//转换为BYTE型数组
		if (((rxdata1[0] & 0xFF) == 0xAA) && (((rxdata1[2] + rxdata1[3] + rxdata1[4] + rxdata1[5]) & 0xFF) == rxdata1[6]))              //数据帧校验通过
		{
			BMQ_Val1 = ((rxdata1[5] & 0xFF) | ((rxdata1[4] & 0xFF) << 8) | ((rxdata1[3] & 0xFF) << 16) | ((rxdata1[2] & 0xFF) << 24)) & 0xFFFFFFF; //数据拼接

			tmp1 = ((float)(BMQ_Val1 & 0xFFF) / 0xFFF)*360.0;    //将0x000-0xFFF的12位十六进制数据转换成0-360角度值
		}
		m_Angle1 = tmp1;//m_Angle1为com2口的角度
	}
	UpdateData(FALSE);           //更新编辑框内容
}


void CkublerencoderfinalDlg::OnCommMscomm2()
{
	// TODO:  在此处添加消息处理程序代码
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[1024]; //设置BYTE数组 
	CString strtemp;
	float tmp;
	unsigned long BMQ_Val;
	if (m_Mscomm2.get_CommEvent() == 2)     //事件值为2表示接收缓冲区内有字符
	{
		variant_inp = m_Mscomm2.get_Input();   //读缓冲区
		safearray_inp = variant_inp;           //VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize(); //得到有效数据长度
		for (k = 0; k<len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组
		if (((rxdata[0] & 0xFF) == 0xAA) && (((rxdata[2] + rxdata[3] + rxdata[4] + rxdata[5]) & 0xFF) == rxdata[6]))              //数据帧校验通过
		{
			BMQ_Val = ((rxdata[5] & 0xFF) | ((rxdata[4] & 0xFF) << 8) | ((rxdata[3] & 0xFF) << 16) | ((rxdata[2] & 0xFF) << 24)) & 0xFFFFFFF; //数据拼接

			tmp = ((float)(BMQ_Val & 0xFFF) / 0xFFF)*360.0;    //将0x000-0xFFF的12位十六进制数据转换成0-360角度值
		}
		m_Angle2 = tmp;//m_Angle2为com4口的角度
	}
	UpdateData(FALSE);           //更新编辑框内容
}
