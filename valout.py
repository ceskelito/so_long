==76765== Memcheck, a memory error detector
==76765== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==76765== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==76765== Command: ./bin/so_long maps/test.ber
==76765== 
==76765== Invalid read of size 8
==76765==    at 0x40339F: free_grid (free_utils.c:35)
==76765==    by 0x40266C: close_window (main.c:81)
==76765==    by 0x403CA1: mlx_loop (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402991: main (main.c:141)
==76765==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==76765== 
==76765== 
==76765== Process terminating with default action of signal 11 (SIGSEGV)
==76765==  Access not within mapped region at address 0x0
==76765==    at 0x40339F: free_grid (free_utils.c:35)
==76765==    by 0x40266C: close_window (main.c:81)
==76765==    by 0x403CA1: mlx_loop (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402991: main (main.c:141)
==76765==  If you believe this happened as a result of a stack
==76765==  overflow in your program's main thread (unlikely but
==76765==  possible), you can try to increase the size of the
==76765==  main thread stack using the --main-stacksize= flag.
==76765==  The main thread stack size used in this run was 8388608.
==76765== 
==76765== HEAP SUMMARY:
==76765==     in use at exit: 1,706 bytes in 24 blocks
==76765==   total heap usage: 991 allocs, 967 frees, 150,182 bytes allocated
==76765== 
==76765== 48 bytes in 1 blocks are still reachable in loss record 1 of 16
==76765==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x40569C: ft_calloc (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402A0A: extract_map (map_parser.c:30)
==76765==    by 0x402F7F: get_map (map_parser.c:140)
==76765==    by 0x402829: main (main.c:123)
==76765== 
==76765== 48 bytes in 1 blocks are still reachable in loss record 2 of 16
==76765==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x40569C: ft_calloc (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402C67: translate_map (map_parser.c:99)
==76765==    by 0x402FB1: get_map (map_parser.c:144)
==76765==    by 0x402829: main (main.c:123)
==76765== 
==76765== 66 bytes in 5 blocks are still reachable in loss record 3 of 16
==76765==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x40569C: ft_calloc (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4068FE: ft_strjoin (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4065CC: ft_append_buff (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4064FE: get_next_line (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402A36: extract_map (map_parser.c:34)
==76765==    by 0x402F7F: get_map (map_parser.c:140)
==76765==    by 0x402829: main (main.c:123)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 4 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4030A2: set_assets (assets_checker.c:27)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 5 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403104: set_assets (assets_checker.c:30)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 6 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403166: set_assets (assets_checker.c:33)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 7 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4031C8: set_assets (assets_checker.c:36)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 8 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x40322A: set_assets (assets_checker.c:39)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 88 bytes in 1 blocks are still reachable in loss record 9 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x403F1B: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403289: set_assets (assets_checker.c:42)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 10 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4030A2: set_assets (assets_checker.c:27)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 11 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403104: set_assets (assets_checker.c:30)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 12 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403166: set_assets (assets_checker.c:33)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 13 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x4031C8: set_assets (assets_checker.c:36)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 14 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x40322A: set_assets (assets_checker.c:39)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 136 bytes in 1 blocks are still reachable in loss record 15 of 16
==76765==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x49B80C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==76765==    by 0x403F46: mlx_int_new_xshm_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404242: mlx_new_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404B17: mlx_int_parse_xpm (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x404F51: mlx_xpm_file_to_image (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x403289: set_assets (assets_checker.c:42)
==76765==    by 0x4028CF: main (main.c:126)
==76765== 
==76765== 200 bytes in 5 blocks are still reachable in loss record 16 of 16
==76765==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==76765==    by 0x40569C: ft_calloc (in /nfs/homes/rceschel/so_long/bin/so_long)
==76765==    by 0x402C9F: translate_map (map_parser.c:103)
==76765==    by 0x402FB1: get_map (map_parser.c:144)
==76765==    by 0x402829: main (main.c:123)
==76765== 
==76765== LEAK SUMMARY:
==76765==    definitely lost: 0 bytes in 0 blocks
==76765==    indirectly lost: 0 bytes in 0 blocks
==76765==      possibly lost: 0 bytes in 0 blocks
==76765==    still reachable: 1,706 bytes in 24 blocks
==76765==         suppressed: 0 bytes in 0 blocks
==76765== 
==76765== For lists of detected and suppressed errors, rerun with: -s
==76765== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 1 from 1)
