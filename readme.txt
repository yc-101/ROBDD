$ g++ source.cpp
$ ./a.out [PLA_FILE_NAME]
$ dot -T png [DOT_FILE_NAME] > output.png

note:
1. 檔案名稱
  4變數：a.pla
  5變數：b.pla
2.
 "g++ source.cpp" will generate "a.out" file
 When running "./a.out a.pla", there will be a robdd.dot (of a.pla) in the folder.
