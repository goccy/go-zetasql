#ifndef ZETASQL_SCRIPTING_CONTROL_FLOW_GRAPH_EXPORT_H
#define ZETASQL_SCRIPTING_CONTROL_FLOW_GRAPH_EXPORT_H

#include "zetasql/scripting/control_flow_graph.h"
#include "zetasql/scripting/control_flow_graph.cc"

#if 0
namespace zetasql {

  std::string ControlFlowEdgeKindString(ControlFlowEdge::Kind kind) {
    return "";
  }

  absl::StatusOr<std::unique_ptr<const ControlFlowGraph>>
  ControlFlowGraph::Create(const ASTScript* ast_script,
                           absl::string_view script_text) {
    std::unique_ptr<const ControlFlowGraph> v;
    return v;
  }

  ControlFlowGraph::ControlFlowGraph(const ASTScript* ast_script,
                                     absl::string_view script_text)
    : start_node_(nullptr),
      ast_script_(ast_script),
      script_text_(script_text) {}

  ControlFlowEdge::SideEffects ControlFlowEdge::ComputeSideEffects() const {
    SideEffects v;
    return v;
  }

  std::string ControlFlowEdge::DebugString() const {
    return "";
  }

  std::string ControlFlowNode::DebugString() const {
    return "";
  }

  std::string ControlFlowNode::SuccessorsDebugString(absl::string_view indent) const {
    return "";
  }

  std::vector<const ControlFlowNode*> ControlFlowGraph::GetAllNodes() const {
    std::vector<const ControlFlowNode*> v;
    return v;
  }

  std::string ControlFlowGraph::DebugString() const {
    return "";
  }

  const ControlFlowNode* ControlFlowGraph::GetControlFlowNode(const ASTNode* ast_node, ControlFlowNode::Kind kind) const {
    return nullptr;
  }

}
#endif

#include "go-zetasql/scripting/script_segment/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
