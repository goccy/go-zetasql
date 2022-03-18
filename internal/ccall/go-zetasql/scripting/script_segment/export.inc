#ifndef ZETASQL_SCRIPTING_SCRIPT_SEGMENT_EXPORT_H
#define ZETASQL_SCRIPTING_SCRIPT_SEGMENT_EXPORT_H

#include "zetasql/scripting/script_segment.h"
#include "zetasql/scripting/script_segment.cc"

#if 0
namespace zetasql {

  ScriptSegment::ScriptSegment(absl::string_view script, const ASTNode* node)
    : script_(script), node_(node), range_(GetFullParseLocationRange(node)) {}

  ScriptSegment ScriptSegment::FromASTNode(absl::string_view script,
                                           const ASTNode* node) {
    return ScriptSegment(script, node);
  }

  absl::string_view ScriptSegment::GetSegmentText() const {
    absl::string_view v;
    return v;
  }

  std::ostream& operator<<(std::ostream& os, const ScriptSegment& segment) {
    return os;
  }

}
#endif

#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
