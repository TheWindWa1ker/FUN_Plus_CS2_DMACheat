#pragma once
#include "imgui.h"



namespace colors {

    inline ImVec4 general_color = ImColor(195, 105, 48, 255); // 一般颜色
    inline ImVec4 main_color = ImColor(16, 16, 16, 255);      // 主色调
    inline ImVec4 lite_color = ImColor(20, 20, 20, 255);      // 亮色调
    inline ImVec4 gray_color = ImColor(43, 43, 43, 255);      // 灰色
    inline ImVec4 Tab_Child = ImColor(15, 15, 15, 255);       // 子标签颜色
    inline ImVec4 Tab_Border = ImColor(26, 26, 26, 255);      // 标签边框颜色

    inline ImVec4 Tab_Selected = ImColor(223, 99, 25, 255);   // 选中标签颜色
    inline ImVec4 Tab_Hovered = ImColor(130, 130, 130, 255);  // 悬停标签颜色
    inline ImVec4 Tab = ImColor(80, 80, 80, 255);             // 标签颜色

    inline ImVec4 Checkbox = ImColor(14, 14, 14, 255);        // 复选框颜色
    inline ImVec4 Checkbox_Hovered = ImColor(12, 12, 12, 255);// 悬停复选框颜色
    inline ImVec4 Checkbox_Active = ImColor(218, 96, 21, 255);// 激活复选框颜色

    inline ImVec4 Car_Slider = ImColor(221, 97, 23, 255);     // 滑块颜色
    inline ImVec4 Car_Slider_Hovered = ImColor(223, 99, 25, 255); // 悬停滑块颜色
    inline ImVec4 Car_Slider_Active = ImColor(223, 99, 25, 255);  // 激活滑块颜色

    inline ImVec4 Slider = ImColor(16, 16, 16, 255);          // 普通滑块颜色
    inline ImVec4 Slider_Hovered = ImColor(18, 18, 18, 255);  // 悬停滑块颜色
    inline ImVec4 Slider_Active = ImColor(18, 18, 18, 255);   // 激活滑块颜色

    inline ImVec4 Circle_Slider = ImColor(255, 255, 255, 255);// 圆形滑块颜色
    inline ImVec4 Circle_SliderHovered = ImColor(255, 255, 255, 255); // 悬停圆形滑块颜色
    inline ImVec4 Circle_SliderActive = ImColor(255, 255, 255, 255);  // 激活圆形滑块颜色

    inline ImVec4 Combo = ImColor(26, 26, 26, 255);           // 下拉框颜色
    inline ImVec4 Combo_Hovered = ImColor(26, 26, 26, 255);   // 悬停下拉框颜色
    inline ImVec4 Combo_Active = ImColor(26, 26, 26, 255);    // 激活下拉框颜色

    inline ImVec4 InputText = ImColor(16, 16, 16, 255);       // 输入框颜色
    inline ImVec4 InputText_Hovered = ImColor(18, 18, 18, 255);// 悬停输入框颜色
    inline ImVec4 InputText_Active = ImColor(18, 18, 18, 255);// 激活输入框颜色

    inline ImVec4 Button = ImColor(26, 26, 26, 255);          // 按钮颜色
    inline ImVec4 Button_Hovered = ImColor(30, 30, 30, 255);  // 悬停按钮颜色
    inline ImVec4 Button_Active = ImColor(33, 33, 33, 255);   // 激活按钮颜色

    inline ImVec4 Selectable_Hovered = ImColor(150, 150, 150, 255); // 悬停可选项颜色
    inline ImVec4 Selectable_Active = ImColor(250, 250, 250, 255);  // 激活可选项颜色

    inline ImVec4 Picker_Active = ImColor(20, 20, 20, 255);    // 颜色选择器激活颜色

    inline ImVec4 Text = ImColor(71, 71, 71, 255);             // 文本颜色
    inline ImVec4 Text_Hovered = ImColor(200, 200, 200, 255);  // 悬停文本颜色
    inline ImVec4 Text_Active = ImColor(235, 245, 255, 255);   // 激活文本颜色

    inline ImVec4 CheckMark = ImColor(255, 255, 255, 255);     // 复选框勾选标记颜色

    inline ImVec4 Transparent = ImColor(0, 0, 0, 0);           // 透明颜色

    inline ImVec4 tab_tooltip = ImColor(180, 180, 180, 255);   // 标签提示颜色

    inline ImVec4 keybind_background = ImColor(17, 17, 17, 255); // 按键绑定背景颜色
    inline ImVec4 keybind_border = ImColor(28, 28, 28, 255);   // 按键绑定边框颜色
}