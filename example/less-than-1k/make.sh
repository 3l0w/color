
#cd ./akin
#./make.sh
#cd ..

cd ./assign
./make.sh
cd ..

cd ./check
./make.sh
cd ..

cd ./compare
./make.sh
cd ..

cd ./convert
./make.sh
cd ..

cd ./ctor
./make.sh
cd ..

cd ./fix
./make.sh
cd ..

cd ./format
./make.sh
cd ..

cd ./get
./make.sh
cd ..

cd ./make
./make.sh
cd ..

cd ./operation
./make.sh
cd ..

cd ./operator
./make.sh
cd ..

#cd ./place
#./make.sh
#cd ..

#cd ./set
#./make.sh
#cd ..

cd ./tip
./make.sh
cd ..

cd ./trait
./make.sh
cd ..

g++ -fexceptions -std=c++11 -g -I../../src empty.cpp        -o  empty
g++ -fexceptions -std=c++11 -g -I../../src hello.cpp        -o  hello
g++ -fexceptions -std=c++11 -g -I../../src yuv601.cpp       -o  yuv601
g++ -fexceptions -std=c++11 -g -I../../src yuv709.cpp       -o  yuv709
g++ -fexceptions -std=c++11 -g -I../../src pp2f.cpp         -o  pp2f

