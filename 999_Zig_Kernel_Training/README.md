# zig로 만든 커널
- https://github.com/popovicu/zig-time-sharing-kernel
- **[처음부터 직접 운영체제 커널 만들기](<https://news.hada.io/topic?id=23105&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**
- **RISC-V 아키텍처**에서 **타임셰어링 운영체제 프로토타입 커널**을 구현한 경험을 공유  
- **시분할(time-sharing) 커널**의 개념과 동작 방식을 실습 중심으로 설명하며, C 대신 **Zig**로 구현해 재현성을 높임  
- 커널과 사용자 코드를 하나의 바이너리로 묶는 **unikernel** 접근을 취하고, 콘솔 출력과 타이…
  - Writing an operating system kernel from scratch (Posted on: September 13, 2025 |  at 09:30 AM)
    - https://popovicu.com/posts/writing-an-operating-system-kernel-from-scratch/

# How to set up syzkaller
- https://github.com/google/syzkaller/blob/master/docs/linux/setup.md


# 리눅스 커널의 암호화가 양자 내성 암호(PQC)에 맞춰서 진화가 필요해요!
- https://gamma.app/docs/Lets-Get-the-Linux-Kernel-Ready-for-the-PQCPost-Quantum-Era-KR-k8n5edhoamovypp


# 커널 크립토 메일링 리스트
- https://lore.kernel.org/linux-crypto/?q=quantum

# 여러 mem cgroup이 page를 공유하는 유즈케이스가 궁금합니다.
- private anonymous (copy-on-write), shared anonymous (shmem/tmpfs), private file-backed, shared file-backed 모두 여러 memory cgroup이 공유할 수 있습니다

# 논리 qbit 몇비트에 도달하면 확실히 rsa가 깨질까요?
- RSA-2048을 해독하려면 약 4,000개의 논리 큐비트 (logical qubits)가 필요

<hr />