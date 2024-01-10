//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "zetasql/public/types/internal_utils.h"

#include <cstdint>
#include <limits>
#include <memory>
#include <optional>
#include <set>

#include "zetasql/base/logging.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/descriptor.h"
#include "zetasql/common/proto_helper.h"
#include "zetasql/public/types/type.h"
#include "absl/memory/memory.h"
#include "absl/status/status.h"
#include "zetasql/base/ret_check.h"
#include "zetasql/base/status_macros.h"

namespace zetasql {
namespace internal {

int64_t FileDescriptorSetMapTotalSize(
    const FileDescriptorSetMap& file_descriptor_set_map) {
  int64_t total_size = 0;
  for (const auto& entry : file_descriptor_set_map) {
    total_size += entry.second->file_descriptor_set.ByteSizeLong();
  }
  return total_size;
}

absl::Status PopulateDistinctFileDescriptorSets(
    const BuildFileDescriptorMapOptions& options,
    const google::protobuf::FileDescriptor* file_descr,
    FileDescriptorSetMap* file_descriptor_set_map,
    int* file_descriptor_set_index) {
  ZETASQL_RET_CHECK(file_descr != nullptr);
  ZETASQL_RET_CHECK(file_descriptor_set_map != nullptr);

  std::unique_ptr<Type::FileDescriptorEntry>& file_descriptor_entry =
      (*file_descriptor_set_map)[file_descr->pool()];
  if (file_descriptor_entry == nullptr) {
    // This is a new entry in the map.
    file_descriptor_entry = absl::make_unique<Type::FileDescriptorEntry>();
    ZETASQL_CHECK(file_descriptor_set_map->size() <
          std::numeric_limits<decltype(
              file_descriptor_entry->descriptor_set_index)>::max());
    file_descriptor_entry->descriptor_set_index =
        static_cast<decltype(file_descriptor_entry->descriptor_set_index)>(
            file_descriptor_set_map->size() - 1);
  }
  absl::optional<int64_t> this_file_descriptor_set_max_size;
  if (options.file_descriptor_sets_max_size_bytes.has_value()) {
    const int64_t map_total_size =
        FileDescriptorSetMapTotalSize(*file_descriptor_set_map);
    this_file_descriptor_set_max_size =
        options.file_descriptor_sets_max_size_bytes.value() - map_total_size +
        file_descriptor_entry->file_descriptor_set.ByteSizeLong();
  }
  if (options.build_file_descriptor_sets) {
    ZETASQL_RETURN_IF_ERROR(
        PopulateFileDescriptorSet(file_descr, this_file_descriptor_set_max_size,
                                  &file_descriptor_entry->file_descriptor_set,
                                  &file_descriptor_entry->file_descriptors));
  } else {
    file_descriptor_entry->file_descriptors.insert(file_descr);
  }
  *file_descriptor_set_index = file_descriptor_entry->descriptor_set_index;
  return absl::OkStatus();
}

}  // namespace internal
}  // namespace zetasql
