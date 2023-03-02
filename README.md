# Symbolic-Execution-Testing-of-TCP-using-KLEE-Float
Symbolic execution is not straightforward when floating point arithmetic is involved. KLEE-float is a good tool to combat this problem.

To run this project,
1. Test code is provided in the Artifacts_Test_Evidence folder as test1_code(simple tutorial 
code) and test2_code(CUBIC_TCP_Snippet). CUBIC_Original is just for reference.
2. KLEE software needs to be run on a docker container.
Instructions to run KLEE:
1. Install Ubuntu on your system from Microsoft store after making sure that WSL latest 
version is active on your windows system.
2. Install docker on your Ubuntu Machine using following commands (fastest way: Watch 
the youtube video:- “Docker tutorial - Install Docker on Ubuntu fast”)
a. sudo apt-get update
b. sudo apt-get install apt-transport-https ca-certificates curl gnupg-agent softwareproperties-common
c. curl -fsSL https://download.docker.com/linux/ubu... | sudo apt-key add - sudo
apt-key fingerprint 0EBFCD88
d. sudo add-apt-repository "deb [arch=amd64]
https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
e. sudo apt-get update
f. sudo apt-get install docker-ce docker-ce-cli containerd.io
g. sudo docker run hello-world
3. After installing docker, use sudo dockerd command on bash shell to start a docker 
daemon.
4. Run the following shell commands to install KLEE on your system:
a. docker pull klee/klee
b. docker run –rm -ti –ulimit=’stack=-1:-1’ klee/klee
3. After installing KLEE, and entering the docker KLEE container, create a file and paste the 
contents of the test files into a file (test.c) and execute the following commands to analyze 
the code:
a. clang -emit-llvm -g -c test.c
b. llvm-dis ./test.bc
c. klee test.bc
After running test.bc, you should see an output file with the generated test cases, you 
can check those test cases using 
d. ktest-tool klee-last/test000001.ktest where test000001.ktest is the test file name.
Running KLEE-Float:
To pull the KLEE-Float into your Ubuntu machine, use the following commads:
a. docker pull comsys/klee-dev-fpbench-prebuilt:latest
b. git clone -b tool_exchange_03.05.2017_rebase_extra_bug_fixes https://github.com/srgimperial/klee-float.git
c. cd klee-float
d. scripts/docker_aachen_build.sh
Problems while installing KLEE-Float:
1. You might experience errors during the run of docker_aachen_build.sh where you might 
need to run as a non-root user, easiest way is to create a non-root user and run this build.
2. Also, one more issue we faced was that while running the build, one step tries to connect to 
a website https://pkgbuild.com/ which has it’s certificate expired. So, in order to override 
the certificate check of this website, we downloaded the project from GitHub to PyCharm 
IDE and modified the scripts/patch_aachen.Dockerfile line number 26 where we gave the 
command “—no-check-certificate”. Otherwise, installation will be halted.
e. After building, run this in the same way as original KLEE.
Limitations of the project:
We faced some errors where a symbolic input is used to call a different function of the code. 
Although there is a method klee --libc=uclibc --posix-runtime test.bc, we are yet to completely 
explore this and for now considering this as future work
