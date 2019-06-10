
#pragma once

#include "cimgui.h"
#include "imgui.h"


CIMGUI_API void igSetMousePosForIO_nonUDT2(ImVec2_Simple pos)
{
    ImGuiIO *io = &ImGui::GetIO();
    io->MousePos = ImVec2(pos.x, pos.y);
}

CIMGUI_API void igSetMouseState(ImVec2_Simple pos, bool button_0, bool button_1, bool button_2, float mouseWheel)
{
    ImGuiIO *io = &ImGui::GetIO();
    io->MouseDown[0] = button_0;
    io->MouseDown[1] = button_1;
    io->MouseDown[2] = button_2;
    io->MousePos = ImVec2(pos.x, pos.y);
    io->MouseWheel = mouseWheel;
}

CIMGUI_API float igGetDisplayWidth()
{
    ImGuiIO *io = &ImGui::GetIO();
    return io->DisplaySize.x;
}

CIMGUI_API float igGetDisplayHeight()
{
    ImGuiIO *io = &ImGui::GetIO();
    return io->DisplaySize.y;
}

CIMGUI_API float igGetFramerate()
{
    ImGuiIO *io = &ImGui::GetIO();
    return io->Framerate;
}

CIMGUI_API void igSetDisplayState(float width, float height, float scale, float deltaSeconds) 
{
    ImGuiIO *io = &ImGui::GetIO();
    io->DisplaySize.x = width;
    io->DisplaySize.y = height;
    io->DisplayFramebufferScale.x = scale;
    io->DisplayFramebufferScale.y = scale;
    io->DeltaTime = deltaSeconds;
    io->MouseDrawCursor = false;
}

CIMGUI_API void igSetKeyboardState(bool shiftKey, bool ctrlKey, bool altKey, bool superKey) 
{
    ImGuiIO *io = &ImGui::GetIO();
    io->KeyShift = shiftKey;
    io->KeyCtrl = ctrlKey;
    io->KeyAlt = altKey;
    io->KeySuper = superKey;
}

CIMGUI_API void igSetKeyMapKey(int imGuiKey, int userKey)
{
    ImGuiIO *io = &ImGui::GetIO();
    io->KeyMap[imGuiKey] = userKey;
}

CIMGUI_API void igSetKeyDownState(int userKey, bool isDown)
{
    ImGuiIO *io = &ImGui::GetIO();
    io->KeysDown[userKey] = isDown;
}

CIMGUI_API float igGetMouseWheel()
{
    ImGuiIO *io = &ImGui::GetIO();
    return io->MouseWheel;
}

CIMGUI_API int igGetModifierKeys()
{
    ImGuiIO *io = &ImGui::GetIO();
    int result = 0;
    result |= io->KeyShift ? 1 : 0;
    result |= io->KeyCtrl ? 2 : 0;
    result |= io->KeyAlt ? 4 : 0;
    result |= io->KeySuper ? 8 : 0;
    return result;
}

CIMGUI_API ImVec2_Simple igGetDisplayFramebufferScale_nonUDT2()
{
    ImGuiIO *io = &ImGui::GetIO();
    return ImVec2ToSimple(io->DisplayFramebufferScale);
}

CIMGUI_API ImVec2_Simple igGetMouseDelta_nonUDT2()
{
    ImGuiIO *io = &ImGui::GetIO();
    return ImVec2ToSimple(io->MouseDelta);
}

static inline ImVec2 SimpleToImVec2(ImVec2_Simple v) 
{
    return ImVec2(v.x, v.y);
}

CIMGUI_API void igAddConvexPolyFilled(ImDrawList* drawList,
    ImVec2_Simple v0, ImVec2_Simple v1, ImVec2_Simple v2, ImVec2_Simple v3, ImVec2_Simple v4,
    ImU32 col)
{
    ImVec2 points[] = { SimpleToImVec2(v0), SimpleToImVec2(v1), SimpleToImVec2(v2), SimpleToImVec2(v3), SimpleToImVec2(v4) };
    drawList->AddConvexPolyFilled(points, 5, col);
}