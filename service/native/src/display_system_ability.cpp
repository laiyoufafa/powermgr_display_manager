/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "display_system_ability.h"
#include "display_common.h"

namespace OHOS {
namespace DisplayPowerMgr {
namespace {
REGISTER_SYSTEM_ABILITY_BY_ID(DisplaySystemAbility, DISPLAY_MANAGER_SERVICE_ID, true);
}
void DisplaySystemAbility::OnStart()
{
    DISPLAY_HILOGI(COMP_SVC, "Start service");
    if (!Publish(DelayedSpSingleton<DisplayPowerMgrService>::GetInstance())) {
        DISPLAY_HILOGE(COMP_SVC, "Failed to publish service");
    }
}

void DisplaySystemAbility::OnStop()
{
    DISPLAY_HILOGI(COMP_SVC, "Stop service");
}
}
}