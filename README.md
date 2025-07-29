valgrind --trace-children=yes  --track-fds=yes --show-leak-kinds=all --leak-check=full ./pipex main.c "ls -l" "wc -l" test.txt
