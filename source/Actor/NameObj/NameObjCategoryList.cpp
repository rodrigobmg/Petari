#include "Actor/NameObj/NameObjCategoryList.h"

NameObjCategoryList::CategoryInfo::CategoryInfo()
{
    mArr.mContent = 0;
    mArr.mCount = 0;
    _8 = 0;
}

// todo -- finish
void NameObjCategoryList::initTable(u32 numEntries, const CategoryListInitialTable *pTable)
{
    CategoryInfo* cat = new CategoryInfo[numEntries];
    mCategoryInfo = cat;
    _4 = numEntries;

    while(cat != mCategoryInfo + _4)
    {
        cat->_C = 0;
        cat++;
    }

    while(pTable->mIndex != -1)
    {
        if (_D == 0)
        {

            _C = 1;
        }
    }

    return;
}

void NameObjCategoryList::incrementCheck(NameObj *pObj, s32 idx)
{
    mCategoryInfo[idx].mChecks++;
}

void NameObjCategoryList::add(NameObj *pObj, s32 idx)
{
    mCategoryInfo[idx]._8++;
    // some other array store
}