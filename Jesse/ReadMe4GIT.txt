GIT使用记录

su - omniORB
cd $HOME

-----------------------本地库-基本操作,增加、删除、还原------------------------
#初始化
~$git init
初始化空的 Git 版本库于 /home/omniORB/.git/

~$lf
bin/  Downloads/  include/  Jesse/  lib/  mk/  omniORB-4.2.0/  omniORB-4.2.0.tar.bz2*  ReadMe4GIT.txt  share/  stub/

#增加文件夹和文件
~$ git add bin include lib omniORB-4.2.0 omniORB-4.2.0.tar.bz2 share 

#设置用户名
~$ git config --global user.name "User1"

#彩色输出
~$ git config color.ui true

#提交初始化操作
~$ git commit  -m "初始化"　

#查看状态
~$ git status

#删除整个文件夹,同时删除物理文件(未提交，放到缓存区)
~$ git rm -r omniORB-4.2.0     

#对删除内容进行还原(未提交)
~$ git status
~$ git reset #把当前的版本回退到上一个版本:--hard HEAD^ ;那么如果要回退到上上个版本只需把HEAD^ 改成 HEAD^^ 以此类推。那如果要回退到前100个版本的话，可以使用简便命令:git reset  --hard HEAD~100 即可。
~$ git checkout -- omniORB-4.2.0

#删除整个文件夹(提交)
~$ git rm -r omniORB-4.2.0     
~$ git commit -m "测试删除"

#对删除内容进行还原(已提交)
~$ git status
~$ git log    #查看对应的commit的ID
~$ git revert 90bf8b67e2f7e234d64d1f2bb0b9bb26fed39144 #为commit的ID

#对指定内容进行更新
~$ git add  ReadMe4GIT.txt
~$ git commit -m "增加内容"
~$ echo "just for test" >> ReadMe4GIT.txt
~$ git rm -r omniORB-4.2.0     
~$ git status
~$ git add ReadMe4GIT.txt                          #提交到缓存区, 可以通过 git commit -m "默认提交所有缓存区的到版本库"  进行提交
~$ git status
~$ git commit ReadMe4GIT.txt -m "测试更新"         #提交到版本库(可不提交到缓存区直接提交)
~$ git status
~$ git reset
~$ git checkout -- omniORB-4.2.0

#查看更新的具体内容
~$ git log    #查看对应的commit的ID,  git reflog 查看隐藏日志
~$ git show 90bf8b67e2f7e234d64d1f2bb0b9bb26fed39144 #为commit的ID


-----------------------本地库-分支操作与冲突解决------------------------
#查看分支
~$ git branch -a

#建立分支(branch_1)
~$ git branch branch_1   #创建+切换分支: git checkout -b branch_1

#切换分支
~$ git checkout branch_1 
~$ echo "just for test branch_1" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支1"
~$ git checkout master     #切换为主分支,需提交完当前分支的修改,才能切换
~$ tail ReadMe4GIT.txt     #看不到"just for test branch_1"文字
~$ git checkout branch_1   #切换为主分支,需提交完当前分支的修改,才能切换
~$ tail ReadMe4GIT.txt     #可看"just for test branch_1"文字
~$ git checkout -b branch_1_a  #在分支1基础上再分支
~$ echo "just for test branch_1_a" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支1中再建立分支"
~$ tail ReadMe4GIT.txt    #可看到 "just for test branch_1" 和 "just for test branch_1_a" 文字
~$ git checkout master     
~$ tail ReadMe4GIT.txt    #看不到 "just for test branch_1" 和 "just for test branch_1_a" 文字
~$ git checkout -b branch_2 
~$ echo "just for test branch_2" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支2"
~$ tail ReadMe4GIT.txt     #可看"just for test branch_2"文字

分支示意图:
----master----
     |----branch_1----
            |----branch_1_a----
     |----branch_2----

#合并、重命名、删除分支
~$ git checkout branch_1
~$ git merge  branch_1_a  #合并branch_1_a分支到branch_1
~$ tail ReadMe4GIT.txt    #可看到 "just for test branch_1" 和 "just for test branch_1_a" 文字
~$ git checkout master
~$ tail ReadMe4GIT.txt    #看不到 "just for test branch_1" 或 "just for test branch_1_a" 文字
~$ git merge  branch_1    #再合并branch_1分支到master
~$ tail ReadMe4GIT.txt    #可看到 "just for test branch_1" 和 "just for test branch_1_a" 文字
~$ git branch -d branch_1  #删除branch_1分支
~$ git checkout branch_1_a
~$ echo "just for test branch_1_a2" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试删除上级分支和再合并"
~$ git checkout master
~$ git merge  branch_1_a
~$ tail ReadMe4GIT.txt    #可看到 "just for test branch_1" 和 "just for test branch_1_a" 和 "just for test branch_1_a2" 文字
~$ git branch -m branch_2 dev

分支示意图:
----master----
     |----branch_1_a----
     |----dev----

#合并分支(多层合并测试)、冲突解决
~$ git checkout -b branch_3
~$ echo "just for test branch_3" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支3"
~$ git checkout -b branch_3_a
~$ echo "just for test branch_3_a" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支3上建立分支1"
~$ git branch branch_3_b  branch_3   #在分支3上建立反之3_b 相当于  git checkout branch_3; git checkout -b branch_3_b
~$ git checkout branch_3_b
~$ echo "just for test branch_3_b" >> ReadMe4GIT.txt
~$ git commit  ReadMe4GIT.txt -m "测试分支3上建立分支2"
~$ git checkout master
~$ git merge  branch_3_b  #合并branch_3_b分支到master
~$ tail ReadMe4GIT.txt    
~$ git checkout branch_3
~$ git merge  --no-ff -m "merge with no-ff"  branch_3_a  #合并branch_3_a分支到branch_3, 禁用Fast forward 
~$ git merge  --no-ff -m "merge with no-ff"  branch_3_b  #合并branch_3_b分支到branch_3,这时候会提示冲突
~$ tail ReadMe4GIT.txt    #能看到 <<<<<<<，=======，>>>>>>>标记出不同分支的内容
~$ vi ReadMe4GIT.txt      #修改为正确的内容后，保存
~$ git add ReadMe4GIT.txt
~$ git commit -m "测试分支合并冲突" 
~$ git status
~$ git branch -d branch_3_a
~$ git branch -d branch_3_b
~$ git branch -a
~$ git log --graph --pretty=oneline --abbrev-commit  #查看分支合并图,GIT合并分支时，如果可能，Git会用Fast forward模式，但这种模式下，删除分支后，会丢掉分支信息。 如果要强制禁用Fast forward模式，Git就会在merge时生成一个新的commit，这样，从分支历史上就可以看出分支信息。

分支示意图:
----master----
     |----branch_3----
            |----branch_3_a----
            |----branch_3_b----

其他命令:
git stash 把当前的工作隐藏起来 等以后恢复现场后继续工作
git stash list 查看所有被隐藏的文件列表
git stash apply 恢复被隐藏的文件，但是内容不删除
git stash drop 删除文件
git stash pop 恢复文件的同时 也删除文件


-----------------------远程库-------------------------











