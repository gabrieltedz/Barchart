#ifndef BARCHART_H
#define BARCHART_H

/*!
 * Bar Char Race project.
 *
 * @author Selan
 * @data October 5th, 2020.
 */

#include <string>
using std::string;

#include <chrono>
#include <thread>

#include <utility>
#include <vector>
using std::vector;

#include "libs/text_color.h"

namespace bcra {
// The value type of a data item.
using value_t = long;

/// This class represents a single Bar Chart.
class BarChart {
  //=== Definition
public:
  /// Represents a single bar information.
  struct BarItem {
    string label;    //!< Bar label.
    value_t value;   //!< Bar value.
    string category; //!< Bar category.
    BarItem(string l, value_t v, string c)
        : label{std::move(l)}, value{v}, category{std::move(c)} { /*empty*/
    }
  };

  //== Public interface
  /// Default ctro.
  BarChart();
  /// Default dtro.
  ~BarChart() = default;
};

} // namespace bcra.
#endif
