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

#ifndef DISPLAYMGR_SCREEN_ACTION_H
#define DISPLAYMGR_SCREEN_ACTION_H

#include <functional>
#include <memory>
#include <vector>

#include <display_device.h>

#include "display_power_info.h"

namespace OHOS {
namespace DisplayPowerMgr {
class ScreenAction {
public:
    ScreenAction();
    ~ScreenAction() = default;
    uint32_t GetDefaultDisplayId();
    std::vector<uint32_t> GetDisplayIds();
    DisplayState GetPowerState(uint32_t displayId);
    bool SetDisplayState(uint32_t displayId, DisplayState state, const std::function<void(DisplayState)> &callback);
    bool SetDisplayPower(uint32_t displayId, DisplayState state, uint32_t reason);
    uint32_t GetBrightness(uint32_t displayId);
    bool SetBrightness(uint32_t displayId, uint32_t value);

private:
    static constexpr uint32_t DEFAULT_DISPLAY_ID = 0;
    std::vector<uint32_t> displayIds_;
};
} // namespace DisplayPowerMgr
} // namespace OHOS
#endif // DISPLAYMGR_SCREEN_ACTION_H
