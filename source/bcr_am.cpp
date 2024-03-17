#include <algorithm>
using std::transform;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

#include "bcr_am.h"

namespace bcra {
// Instantiation of the global configuration variable.
const Cfg global_cfg;

auto str_lowercase = [](const char *t) -> std::string {
  std::string str{t};
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
};

BCRAnimation::BCRAnimation() {
  m_opt.input_filename = "";
  m_opt.fps = bcra::Cfg::default_fps;
  m_opt.n_bars = bcra::Cfg::default_bars;
}

/// Initializes the animation engine.
void BCRAnimation::initialize(int argc, char **argv) {
  // TODO: Process CLI here.

  // Set the initial animation state.
  m_animation_state = ani_state_e::START;
}
bool BCRAnimation::is_over() const {
  return m_animation_state == ani_state_e::END;
}

void BCRAnimation::process_events() {
  // TODO
}

void BCRAnimation::update() {
  // TODO
}

void BCRAnimation::render() const {
  // TODO
}
}; // namespace bcra
