# fuzzer

My experiments with clang fuzzer.

## clang

    $ /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/clang++ -fsanitize=address,fuzzer -fno-omit-frame-pointer -g -v test_fuzzer.cpp -o test_fuzzer
    clang version 6.0.0 (tags/RELEASE_600/final)
    Target: x86_64-unknown-linux-gnu
    Thread model: posix
    InstalledDir: /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/bin
    Found candidate GCC installation: /usr/lib/gcc/i686-linux-gnu/5
    Found candidate GCC installation: /usr/lib/gcc/i686-linux-gnu/5.4.0
    Found candidate GCC installation: /usr/lib/gcc/i686-linux-gnu/6
    Found candidate GCC installation: /usr/lib/gcc/i686-linux-gnu/6.0.0
    Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/5
    Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/5.4.0
    Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/6
    Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/6.0.0
    Selected GCC installation: /usr/lib/gcc/x86_64-linux-gnu/5.4.0
    Candidate multilib: .;@m64
    Candidate multilib: 32;@m32
    Candidate multilib: x32;@mx32
    Selected multilib: .;@m64
    Found CUDA installation: /usr/local/cuda, version 8.0
    "/home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/clang-6.0" -cc1 -triple x86_64-unknown-linux-gnu -emit-obj -mrelax-all -disable-free -disable-llvm-verifier -discard-value-names -main-file-name test_fuzzer.cpp -mrelocation-model static -mthread-model posix -mdisable-fp-elim -fmath-errno -masm-verbose -mconstructor-aliases -munwind-tables -fuse-init-array -target-cpu x86-64 -dwarf-column-info -debug-info-kind=limited -dwarf-version=4 -debugger-tuning=gdb -v -resource-dir /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/backward -internal-isystem /usr/local/include -internal-isystem /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -fdeprecated-macro -fdebug-compilation-dir /home/proydakov/repository/fuzzer -ferror-limit 19 -fmessage-length 204 -fsanitize-coverage-type=1 -fsanitize-coverage-type=3 -fsanitize-coverage-indirect-calls -fsanitize-coverage-trace-cmp -fsanitize-coverage-inline-8bit-counters -fsanitize-coverage-pc-table -fsanitize-coverage-stack-depth -fsanitize=address,fuzzer,fuzzer-no-link -fsanitize-blacklist=/home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/asan_blacklist.txt -fsanitize-address-use-after-scope -fno-assume-sane-operator-new -fobjc-runtime=gcc -fcxx-exceptions -fexceptions -fdiagnostics-show-option -o /tmp/test_fuzzer-ad6fc8.o -x c++ test_fuzzer.cpp
    clang -cc1 version 6.0.0 based upon LLVM 6.0.0 default target x86_64-unknown-linux-gnu
    ignoring nonexistent directory "/include"
    ignoring duplicate directory "/usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0"
    #include "..." search starts here:
    #include <...> search starts here:
     /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0
     /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0
     /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/backward
     /usr/local/include
     /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/include
     /usr/include/x86_64-linux-gnu
     /usr/include
    End of search list.
     "/usr/bin/ld" -z relro --hash-style=gnu --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o test_fuzzer /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../x86_64-linux-gnu/crt1.o /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/5.4.0/crtbegin.o -L/usr/lib/gcc/x86_64-linux-gnu/5.4.0 -L/usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L/lib/../lib64 -L/usr/lib/x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../.. -L/home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/../lib -L/lib -L/usr/lib -whole-archive /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.fuzzer-x86_64.a -no-whole-archive -lstdc++ -whole-archive /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.a -no-whole-archive --dynamic-list=/home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.a.syms -whole-archive /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a -no-whole-archive --dynamic-list=/home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a.syms /tmp/test_fuzzer-ad6fc8.o -lstdc++ -lm --no-as-needed -lpthread -lrt -lm -ldl -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/5.4.0/crtend.o /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../x86_64-linux-gnu/crtn.o

## ulimit
    ulimit -v unlimited

## ldd

    $ ldd ./test_fuzzer
    linux-vdso.so.1 =>  (0x00007ffe6a5fc000)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007ff328acf000)
    libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007ff3287c6000)
    libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007ff3285a9000)
    librt.so.1 => /lib/x86_64-linux-gnu/librt.so.1 (0x00007ff3283a0000)
    libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007ff32819c000)
    libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007ff327f86000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007ff327bbb000)
    /lib64/ld-linux-x86-64.so.2 (0x000056464ecdf000)

## nm

    nm /home/proydakov/software/clang+llvm-6.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/clang/6.0.0/lib/linux/libclang_rt.fuzzer-x86_64.a | grep concurrency
                     U _ZNSt6thread20hardware_concurrencyEv

