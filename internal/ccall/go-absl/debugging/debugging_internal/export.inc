#ifndef ABSL_DEBUGGING_DEBUGGING_INTERNAL_EXPORT_H
#define ABSL_DEBUGGING_DEBUGGING_INTERNAL_EXPORT_H

#include "absl/debugging/internal/address_is_readable.h"
#include "absl/debugging/internal/elf_mem_image.h"
#include "absl/debugging/internal/vdso_support.h"

#include "absl/debugging/internal/address_is_readable.cc"
#include "absl/debugging/internal/elf_mem_image.cc"
#include "absl/debugging/internal/vdso_support.cc"

#if 0

namespace absl {
  namespace debugging_internal {
    bool AddressIsReadable(const void *addr) {
      return false;
    }
  }
}

#ifdef ABSL_HAVE_ELF_MEM_IMAGE

namespace absl {
  namespace debugging_internal {
    const int ElfMemImage::kInvalidBaseSentinel = 0;

    ElfMemImage::ElfMemImage(const void *base) {
    }

    int ElfMemImage::GetNumSymbols() const {
      return 0;
    }

    const ElfW(Sym) *ElfMemImage::GetDynsym(int index) const {
      return nullptr;
    }

    const ElfW(Versym) *ElfMemImage::GetVersym(int index) const {
      return nullptr;
    }

    const ElfW(Phdr) *ElfMemImage::GetPhdr(int index) const {
      return nullptr;
    }

    const char *ElfMemImage::GetDynstr(ElfW(Word) offset) const {
      return nullptr;
    }

    const void *ElfMemImage::GetSymAddr(const ElfW(Sym) *sym) const {
      return nullptr;
    }

    const ElfW(Verdef) *ElfMemImage::GetVerdef(int index) const {
      return nullptr;
    }

    const ElfW(Verdaux) *ElfMemImage::GetVerdefAux(
                                                   const ElfW(Verdef) *verdef) const {
      return nullptr;
    }

    const char *ElfMemImage::GetVerstr(ElfW(Word) offset) const {
      return nullptr;
    }

    void ElfMemImage::Init(const void *base) {
    }

    bool ElfMemImage::LookupSymbol(const char *name,
                                   const char *version,
                                   int type,
                                   SymbolInfo *info_out) const {
      return false;
    }

    bool ElfMemImage::LookupSymbolByAddress(const void *address,
                                            SymbolInfo *info_out) const {
      return false;
    }

    ElfMemImage::SymbolIterator::SymbolIterator(const void *const image, int index)
      : index_(index), image_(image) {
    }

    const ElfMemImage::SymbolInfo *ElfMemImage::SymbolIterator::operator->() const {
      return &info_;
    }

    const ElfMemImage::SymbolInfo& ElfMemImage::SymbolIterator::operator*() const {
      return info_;
    }

    bool ElfMemImage::SymbolIterator::operator==(const SymbolIterator &rhs) const {
      return false;
    }

    bool ElfMemImage::SymbolIterator::operator!=(const SymbolIterator &rhs) const {
      return false;
    }

    ElfMemImage::SymbolIterator &ElfMemImage::SymbolIterator::operator++() {
      return *this;
    }

    ElfMemImage::SymbolIterator ElfMemImage::begin() const {
      SymbolIterator it(this, 0);
      return it;
    }

    ElfMemImage::SymbolIterator ElfMemImage::end() const {
      return SymbolIterator(this, GetNumSymbols());
    }

    void ElfMemImage::SymbolIterator::Update(int increment) {
    }
  }
}

#endif

#ifdef ABSL_HAVE_VDSO_SUPPORT

namespace absl {
  namespace debugging_internal {
    std::atomic<const void *> VDSOSupport::vdso_base_(
                                                      debugging_internal::ElfMemImage::kInvalidBase);

    std::atomic<VDSOSupport::GetCpuFn> VDSOSupport::getcpu_fn_(&InitAndGetCPU);
    VDSOSupport::VDSOSupport()
      : image_(vdso_base_.load(std::memory_order_relaxed) ==
               debugging_internal::ElfMemImage::kInvalidBase
               ? Init()
               : vdso_base_.load(std::memory_order_relaxed)) {}

    const void *VDSOSupport::Init() {
      return nullptr;
    }

    const void *VDSOSupport::SetBase(const void *base) {
      return nullptr;
    }

    bool VDSOSupport::LookupSymbol(const char *name,
                                   const char *version,
                                   int type,
                                   SymbolInfo *info) const {
      return false;
    }

    bool VDSOSupport::LookupSymbolByAddress(const void *address,
                                            SymbolInfo *info_out) const {
      return false;
    }

    long VDSOSupport::GetCPUViaSyscall(unsigned *cpu, void *, void *) {
      return 0;
    }

    long VDSOSupport::InitAndGetCPU(unsigned *cpu, void *x, void *y) {
      return 0;
    }

    int GetCPU() {
      return 0;
    }
  }
}

#endif

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/errno_saver/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
