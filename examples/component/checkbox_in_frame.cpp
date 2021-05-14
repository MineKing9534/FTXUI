#include <memory>  // for __shared_ptr_access, allocator_traits<>::value_type, shared_ptr
#include <string>  // for operator+
#include <vector>  // for vector

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Checkbox, Renderer, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, operator|, size, border, frame, HEIGHT, LESS_THAN
#include "ftxui/screen/string.hpp"  // for to_wstring

using namespace ftxui;

struct CheckboxState {
  bool checked;
};

int main(int argc, const char* argv[]) {
  int size = 30;
  std::vector<CheckboxState> states(size);
  auto container = Container::Vertical({});
  for (int i = 0; i < size; ++i) {
    states[i].checked = false;
    container->Add(Checkbox(L"Checkbox" + to_wstring(i), &states[i].checked));
  }

  auto component = Renderer(container, [&] {
    return container->Render() | frame | ftxui::size(HEIGHT, LESS_THAN, 10) |
           border;
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(component);

  return 0;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
