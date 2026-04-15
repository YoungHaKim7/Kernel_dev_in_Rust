# link

- [Rust unstable features needed for the kernel #2](https://github.com/Rust-for-Linux/linux/issues/2)


<hr />

# coreutils진행사항
- https://github.com/uutils/coreutils/releases/tag/0.7.0

# 최신 (러스트 Rust)커널 소식[|🔝|](#link)
- [(260322) Ubuntu 26.04, 46년 만에 ‘무음 sudo 비밀번호 입력’ 종료](#260322-ubuntu-2604-46년-만에-무음-sudo-비밀번호-입력-종료)
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

# 260415 Linux 커널 7.0 공식 릴리스 (9to5linux.com/linux-kernel-7-0-officially-released-this-is-whats-new)
10P by princox 13시간전 
- Linus Torvalds가 Linux 커널 7.0을 공식 릴리스했습니다. **다만 버전 번호가 크게 올랐다고 해서 획기적인 변화가 있는 건 아닙니다.** Torvalds는 마이너 버전이 x.19처럼 너무 높아지면 메이저 버전을 올리는 관행을 유지하고 있으며, 이번 7.0도 그 연장선입니다.

## 주요 변경사항

### Rust 지원 정식화: 가장 주목할 변화는 Rust의 "실험적" 딱지가 제거된 것입니다. Rust가 커널 개발의 주류 언어가 된 건 아니지만, 프로젝트 내 점진적 통합에서 중요한 이정표입니다.

보안: 커널 모듈 인증에 ML-DSA 포스트 양자 서명이 추가됐고, SHA-1 기반 모듈 서명 방식은 제거됐습니다.

Self-healing XFS: XFS 파일시스템 오류를 실시간으로 감시하고, 마운트 상태를 유지하면서 백그라운드 데몬이 자동으로 복구를 트리거하는 헬스 모니터링 시스템이 추가됐습니다.

io_uring / BPF: io_uring에 cBPF 필터 지원이 추가됐고, BTF 타입 조회는 이진 탐색으로 성능이 개선됐습니다.

스왑 및 메모리: zram 압축 데이터를 디스크에 바로 쓸 수 있게 되어 메모리 압박 상황에서 스왑 성능이 향상됐습니다.

네트워킹: AccECN이 기본 활성화되어, 38년 된 TCP 설계 결함이 수정됐습니다. 패킷 드롭 이전에 혼잡 피드백을 지속적으로 받을 수 있습니다.

KVM: AMD Zen5 이상 CPU에서 ERAPS(Enhanced Return Address Predictor Security) 가상화 지원이 추가됐습니다.

AI 키보드 키: AI 전용 키보드 단축키를 위한 3개의 새로운 AI 특수 키가 추가됐습니다
- https://news.hada.io/topic?id=28518

# (251211)러스트 커널 접수 완료 👍[|🔝|](#link)

# (260322) **[Ubuntu 26.04, 46년 만에 ‘무음 sudo 비밀번호 입력’ 종료](<https://news.hada.io/topic?id=27726&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**
- Ubuntu 26.04 LTS에서는 `sudo` 명령 실행 시 **비밀번호 입력마다 별표(*)가 표시되는 시각적 피드백**이 기본 활성화됨  
- 이 기능은 **Rust로 재작성된 sudo-rs** 도입으로 가능해졌으며, Canonical이 Ubuntu 25.10부터 이를 기본 sudo로 채택함  
- 일부 사용자는 **비밀번호 길이 노출 위험**을 이유로 반대했으…

# (251211)**[리눅스 커널에서의 Rust 실험 (성공적) 종료](<https://news.hada.io/topic?id=24987&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- 리눅스 커널 내 **Rust 통합 작업**이 실험 단계를 마치고 **정식 구성 요소**로 인정됨  
- 연례 **Maintainers Summit**에서 개발자들이 Rust 지원을 **영구적 기능으로 채택**하기로 합의  
- 이에 따라 커널 내 Rust 관련 코드에서 **‘experimental’ 태그가 제거**될 예정  
- LWN 편집자는 “실험은 끝났고, 성공…
