# /bin/zsh
mkdir abc/$1
cp template/abc/makefile abc/$1/
for i in {a..f}
do
  cp template/abc/template.cpp abc/$1/$i.cpp
done
