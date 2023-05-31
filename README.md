# process_information_linux
Utility to get information about process by its PID.
## Examples
```
$ ./pinfo 
Try './pinfo help' for more information.
```
```
$ ./pinfo help
MANUAL PAGE for pInfo.
Made by Shaganov Vyacheslav.

Usage:
    ./pInfo [pid] [keywords]...

Keywords:
    name - Name of the process
    ppid - Parent's PID
    state - Current state
    uid - UID of user who runs the process
    threads - number of threads
    thpid - list of PIDs of the process threads
    prt - Priority of the process
    policy - Planning policy
    dm - Whether process is daemon
    sys - Whether process is system
    flags - Flags of a process
```
```
$ ./pinfo 4860 dm sys name ppid uid state threads thpid policy prt 
dm: Not a daemon
sys: Not a kernel process
name: cpptools-srv
ppid: 1210
uid: 1000
state: S (sleeping)
threads: 12
thpid:
	4860
	4861
	4862
	4863
	4864
	4865
	4866
	4867
	4868
	4869
	4870
	4882
policy: SCHED_OTHER
prt: 20
```
```
$ ./pinfo 4 name ppid flags
name: rcu_par_gp
ppid: 2
flags:
	I'm a workqueue worker
	Forked but didn't exec
	This thread should not be frozen
	I am a kernel thread
	Userland is not allowed to meddle with cpus_mask

$ ./pinfo 460 name ppid flags
name: systemd-udevd
ppid: 1
flags:
	Used super-user privileges
	Randomize virtual address space

```