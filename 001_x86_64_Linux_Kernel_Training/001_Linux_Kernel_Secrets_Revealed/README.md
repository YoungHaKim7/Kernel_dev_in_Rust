#  리눅스 커널의 비밀이 밝혀졌습니다
- [(260321) Linux Kernel Secrets Revealed | YouTux Channel | 자동 더빙](https://youtu.be/VN16KCXc8oM?si=MvSqUtvigzUBsYrq)

```bash
00:00 당신이 모르는 커널
02:28 커널이 실제로 제어하는 ​​것
05:25 Swappiness: 모두가 잘못 이해하는 파라미터
07:58 VFS 캐시 압력과 더티 페이지
11:13 투명 대용량 페이지(Transparent Huge Pages): 당신이 생각하는 것과 다릅니다
13:03 KSM, PSI, max_map_count
14:49 자동 그룹화 및 CPU 거버너
18:50 CPU 완화: 보안 vs 성능
21:06 틱리스 커널 및 RCU
25:02 I/O 스케줄러: 올바른 스케줄러 선택
27:53 Zswap, 미리 읽기, 커널 포렌식
32:40 당신이 제어합니다: 기본값을 그대로 두지 마세요
```


- 당신의 배포판은 수백 가지의 커널을 만들었습니다. 여러분을 위해 내려진 결정들. 이제 그 결정들을 되돌리는 방법을 알려드립니다.

- 대부분의 리눅스 사용자는 배포판에 기본으로 제공되는 커널을 그대로 사용하는 것 외에는 커널을 건드려 본 적이 없을 것입니다. 하지만 커널은 수백 가지의 런타임 매개변수를 제공하며, 그중 일부는 시스템의 작동 방식과 성능을 근본적으로 바꿀 수 있습니다.

- 이 영상에서는 모든 명령어, 모든 설정 파일, 그리고 각각의 장단점을 자세히 살펴봅니다. 단순한 설명은 없습니다.

```
→ vm.swappiness, vfs_cache_pressure, dirty_ratio
→ THP(Transparent Huge Pages): always / madvise / never
→ VM 및 컨테이너용 커널 동일 페이지 병합(KSM)
→ PSI(Pressure Stall Information): 실제 커널 원격 측정 데이터
→ 스케줄러 자동 그룹화 및 CPU 거버너(schedutil, performance, powersave)
→ Spectre/Meltdown 완화 조치 및 실제 성능 저하 비용
→ 틱리스 커널(NO_HZ), RCU 스톨 타임아웃
→ I/O 스케줄러: mq-deadline, Kyber, BFQ, none
→ LZ4/Zstandard 압축을 사용한 Zswap
→ 미리 읽기 튜닝 및 커널 카운터 분석
→ max_map_count: Proton, Elasticsearch, Java의 조용한 킬러

리소스
────────────────────

참고 자료 및 문서

메모리 관리
kernel.org/doc/html/latest/admin-guide/sysctl/vm.html — vm.swappiness, vm.vfs_cache_pressure, vm.dirty_ratio, vm.max_map_count
kernel.org/doc/html/latest/mm/transhuge.html — 투명 대용량 페이지(Transparent Huge Pages)
kernel.org/doc/html/latest/mm/ksm.html — 커널 동일 페이지 병합(Kernel Same-page Merging)

CPU 및 스케줄링
kernel.org/doc/html/latest/admin-guide/pm/cpufreq.html — CPU 주파수 조절(CPU frequency governors)
kernel.org/doc/html/latest/admin-guide/hw-vuln/index.html — CPU 보안 완화 조치
kernel.org/doc/html/latest/timers/no_hz.html — 틱리스 커널(NO_HZ)
kernel.org/doc/html/latest/RCU/index.html — RCU

저장소 및 I/O
kernel.org/doc/html/latest/block/bfq-iosched.html — BFQ I/O 스케줄러
kernel.org/doc/html/latest/mm/zswap.html — Zswap

압력 스톨 정보
kernel.org/doc/html/latest/accounting/psi.html — PSI

커뮤니티 참조
wiki.archlinux.org/title/Sysctl
wiki.archlinux.org/title/CPU_frequency_scaling
wiki.archlinux.org/title/Zswap
wiki.gentoo.org/wiki/Kernel/Gentoo_Kernel_Configuration_Guide
```

# `sysctl -a`

```bash
$ sysctl -a
fs.binfmt_misc.status = enabled
fs.binfmt_misc.WSLInterop = enabled
fs.binfmt_misc.WSLInterop = interpreter /init
fs.binfmt_misc.WSLInterop = flags:
fs.binfmt_misc.WSLInterop = offset 0
fs.binfmt_misc.WSLInterop = magic 4d5a
fs.inotify.max_queued_events = 16384
fs.inotify.max_user_instances = 128
fs.inotify.max_user_watches = 8192
fs.file-max = 1048576
kernel.cap_last_cap = 36
kernel.domainname = localdomain
kernel.hostname = DESKTOP-7FCSUVF
kernel.keys.root_maxkeys = 1000000
kernel.osrelease = 4.4.0-18362-Microsoft
kernel.ostype = Linux
kernel.overflowgid = 65534
kernel.overflowuid = 65534
kernel.ngroups_max = 65536
kernel.pid_max = 32768
kernel.random.boot_id = 1da1d722-5635-46cf-8aed-368e32725216
kernel.random.entropy_avail = 4096
kernel.random.poolsize = 4096
kernel.random.uuid = 76cba016-33d6-44f9-97af-947182028711
kernel.randomize_va_space = 2
kernel.sem = 32000      1024000000      500     32000
kernel.threads-max = 32768
kernel.shmmax = 4294967295
kernel.shmmni = 4096
kernel.yama.ptrace_scope = 1
net.bridge.bridge-nf-call-arptables = 1
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
net.bridge.bridge-nf-filter-pppoe-tagged = 0
net.bridge.bridge-nf-filter-vlan-tagged = 0
net.bridge.bridge-nf-filter-nf-pass-vlan-input-dev = 0
net.core.somaxconn = 128
net.ipv4.ip_forward = 1
vm.min_free_kbytes = 45056
vm.overcommit_memory = 0
vm.swappiness = 60
```
