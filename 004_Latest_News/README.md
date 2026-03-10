# link

- [Rust unstable features needed for the kernel #2](https://github.com/Rust-for-Linux/linux/issues/2)


<hr />

# 최신 (러스트 Rust)커널 소식[|🔝|](#link)
- [(251211)**[리눅스 커널에서의 Rust 실험 (성공적) 종료]](#251211리눅스-커널에서의-rust-실험-성공적-종료)
- [(251128)Rust For Linux Kernel Co-Maintainer Formally Steps Down](https://www.phoronix.com/news/Alex-Gaynor-Rust-Maintainer)

# 기타 News[|🔝|](#link)
- [(유료 콘텐츠 250903)Tracking trust with Rust in the kernel](https://lwn.net/SubscriberLink/1034603/5dcfecdd5e3af0c2/)
- 한글 영상
  - 리눅스 커널 변경 사항(v6.5 ~ v6.10)
    - [(241123)[9회 커널 개발자 모임] 1. kernel report (Part1) - 이현철 개발자님 Austin Kim](https://youtu.be/GN3HezzYW8Y?si=R9Dt9tybuJQ1_RK5)
    - [(241125)[9회 커널 개발자 모임] 1. kernel report (Part2) - 이현철 개발자님 Austin Kim](https://youtu.be/oSQ6M-oaQJk?si=_STI5nFBa4P1v8km)
    - [(241127)[9회 커널 개발자 모임] 1. kernel report (Part3) - 이현철 개발자님 Austin Kim](https://youtu.be/cnkdD1-pPsI?si=AAQXiSkcHTQXYASK)
  - 제10회 한국 리눅스 커널 개발자 모임(250918(목))
    - https://kernel-dev-ko.github.io/10th/

# Do kernel maintainers support Rust in the kernel?
- 출처 : https://rust-for-linux.com/rust-kernel-policy
- Yes, there are key kernel maintainers that support Rust in the kernel.

- Please see the quotes given by kernel maintainers for the [FOSDEM 2025 Rust for Linux keynote, slides 45-85.](https://fosdem.org/2025/events/attachments/fosdem-2025-6507-rust-for-linux/slides/237976/2025-02-0_iwSaMYM.pdf)

# Kernel 요약[|🔝|](#link)
- How to write Rust in the kernel [Posted June 20, 2025 by daroc]
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

# (251211)러스트 커널 접수 완료 👍[|🔝|](#link)

# (251211)**[리눅스 커널에서의 Rust 실험 (성공적) 종료](<https://news.hada.io/topic?id=24987&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- 리눅스 커널 내 **Rust 통합 작업**이 실험 단계를 마치고 **정식 구성 요소**로 인정됨  
- 연례 **Maintainers Summit**에서 개발자들이 Rust 지원을 **영구적 기능으로 채택**하기로 합의  
- 이에 따라 커널 내 Rust 관련 코드에서 **‘experimental’ 태그가 제거**될 예정  
- LWN 편집자는 “실험은 끝났고, 성공…
