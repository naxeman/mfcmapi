#pragma once
#include <core/smartview/SmartViewParser.h>
#include <core/smartview/EntryIdStruct.h>

namespace smartview
{
	struct FlatEntryID
	{
		blockT<DWORD> dwSize;
		EntryIdStruct lpEntryID;

		blockBytes padding;
	};

	class FlatEntryList : public SmartViewParser
	{
	private:
		void Parse() override;
		void ParseBlocks() override;

		blockT<DWORD> m_cEntries;
		blockT<DWORD> m_cbEntries;
		std::vector<FlatEntryID> m_pEntryIDs;
	};
} // namespace smartview