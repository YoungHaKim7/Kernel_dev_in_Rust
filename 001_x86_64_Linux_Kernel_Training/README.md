# link

- [리눅스 커널을 만들기 위해 마스터 해야 3권의 책 How to do Linux Kernel dev.](#howto-do-linux-kernel-development)

- [A PROGRAM is not a PROCESS. | Core Dumped](https://youtu.be/7ge7u5VUSbE)

- Rust로 컴파일러 만들기 시리즈
  - [Sketching It Out - Rust Clipper Compiler (EP.1) | CoderSauce](https://youtu.be/K7UGL1HyFJQ?si=brGkCDa2TpDMbIfP)
  - [240916_Bridging the Gap to Assembly - Rust Clipper Compiler (EP.2)CoderSauce](https://youtu.be/9_fDhaKUMbU?si=5jPdTgeivkvHPx10)
  - [Handcrafting Some Assembly in Rust - Clipper Compiler (EP.3)](https://youtu.be/4xSNH3Ql2Jk?si=la2IV_kw_qn-mkG-)
  - [Teaching my Compiler to Talk to Others - Rust Clipper Compiler (EP.4)](https://youtu.be/-rxm58qu7Rc)
  - [Expanding The Tree - Rust Clipper Compiler (EP.5) | CoderSauce](https://youtu.be/mS51V_L9Jz8?si=gzCTvgzpNfK6Oi_P)

- 유료 링크(리눅스 커널 난중에 결제해서 보자 넘 좋다.)
  - [리눅스 커널 난중에 결제해서 보자 넘 좋다.](#유료-콘텐츠난중에-결제해서-보자)

- [외부링크) PopOS러스트 iced(GUI)(Alpha release of PopOS's Cosmic desktop environment, written in Rust and based on Iced )](https://www.reddit.com/r/rust/comments/1f38xni/alpha_release_of_poposs_cosmic_desktop/?rdt=55213)

- 유튜브 영상 모음
  - Arm
    - [240205 유료강의소개 (인프런-로드맵 |'Arm 아키텍처의 구조와 원리 저자 직강 강의'- 모두 업로드 완료! | Austin Kim](https://m.youtube.com/watch?si=DAzymb8g8F7JhQC0&v=9kOdb7w_PCU&feature=youtu.be)
  - [리눅스 커널의 존재 이유_간단히 설명 굿](https://youtube.com/shorts/ivyPFMZg4KI?si=4Qwqgt42CYHmC10s)
  - [(240806) Operating Systems Course for Beginners | freeCodeCamp.org](https://youtu.be/yK1uBHPdp30?si=aGUK8RRxTdXu1A-9)
  - [(210108) System Design Course for beginners | Geek's Lesson](https://youtu.be/MbjObHmDbZo?si=SwE1oWai_aaJZaN5)
  - [(250325) System Design was HARD until I Learned these 30 Concepts | Ashish Pratap Singh](https://youtu.be/s9Qh9fWeOAk?si=uNOk8J2o7eFDMAO8)
  - RISC-V 아키텍처
    - [RISC-V영상 모아보기 | Austin Kim](https://youtube.com/playlist?list=PLRrUisvYoUw_4ES8R-H7lgjsqjZeKhI9W&si=nf6j59Z1IBzUai2d)
  - 리눅스 커널의 구조와 원리
    - Armv8-A
      - [영상모아 보기) 리눅스 커널의 구조와 원리 1부(v6.1, Armv8-A 기반) | Austin Kim](https://youtube.com/playlist?list=PLRrUisvYoUw_bFoK0ahLy9MHfBgBZJyz4&si=WmveEC7wLZ9ZK0nP)
  - dr Jonas Birch시리즈
    - [외부영상 (251003)Project: Coding a GRUB bootloader for booting Linux | dr Jonas Birch](https://www.youtube.com/watch?v=ukIajayMv5U&t=153s)


- 용어정리
  - [DPL개념이해](#dpl개념이해)
  - [Programs Call이해](#programs-call이해)
  - [시스템 콜 주요 개념](#시스템-콜-주요-개념)
  - [Effective Address란? 선형주소](#effective-address란-선형주소)
  - [컴퓨터 구조 | Instruction Sets](#컴퓨터-구조-instruction-sets)
  - [Addressing mode](#addressing-mode)

- 실습(해보면서 익히자)
  - [(외부링크) GDB로 리눅스 커널 디버깅 하기 | Posted Jun 25, 2024](https://gee6809.github.io/posts/debug_kernel/)
  - [(외부링크) QEMU Network 설정 방법 (가상머신끼리 통신하기) | Posted May 16, 2024](https://gee6809.github.io/posts/qemu-network/)
  - [(외부링크) QEMU UEFI 환경으로 부팅하기 (OVMF) | Posted May 23, 2024](https://gee6809.github.io/posts/ovmf/)

<hr />

<hr />

# Quick Start) kernel development in Rust.
This document describes how to get started with kernel development in Rust.
- https://docs.kernel.org/rust/quick-start.html
- https://rust.docs.kernel.org/kernel/index.html
  - https://github.com/Rust-for-Linux/linux/

  - https://rust-for-linux.com/

# Linux 오리지날 문서
- https://www.kernel.org/doc/html/latest/

# fork 해서 미친듯이 분석해보자
- https://github.com/YoungHaKim7/linux

# 알고리즘 및 OS & 네트워크 다정리중..
- https://github.com/YoungHaKim7/Algorithm_Training

# Rust OSDev(Operating System Development in Rust)
- https://rust-osdev.com/

<hr />

# HOWTO do Linux kernel development
- https://www.kernel.org/doc/html/latest/process/howto.html
- 리눅스 커널을 만들기 위해선 이 3가지 책은 필수 마스터
  - “The C Programming Language” by Kernighan and Ritchie [Prentice Hall]
  - “Practical C Programming” by Steve Oualline [O’Reilly]
  - “C: A Reference Manual” by Harbison and Steele [Prentice Hall]



# 유료 콘텐츠(난중에 결제해서 보자)[|🔝|](#link)

# (유료 콘텐츠)Tracking trust with Rust in the kernel[|🔝|](#link)
- https://lwn.net/SubscriberLink/1034603/5dcfecdd5e3af0c2/

# Kernel 요약
- How to write Rust in the kernel [Posted June 20, 2025 by daroc][|🔝|](#link)
- This page collects entries in our mini series on how to write Rust code in the Linux kernel.
  - Part 1: details on how to build, test, lint, and format Rust code.
  - Part 2: a close comparison of a PHY driver in Rust and in C.
  - Part 3: a look at the most common bindings Rust drivers will need to use.
- https://lwn.net/Articles/1024941/

# How to write Rust in the kernel: part 1[|🔝|](#link)
[LWN subscriber-only content]
- https://lwn.net/SubscriberLink/1024202/556fa7b3c51d7899/

# How to write Rust in the kernel: part 2
- https://lwn.net/Articles/1025232/

# How to write Rust in the kernel: part 3
- https://lwn.net/Articles/1026694/

# 커널에서 에러 핸들링 하는방법(Rust)Best practices for error handling in kernel Rust[|🔝|](#link)
- https://lwn.net/Articles/990489/



<hr />

<hr />

<hr />

# Summit-AST translates parsed Apex source code into an abstract syntax tree[|🔝|](#link)
- https://github.com/google/summit-ast

# **[매우 빠른 Lexer 구현 전략](<https://news.hada.io/topic?id=22140&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- **purple-garden 언어**를 위해 **초고속 Lexer**를 직접 설계·구현한 전략과 실측 성능 데이터 공유  
- **Threaded Lexing(점프 테이블 기반)**, **0복사·윈도우 문자열**, **인터닝**, **bump allocator** 등 다양한 **최적화 기법** 적용  
- **토큰 해싱**·** 키워드 사전 해시 비교**를 통해 파싱 속도 극대화, …

<hr />

# 시스템 프로그래밍 개요[|🔝|](#link)
- https://youtube.com/playlist?list=PLBrGAFAIyf5pIIFQv_U1dG36L5rylTvbx&si=TvM_LyiU9SnDWDzG

# 10분 만에 설명하는 7가지 시스템 설계 개념[|🔝|](#link)
ByteByteGo
- https://youtu.be/Qd9tJ3H_hPE?si=H0rbqnS-sYmnI56M

<hr />

# The source for the Linux kernel used in Windows Subsystem for Linux 2 (WSL2)[|🔝|](#link)
- https://github.com/microsoft/WSL2-Linux-Kernel

# How Does Linux Boot Process Work?[|🔝|](#link)
ByteByteGo
- https://youtu.be/XpFsMB6FoOs?si=giAQss9aqtz40Zp7

# 리눅스 커널 분석[|🔝|](#link)
- https://youtu.be/GN3HezzYW8Y?si=GFWwchqYrNw2BbPL

# 리눅스 커널 4Kbytes알뜰하게 설명[|🔝|](#link)
-  Linux Kernel 6.11 | Drama and 15X Part 1
Maple Circuit
  - https://youtu.be/NPJ7DzdysE4?si=oqkQdZww0zCpOwMG

# (2019년에만든거 _영상모아보기)Operating Systems | Computer Science Lessons[|🔝|](#link)
- This is a selection of videos about operating systems including memory management and virtual memory, processor addressing modes, process scheduling, an the role of the call stack.
  - https://youtube.com/playlist?list=PLTd6ceoshprdCI72yuKI_VexnJygy-34e&si=pLToMQ5VCA4s23LO

<hr />

# Crafting executables from raw bytes | Kay Lack[|🔝|](#link)
- https://youtu.be/cX5tQJhuNeY?si=6lO7UaboaJ6cXpzk

# Device Manager & Error Code[|🔝|](#link)
 Device Manager is a component of the Microsoft Windows operating system. 
- https://en.wikipedia.org/wiki/Device_Manager

# 다양한 커널의 종류[|🔝|](#link)
- https://en.wikipedia.org/wiki/Comparison_of_operating_system_kernels

# **[좋은 시스템 설계](<https://news.hada.io/topic?id=22580&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- **좋은 시스템 설계**란 복잡해 보이지 않고 오랜 기간 별다른 문제가 발생하지 않는 형태  
- **상태(state)** 를 다루는 것이 시스템 설계에서 가장 어려운 부분이며, 가능한 한 상태를 저장하는 컴포넌트 수를 줄이는 방향이 중요  
- 데이터베이스는 주로 상태가 보관되는 위치로, **스키마 설계와 인덱싱**, 병목…

# **[리눅스 파이프는 실제로 얼마나 빠를까?](<https://news.hada.io/topic?id=21623&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- **Linux에서 구현된 Unix 파이프의 성능**을 점진적 최적화를 통해 분석함  
- 최초 **간단한 파이프 프로그램의 대역폭**은 약 3.5GiB/s로 측정되며, 프로파일링과 시스템콜 변경을 통해 이를 20배 이상 향상하는 과정을 다룸  
- **vmsplice, splice 같은 Zero-Copy 시스템콜**을 활용해 불필요한 데이터 복사를 줄이…

# **[Asterinas - 새로운 Linux-호환 커널 프로젝트](<https://news.hada.io/topic?id=21594&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Rust로 작성된 **Linux ABI 호환 커널**로, “**프레임커널(framekernel)**” 아키텍처를 적용해 **모놀리식과 마이크로커널의 장점을 결합**하고자 함  
- 모든 unsafe 코드를 한정된 라이브러리 내부에 캡슐화하여, 나머지 커널 서비스는 안전한 Rust 추상화로 개발 가능하게 설계해 **메모리 안전성과 단순한 공유 메…

# **[GN⁺: Asterinas - Rust로 작성된 Linux 호환 ABI 제공 OS 커널](<https://news.hada.io/topic?id=17283&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Asterinas는 _안전성_, _속도_, _범용성_ 을 갖춘 OS 커널로, _Linux 호환_ ABI를 제공  
- Linux를 대체할 수 있으며, _메모리 안전성_ 과 _개발자 친화성_ 을 향상시킴  
  - Rust를 유일한 프로그래밍 언어로 사용하고, _unsafe Rust_ 의 사용을 최소화하여 명확히 정의된 신뢰 컴퓨팅 기반(TCB)으로 제한함으로써...

# OSle - 부트 섹터에 들어가는 510바이트 짜리 초소형 OS (shikaan.github.io)[|🔝|](#link)
13P by xguru 2일전 | ★ favorite | 댓글 1개
510 바이트안에 쉘, 파일 시스템, 프로세스 관리 기능을 담은 x86 어셈블리 기반 부트섹터 운영체제
- https://news.hada.io/topic?id=20683

# **[Hyperlight WASM: 빠르고, 안전하고 OS-Free](<https://news.hada.io/topic?id=20219&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Hyperlight Wasm은 Microsoft가 CNCF에 기부한 **초경량 가상 머신(VM)** 기술 Hyperlight의 최신 확장 버전으로, **WebAssembly(Component Model 기반)** 워크로드를 빠르고 안전하게 실행함  
- 전통적인 VM과 달리 OS나 가상 디바이스 없이 **메모리 슬라이스와 CPU만 노출**, 1~2ms의 빠른 부팅 시간 제공  
- 다양…  

# 리눅스 시스템 설계 | jihunback[|🔝|](#link)
- https://youtu.be/96FVy_h4VY8?si=WlnKdYFdVmR35hNY

# (241119)Miguel Ojeda (Rust for Linux): KEYNOTE | RustConf 2024 | Rust Foundation[|🔝|](#link)
- https://youtu.be/FRMJzNYut4g?si=0QYe24x2wmCpv6Wn

# OS코딩을 한다는건 코딩의 정점에 서 있는거다. 나머지 코딩은 OS코딩의 열화판 ㅋㅋ[|🔝|](#link)
-  [인터뷰#2] 리눅스 커널 배우려면 얼마나 걸려요? | [오제이 튜브]OJ Tube
  - https://youtu.be/N7rk_qDivVQ?si=xDXNrAlSPpKyDa-l

# 러스트로 인터프리터 만들며 컴파일러 만들기 기초 잡기[|🔝|](#link)
- https://github.com/Polanas/monkey_interpreter

# (250210) Rewriting the future of the Linux essential packages in rust | Sylvestre Ledru[|🔝|](#link)
- https://youtu.be/cXf31nFPo0U?si=Zxs6YQCZDIa1lMFX

# (구글 개발자 250226)Rust project goals 2024: Stabilizing Rust in the Linux Kernel - Alice Ryhl | Rust Nation UK[|🔝|](#link)
- https://youtu.be/J2M3EGUgq0c?si=PvQPW2asgIrf2dXC

# **[GN⁺: 1,000줄로 운영체제 구현하기](<https://news.hada.io/topic?id=18639&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- 이 책은 작은 운영체제를 처음부터 단계별로 구축하는 방법을 설명함  
- 운영체제(OS)나 커널 개발이라는 말에 겁먹을 수 있지만, OS의 기본 기능(특히 커널)은 놀랍도록 간단함  
- Linux도 처음에는 8,413줄의 코드로 시작했으며, 오늘날의 Linux 커널은 매우 크지만, 취미 프로젝트처럼 작은 코드베이스로 시작했...

# Watch Linux kernel developer write a USB driver from scratch in just 3h for Apple Xserve front-panel[|🔝|](#link)
Bits inside by René Rebe
- https://youtu.be/IXBC85SGC0Q?si=QKO2Ndz-zc20uWiq

# **[gccrs: Rust를 위한 대체 컴파일러](<https://news.hada.io/topic?id=17681&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- `gccrs`는 GCC 프로젝트의 일환으로 개발 중인 대체 Rust 컴파일러입니다.  
- 이 프로젝트는 GNU 컴파일러 컬렉션 내에서 Rust를 지원하는 것을 목표로 하며, `rustc`와 동일한 동작을 목표로 합니다.  
- 주요 목표는 특히 LLVM이 지원하지 않는 플랫폼에서 Rust를 컴파일할 수 있는 대안을 제공하는 것입니다.  
...

# uutils/coreutils[|🔝|](#link)
Cross-platform Rust rewrite of the GNU coreutils
- https://github.com/uutils/coreutils

# 2024 LLVM Developers' Meeting - Rust ❤️ LLVM[|🔝|](#link)
- https://youtu.be/Kqz-umsAnk8?si=NLogEP1h-CXUSXPy

# kata-containers/kata-containers[|🔝|](#link)
- Kata Containers is an open source project and community working to build a standard implementation of lightweight Virtual Machines (VMs) that feel and perform like containers, but provide the workload isolation and security advantages of VMs. 
- https://katacontainers.io/

# **[Bazel: 언제 사용해야 할까? (2023)](<https://news.hada.io/topic?id=18232&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Bazel은 Google이 대규모 모노레포를 효율적으로 빌드하기 위해 개발한 오픈 소스 빌드 시스템  
- 복잡한 프로젝트를 정확하고 빠르게 빌드하며, 특히 대규모 코드베이스와 다중 언어 종속성을 다룰 때 효과적  
- Bazel의 핵심 개념  
  - **정확성 기반의 속도**: Bazel은 빌드를 순수 함수로 간주, 동일한 입력...

# **[흔한 컴파일러 오해들](<https://news.hada.io/topic?id=18194&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
### 컴파일러 최적화에 대한 오해  
  
* **최적화는 최적의 프로그램을 제공한다?**   
    * 컴파일러는 최적의 프로그램을 생성하는 것이 아니라, 단순화된 프로그램을 개선하는 것을 목표로 합니다.  
    * 코드 크기 최적화는 가능성이 있지만, 실행 시간 최적화는 측정의 어려움, 최적 부분 구조의 부재, 하드...

# **[Rust 기반 Redox OS, RISC-V 지원 및 Raspberry Pi 4에서 부팅 가능해짐](<https://news.hada.io/topic?id=17622&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Redox OS는 Rust로 작성된 오픈 소스 운영 체제 프로젝트  
- RISC-V가 이제 Redox OS의 지원 대상이 됨. QEMU 에뮬레이터에서 데스크톱과 함께 Redox OS를 실행할 수 있는 수준에 이름  
- Raspberry Pi 4에서 Redox OS가 부팅됨. 로그인 화면까지는 진입하지만 USB 지원 등 다른 기능은 아직 완성되지 않음  
- R...

# Systems Software for Linux with Rust – Interview with Zeeshan Ali Khan[|🔝|](#link)
 | timClicks
- https://youtu.be/atE94jvfVuA?si=7BgYxVChN5hq7_Hn

<hr />

# 중국 안드로이드 버리고 전환 성공한 HarmonyOS NEXT(241023)[|🔝|](#link)

- [241023_GN⁺: 화웨이, HarmonyOS NEXT 출시로 안드로이드와 공식 결별 (theregister.com)](https://news.hada.io/topic?id=17399)

- HarmonyOS NEXT (Chinese: 鸿蒙星河版; pinyin: Hóngméng Xīnghébǎn)
is a proprietary distributed operating system and a major iteration of HarmonyOS, developed by Huawei to support only HarmonyOS native apps.
  - https://en.m.wikipedia.org/wiki/HarmonyOS_NEXT

- HarmonyOS 최근 수정 시각: 2025-03-09 03:51:12
  - https://namu.wiki/w/HarmonyOS

<hr />



# **[GN⁺: Windows NT vs. Unix: 설계 비교](<https://news.hada.io/topic?id=16692&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- https://news.hada.io/topic?id=16692&utm_source=discord&utm_medium=bot&utm_campaign=1480
- NT는 종종 "매우 진보된" 운영 체제로 평가받았지만 그 이유를 잘 몰랐음  
  - 2023년 말, 'Inside Windows NT' 1판을 읽고 NT와 Unix를 비교하기로 함  
  - NT(1993년 7월)와 당시 Unix 시스템(4.4BSD, 리눅스 1.0)의 설계를 비교한 것임  
  - Unix 전문가로서 NT는 잘 모르기에 NT의 차이점 위주로 서술함  
...

<hr>


# (컴파일러 만드는 책으로 유명한거 하네 굿)Implementing a Lox interpreter in Rust | Jon Gjengset[|🔝|](#link)
- https://youtu.be/mNOLaw-_Buc?si=U80ttpOVb_xGVcWK

<hr>

# OS기본 개념잡기[|🔝|](#link)
- 모아보기 1 ( 1.2 OPERATING SYSTEM (Complete Playlist) | KnowledgeGATE by Sanchit Sir)
  - https://youtube.com/playlist?list=PLmXKhU9FNesSFvj6gASuWmQd23Ul5omtD&si=m6o65lgTsMBMPVK_

- 다른거 2(4시간30분_한방에)(Introduction to Operating System | Full Course for Beginners Mike Murphy 🌚 Lecture for Sleep & Study | LECTURES FOR SLEEP & STUDY)
  - https://youtu.be/dOiA2nNJpc0?si=JRjWo2OdPwV1wBJ5

- 손글씨라 ㅜㅜ 글자가 잘 안보임(Operating Systems Course for Beginners | freeCodeCamp.org)
  - https://youtu.be/yK1uBHPdp30?si=ft4gjiJOvW2IH13-


```
00:02 Comprehensive operating system course covering fundamental and advanced concepts.
02:41 Operating Systems Course overview and guidelines
07:28 ALU performs arithmetic and logical functions.
09:44 Operating system loads the executable file from hard disk to main memory for CPU execution.
14:33 Operating system acts as a resource manager
16:51 Operating system controls everything in the computer.
21:07 Operating system acts as a resource manager and government in controlling program applications.
23:05 Uni programming OS allows only one program in memory, leading to CPU idle time.
27:26 Multiprocessor systems run one program at a time
29:33 Schematic view of multiprogramming operating system
33:30 Difference between uniprocessor and multiprocessor systems
35:22 Multiprogramming increases CPU utilization and efficiency
39:25 Process Management in Operating Systems
41:30 Secondary storage devices need to be DMA compatible and support address translation for efficient data transfer.
45:49 Privileged processes in operating systems
47:57 Mode shifting is necessary for user applications to access OS kernel level services.
52:05 Multiprogramming increases CPU utilization and efficiency.
53:47 Architectural requirements for operating systems
57:41 Operating System Booting and Memory
59:39 Non-preemptive processes have better response time
1:03:42 Learn about mode shifting via API and SCI
1:05:57 Understanding the difference between print F in header and library files
1:10:28 Shift mode from user to kernel to access fork services
1:12:39 SVC and Interrupts in Operating Systems
1:16:58 Understanding how mode shifting is essential in operating systems.
1:18:51 Operating system mode shifting and system calls
1:22:39 Understanding kernel mode and user mode operation
1:24:33 Explanation of child process creation using Fork
1:28:52 Difference between a program and a process
1:30:58 Compilation process converts high-level code into low-level instructions
1:35:20 Dynamic array implementation in C using Maloc
1:37:31 Process is the program in execution using computer resources.
1:41:34 Program consists of instruction and data, with data types static and dynamic.
1:43:36 Activation records in function calls
1:47:40 Learning VSS extension and process operations
1:49:40 Transition diagram states and process attributes
1:53:47 Understanding Process Control Block (PCB) and Process Lifetime Stages
1:56:02 Understanding resource deallocation and process states
2:00:15 Operating systems shift processes from main memory to hard disk to manage clutter.
2:02:35 Process transitions from ready to waiting to running state in an OS
2:06:58 Processes go directly to running state with no ready stage
2:09:16 Resource allocation and deallocation in main memory
2:13:42 Transferring processes from Main memory to disk
2:15:47 Ready state is the most desirable for suspension
2:20:07 Understanding process states in Operating Systems
2:22:03 Processes transitioning in the operating system
2:25:53 Transition from suspended block to ready state involves swapping/loading to bring process back to main memory
2:27:46 Operating system resumes process based on resource availability
2:32:03 Explaining the concept of block and device queues in memory management.
2:34:12 Overview of Scheduling Cues in Operating Systems
2:38:16 Dispatcher controls CPU execution for selected process.
2:40:23 Schedulers in Operating Systems
2:44:46 Process Switching
2:46:53 Overview of schedulers and dispatcher in Operating Systems
2:50:58 Understanding arrival time and waiting time in an Operating System
2:52:48 Understanding process state transitions and timing
2:56:56 Preemptive scheduling allows for infinite possible ways to schedule processes.
2:58:50 Schedule Length Calculation
3:02:38 Understanding turnaround time in process scheduling
3:04:32 Discussing scheduling and its types
3:08:44 Introduction to Process Scheduling
3:10:49 The Gant chart always starts from zero.
3:15:02 Calculating waiting time in Operating Systems
3:17:00 Scheduling processes based on arrival time and execution time
3:21:04 Understanding Gantt chart and CPU idleness
3:23:07 Calculate percentage CPU idleness over schedule length
3:27:11 Understanding the life cycle of a process in Operating Systems
3:29:22 Process scheduling involved loading from ready to running via dispatcher
3:33:38 Understanding process scheduling and completion times in operating systems
3:35:48 Understanding the distinction between transit time and waiting time is crucial.
3:40:17 Calculate waiting time from chart, not formula
3:42:22 Understanding process transition from ready to running and then block in Operating Systems
3:46:38 Process scheduling and termination process in an operating system
3:48:37 Dispatcher time and process scheduling overview
3:52:46 Tips for solving process transition questions
3:54:47 Understanding CPU idleness and scheduling processes
3:58:47 Calculate CPU overhead for given process scheduling
4:00:45 Homework questions for CPU efficiency and scheduling overhead
4:04:54 Process transitions in an operating system
4:06:48 Scheduling processes with single IO device
4:10:32 Shortest Job First (SJF) prioritizes processes with the least burst time.
4:12:26 Scheduling in non-preemptive algorithms
4:16:18 Scheduling processes based on burst time and process ID.
4:18:09 Understanding the shortest job first (SJF) algorithm and its preemptive version (SRTF)
4:22:02 SRTF scheduling preempt shorter burst times
4:23:49 Understanding Preemption in SRTF Scheduling
4:27:34 SRTF scheduling algorithm involves checking every time a new process arrives
4:29:33 Scheduling and preemption in operating systems
4:33:32 SGF and SRTF algorithms are optimal
4:35:39 Calculating optimal average waiting time using Shortest Job First algorithm (SJF)
4:39:28 Calculate waiting time for processes based on scheduling order.
4:41:23 Predicting burst time using static and dynamic techniques
4:45:48 Explaining recurrence relation and initial guess concept
4:47:43 Prediction techniques for CPU burst time
4:51:55 Processes with high response ratio are given priority in HRR algorithm
4:54:02 Discussing unfairness in process scheduling based on bus time
4:58:11 Longest remaining time first (LRTF) algorithm is the opposite of SRTF, scheduling the longest process first.
5:00:13 SRTF scheduling prioritizes processes based on remaining burst time
5:04:32 Processes scheduling based on remaining burst time and process ID
5:06:23 Scheduling based on burst time and process IDs
5:10:04 Scheduling jobs using Shortest Job First algorithm
5:12:03 Introduction to priority-based scheduling algorithm
5:16:06 Priority scheduling in Operating Systems
5:18:10 Scheduling processes based on priority levels
5:22:12 Scheduling based on priority and completion time
5:24:08 Understanding the priority and scheduling of processes
5:28:10 Introduction to Round Robin algorithm
5:30:13 In round robin scheduling, processes have to leave after the time quantum
5:34:20 Scheduling multiple processes based on time Quantum
5:36:28 Scheduling new and preemptive processes
5:40:20 Scheduling processes based on arrival times and time quantum in round-robin algorithm.
5:42:16 Schedule of processes in the RQ
5:46:22 Efficiency drops to zero with small time Quantum in operating systems
5:48:32 Determining the suitable time quantum for round-robin scheduling
5:53:05 Understanding the implications of different values of Q in the context of CPU scheduling
5:55:39 Understanding CPU scheduling and time quantum
6:00:00 Explaining CPU scheduling and response time calculation
6:02:18 Calculation of response time in CPU scheduling
6:06:37 Different scheduling algorithms applied to different queues based off priorities
6:08:44 Processes penalized based on running time
6:12:46 Interprocess communication (IPC) is essential for communication between processes.
6:14:48 Synchronization is performing an agreed action.
6:19:00 Synchronization is the coordination of concurrent processes.
6:21:07 Synchronization in Operating Systems
6:25:20 Understanding the producer-consumer problem
6:27:29 Understanding process synchronization and deadlock
6:31:49 Understanding preemption and process execution
6:33:49 Understanding race conditions and synchronization
6:38:03 Importance of Correct Results in Processes
6:40:09 Producer places item onto buffer when buffer is not full
6:44:25 Understanding the circular buffer concept in operating systems.
6:46:20 Implementation of producer and consumer in C language
6:50:35 Stagnant water and mosquitoes are the main culprits for malaria spreading.
6:52:32 Synchronization requires critical sections and race conditions.
6:56:49 Security guard manages access to critical section
6:58:55 Requirements of Critical Section Problem

7:03:18 Critical section must have bounded waiting for interested processes.
7:05:23 Differentiating synchronization mechanisms as solutions or not
7:09:41 Introduction to lock variable as a synchronization mechanism
7:11:56 Implementing locking mechanism for mutual exclusion
7:16:17 Understanding the critical section and entry process.
7:18:41 Explanation of lock variable implementation
7:23:14 Preemption and lock value changes in a multi-process scenario
7:25:27 Importance of Lock in Ensuring Mutual Exclusion
7:29:39 Lock variable leads to wastage of CPU time.
7:31:52 Importance of critical section and preventing wastage of CPU cycles
7:36:22 Strictly alternate process execution for critical section access
7:38:28 Understanding mutual exclusion and the turn variable
7:42:40 Uninterested processes hinder the progress of interested processes
7:44:41 Explanation of mutual exclusion and bounded waiting in synchronization mechanisms
7:48:53 Concept of flag and turn for process synchronization
7:51:03 Understanding the concept of turn and flag in the context of processes.
7:55:26 Peterson solution is about the critical section and updating turn value.
7:57:38 Discussing process scheduling and completion of sections
8:01:49 Peterson solution ensures non-interested processes do not hinder progress
8:03:57 Peterson solution ensures mutual exclusion
8:08:08 Ensuring mutual exclusion and progress in operating systems.
8:10:16 Understanding the impacts of initialization on process turns
8:14:35 Decker's algorithm in operating systems
8:16:45 Algorithm provides mutual exclusion and progress
8:21:01 Explanation of Deadlock in Operating Systems
8:23:11 Discussion on bounded waiting and strict alternation
8:27:15 Discussing Test and Set Lock functionality
8:29:27 Explanation of TSL operation and its impact on critical section execution.
8:33:24 Swap mechanism based on lock and key ensures atomic execution
8:35:20 Understanding the process of swapping using a temporary variable.
8:39:16 Swap mechanism guarantees Mutual exclusion and progress
8:41:17 Test and set provides mutual exclusion
8:45:22 Priority inheritance solves deadlock in critical sections
8:47:30 Fetch and add X, I is an atomic read modify write instruction.
8:51:39 Understanding synchronization mechanisms and problem-solving
8:53:35 Understanding how L=0 and L!=1 affect log value increments.
8:57:25 Demonstration of Mutual exclusion and prevention of overflow
8:59:14 Preemption strategy in entry section
9:03:06 Understanding overflow in processes
9:05:15 FCFS doesn't suffer from starvation except for infinite loops
9:09:32 Sleep and wake up is a blocking mechanism in multiprocess solutions
9:11:33 Solving the producer-consumer problem using non-busy waiting solution
9:15:38 Implementing consumer functionality in operating systems
9:17:37 Understanding preemptive process scheduling
9:21:38 Semaphore - Definition and Types
9:23:51 Explanation of the down operation in kernel mode
9:28:16 Positive value of SEMA 4 indicates successful down operations, negative value indicates blocked processes
9:30:09 Understanding how sema4 provides Mutual exclusion
9:34:03 The objective of up operation is to wake up a sleeping process
9:36:01 Understanding the conditions for waking up processes
9:40:04 Using SEMA 4 helps manage concurrent requests effectively.
9:42:10 Managing Processes with Counting Semaphores
9:46:05 Understanding down operation in binary semaphores
9:48:05 Understanding the process blocking and synchronization
9:51:58 Understanding value changes in critical sections
9:53:57 Explanation of binary semaphore operations
9:58:13 Semaphore 4 and its operations
10:00:07 Ensuring mutual exclusion and progress in critical section
10:04:17 Preemption in semaphores can lead to deadlock.
10:06:27 Preempting processes to prevent deadlock
10:10:53 Process synchronization using down and up operations
10:13:07 Implication of strict alternation for mutual exclusion
10:17:22 Demonstrating mutual exclusion and deadlock in operating systems.
10:19:24 Understanding a scenario leading to deadlock and semaphore initialization
10:23:44 Explaining the limitations of processes without a while loop.
10:26:03 Determining minimum and maximum value of variable C in a concurrent process scenario
10:30:29 Understanding deadlock in operating systems
10:32:29 Discussing synchronization and mutual exclusion in operating systems.
10:36:25 Concurrency issues in race condition
10:38:41 Processes changing values and storing them
10:42:56 Understanding implementation using semaphores
10:44:56 Operating System synchronization in producer-consumer scenario
10:49:16 Understanding the deadlock and order importance in synchronization problems.
10:51:21 Understanding synchronization problem in operating systems
10:55:26 Producer adds item to buffer but consumer can't consume
10:57:32 Consumer removing one item at a time from buffer
11:01:20 Reader Writer problem and its solution using semaphores
11:03:29 Starvation of writers in database access
11:07:47 Database locking mechanism for readers and writers
11:09:55 Understanding the use of mutex and database for accessing the critical section.
11:14:10 Solving reader-writer problem using Mutex
11:16:05 Semaphore used to solve reader-writer problem
11:19:55 Implementation of Dining Philosopher problem
11:21:59 Philosophers sharing forks for eating efficiency
11:26:06 Preventing deadlocks by changing philosopher pattern
11:28:07 Preventing deadlock by changing paths
11:32:26 Statements can be executed concurrently if they are independent.
11:34:49 Understanding concurrency and parallelism
11:39:01 Concurrency and parallelism in operating systems
11:41:05 Understanding concurrent execution in Operating Systems
11:45:28 Understanding read set and write set for concurrent statements
11:47:38 Understanding the difference between sequential and concurrent execution using pair begin and pair end
11:51:57 Dependent nodes cannot always be considered concurrent.
11:54:10 Exploration of handling dependencies and contradictions in program execution
11:58:17 Acquiring keys in executing statements

12:00:23 Understanding the dependency between locks in executing sequence of commands.
12:04:41 Understanding key requirements for locks in the given scenario.
12:06:52 Understand the importance of valid sequences in executing concurrent tasks
12:11:11 Updating values of x and y in a sequence
12:13:30 Understanding binary semaphore and sequentiality in execution.
12:17:51 Understanding the concepts of Fork and Join in operating systems.
12:20:00 Explaining how to branch instructions in Fork
12:23:48 Understanding control flow in Operating Systems.
12:25:53 The process synchronization section is over.
12:29:45 Value of counter depends on thread execution
12:31:40 Deadlock is when two or more processes are waiting for an event that is never going to happen.
12:35:51 Deadlock explained with a meme
12:38:00 Deadlock occurs when a process is blocked forever due to resource unavailability.
12:42:14 Four necessary conditions for deadlock
12:44:24 Circular wait is not a sufficient condition for deadlock
12:48:49 Understanding resource allocation and blocking in Operating Systems
12:50:53 Preventing Deadlocks by Resource Release
12:55:03 Deadlock prevention strategies are crucial for critical operating systems.
12:57:11 Deadlock prevention negates necessary conditions
13:01:32 Efficient resource utilization through protocol 2
13:03:52 Forceful preemption and self preemption prevent deadlock
13:08:11 Resource preemption is crucial for avoiding circularity and maintaining linearity.
13:10:07 Understanding the necessity of cycles in resource allocation
13:14:27 Resource allocation graph aims to maintain a safe state
13:16:40 Understanding safe and unsafe states in resource allocation
13:20:51 Understanding Safety Algorithm and Resource Request Algorithm Basics
13:23:36 Understanding resource allocation in operating systems
13:28:25 Resource allocation and satisfaction process summarized.
13:30:35 Understanding the Banker algorithm for multiple resources with multiple instances.
13:34:55 Proving the existence of multiple CF sequences
13:37:07 Multiple safe sequences can exist with Banker's algorithm
13:41:32 Updating resource allocation and running the safety algorithm
13:43:54 Resource allocation and availability
13:48:10 Applying safety algorithm to check system state based on resource values
13:50:28 Satisfied the need for resources
13:54:59 Deadlock in single instance and multi-instance resource allocation
13:57:13 Achieving safe state by satisfying process requests
14:01:40 Resource preemption and process recovery
14:03:49 Deadlock avoidance strategies
14:08:12 Maximum resources for deadlock is 36, minimum for deadlock freedom is 37
14:10:22 Understanding unsafe state vs deadlock in resource allocation graphs
14:15:02 Ensure system can satisfy minimum resource requests to avoid deadlock
14:17:05 Resource allocation using Bankers algorithm
14:21:23 Understanding the hierarchy of memory sizes and functions of RAM in operating systems
14:23:44 Memory size calculation based on number of words and word size
14:27:57 Understanding data representation using bits and bytes
14:30:11 Explaining memory size in bits and bytes
14:34:40 Addressing Memory Blocks in Operating Systems
14:36:45 Understanding memory size and word addressing
14:40:51 Understanding the purpose and operation of the bus, chip select, and address bus in a computer system
14:42:57 Static and dynamic loading in operating systems
14:47:13 Resolving External References
14:49:25 Linker module fills up blank addresses in program code.
14:53:53 Dynamic linking allows for flexibility and code reusability
14:56:10 Difference between static and dynamic linking
15:00:45 Understanding different types of binding in Operating Systems.
15:03:02 Static and dynamic binding in operating systems
15:07:23 Address binding provides relocation flexibility at runtime.
15:09:33 Static binding vs. dynamic binding
15:13:44 Memory management fundamentals from older theories
15:15:54 Memory manager goals to minimize wastage and utilize memory effectively
15:20:20 Understanding memory overlay and its application
15:22:41 Explaining partitioning in Operating Systems.
15:26:54 Base plus limit architecture to ensure protection
15:29:05 Overview of old and new techniques in Operating Systems
15:33:22 Fixed partition leads to internal fragmentation and limited multiprogramming.
15:35:25 Dynamic partitioning allows for flexible memory allocation
15:39:35 External Fragmentation and Solutions
15:41:39 Resolve external fragmentation by reallocating memory and creating a bigger free hole
15:45:35 Variable partitioning and best fit allocation in memory systems
15:47:35 Memory allocation strategies
15:51:55 Operating Systems manages process table and memory partitions
15:54:09 Process table size calculation for 500 processes.
15:58:31 Scheduling and memory management using FCFS
16:00:32 Explaining memory allocation based on program size
16:04:24 Understanding non-continuous allocation
16:06:27 Introduction to Variable Partitioning for memory management
16:10:41 Differences between logical address and physical address
16:12:53 Memory management involves converting logical addresses to physical addresses.
16:17:11 Memory management unit handles address translation
16:19:26 Pages and Page Size Calculation
16:24:18 Understanding page offset and page number in memory addressing
16:26:37 Logical address format explained with page number and page offset
16:31:02 Understanding the concept of frames and pages in memory management.
16:33:13 Understanding logical address space and physical address space division
16:37:42 Finding physical address space using page size and frame size.
16:39:53 Understanding address translation in Operating Systems
16:44:06 Page table contains the frame number where pages are stored.
16:46:21 Understanding Page Table in Operating Systems
16:50:37 Paging technique for accessing physical memory
16:52:51 Understanding virtual memory and page table size
16:57:30 Calculating page offset and physical address space size in a computer system using paging technique
16:59:47 Determining page size and number of pages in simple paging technique.
17:04:07 Page table size calculation and performance impacts
17:06:20 Main memory access time (M) is crucial for CPU operations
17:10:46 Cache memory access time is less than main memory access time
17:12:40 Introduction to cache memory and effective access time
17:16:55 Defined hit and miss ratio for effective memory access time
17:19:12 Understanding TLB and PSC in CPU processing
17:23:30 Optimizing memory access using TLB and physical address
17:25:37 Page table size can be reduced by increasing page size
17:30:07 Finding the optimal page size for minimal internal fragmentation and page table size.
17:32:17 Optimal page size affects page table size and internal fragmentation
17:37:10 Memory division into units and load time calculation
17:39:33 Calculating CPU Time Fraction for Loading Page Table
17:43:41 Dividing program into pages and calculating required pages for text, data, and stack sections
17:45:50 Calculating number of pages based on address space and page size
17:50:07 Introduction to Hashed Page Table
17:52:19 Collision resolution technique using chaining
17:56:31 VUM architecture involves tradeoff between space and time 
```

<hr>

# C++언어 공부하기 좋다.[|🔝|](#link)
https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf

# `std::prt::read_volatile`[|🔝|](#link)
https://doc.rust-lang.org/std/ptr/fn.read_volatile.html

```rs
pub unsafe fn read_volatile<T>(src: *const T) -> T
```

- https://doc.rust-lang.org/std/ptr/fn.read_volatile.html#examples
```rs
let x = 12;
let y = &x as *const i32;

unsafe {
    assert_eq!(std::ptr::read_volatile(y), 12);
}
```

- Performs a volatile read of the value from `src` without moving it. This leaves the memory in `src` unchanged.
  - src에서 값을 이동하지 않고 휘발성으로 읽습니다. 그러면 메모리가 src로 바뀌지 않습니다.


- Volatile operations are intended to act on I/O memory, and are guaranteed to not be elided or reordered by the compiler across other volatile operations.
  - 휘발성 연산은 I/O 메모리에 작용하도록 되어 있으며, 컴파일러가 다른 휘발성 연산에 걸쳐 제거하거나 재정렬하지 않도록 보장합니다.

# Notes

- Rust does not currently have a rigorously and formally defined memory model, so the precise semantics of what "volatile" means here is subject to change over time. That being said, the semantics will almost always end up pretty similar to `[C11's definition of volatile][c11]`.
  - 러스트는 현재 엄격하고 형식적으로 정의된 메모리 모델을 가지고 있지 않으므로 여기서 "휘발성"이 무엇을 의미하는지에 대한 정확한 의미론은 시간이 지남에 따라 변경될 수 있습니다. 즉, 의미론은 거의 항상 '[C11의 휘발성][c11]의 정의와 상당히 유사하게 끝날 것입니다.

- The compiler shouldn't change the relative order or number of volatile memory operations. However, volatile memory operations on zero-sized types (e.g., if a zero-sized type is passed to `read_volatile`) are noops and may be ignored.
  - 컴파일러는 휘발성 메모리 연산의 상대적인 순서나 개수를 변경해서는 안 됩니다. 하지만 제로 사이즈 타입에서의 휘발성 메모리 연산(예를 들어, 제로 사이즈 타입이 'read_volatile'로 전달되는 경우)은 noops이며 무시될 수 있습니다.

 [c11]: http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf

# Safety[|🔝|](#link)

- Behavior is undefined if any of the following conditions are violated:
  - 다음 조건 중 하나라도 위반하면 동작이 정의되지 않습니다:

  - * `src` must be [valid] for reads.
    - * 읽기의 경우 'src'가 [valid]여야 합니다.

  - * `src` must be properly aligned.
    - * 'src'가 올바르게 정렬되어야 합니다.

  - * `src` must point to a properly initialized value of type `T`.
    - * 'src'는 T형의 초기화된 값을 가리켜야 합니다.

- Like [`read`], `read_volatile` creates a bitwise copy of `T`, regardless of whether `T` is [`Copy`]. If `T` is not [`Copy`], using both the returned value and the value at `*src` can [violate memory safety][read-ownership]. However, storing non-[`Copy`] types in volatile memory is almost certainly incorrect.
  - read_volatile은 read와 마찬가지로 T가 [Copy]이든 상관없이 T의 비트 단위 복사본을 만듭니다. 만약 T가 [Copy]가 아니라면 반환된 값과 *src 값을 모두 사용하면 메모리 안전성[read-소유권]을 침해할 수 있습니다. 그러나 [Copy]가 아닌 유형을 휘발성 메모리에 저장하는 것은 거의 확실하지 않습니다.

- Note that even if `T` has size `0`, the pointer must be non-null and properly aligned.
  - 'T'의 크기가 '0'이더라도 포인터가 null이 아니며 적절하게 정렬되어 있어야 합니다.

 [valid]: self#safety
 [read-ownership]: read#ownership-of-the-returned-value

- Just like in C, whether an operation is volatile has no bearing whatsoever on questions involving concurrent access from multiple threads. Volatile accesses behave exactly like non-atomic accesses in that regard. In particular, a race between a `read_volatile` and any write operation to the same location is undefined behavior.
  - C와 마찬가지로 연산의 휘발성 여부는 여러 스레드에서 동시에 액세스하는 것과 관련된 질문과 전혀 관련이 없습니다. 휘발성 액세스는 원자가 아닌 액세스와 똑같이 작동합니다. 특히 'read_volatile'과 동일한 위치에 대한 임의의 쓰기 연산 간의 경쟁은 정의되지 않은 동작입니다.

<hr />

<hr />

<hr />

# 용어정리[|🔝|](#link)

# DPL개념이해[|🔝|](#link)
- Privilege Level (Ring 0, Ring 3)
출처: https://elfmfl.tistory.com/2 [Elfmfl:티스토리]
# DPL
- (Descriptor Privilege Level)
  -  C++로 나만의 운영체재만들기(p.113)

# Programs Call이해[|🔝|](#link)
- https://youtu.be/e5g8eYKEhMw?si=vcOuJlO55xvguRwp

# 시스템 콜 주요 개념[|🔝|](#link)
- https://youtu.be/bfZ-f0m4nqQ?si=2vhhSy9DH6yc_KYd

# Effective Address란? 선형주소[|🔝|](#link)
- http://www.iamroot.org/xe/index.php?mid=Kernel&document_srl=26233

# [컴퓨터 구조] Instruction Sets[|🔝|](#link)
- https://blackinkgj.github.io/ISA/
  - 출처 : Willian Stallings. (2013). Computer Organization and Architecture. London:Pearson

# [Assembly] Can anyone explain to me what an effective address is?[|🔝|](#link)

I am taking a course on data organization this semester, and since it is the professor's first year teaching, he is not the greatest at explaining concepts. I have an assignment where I read some assembly code and identify what is going on and what the effective address is. I just have no idea how to identify what the EA is. Reading the textbook and going on Wikipedia have not helped either. Does anyone have a simple, concise explanation as to what it is? I can provide the code I am looking at for the assignment if need be.
-  [어셈블리] 효과적인 주소가 무엇인지 설명해 줄 수 있는 사람이 있습니까?
  - 저는 이번 학기에 데이터 정리에 대한 강의를 듣고 있는데 교수님의 1학년 강의이기 때문에 개념 설명에 능숙하지 않습니다. 저는 어셈블리 코드를 읽고 무슨 일이 일어나고 있는지, 유효 주소가 무엇인지 식별하는 과제가 있습니다. EA가 무엇인지 식별하는 방법을 전혀 모르겠습니다. 교과서를 읽고 위키피디아를 사용하는 것도 도움이 되지 않았습니다. 그것이 무엇인지에 대한 간단하고 간결한 설명을 가지고 있는 사람이 있습니까? 필요하다면 제가 찾고 있는 코드를 제공할 수 있습니다.
- https://www.reddit.com/r/learnprogramming/s/3Zcy1WFVoV

# Addressing mode[|🔝|](#link)
- https://en.m.wikipedia.org/wiki/Addressing_mode

# x86 memory segmentation[|🔝|](#link)
- https://en.m.wikipedia.org/wiki/X86_memory_segmentation

# Real mode[|🔝|](#link)
- https://en.m.wikipedia.org/wiki/Real_mode

# Protected mode[|🔝|](#link)
- https://en.m.wikipedia.org/wiki/Protected_mode



<hr />  

# 이 사람은 넘 좋다.
# (251003)Project: Coding a GRUB bootloader for booting Linux | dr Jonas Birch[|🔝|](#link)
- https://youtu.be/ukIajayMv5U?si=w1tlw42I4nHsp4G7


<hr />

<hr />
