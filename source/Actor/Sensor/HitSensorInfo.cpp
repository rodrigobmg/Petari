#include "Actor/Sensor/HitSensorInfo.h"

#include "Actor/LiveActor/LiveActor.h"
#include "Actor/Sensor/HitSensor.h"
#include "MR/actor/LiveActorUtil.h"

#include <revolution/mtx.h>

/*void HitSensorInfo::update()
{
    JGeometry::TVec3<f32> temp;

    if (!_20)
    {
        if (!_1C)
        {
            if (!_18)
            {
                temp.set(mSensor->mParentActor->mTranslation);
            }
            else
            {
                temp.set(_18->x, _18->y, _18->z);
            }
            
            Mtx* mtx = mSensor->mParentActor->getBaseMtx();

            if (!mtx)
            {

            }
            else
            {
                
            }
            
        }
        else
        {
            temp.set(_1C[3], _1C[6], _1C[9])
        }

        mSensor->_4.set(temp);
    }
}*/

void HitSensorInfo::doObjCol()
{
    u32 curSensor = 0;

    while (curSensor < mSensor->mNumSensors)
    {
        if (!MR::isDead(mSensor->mSensors[curSensor]->mParentActor))
        {
            mSensor->mParentActor->attackSensor(mSensor, mSensor->mSensors[curSensor]);
        }

        curSensor++;
    }
}