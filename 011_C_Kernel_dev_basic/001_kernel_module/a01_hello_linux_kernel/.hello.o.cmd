savedcmd_hello.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o hello.o @hello.mod  ; /usr/src/linux-7.1.3-1-obj/x86_64/default/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --orc --retpoline --rethunk --sls --static-call --uaccess --prefix=16  --link  --module hello.o

hello.o: $(wildcard /usr/src/linux-7.1.3-1-obj/x86_64/default/tools/objtool/objtool)
