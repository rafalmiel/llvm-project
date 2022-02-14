#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CYKUSZ_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CYKUSZ_H

#include "Gnu.h"
#include "Clang.h"
#include "clang/Driver/ToolChain.h"

namespace clang {
namespace driver {
namespace toolchains {

class LLVM_LIBRARY_VISIBILITY Cykusz : public Generic_ELF {
public:
  Cykusz(const Driver &D, const llvm::Triple &Triple,
         const llvm::opt::ArgList &Args);

  bool HasNativeLLVMSupport() const override;

  void
  AddClangSystemIncludeArgs(const llvm::opt::ArgList &DriverArgs,
                            llvm::opt::ArgStringList &CC1Args) const override;
  void addLibStdCxxIncludePaths(
      const llvm::opt::ArgList &DriverArgs,
      llvm::opt::ArgStringList &CC1Args) const override;
  SanitizerMask getSupportedSanitizers() const override;
  virtual std::string computeSysRoot() const override;

  virtual std::string getDynamicLinker(const llvm::opt::ArgList &Args) const override;

  const char *getDefaultLinker() const override;

  std::vector<std::string> ExtraOpts;

protected:
  Tool *buildAssembler() const override;
  Tool *buildLinker() const override;
};

} // end namespace toolchains
} // end namespace driver
} // end namespace clang

#endif
