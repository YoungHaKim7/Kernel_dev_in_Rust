# 260822) **[Linux 7.2 정식 출시](<https://news.hada.io/topic?id=32734&utm_source=discord&utm_medium=bot&utm_campaign=5116>)**

- 정규 일정에 맞춰 출시된 Linux 7.2는 6.7에 이어 역대 두 번째로 변경량이 많은 개발 주기로, **CPU·GPU 스케줄링**과 메모리 관리를 폭넓게 개선함
- **캐시 인식 스케줄링**과 MGLRU 개선, sched_ext 하위 스케줄러, 여러 크기의 투명 거대 페이지 자동 생성이 포함됨
- GPU 자원 배분을 개선하는 DRM **공정 스케줄링 정책**은 7.2-rc7에서 발견된 회귀로 인해 실험적 선택 기능으로 남았으며, 기본값은 FIFO를 유지함
- Raspberry Pi 4·5 GPU는 **런타임 전력 관리**로 유휴 시 클록을 끌 수 있게 됐고, Raspberry Pi 3에서 Retro…

# **[Linux, 6년·360개 이상 패치 끝에 strncpy API 제거](<https://news.hada.io/topic?id=30696&utm_source=discord&utm_medium=bot&utm_campaign=5116>)**
- Linux 7.2에서 커널 내부의 **strncpy API** 사용처가 사라지며, 오래전부터 폐기 예정이던 문자열 복사 인터페이스가 최종 제거됨
- strncpy()는 지정한 바이트 수만큼 복사하지만 **NUL 종료** 동작이 직관적이지 않아, 커널에서 수년간 버그의 원인으로 남아 있었음
- 목적지 버퍼를 불필요하게 0으로 채우는 특성은 **성능 문제**까지 만들었고, 이를 걷어내는 데 약 6년과 362개 커밋이 필요했음
- 금요일 머지에서 API 본체뿐 아니라 마지막 **per-CPU 아키텍처별 구현**도 함께 제거됨
- 커널 코드는 이제 용도에 따라 strscpy(…


```bash
util-linux-2.42.2-2.1.x86_64 (/var/adm/update-messages/util-linux-2.42.2-2.1-1)
View the notifications now? [y/n] (n): y
(Use arrows or pgUp/pgDown keys to scroll the text by lines or pages.)

Message from package util-linux:

New /etc/fstab limitations for mount(8)!

This update introduces significant security hardening that may
result in breaking or incompatible changes for unprivileged user
mounts. The following changes are permanent security hardening
measures and cannot be disabled. They apply to unprivileged
(non-root) users:

X-mount.nocanonicalize:

  Paths must always be canonicalized for unprivileged users. The
  X-mount.nocanonicalize option is now ignored for non-root users.

X-mount.subdir:

  The X-mount.subdir feature for detached subdirectories is
  disabled for kernel < 6.15 for unprivileged users due to inherent
  race conditions.

Path canonicalization:

  If LIBMOUNT_FORCE_MOUNT2 is set, mount target paths for user
  mounts will no longer traverse directories writable by
  unprivileged users to prevent TOCTOU races.

Future util-linux or kernel versions can remove these restrictions.
Follow the mount(8) man page.

-----------------------------------------------------------------------------
There are running programs which still use files and libraries deleted or updated by recent upgrades. They should be restarted to benefit from the latest updates. Run 'zypper ps -s' to list these programs.

```
