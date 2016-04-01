#pragma once

#define INL_BEGIN_MESSAGE_MAP(theClass, baseClass) \
	PTM_WARNING_DISABLE \
	virtual const AFX_MSGMAP* GetMessageMap() const \
				{ return GetThisMessageMap(); } \
	const AFX_MSGMAP* PASCAL GetThisMessageMap() const \
		{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
				{

#define INL_END_MESSAGE_MAP()					END_MESSAGE_MAP()
