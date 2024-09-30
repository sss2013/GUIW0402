
// GUIW04MFCDoc.h: CGUIW04MFCDoc 클래스의 인터페이스
//


#pragma once


class CGUIW04MFCDoc : public CDocument
{
protected:
	CArray<CPoint, CPoint> Points;

public :
	int getPointsCount() { return (int)Points.GetCount(); }
	void addPoint(CPoint p) { 
		Points.Add(p); 
		SetModifiedFlag();
	}
	CPoint GetPoint(int index) { return Points[index]; }

//protected:
//	CPoint Pos = CPoint(-100,-100);
//public:
//	CPoint GetPos() {
//		return Pos;
//	}
//	
//	void SetPos(CPoint p) {
//		Pos = p;
//		SetModifiedFlag();
//	}

	CGUIW04MFCDoc() noexcept;
	DECLARE_DYNCREATE(CGUIW04MFCDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CGUIW04MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
