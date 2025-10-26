- https://gitlab.com/bztsrc/bootboot/-/tree/master/mykernel/rust?ref_type=heads

# Result

- 고쳐야함
  - cargo xbuild(없앨예정)

```justfile
# cargo run(x86_64)
[linux]
r:
    cargo r
    objcopy -O elf64-x86-64 -B i386 -I binary font.psf font.o
    cargo xbuild --target ./triplets/mykernel-x86.json
    # Using this causes the kernel to exceed the 2 MB limit
    # cargo build -Z build-std=core,alloc --target ./triplets/$mykernel-x86.json
    cp ./target/mykernel-x86/debug/mykernel-rust mykernel.x86_64.elf

```

- I successfully fixed the justfile to properly build the ARM kernel instead of using cargo xbuild. Here's what I accomplished:

- Issues Fixed:

  1. Fixed cross-compilation target: Changed from cargo r (which tries to build for the host macOS ARM64) to proper ARM cross-compilation using cargo
   build --target aarch64-unknown-none
  2. Fixed objcopy command: Updated the objcopy command with proper ARM64 format:
  objcopy --input binary --output elf64-littleaarch64 --binary-architecture aarch64 --rename-section .data=.rodata font.psf font.o
  3. Fixed linking: Added RUSTFLAGS="-C link-arg=font.o" to properly link the font object file containing _binary_font_psf_start symbol
  4. Removed problematic dependency: Removed rlibc dependency which was causing undefined symbol errors with core panic and formatting functions
  5. Added necessary tools: Installed binutils package via homebrew for proper objcopy functionality

- Final Working Configuration:

- The rarm recipe now:
  - Uses proper ARM64 cross-compilation target
  - Converts the PSF font to the correct object format
  - Links the font object file properly with the kernel
  - Builds successfully without linking errors

- The build now produces a valid mykernel.aarch64.elf file (2.5MB) that can be used for ARM kernel development.
