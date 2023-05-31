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
```
```
$ ./pinfo 4860 name ppid uid state threads thpid policy prt
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
