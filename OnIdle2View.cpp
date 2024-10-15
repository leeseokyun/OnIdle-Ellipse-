
// OnIdle2View.cpp: COnIdle2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "OnIdle2.h"
#endif

#include "OnIdle2Doc.h"
#include "OnIdle2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COnIdle2View

IMPLEMENT_DYNCREATE(COnIdle2View, CView)

BEGIN_MESSAGE_MAP(COnIdle2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// COnIdle2View 생성/소멸

COnIdle2View::COnIdle2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COnIdle2View::~COnIdle2View()
{
}

BOOL COnIdle2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COnIdle2View 그리기
void COnIdle2View::OnDraw(CDC* pDC)
{
	COnIdle2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect r;
	GetClientRect(&r);

	int centerX = rand() % r.Width();
	int centerY = rand() % r.Height();
	int radiusX = rand() % r.Width()/4;
	int radiusY = rand() % r.Height()/4;

	COLORREF rc = RGB(rand() % 256, rand() % 256, rand() % 256);
	CBrush brush(rc);
	pDC->SelectObject(&brush);

	pDC->Ellipse(centerX - radiusX, centerY - radiusY, centerX + radiusX, centerY + radiusY);
}



// COnIdle2View 인쇄

BOOL COnIdle2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void COnIdle2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void COnIdle2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// COnIdle2View 진단

#ifdef _DEBUG
void COnIdle2View::AssertValid() const
{
	CView::AssertValid();
}

void COnIdle2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COnIdle2Doc* COnIdle2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COnIdle2Doc)));
	return (COnIdle2Doc*)m_pDocument;
}
#endif //_DEBUG


// COnIdle2View 메시지 처리기
