
// GUIW04MFCView.cpp: CGUIW04MFCView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GUIW04MFC.h"
#endif

#include "GUIW04MFCDoc.h"
#include "GUIW04MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGUIW04MFCView

IMPLEMENT_DYNCREATE(CGUIW04MFCView, CView)

BEGIN_MESSAGE_MAP(CGUIW04MFCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CGUIW04MFCView 생성/소멸

CGUIW04MFCView::CGUIW04MFCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGUIW04MFCView::~CGUIW04MFCView()
{
}

BOOL CGUIW04MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGUIW04MFCView 그리기

void CGUIW04MFCView::OnDraw(CDC* pDC)
{
	CGUIW04MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//CPoint p = pDoc->GetPos();

	int n = pDoc->getPointsCount();

	CPoint p;
	for (int i = 0; i < n; i++) {
		p = pDoc->GetPoint(i);
		pDC->Ellipse(p.x - 30, p.y - 30, p.x + 30, p.y + 30);
	}

}


// CGUIW04MFCView 인쇄

BOOL CGUIW04MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGUIW04MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGUIW04MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGUIW04MFCView 진단

#ifdef _DEBUG
void CGUIW04MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CGUIW04MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGUIW04MFCDoc* CGUIW04MFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGUIW04MFCDoc)));
	return (CGUIW04MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CGUIW04MFCView 메시지 처리기


void CGUIW04MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CClientDC dc(this);
	dc.Ellipse(point.x - 30, point.y - 30,
		point.x + 30, point.y + 30);*/

	/*GetDocument()->SetPos(point);*/
	GetDocument()->addPoint(point);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CGUIW04MFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CClientDC dc(this);
	dc.Ellipse(point.x - 30, point.y - 30,
		point.x + 30, point.y + 30);*/

		/*GetDocument()->SetPos(point);*/
	GetDocument()->RemoveLast();
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}
void CGUIW04MFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CClientDC dc(this);
	dc.Ellipse(point.x - 30, point.y - 30,
		point.x + 30, point.y + 30);*/

		/*GetDocument()->SetPos(point);*/
	if (nFlags & MK_LBUTTON) {
		GetDocument()->addPoint(point);
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
