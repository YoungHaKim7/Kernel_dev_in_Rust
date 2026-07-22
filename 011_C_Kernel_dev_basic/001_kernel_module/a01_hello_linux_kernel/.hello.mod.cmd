savedcmd_hello.mod := printf '%s\n'   src/main.o | awk '!x[$$0]++ { print("./"$$0) }' > hello.mod
